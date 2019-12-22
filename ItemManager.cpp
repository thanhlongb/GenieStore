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
    string item_id = Helper::read_user_input();
    cout << "Item title: ";
    string item_title = Helper::read_user_input();
    cout << "Item loan type: ";
    string item_loan_type = Helper::read_user_input();
    cout << "Item type: ";
    string item_type = Helper::read_user_input();
    cout << "Item copies: ";
    string item_copies = Helper::read_user_input();
    cout << "Item rental fee: ";
    string item_rental_fee = Helper::read_user_input();
    cout << "Item rental status: ";
    string item_rental_status = Helper::read_user_input();
}

void update_item();
void delete_item();
void restock_item();
void rent_an_item();
void return_an_item();
void display_all_items();
void display_out_of_stock_items();
void search_for_items();