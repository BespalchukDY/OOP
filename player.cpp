#include "player.h"

Player::Player(const std::string &name) : GenericPlayer(name) {}

Player::~Player() {}

bool Player::IsHitting() const {
    cout << m_Name << ", ������ ��� �����? (Y/N): ";
    char response;
    cin >> response;
    return (response == 'y' || response == 'Y' || response == '�' || response == '�');
}

void Player::Win() const { cout << m_Name << " �������. �����������!\n"; }

void Player::Lose() const { cout << m_Name << " ��������(((\n"; }

void Player::Push() const { cout << m_Name << " �����. ������� � ������ ���!\n"; }
