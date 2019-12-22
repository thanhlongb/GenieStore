//
// Created by longb on 12/19/19.
//

#include "Item.h"

Item::Item(string id, string title, string loan_type, string item_type, int copies, float rental_fee, string rental_status) {
    this->id = id;
    this->title = title;
    this->loan_type = loan_type;
    this->item_type = item_type;
    this->copies = copies;
    this->rental_fee = rental_fee;
    this->rental_status = rental_status;
}

void Item::restock(int quantity) {
    if (quantity > 0) {
        this->copies += quantity;
    }
}

void Item::destock(int quantity) {
    if (quantity > 0) {
        this->copies -= quantity;
    }
}

string Item::get_id() {
    return this->id;
}

string Item::get_title() {
    return this->title;
}

string Item::get_loan_type() {
    return this->loan_type;
}

string Item::get_item_type() {
    return this->item_type;
}

int Item::get_copies() {
    return this->copies;
}

float Item::get_rental_fee() {
    return this->rental_fee;
}

string Item::get_rental_status() {
    return this->rental_status;
}

const char* Item::LOAN_TYPE[] = {"2-day", "1-week"};
const char* Item::ITEM_TYPE[] = {"record", "dvd", "game"};
const char* Item::RENTAL_STATUS[] = {"avaiable", "not_avaialble"};
const char* Item::GENRE[];