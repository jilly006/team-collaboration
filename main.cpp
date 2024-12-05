#include <iostream>
#include "./Functions.cpp"
#include "./Hands.cpp"
using namespace std;

int main() {
    int num_players = 0;

    // Checks to see how many people want to play
    do {
        cout << "Welcome to Blackjack!" << "\n" << endl;
        cout << "Home many people would like to play" << "\n" << "(Enter a number 1 to 3)? : ";
        cin >> num_players;
        if (num_players == 0 or num_players > 3) {
            if (num_players == 0) {
                //system("cls");
                system("clear");
                cout << "The dealer can't play by himself, you need at least one player." << endl << endl;
            }
            else {
                //system("cls");
                system("clear");
                cout << "Lets not get crazy, pick a maximum of 3." << endl << endl;
            }
        }
        else if (num_players > 0 and num_players < 4) {
            //system("cls");
            system("clear");
        }
        else {
            cout << "Something went wrong, please try again";
            num_players = 0;
        }
    } while (num_players == 0 || num_players > 3); // Controls intro game loop where number of players are set
    char play = 'Y';

    do { // main game loop
        int game_state = 0; // tells the score_hand function how to score hands and output the score
        start_game(num_players, dealer_hand, player1_hand, player2_hand, player3_hand, card_suit, card, game_state);
        for (int i = 1; i <= num_players; i++) { // loops draw or not draw decision for how ever many players active
            char draw_dec = 'y';
            do {
                cout << "Player " << i << "'s turn." << endl;
                cout << "Would you like to draw a card?" << endl << "('Y' for yes and 'N' for no): ";
                cin >> draw_dec;
                if (draw_dec == 'y' or draw_dec == 'Y') {
                    if (i == 1 & player1_hand[0][0] == 1) { // player one, adds card if they decide and outputs altered game state
                        add_card_hand(player1_hand);
                        score_hand(dealer_hand, player1_hand, game_state);
                        if (player1_hand[0][0] == 0 || player1_hand[0][0] == 2) { // interrupts if state of player is 0 if player busted and 2 if they blackjack
                            draw_dec = 'N';
                        }
                    }
                    else if (i == 2 & player2_hand[0][0] == 1) {
                        add_card_hand(player2_hand);
                        score_hand(dealer_hand, player2_hand, game_state);
                        if (player2_hand[0][0] == 0 || player2_hand[0][0] == 2) {
                            draw_dec = 'N';
                        }
                    }
                    else if (i == 3 & player3_hand[0][0] == 1) {
                        add_card_hand(player3_hand);
                        score_hand(dealer_hand, player3_hand, game_state);
                        if (player3_hand[0][0] == 0 || player3_hand[0][0] == 2) {
                            draw_dec = 'N';
                        }
                    }
                    update_game_status (num_players, dealer_hand, player1_hand, player2_hand, player3_hand, card_suit, card, game_state);
                }
                else {
                    update_game_status (num_players, dealer_hand, player1_hand, player2_hand, player3_hand, card_suit, card, game_state);
                }
            } while (draw_dec == 'y' || draw_dec == 'Y');
        }

        // Purely to slow the game down before the dealer draws and the game is decided
        char temp;
        cout << endl << "Are you ready for the dealer to proceed?" << endl << "('Y' for yes and 'N' for no): ";
        cin >> temp;

        // Dealer draws second card after everyone is finished drawing
        add_card_hand(dealer_hand);
        score_hand(dealer_hand, dealer_hand, game_state);
        update_game_status (num_players, dealer_hand, player1_hand, player2_hand, player3_hand, card_suit, card, game_state);

        // initializes dealer AI to decide whether to continue drawing or not
        do {
            dealer_AI(dealer_hand, game_state);
            update_game_status (num_players, dealer_hand, player1_hand, player2_hand, player3_hand, card_suit, card, game_state);
        } while (dealer_hand[0][0] == 1);
        game_state = 1;

        // Updates the game after the dealer is finished drawing
        //system("cls");
        system("clear");
        update_game_status (num_players, dealer_hand, player1_hand, player2_hand, player3_hand, card_suit, card, game_state);

        // Checks if everyone wants to play again
        cout << "Would you like to play again? (Y or N): ";
        cin >> play;
        if (play == 'Y' or play == 'y') {
            clear_game(dealer_hand, player1_hand, player2_hand, player3_hand, control_hand);
        }
        //system("cls");
        system("clear");

        // system(clear);
    } while (play == 'y' || play == 'Y');

    cout << "Thanks for playing !!!!!";
}