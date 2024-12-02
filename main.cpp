#include <iostream>
#include "./Functions.cpp"
#include "./Hands.cpp"
using namespace std;


// Main driver of the game, currently only determines number of players up to 3
//      then from there draws initial cards and allows each player to draw more
//      no logic to actually score the game, win/lose, or place bets, or have the dealer draw
int main() {
    double num_players = 0;

    // could add names to each player
    do {
        cout << "Home many people would like to play" << "\n" << "(enter a number 1 to 3)? : ";
        cin >> num_players;
        if (num_players == 0 or num_players > 3) {
            if (num_players == 0) {
                system("clear");
                cout << "The dealer can't play by himself, you need at least one player." << endl << endl;
            }
            else {
                system("clear");
                cout << "Lets not get crazy, pick a maximum of 3." << endl << endl;
            }
        }
        else if (num_players > 0 and num_players < 4) {
            system("clear");
            cout << "Lets Play BlackJack!!!" << endl << endl;
        }
        else {
            cout << "Something went wrong, please try again";
            num_players = 0;
        }
    } while (num_players == 0 || num_players > 3);
    start_game(num_players, dealer_hand, player1_hand, player2_hand, player3_hand, card_suit, card);
    for (int i = 1; i <= num_players; i++) {
        char draw_dec = 'y';
        cout << "Player " << i << "'s turn." << endl;
        do {
            cout << "Would you like to draw a card? " << endl;
            cin >> draw_dec;
            if (draw_dec == 'y' or draw_dec == 'Y') {
                if (i == 1) {
                    add_card_hand(player1_hand);
                }
                else if (i == 2) {
                    add_card_hand(player2_hand);
                }
                else if (i == 3) {
                    add_card_hand(player3_hand);
                }
                update_game_status (num_players, dealer_hand, player1_hand, player2_hand, player3_hand, card_suit, card);
            }
            else {
                update_game_status (num_players, dealer_hand, player1_hand, player2_hand, player3_hand, card_suit, card);
            }
        } while (draw_dec == 'y');
    }
}

// some way to bet on the games ??
// AI for the dealer to decide to draw or not
// Logic to test when the player or dealer goes over, and to test at the end after the dealer has gone or buated
// Logic to clear and reset the game (except for the bets between rounds.)
// AI for players that you can add in ??
