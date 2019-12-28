//
// Created by longb on 12/22/19.
//
#include <iostream>
#include "Item.h"
#include "Helper.h"
#include "Customer.h"
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
    int genre = 0; // default value
    if (strcmp(Item::ITEM_TYPE[item_type].c_str(), "Game") != 0) {
        cout << "Item genre: " << endl;
        genre = Helper::prompt_user_option(Item::GENRE);
    }
    Item item;
    try {
        item = Item(id, title,
                  Item::LOAN_TYPE[loan_type],
                  Item::ITEM_TYPE[item_type],
                  copies, rental_fee,
                  Item::GENRE[genre]);
        this->stock.add(item);
    } catch (const char* error) {
        cout << error << endl;
        return;
    }
    cout << "Item '" << item.get_id() << "' has been added to the stock." << endl;
}

void ItemManager::update_item() {
    const string UPDATE_OPTIONS[] = {"title", "loan type",
                                     "item type", "copies",
                                     "rental fee", "genre",
                                     "confirm update", "."};
    cout << "Enter ID of the item you want to update: ";
    string update_item_id = Helper::read_user_string();
    Item item;
    try {
        item = this->stock.get(update_item_id);
    } catch (const char* error) {
        cout << error << endl;
        return;
    }
    bool confirmed_update = false;
    while (!confirmed_update) {
        cout << "Select the field you want to edit: " << endl;
        int selected_option = Helper::prompt_user_option(UPDATE_OPTIONS);
        switch (selected_option) {
            case 0: {
                cout << "Item title (old: '" << item.get_title() << "'): ";
                string title = Helper::read_user_string();
                item.set_title(title);
                break;
            }
            case 1: {
                cout << "Item loan type (old: '" << item.get_loan_type() << "'): " << endl;
                int loan_type = Helper::prompt_user_option(Item::LOAN_TYPE);
                item.set_loan_type(Item::LOAN_TYPE[loan_type]);
                break;
            }
            case 2: {
                cout << "Item type (old: '" << item.get_item_type() << "'): " << endl;
                int item_type = Helper::prompt_user_option(Item::ITEM_TYPE);
                item.set_item_type(Item::ITEM_TYPE[item_type]);
                break;
            }
            case 3: {
                cout << "Item copies (old: '" << item.get_copies() << "'): ";
                int copies = Helper::read_user_int();
                item.set_copies(copies);
                break;
            }
            case 4: {
                cout << "Item rental fee (old: '" << item.get_rental_fee() << "'): ";
                float rental_fee = Helper::read_user_float();
                item.set_rental_fee(rental_fee);
                break;
            }
            case 5: {
                if (item.is_game()) {
                    cout << "Games doesn't have genre." << endl;
                    break;
                }
                int genre = 0; // default value
                cout << "Item genre (old: '" << item.get_genre() << "'): " << endl;
                genre = Helper::prompt_user_option(Item::GENRE);
                item.set_genre(Item::GENRE[genre]);
                break;
            }
            case 6: {
                confirmed_update = true;
                break;
            }
            default: break;
        }
    }
    try {
        this->stock.update(update_item_id, item);
    } catch (const char* error) {
        cout << error << endl;
    }
}

void ItemManager::delete_item() {
    cout << "Enter ID of the item you want to delete: ";
    string delete_item_id = Helper::read_user_string();
    try {
        this->stock.remove(delete_item_id);
    } catch (const char* error) {
        cout << error << endl;
        return;
    }
    cout << "Item deleted." << endl;
}

void ItemManager::restock_item() {
    cout << "Enter ID of the item you want to restock: ";
    string restock_item_id = Helper::read_user_string();
    cout << "Enter the quantity you want to restock: ";
    int quantity = Helper::read_user_int();
    try {
        this->stock.restock(restock_item_id, quantity);
    } catch (const char* error) {
        cout << error << endl;
        return;
    }
    cout << "Item restocked." << endl;
}

void ItemManager::display_all_items() {
    LinkedList<Item> all_items = this->stock.get_all();
    for (int i = 0; i < all_items.size(); i++) {
        Item item = all_items.get(i);
        cout << item.to_string() << endl;
    }
}

void ItemManager::display_out_of_stock_items() {
    LinkedList<Item> all_items = this->stock.get_all();
    for (int i = 0; i < all_items.size(); i++) {
        Item item = all_items.get(i);
        if (item.get_copies() == 0) {
            cout << item.to_string() << endl;
        }
    }
}

void ItemManager::search_for_items() {
    // TODO: add sorting
    cout << "Enter the keyword of the item you want to search: ";
    string keyword = Helper::read_user_string();
    LinkedList<Item> all_items = this->stock.get_all();
    for (int i = 0; i < all_items.size(); i++) {
        Item item = all_items.get(i);
        if (item.to_string().find(keyword) != string::npos) {
            cout << item.to_string() << endl;
        }
    }
}

ItemStock* ItemManager::get_stock_pointer() {
    return &this->stock;
}

void ItemManager::set_db_file(string db_file) {
    this->stock.set_data_file_name(db_file);
}

void ItemManager::load_items() {
    try {
        this->stock.load();
    } catch (const char* error) {
        cout << error << endl;
    }
}

void ItemManager::save_items() {
    try {
        this->stock.save();
    } catch (const char* error) {
        cout << error << endl;
    }
}