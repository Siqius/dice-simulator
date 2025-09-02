#include "game.h"
#include <stdio.h>
#include <ctime>
#include <iostream>
#include <unistd.h>

//Game constructor
Game::Game(const int _player_balance, const int _max_bet): player_bet(0), player_wins(0), computer_wins(0), round(0), running(true) {
    player_balance = _player_balance;
    max_bet = _max_bet;
}

//Basic game loop
void Game::init() {
    bet_system();
    round++;

    //Roll all the die and display them
    int computer_roll1 = this->roll_dice();
    printf("Computer rolled a %i\n", computer_roll1);
    this->pause();
    int player_roll1 = this->roll_dice();
    printf("Player rolled a %i\n", player_roll1);
    this->pause();
    int computer_roll2 = this->roll_dice();
    printf("Computer rolled a %i\n", computer_roll2);
    this->pause();
    int player_roll2 = this->roll_dice();
    printf("Player rolled a %i\n", player_roll2);
    this->pause();

    //Calculate total points and display them to the user
    int player_total = player_roll1 + player_roll2;
    int computer_total = computer_roll1 + computer_roll2;

    printf("Player rolled a total of %i points\n", player_total);
    this->pause();
    printf("Computer rolled a total of %i points\n", computer_total);
    this->pause();

    //Check who won the round, or if it was a tie
    if (player_total == computer_total) {
        printf("It's a tie!\n");
    }else if (player_total > computer_total) {
        printf("Player wins this round!\n");
        player_wins++;
    }else {
        printf("Computer wins this round!\n");
        computer_wins++;
    }

    //Display amount of wins for both player and computer
    this->pause();
    printf("Player now has %i wins\n", player_wins);
    this->pause();
    printf("Computer now has %i wins\n", computer_wins);
    this->pause();

    //Check if either player or computer has won the game and handle betting, aswell ass reset the game
    if (player_wins >= 2) {
        printf("Player has won the game!\nYou have won $%i!\nYour new balance is $%i.\nYour new total earnings are $%i\n", player_bet, player_balance + player_bet, total_winnings + player_bet);
        player_balance += player_bet;
        total_winnings += player_bet;
        this->reset_game();
    }
    if (computer_wins >= 2) {
        printf("Computer has won the game, better luck next time!\nYou have lost $%i!\nYour new balance is $%i.\nYour new total earnings are $%i\n", player_bet, player_balance + player_bet, total_winnings - player_bet);
        player_balance -= player_bet;
        total_winnings -= player_bet;
        this->reset_game();
    }

    //New line between games for readability
    std::cout << std::endl;
}

//Betting system, with fail-safes to ensure the player cannot illegally bet negative numbers, above the maximum bet amount, or more than is in their account
void Game::bet_system() {
    if (round == 0) {
        printf("Your balance is $%i\n", player_balance);
        this->pause();
        printf("How much do you want to bet? (max $5000)\n");
        while (true) {
            std::cin >> player_bet;
            if (player_bet > 5000) {
                printf("Value too high, must be $5000 or below\n");
                continue;
            }
            if (player_bet < 0) {
                printf("Value too small, must be greater than 0\n");
                continue;
            }
            if (player_bet > player_balance) {
                printf("Insufficient account balance, you only have $%i\n", player_balance);
                continue;
            }
            break;
        }
    }
}

//Reset game state and ask player if they want to continue
void Game::reset_game() {
    player_wins = 0;
    computer_wins = 0;
    round = 0;
    printf("continue? (y/n)\n");
    while (true) {
        std::string input;
        std::cin >> input;
        if (input == "y") {
            break;
        }
        if (input == "n") {
            running = false;
            break;
        }
        printf("Invalid, try again.\n");
    }
}

//Pause the game for a few seconds to make the results more readable
void Game::pause() {
    sleep(3);
}

//Function to roll the dice
int Game::roll_dice() {
    srand(time(nullptr));
    return rand() % 6 + 1;
}