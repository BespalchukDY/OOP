#include "player.h"

Player::Player(const std::string &name) : GenericPlayer(name) {}

Player::~Player() {}

bool Player::IsHitting() const {
    cout << m_Name << ", хотите еще карту? (Y/N): ";
    char response;
    cin >> response;
    return (response == 'y' || response == 'Y' || response == 'д' || response == 'Д');
}

void Player::Win() const { cout << m_Name << " выиграл. Поздравляем!\n"; }

void Player::Lose() const { cout << m_Name << " проиграл(((\n"; }

void Player::Push() const { cout << m_Name << " ничья. Повезет в другой раз!\n"; }
