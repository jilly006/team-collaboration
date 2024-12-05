//
// Created by cbowe on 11/22/2024.
//
#include <string>
using namespace std;

// used to print out the suit from the suit "number" stored in each hand
string card_suit[] = { "Heart", "Diamond", "Spade", "Club"};
// used to store the players names as given at the beginning of the game
string player_names[] = {"Dealer", "Player1", "Player2", "Player3"};

// this is the prototype card that is used to print all other cards
string card[5][1]={
    {" ______  "},
    {"         "},
    {"|      | "},
    {"|        "},
    {"|______| "}
};

//control hand to reset hands between games
int control_hand[3][10]={ // Each column is an individual card each row data on that card
    {1, 1, 0, 0, 0, 0, 0, 0, 0, 0}, // in use? 2 denotes a colum 'holding' a card '1' denotes next column to place a card
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // Number of that card (not nessecarily its value, that's decided in the score_hand function)
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0} // Suit of that card in number form, when printed accesses the card_suit array
};
    // The first column in each hand does not hold a card but holds information for the hand
    // [0][0] - holds the "player state" which drives what is printed below each hand
//          - 0 for players if they have busted
//          - 1 for players and dealer if they are active and either still drawing or have stopped drawing without busting
//          - 2 for players if they blackjack
//      These next 2 are for the dealer
//          - 3 for dealer if the hand decided to stand and not busted
//          - 4 for dealer if they busted
//      These next 4 are for the end game states after everyone has finished drawing including the dealer
//          - 6 player busted and lost
//          - 7 player tied with dealer
//          - 8 neither player nor dealer busted and the player lost
//          - 9 the player won regardless of what the dealer did
    // [1][0] - holds the number of cards in the hand
    // [2][0] - holds the total score of the hand

//Dealer and player Hands
int dealer_hand[3][10] = {
    {1, 1, 0, 0, 0, 0, 0, 0, 0, 0}, // Tracks if there is a card in this column
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // Card number
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0} // Card Suit number which is used to find suit in the Card_suit array above
};

int player1_hand[3][10] = {
    {1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int player2_hand[3][10] = {
    {1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int player3_hand[3][10] = {
    {1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};
