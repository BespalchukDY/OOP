#include "house.h"

House::House(const std::string &name) : GenericPlayer(name) {}

House::~House() {}

bool House::IsHitting() const { return (GetTotal() <= 16); }

void House::FlipFirstCard() {
    if (!(m_Cards.empty())) {
        m_Cards[0]->Flip();
    } else {
        cout << "Нет карт для переворачивания!\n";
    }
}
