#ifndef HOUSE_H
#define HOUSE_H
#include "generic_player.h"

class House : public GenericPlayer {
  public:
    House(const string &name = "Computer");

    virtual ~House();

    virtual bool IsHitting() const;

    void FlipFirstCard();
};

#endif  // HOUSE_H
