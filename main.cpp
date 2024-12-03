#include <iostream>
#include "./Functions.cpp"
#include "./Hands.cpp"
using namespace std;


// Main driver of the game, currently only determines number of players up to 3
//      then from there draws initial cards and allows each player to draw more
//      no logic to actually score the game, win/lose, or place bets, or have the dealer draw
int main() {
    int num_players = 0;

    // could add names to each player
    do {
        cout << "Home many people would like to play" << "\n" << "(enter a number 1 to 3)? : ";
        cin >> num_players;
        if (num_players == 0 or num_players > 3) {
            if (num_players == 0) {
                //system("cls");
                system(clear);
                cout << "The dealer can't play by himself, you need at least one player." << endl << endl;
            }
            else {
                //system("cls");
                system(clear);
                cout << "Lets not get crazy, pick a maximum of 3." << endl << endl;
            }
        }
        else if (num_players > 0 and num_players < 4) {
            //system("cls");
            system(clear);
            cout << "Lets Play BlackJack!!!" << endl << endl;
        }
        else {
            cout << "Something went wrong, please try again";
            num_players = 0;
        }
    } while (num_players == 0 || num_players > 3);
    char play = 'Y';
    do {
        start_game(num_players, dealer_hand, player1_hand, player2_hand, player3_hand, card_suit, card);
        for (int i = 1; i <= num_players; i++) {
            char draw_dec = 'y';
            cout << "Player " << i << "'s turn." << endl;
            do {
                cout << "Would you like to draw a card? " << endl;
                cin >> draw_dec;
                if (draw_dec == 'y' or draw_dec == 'Y') {
                    if (i == 1 & player1_hand[0][0] == 1) {
                        add_card_hand(player1_hand);
                        score_hand(player1_hand);
                        if (player1_hand[0][0] == 0 || player1_hand[0][0] == 2) {
                            draw_dec = 'N';
                        }
                    }
                    else if (i == 2 & player2_hand[0][0] == 1) {
                        add_card_hand(player2_hand);
                        score_hand(player2_hand);
                        if (player2_hand[0][0] == 0 || player2_hand[0][0] == 2) {
                            draw_dec = 'N';
                        }
                    }
                    else if (i == 3 & player3_hand[0][0] == 1) {
                        add_card_hand(player3_hand);
                        score_hand(player3_hand);
                        if (player3_hand[0][0] == 0 || player3_hand[0][0] == 2) {
                            draw_dec = 'N';
                        }
                    }
                    update_game_status (num_players, dealer_hand, player1_hand, player2_hand, player3_hand, card_suit, card);
                }
                else {
                    update_game_status (num_players, dealer_hand, player1_hand, player2_hand, player3_hand, card_suit, card);
                }
            } while (draw_dec == 'y');
        }
        add_card_hand(dealer_hand);
        score_hand(dealer_hand);
        update_game_status (num_players, dealer_hand, player1_hand, player2_hand, player3_hand, card_suit, card);

        do {
                dealer_AI(dealer_hand);
                update_game_status (num_players, dealer_hand, player1_hand, player2_hand, player3_hand, card_suit, card);
        } while (dealer_hand[0][0] == 1);

        update_game_status(num_players, dealer_hand, player1_hand, player2_hand, player3_hand, card_suit, card);

        cout << "Would you like to play again? (Y or N): ";
        cin >> play;
        if (play == 'Y' or play == 'y') {
            clear_game(dealer_hand, player1_hand, player2_hand, player3_hand, control_hand);
        }
        //system("cls");
        system(clear);
    } while (play == 'y' || play == 'Y');

    cout << "Thanks for playing !!!!!";
}

/*
start program (home screen "welcome to blackjack")
    - intro game loop - (way to edit number of players after each round)
    how many players are playing (1 to 3)
        names of players
    - main game loop -
    start round
        draw initial cards
        - begin main round loop -
        would each player like to draw cards
*/

// some way to bet on the games ??
// AI for the dealer to decide to draw or not
// Logic to test when the player or dealer goes over, and to test at the end after the dealer has gone or buated
// Logic to clear and reset the game (except for the bets between rounds.)
// AI for players that you can add in ??