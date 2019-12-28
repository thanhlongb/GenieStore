//
// Created by longb on 12/22/19.
//
#include "ItemStock.h"

#ifndef GENIESTORE_ITEMMANAGER_H
#define GENIESTORE_ITEMMANAGER_H


class ItemManager {
private:
    ItemStock stock;
public:
    ItemManager() {};
    void add_item();
    void update_item();
    void delete_item();
    void restock_item();
    void display_all_items();
    void display_out_of_stock_items();
    void search_for_items();
    ItemStock* get_stock_pointer();
    void set_db_file(string db_file);
    void load_items();
    void save_items();
};


#endif //GENIESTORE_ITEMMANAGER_H
