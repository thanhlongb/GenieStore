//
// Created by longb on 12/19/19.
//

#include "ItemStock.h"

void ItemStock::add(Item item) {
    this->items.add(item);
}

void ItemStock::remove(string item_id) {
    this->items.remove(item_id);
}

void ItemStock::update(string item_id, Item item) {
    this->items.update(item_id, item);
}

Item ItemStock::get(string item_id) {
    return this->items.get(item_id);
}

Item ItemStock::get(int item_index) {
    return this->items.get(item_index);
}

int ItemStock::size() {
    return this->items.size();
}

void ItemStock::restock(string item_id, int quantity) {
    this->items.get(item_id).restock(quantity);
}

void ItemStock::destock(string item_id, int quantity) {
    this->items.get(item_id).destock(quantity);
}

void ItemStock::load() {
    // TODO: work on ItemStock::load()
}

void ItemStock::save() {
    // TODO: work on ItemStock::load()
    // TODO: consider creating class called Database to implement save() and load() for both ItemStock and CustomerList
}