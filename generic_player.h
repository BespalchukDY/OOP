#ifndef GENERIC_PLAYER_H
#define GENERIC_PLAYER_H

#include "hand.h"
#include <string>

class GenericPlayer : public Hand {
    friend ostream &operator<<(ostream &os, const GenericPlayer &aGenericPlayer);

  public:
    GenericPlayer(const string &name = "");

    virtual ~GenericPlayer();

    /**
     * @brief показывает, хочет ли игрок продолжать брать карты
     *
     * @note Для класса GenericPlayer функция не имеет своей реализации,
     *       т.к. для игрока и дилера это будут разные функции
     *
     * @return true, если берёт карту
     */
    virtual bool IsHitting() const = 0;

    /**
     * @brief Игрок имеет перебор по очкам
     *
     * @note данная функция не виртуальная, т.к. имеет
     *       одинаковую реализацию для игрока и дилера
     *
     * @return true, если перебор
     */
    bool IsBusted() const;

    /**
     * @brief Объявляет, что игрок имеет перебор
     *
     * @note функция одинакова как для игрока, так и для дилера
     */
    void Bust() const;

  protected:
    string m_Name;
};

 /**
  * @brief Перегружает оператор<<, чтобы получить возможность
  *        отправить объект типа GenericPlayer в поток cout
  */
ostream &operator<<(ostream &os, const GenericPlayer &aGenericPlayer);

#endif  // GENERIC_PLAYER_H