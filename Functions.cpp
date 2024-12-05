//
// Created by cbowe on 11/22/2024.
//
#include <random>
#include <ctime>
#include <string>
using namespace std;

// name says it all, grabs a couple random ints for the card # and suit, and adds it to the 2d
//      array of the corresponding hand
void add_card_hand(int which_hand[3][10]) {
    // seeds and initializes the Mersenne Twister random number generator
    random_device rd;
    mt19937 gen(rd());
    // creates 2 distributions to use with the random number gen
    uniform_int_distribution<int> distribution1(1, 12);
    uniform_int_distribution<int> distribution2(0, 3);

    int rand_card = distribution1(gen); // rand_card value from distribution 1 (1 - 12)
    int rand_suit = distribution2(gen); // rand_suit value from distribution 2 (0 - 3)
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

void score_hand(int dealer_hand[][10], int which_hand[][10], int game_state) {
    // The main game loop while everyone is drawing
    if (game_state == 0) {
        which_hand[2][0] = 0; // resets score each time a hand is scored
        for (int i = 1; i < 10; i++) { // scores everything but aces in this loop
            if (which_hand[0][i] == 2) {
                if (which_hand[1][i] == 11) { // covers scoring 11s/queens (value 10)
                    which_hand[2][0] += 10;
                }
                else if (which_hand[1][i] == 12) { // covers scoring 12s/kings (value 10)
                    which_hand[2][0] += 10;
                }
                else if (which_hand[1][i] > 1 & which_hand[1][i] < 11) { // Covers cards 2 to 9
                    which_hand[2][0] += which_hand[1][i];
                }
            }
        }
        // aces are scored in this loop after everything else to know if they need to be dropped in value
        //      from 11 to 1
        for (int i = 1; i < 10; i++) {
            if (which_hand[0][i] == 2) {
                if (which_hand[1][i] == 1 & which_hand[2][0] + 11 <= 21) {
                    which_hand[2][0] += 11;
                }
                else if (which_hand[1][i] == 1) {
                    which_hand[2][0] += which_hand[1][i];
                }
            }
        }
        // changes the hand state [0][0] if the player gets a blackjack or busts by going over 21
        if (which_hand[2][0] > 21) {
            which_hand[0][0] = 0;
        }
        else if (which_hand[2][0] == 21) {
            which_hand[0][0] = 2;
        }
    }
    // once the main game loop is over and the dealer is finished drawing, givees the end results
    else if (game_state == 1) {
        if ((dealer_hand[0][0] == 3 || dealer_hand[0][0] == 2) & (which_hand[0][0] == 1 || which_hand[0][0] == 2)) {
            if (dealer_hand[2][0] == which_hand[2][0]) {
                which_hand[0][0] = 7;
            }
            else if (dealer_hand[2][0] > which_hand[2][0]) {
                which_hand[0][0] = 8;
            }
            else if (dealer_hand[2][0] < which_hand[2][0]) {
                which_hand[0][0] = 9;
            }
        }
        if (which_hand[0][0] == 0) {
            which_hand[0][0] = 6;
        }
        else if (dealer_hand[0][0] == 4 && (which_hand[0][0] == 1 || which_hand[0][0] == 2)) {
            which_hand[0][0] = 9;
        }
    }

}

void print_hand(int which_hand[3][10], string card_suit[], string card[5][1]) {
    // This next chunk bit prints out all the cards currently in a hand
    //      going one row at a time using the card 2d array
    int num_of_cards = which_hand[1][0]; // gets the number of cards in the hand from the relevant array [1][0]
    // Prints out the top of each card for however many cards are in the hand
    for (int i = 1; i < num_of_cards+1; i++) {
        cout << card[0][0];
    }
    cout << endl;
    // Looks at what the card values are in [1][i > 1] and prints the relevant option below
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
    // prints the next space for however many cards are in the hand
    for (int i = 1; i < num_of_cards+1; i++) {
        cout << card[2][0];
    }
    cout << endl;
    // prints out the suit for each card as denoted by [2][i > 1]
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
    // prints the bottom of each card
    for (int i = 1; i < num_of_cards+1; i++) {
        cout << card[4][0];
    }

    // game states for each player hand
    if (which_hand[0][0] == 0) {
        cout << endl << "YOU BUSTED, with a hand totalling: " << which_hand[2][0] << endl;
    }
    else if (which_hand[0][0] == 1) {
        cout << endl << "Sitting at: " << which_hand[2][0] << endl;
    }
    else if (which_hand[0][0] == 2) {
        cout << endl << "BLACKJACK!" << endl;
    }

    // game states for the dealer specifically
    else if (which_hand[0][0] == 3) {
        cout << endl << "The Dealer Stands at: " << which_hand[2][0] << endl;
    }
    else if (which_hand[0][0] == 4) {
        cout << endl << "The Dealer Busted at: " << which_hand[2][0] << endl;
    }

    // end game states for each player hand
    else if (which_hand[0][0] == 6) {
        cout << endl << "You BUSTED and lost with a hand totalling: " << which_hand[2][0] << endl;
    }
    else if (which_hand[0][0] == 7) {
        cout << endl << "You TIED the dealer with a hand totalling: " << which_hand[2][0] << endl;
    }
    else if (which_hand[0][0] == 8) {
        cout << endl << "You LOST to the dealer with a hand totalling: " << which_hand[2][0] << endl;
    }
    else if (which_hand[0][0] == 9) {
        cout << endl << "You BEAT the dealer with a hand totalling: " << which_hand[2][0] << endl;
    }
    cout << endl;
}

// propagates the hands of all players initially to start a new game or round
void start_game(int num_players,int dealer_hand[3][10], int player1_hand[3][10], int player2_hand[3][10], int player3_hand[3][10], string card_suit[], string card[5][1], int game_state) {
    cout << "Lets play Blackjack!" << "\n" << endl;
    if (num_players >= 1) {
        cout << "Dealer:" << endl;
        add_card_hand(dealer_hand);
        score_hand(dealer_hand, dealer_hand, game_state);
        print_hand(dealer_hand, card_suit, card);
        cout << "Player 1:" << endl;
        add_card_hand(player1_hand); add_card_hand(player1_hand);
        score_hand(dealer_hand, player1_hand, game_state);
        print_hand(player1_hand, card_suit, card);
    }
    if (num_players >= 2) {
        cout << "Player 2:" << endl;
        add_card_hand(player2_hand); add_card_hand(player2_hand);
        score_hand(dealer_hand, player2_hand, game_state);
        print_hand(player2_hand, card_suit, card);
    }
    if (num_players >= 3) {
        cout << "Player 3:" << endl;
        add_card_hand(player3_hand); add_card_hand(player3_hand);
        score_hand(dealer_hand, player3_hand, game_state);
        print_hand(player3_hand, card_suit, card);
    }
}

// clears the console and updates all the hands in the game
void update_game_status (int num_players,int dealer_hand[3][10], int player1_hand[3][10], int player2_hand[3][10], int player3_hand[3][10], string card_suit[], string card[5][1], int game_state) {
    //system("cls");
    system("clear");
    cout << "Lets play Blackjack!" << "\n" << endl;
    // system(clear);
    if (num_players >= 1) {
        cout << "Dealer:" << endl;
        print_hand(dealer_hand, card_suit, card);
        cout << "Player 1:" << endl;
        score_hand(dealer_hand, player1_hand, game_state);
        print_hand(player1_hand, card_suit, card);
    }
    if (num_players >= 2) {
        cout << "Player 2:" << endl;
        score_hand(dealer_hand, player2_hand, game_state);
        print_hand(player2_hand, card_suit, card);
    }
    if (num_players >= 3) {
        cout << "Player 3:" << endl;
        score_hand(dealer_hand, player3_hand, game_state);
        print_hand(player3_hand, card_suit, card);
    }

}

// resets the hand inputed to the intial state
void clear_hand(int some_player_hand[][10], int control_hand[][10]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++) {
            some_player_hand[i][j] = control_hand[i][j];
        }
    }
}

// resets all hands in the game to the initial game state for a new round
void clear_game(int dealer_hand[3][10], int player1_hand[3][10], int player2_hand[3][10], int player3_hand[3][10], int control_hand[3][10]) {
    clear_hand(dealer_hand, control_hand);
    clear_hand(player1_hand, control_hand);
    clear_hand(player2_hand, control_hand);
    clear_hand(player3_hand, control_hand);
}

// Determines whether AI should draw a card or not
void dealer_AI (int dealer_hand[][10], int game_state) {
    if (dealer_hand[2][0] < 17) {
        add_card_hand(dealer_hand);
    }
    score_hand(dealer_hand, dealer_hand, game_state);
    if (dealer_hand[2][0] == 21) {
        dealer_hand[0][0] = 2;
    }
    else if (dealer_hand[2][0] > 21) {
        dealer_hand[0][0] = 4;
    }
    else if (dealer_hand[2][0] >= 17 & dealer_hand[2][0] <= 20) {
        dealer_hand[0][0] = 3;
    }
}