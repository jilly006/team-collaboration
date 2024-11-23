//
// Created by cbowe on 11/22/2024.
//
#include <random>
#include <ctime>
#include <string>
#include <windows.h>
#include <stdlib.h>
using namespace std;

// name says it all, grabs a couple random ints for the card # and suit, and adds it to the 2d
//      array of the corresponding hand
// got to be a better way to get a random varaible that doesn't require the sleep time to get a different
//      time seed
void add_card_hand(int which_hand[3][10]) {
    srand((unsigned) time(NULL));
    int rand_card = 2 + (rand() % 10);
    Sleep(800); // Slows down so that the same numbers aren't generated from the time
    int rand_suit = rand() % 4;
    Sleep(800); // 800 Seems to be the lowest value to get a new random value
    for (int i = 0; i < 10; i++) {
        if (which_hand[0][i] == 1 & which_hand[0][i+1] == 0) {
            which_hand[1][i] = rand_card;
            which_hand[2][i] = rand_suit;
            which_hand[0][i] = 2, which_hand[0][i+1] = 1;
            i = 10;
            //This was all just to test shit as i kept fucking it up
            //cout << "rand card " << rand_card << endl;
            //cout << "suit " << rand_suit << endl;
            //for (int j = 0; j < 3; j++) {
            //    cout << which_hand[j][i] << endl;
            //}
        }
    }
}

void print_hand(int which_hand[3][10], string card_suit[], string card[5][1]) {
    int sum_of_hand = 0, num_of_cards = 0;
    // This for loop counts the number of cards in a hand and scores it
    // maybe move the score to another function that also keeps track of betting and other things?
    for (int i = 0; i < 10; i++) {
        if (which_hand[0][i] == 2) {
            num_of_cards++;
            sum_of_hand += which_hand[1][i];
        }
    }
    //cout << num_of_cards << endl; // just to test shit

    //This next chunk bit prints out all the cards currently in a hand going one row at a time
    for (int i = 0; i < num_of_cards; i++) {
        cout << card[0][0];
    }
    cout << endl;
    for (int i = 0; i < num_of_cards; i++) {
        if (which_hand[1][i] < 10) {
            cout << "|" << which_hand[1][i] << "     | ";
        }
        else if (which_hand[1][i] >= 10) {
            cout << "|" << which_hand[1][i] << "    | ";
        }
    }
    cout << endl;
    for (int i = 0; i < num_of_cards; i++) {
        cout << card[2][0];
    }
    cout << endl;
    for (int i = 0; i < num_of_cards; i++) {
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
    for (int i = 0; i < num_of_cards; i++) {
        cout << card[4][0];
    }
    cout << endl << "Sitting at: " << sum_of_hand << endl;
    cout << endl;
}

// propogates the hands of all players initially to start a new game or rounds
void start_game(int num_players,int dealer_hand[3][10], int player1_hand[3][10], int player2_hand[3][10], int player3_hand[3][10], string card_suit[], string card[5][1]) {
    if (num_players >= 1) {
        add_card_hand(dealer_hand);
        print_hand(dealer_hand, card_suit, card);
        add_card_hand(player1_hand); add_card_hand(player1_hand);
        print_hand(player1_hand, card_suit, card);
    }
    if (num_players >= 2) {
        add_card_hand(player2_hand); add_card_hand(player2_hand);
        print_hand(player2_hand, card_suit, card);
    }
    if (num_players >= 3) {
        add_card_hand(player3_hand); add_card_hand(player3_hand);
        print_hand(player3_hand, card_suit, card);
    }
}

// clears the console and updates all of the hands in the game
void update_game_status (int num_players,int dealer_hand[3][10], int player1_hand[3][10], int player2_hand[3][10], int player3_hand[3][10], string card_suit[], string card[5][1]) {
    system("cls");
    if (num_players >= 1) {
        cout << "Dealer:" << endl;
        print_hand(dealer_hand, card_suit, card);
        cout << "Player 1:" << endl;
        print_hand(player1_hand, card_suit, card);
    }
    if (num_players >= 2) {
        cout << "Player 2:" << endl;
        print_hand(player2_hand, card_suit, card);
    }
    if (num_players >= 3) {
        cout << "Player 3:" << endl;
        print_hand(player3_hand, card_suit, card);
    }
}


//void clear_game() // would be to reset all the hands for a new game or round