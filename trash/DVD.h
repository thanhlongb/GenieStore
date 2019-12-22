//
// Created by longb on 12/19/19.
//
#include "Item.h"

#ifndef GENIESTORE_DVD_H
#define GENIESTORE_DVD_H


class DVD : public Item
{
public:
    string to_string();
    string get_genre();
private:
    string genre;
};



#endif //GENIESTORE_DVD_H
