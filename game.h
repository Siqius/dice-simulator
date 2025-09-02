#ifndef GAME_H
#define GAME_H

class Game {
public:
    Game(int _player_balance, int _max_bet);

    int player_balance;
    int player_bet;
    int total_winnings;

    int player_wins;
    int computer_wins;

    bool running;

    void init();
    void pause();
    void bet_system();
    void reset_game();
    int roll_dice();

    int round;

    int max_bet;
};

#endif
