//
// Created by cbowe on 11/22/2024.
//
#include <random>
#include <ctime>
#include <string>
#include <windows.h>
//#include <random>
using namespace std;

// name says it all, grabs a couple random ints for the card # and suit, and adds it to the 2d
//      array of the corresponding hand
void add_card_hand(int which_hand[3][10]) {
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> distribution(0, 3);
    uniform_int_distribution<int> distribution2(1, 12);

    int rand_card = distribution2(gen);
    int rand_suit = distribution(gen);
    for (int i = 1; i < 10; i++) {
        if (which_hand[0][i] == 1 & which_hand[0][i+1] == 0) {
            which_hand[1][i] = rand_card;
            which_hand[2][i] = rand_suit;
            which_hand[0][i] = 2, which_hand[0][i+1] = 1;
            which_hand[1][0] += 1;
            i = 10;
        }
    }
}

void score_hand(int some_player_hand[][10]) {
    some_player_hand[2][0] = 0;
    for (int i = 1; i < 10; i++) {
        if (some_player_hand[0][i] == 2) {
            if (some_player_hand[1][i] == 11) {
                some_player_hand[2][0] += 10;
            }
            else if (some_player_hand[1][i] == 12) {
                some_player_hand[2][0] += 10;
            }
            else if (some_player_hand[1][i] > 1 & some_player_hand[1][i] < 11) {
                some_player_hand[2][0] += some_player_hand[1][i];
            }
        }
    }
    for (int i = 1; i < 10; i++) {
        if (some_player_hand[0][i] == 2) {
            if (some_player_hand[1][i] == 1 & some_player_hand[2][0] + 11 <= 21) {
                some_player_hand[2][0] += 11;
            }
            else if (some_player_hand[1][i] == 1) {
                some_player_hand[2][0] += some_player_hand[1][i];
            }
        }
    }
    if (some_player_hand[2][0] > 21) {
        some_player_hand[0][0] = 0;
    }
    else if (some_player_hand[2][0] == 21) {
        some_player_hand[0][0] = 2;
    }
}

void print_hand(int which_hand[3][10], string card_suit[], string card[5][1]) {
    // This next chunk bit prints out all the cards currently in a hand
    //      going one row at a time
    int num_of_cards = which_hand[1][0];
    for (int i = 1; i < num_of_cards+1; i++) {
        cout << card[0][0];
    }
    cout << endl;
    for (int i = 1; i < num_of_cards+1; i++) {
        if (which_hand[1][i] == 1) {
            cout <<"|A     | ";
        }
        else if (which_hand[1][i] > 1 & (which_hand[1][i] < 10)) {
            cout << "|" << which_hand[1][i] << "     | ";
        }
        else if (which_hand[1][i] == 10) {
            cout << "|J     | ";
        }
        else if (which_hand[1][i] == 11) {
            cout << "|Q     | ";
        }
        else if (which_hand[1][i] == 12) {
            cout << "|K     | ";
        }
    }
    cout << endl;
    for (int i = 1; i < num_of_cards+1; i++) {
        cout << card[2][0];
    }
    cout << endl;
    for (int i = 1; i < num_of_cards+1; i++) {
        if (card_suit[which_hand[2][i]] == "Heart") {
            cout << "|" << card_suit[which_hand[2][i]] << " | ";
        }
        else if (card_suit[which_hand[2][i]] == "Diamond") {
            cout << "|" << card_suit[which_hand[2][i]] << " ";
        }
        else if (card_suit[which_hand[2][i]] == "Spade") {
            cout << "|" << card_suit[which_hand[2][i]] << " | ";
        }
        else if (card_suit[which_hand[2][i]] == "Club") {
            cout << "|" << card_suit[which_hand[2][i]] << "  | ";
        }
    }
    cout << endl;
    for (int i = 1; i < num_of_cards+1; i++) {
        cout << card[4][0];
    }
    if (which_hand[0][0] == 1) {
        cout << endl << "Sitting at: " << which_hand[2][0] << endl;
    }
    else if (which_hand[0][0] == 0) {
        cout << endl << "YOU BUSTED, with a hand totalling: " << which_hand[2][0] << endl;
    }
    else if (which_hand[0][0] == 2) {
        cout << endl << "BLACKJACK!" << endl;
    }
    else if (which_hand[0][0] == 3) {
        cout << endl << "The Dealer Stands at :" << which_hand[2][0] << endl;
    }
    cout << endl;
    /*for (int i = 0; i < 3; i++) {     // Just testing things - prints out the arrays themselves
        for (int j = 0; j < 10; j++) {
            cout << which_hand[i][j] << " ";
        }
        cout << endl;
    }*/
}

