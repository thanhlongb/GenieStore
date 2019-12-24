//
// Created by longb on 12/22/19.
//
#include <iostream>
#include "Item.h"
#include "Helper.h"
#include "ItemManager.h"

void ItemManager::add_item() {
    cout << "Please provide information for new item:" << endl;
    cout << "Item id: ";
    string id = Helper::read_user_string();
    cout << "Item title: ";
    string title = Helper::read_user_string();
    cout << "Item loan type: " << endl;
    int loan_type = Helper::prompt_user_option(Item::LOAN_TYPE);
    cout << "Item type: " << endl;
    int item_type = Helper::prompt_user_option(Item::ITEM_TYPE);
    cout << "Item copies: ";
    int copies = Helper::read_user_int();
    cout << "Item rental fee: ";
    float rental_fee = Helper::read_user_float();
    cout << "Item rental status: " << endl;
    int rental_status = Helper::prompt_user_option(Item::RENTAL_STATUS);
    int genre = 0; // default value
    if (strcmp(Item::ITEM_TYPE[item_type].c_str(), "game") != 0) {
        genre = Helper::prompt_user_option(Item::GENRE);
        cout << "Item genre: " << endl;
    }
    // TODO: validate ID format
    Item new_item(id, title,
                  Item::LOAN_TYPE[loan_type],
                  Item::ITEM_TYPE[item_type],
                  copies, rental_fee,
                  Item::RENTAL_STATUS[rental_status],
                  Item::GENRE[genre]);
    this->stock.add(new_item);
}

void ItemManager::update_item() {
    cout << "Enter ID of the item you want to update: ";
    string update_item_id = Helper::read_user_string();
    Item update_item = this->stock.get(update_item_id);
    // TODO: implement ItemManager::update_time()
}

void ItemManager::delete_item() {
    cout << "Enter ID of the item you want to delete: ";
    string delete_item_id = Helper::read_user_string();
    try {
        this->stock.remove(delete_item_id);
        cout << "Item deleted.";
    } catch (const char* error) {
        cout << error << endl;
    }
}

void ItemManager::restock_item() {
    cout << "Enter ID of the item you want to restock: ";
    string restock_item_id = Helper::read_user_string();
    cout << "Enter the quantity you want to restock: ";
    int quantity = Helper::read_user_int();
    try {
        this->stock.restock(restock_item_id, quantity);
        cout << "Item restocked.";
    } catch (const char* error) {
        cout << error << endl;
    }
}

void ItemManager::rent_an_item() {
    // TODO: implement ItemManager::rent_an_item()
}

void ItemManager::return_an_item() {
    // TODO: implement ItemManager::return_an_item()
}

void ItemManager::display_all_items() {
    LinkedList<Item> all_items = this->stock.get_all();
    for (int i = 0; i < all_items.size(); i++) {
        Item item = all_items.get(i);
        cout << item.to_string() << endl;
    }
}

void display_out_of_stock_items();
void search_for_items();

void ItemManager::print_item(Item item) {
    if (item.get_item_type() != "game") {
    }
}