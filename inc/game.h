#ifndef GAME_H
#define GAME_H

#include "player.h"

#include <vector>

class Game
{
public:
    Game(unsigned char, unsigned char, unsigned char);
    ~Game();

    void loop(void);
    void draw(unsigned char);

private:

    /* Functions */
    unsigned char choose_pawn(void);
    unsigned char choose_disc(unsigned char);

    /* Getters and Setters */
    void number_players(unsigned char);
    unsigned char number_players(void);

    void number_pawns(unsigned char);
    unsigned char number_pawns(void);

    void number_discs(unsigned char);
    unsigned char number_discs(void);

    void init_players(void);
    std::vector<Player*> players(void);

    /* Variables */
    unsigned char _num_players;
    unsigned char _num_pawns;
    unsigned char _num_discs;
    std::vector<Player*> _players;
};

#endif
