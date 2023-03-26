#include <iostream>
#include <stdexcept>
#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Test 1 - Initialization")
{
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1, p2);

    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);
}

TEST_CASE("Test 2 - Card test")
{
    Card first(10, "Diamonds");
    Card second(3, "Clover");
    Card third(8, "Heart");
    Card fourth(1, "Heart");

    CHECK(first.compareto(second) == 1);
    CHECK(second.compareto(third) == -1);
    CHECK(fourth.compareto(fourth) == 0);
    CHECK(fourth.compareto(first) == -1);
    CHECK(third.compareto(first) == -1);
    CHECK(second.compareto(first) == -1);
}

TEST_CASE("Test 3 - Player class")
{
    Player p1("Avichai");
    Player p2("Mizrachi");
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);
    Card first(1, "Hearts");
    Card second(11, "Diamonds");
    Card third(10, "Pikes");
    p1.addCard(first);
    p2.addCard(third);
    CHECK(p1.stacksize() == 27);
    CHECK(p1.cardesTaken() == 28);
    CHECK(p2.cardesTaken() == 26);
    CHECK(p2.cardesTaken() == 27);
    p1.addCard(second);
    CHECK(p1.cardesTaken() == 28);
}

TEST_CASE("Test 4 -  Game class")
{
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1, p2);

    CHECK(game.printWiner() == "No winner yet");

    Card a(3, "Diamond");
    Card b(8, "Heart");
    Card c(10, "Clover");

    p1.addCard(a);
    p1.addCard(b);
    p1.addCard(c);

    Card d(2, "Diamond");
    Card e(4, "Heart");
    Card f(11, "Clover");

    p2.addCard(d);
    p2.addCard(e);
    p2.addCard(f);

    game.playTurn();
    string s = game.printLastTurn();
    CHECK(s == "Alice played 3 of Diamonds Bob played 3 of Diamonds. Alice wins.");
    CHECK(p1.cardesTaken() == 1);
    CHECK(p2.stacksize() == 25);

    game.playAll();

    if (p1.stacksize() == 0)
    {
        string winner = game.printWiner();
        CHECK(winner == "Bob");
    }
    else
    {
        string winner = game.printWiner();
        CHECK(winner == "Alice");
    };

    CHECK(p2.cardesTaken() >= 26);
    CHECK(p2.stacksize() == 52);
    CHECK(p1.cardesTaken() == 0);
    CHECK(p1.stacksize() == 0);

    // SUBCASE("ends by equal"){
    //     Player p1("Alice");
    //     Player p2("Bob");
    //     Game g(p1, p2);

    //     CHECK(g.printWiner() == "No one");

    //     g.playAll();

    //     Player w("Winner");
    //     Player l("Loser");

    //     if(p1.stacksize() == 0) {
    //         w = p2;
    //         l = p1;
    //     } else {
    //         w = p1;
    //         l = p2;
    //     }

    //     w.addCardtoStart(Card(1, "Clubs"));
    //     w.addCardtoStart(Card(10, "Hearts"));
    //     w.addCardtoStart(Card(5, "Hearts"));

    //     l.addCardtoStart(Card(1, "Hearts"));
    //     l.addCardtoStart(Card(12, "Hearts"));
    //     l.addCardtoStart(Card(5, "Diamonds"));

    //     g.playTurn();

    //     string s = g.printLastTurn();

    //     CHECK(s == "Alice played 5 of Hearts Bob played 5 of Diamonds. Draw. Alice played 1 of Clubs Bob played 1 of Hearts. Draw.");

    //     CHECK(l.stacksize() == 3);
    //     CHECK(w.stacksize() == 49);

    //     g.playAll();
    //     CHECK_THROWS(g.playTurn());
}