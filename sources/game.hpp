#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "player.hpp"
using namespace std;
using namespace ariel;

class Game
{

public:
    Game(Player player1, Player player2);
    void playTurn();
    string printLastTurn();
    string printStats();
    string printLog();
    string printWiner();
    void playAll();
};

#endif