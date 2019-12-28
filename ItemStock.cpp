//
// Created by longb on 12/19/19.
//
#include <fstream>
#include <iostream>
#include "ItemStock.h"
#include "Helper.h"

using namespace std;

void ItemStock::add(Item item) {
    this->items.add(item);
}

void ItemStock::remove(string item_id) {
    this->items.remove(item_id);
}

void ItemStock:: update(string item_id, Item item) {
    this->items.update(item_id, item);
}

Item ItemStock::get(string item_id) {
    Item item;
    try {
        item = this->items.get(item_id);
    } catch (int error_code) {
        if (error_code == 404) {
            throw "Item doesn't exist.";
        }
    }
    return item;
}

Item ItemStock::get(int item_index) {
    if (item_index < 0 || item_index >= this->items.size()) {
        throw "Item index is out of bound.";
    }
    Item item;
    try {
        item = this->items.get(item_index);
    } catch (int error_code) {
        throw "Item doesn't exist.";
    }
    return item;
}

LinkedList<Item> ItemStock::get_all() {
    return this->items;
}

int ItemStock::size() {
    return this->items.size();
}

void ItemStock::restock(string item_id, int quantity) {
    if (quantity <= 0) {
        throw "Restock quantity must be larger than 0.";
    }
    Item item;
    try {
        item = this->items.get(item_id);
    } catch (int error_code) {
        if (error_code == 404) {
            throw "Item doesn't exist.";
        }
    }
    item.restock(quantity);
    this->items.update(item_id, item);
}

void ItemStock::destock(string item_id, int quantity) {
    this->items.get(item_id).destock(quantity);
}

void ItemStock::set_data_file_name(string data_file_name) {
    this->data_file_name = data_file_name;
}

void ItemStock::load() {
    string line;
    int count = 0;
    ifstream file(this->data_file_name);
    if (file.is_open()) {
        while (getline(file, line)) {
            this->items.add(Item(line));
        }
    } else {
        // unable to open file
        throw "Unable to load items from data file.";
    }
}

void ItemStock::save() {
    ofstream file(this->data_file_name);
    if (file.is_open()) {
        for (int i = this->size() - 1; i >= 0; i--) {
            file << this->items.get(i).to_string() << endl;
        }
        file.close();
    } else {
        // unable to open file
        throw "Unable to save items to data file.";
    }
}