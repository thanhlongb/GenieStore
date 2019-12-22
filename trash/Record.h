//
// Created by longb on 12/19/19.
//
#include "Item.h"

#ifndef GENIESTORE_RECORD_H
#define GENIESTORE_RECORD_H


class Record : public Item
{
public:
    string to_string();
    string get_genre();
private:
    string genre;
};




#endif //GENIESTORE_RECORD_H
