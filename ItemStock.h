#include "Item.h"
#include "LinkedList.h"
#ifndef GENIESTORE_ITEMSTOCK_H
#define GENIESTORE_ITEMSTOCK_H


class ItemStock
{
private:
    LinkedList<Item> items;
    string data_file_name = "items.txt";
public:
    ItemStock() {};
    void add(Item item);
    void remove(string item_id);
    void update(string item_id, Item item);
    Item get(string item_id);
    Item get(int item_index);
    int size();
    LinkedList<Item> get_all();
    void restock(string item_id, int quantity);
    void destock(string item_id, int quantity);
    void set_data_file_name(string data_file_name);
    void load();
    void save();
};


#endif //GENIESTORE_ITEMSTOCK_H
