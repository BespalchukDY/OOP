#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include <ctime>

#include "deck.h"
#include "house.h"
#include "player.h"

class Game {
  public:

    Game(const vector<string> &names);

    ~Game();

    void Play();

  private:
    Deck m_Deck;
    House m_House;
    vector<Player> m_Players;
};

#endif  // GAME_H