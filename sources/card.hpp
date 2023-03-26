#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

namespace ariel
{

    class Card
    {

    public:
        Card(int value, string type);
        int compareto(Card second);
    };

}

#endif