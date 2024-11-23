//
// Created by cbowe on 11/22/2024.
//
#include <string>
using namespace std;

//int number[] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; // Dont think this is needed
string card_suit[] = { "Heart", "Diamond", "Spade", "Club"};

string card[5][1]={
    {" ______  "},
    {"         "},
    {"|      | "},
    {"|        "},
    {"|______| "}
};

//control hand to reset hands between games
 int control_hand[3][10]={ // Each column is an individual card each row data on that card
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // in use?
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // Number of that card
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0} // Suit of that card
};

//Dealer and player Hands
int dealer_hand[3][10] = {
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // tracks if there is a card in this column
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // Card number
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0} // Card Suit
};

int player1_hand[3][10] = {
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int player2_hand[3][10] = {
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int player3_hand[3][10] = {
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

// Could add more??
// Don't have Kings or queens yet (Could increase the number of cards to 13 and say use 10-12 as jack through king
//      and assign them in the print card function

// Haven't tried or integrated anything to do with this yet
int player_scores[4][10] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // Active or not? (1 - 2)
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // player? (0 = dealer, 1-9 players
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // Amount of money?
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0} // Games won
};