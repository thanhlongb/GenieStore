//
// Created by longb on 12/19/19.
//
#include "Item.h"

#ifndef GENIESTORE_GAME_H
#define GENIESTORE_GAME_H


class Game : public Item
{
public:
    Game() {};
    Game(string id, string title, string loan_type,
    int copies, float rental_fee, string rental_status);
    string to_string();
private:
};



#endif //GENIESTORE_GAME_H
