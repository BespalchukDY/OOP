#ifndef HAND_H
#define HAND_H

#include "card.h"
#include <vector>

class Hand {
  public:
    Hand();

    virtual ~Hand();

    void Add(Card *pCard);

    void Clear();

    int GetTotal() const;

  protected:
    vector<Card *> m_Cards;
};

#endif  // HAND_H
