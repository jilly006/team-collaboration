//
// Created by cbowe on 11/22/2024.
//
#include <string>
using namespace std;

string card_suit[] = { "Heart", "Diamond", "Spade", "Club"};
string player_names[] = {"Dealer", "Player1", "Player2", "Player3"};

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
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0} // Card Suit number which is used to find suit in the Card_suit array above
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
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // Active or not? (0 inactive, 1 active)
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // Amount of money?
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // Active Bets
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0} // Games won
};