// propogates the hands of all players initially to start a new game or round
void start_game(int num_players,int dealer_hand[3][10], int player1_hand[3][10], int player2_hand[3][10], int player3_hand[3][10], string card_suit[], string card[5][1]) {
    if (num_players >= 1) {
        add_card_hand(dealer_hand);
        score_hand(dealer_hand);
        print_hand(dealer_hand, card_suit, card);

        add_card_hand(player1_hand); add_card_hand(player1_hand);
        score_hand(player1_hand);
        print_hand(player1_hand, card_suit, card);
    }
    if (num_players >= 2) {
        add_card_hand(player2_hand); add_card_hand(player2_hand);
        score_hand(player2_hand);
        print_hand(player2_hand, card_suit, card);
    }
    if (num_players >= 3) {
        add_card_hand(player3_hand); add_card_hand(player3_hand);
        score_hand(player3_hand);
        print_hand(player3_hand, card_suit, card);
    }
}

// clears the console and updates all the hands in the game
void update_game_status (int num_players,int dealer_hand[3][10], int player1_hand[3][10], int player2_hand[3][10], int player3_hand[3][10], string card_suit[], string card[5][1]) {
    // system("cls");
    system(clear);
    if (num_players >= 1) {
        cout << "Dealer:" << endl;
        score_hand(dealer_hand);
        print_hand(dealer_hand, card_suit, card);
        cout << "Player 1:" << endl;
        score_hand(player1_hand);
        print_hand(player1_hand, card_suit, card);
    }
    if (num_players >= 2) {
        cout << "Player 2:" << endl;
        score_hand(player2_hand);
        print_hand(player2_hand, card_suit, card);
    }
    if (num_players >= 3) {
        cout << "Player 3:" << endl;
        score_hand(player3_hand);
        print_hand(player3_hand, card_suit, card);
    }

}

void clear_hand(int some_player_hand[][10], int control_hand[][10]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++) {
            some_player_hand[i][j] = control_hand[i][j];
        }
    }
}

void clear_game(int dealer_hand[3][10], int player1_hand[3][10], int player2_hand[3][10], int player3_hand[3][10], int control_hand[3][10]) {
    clear_hand(dealer_hand, control_hand);
    clear_hand(player1_hand, control_hand);
    clear_hand(player2_hand, control_hand);
    clear_hand(player3_hand, control_hand);
}

// Determines whether AI should draw a card or not
void dealer_AI (int dealer_hand[][10]) {
    if (dealer_hand[2][0] < 17) {
        add_card_hand(dealer_hand);
    }
    else if (dealer_hand[2][0] == 21) {
        dealer_hand[0][0] = 2;
    }
    else {
        dealer_hand[0][0] = 3;
    }
/*    else {
        for  (int i = 1; i < 10; i++) {
            if (dealer_hand[1][i] == 1 & (dealer_hand[2][0] - 10 <= 10)) {
                dealer_hand[2][0] -= 0;
                dealer_AI(dealer_hand);
            }
            else {
                dealer_hand[0][0] += 0;
            }
        }
    }
    score_hand(dealer_hand); */
}