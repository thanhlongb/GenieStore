//
// Created by longb on 12/19/19.
//

#include "Item.h"

Item::Item(string id, string title, string loan_type,
           string item_type, int copies, float rental_fee,
           string rental_status, string genre) {
    this->id = id;
    this->title = title;
    this->loan_type = loan_type;
    this->item_type = item_type;
    this->copies = copies;
    this->rental_fee = rental_fee;
    this->rental_status = rental_status;
    this->genre = genre;
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

string Item::get_genre() {
    return this->genre;
}

string Item::to_string() {
    //ID,Title,Rent type,Loan type,Number of copies,rental fee,[genre]
    string item_string = "";
    item_string.append(this->id + ",");
    item_string.append(this->item_type + ",");
    item_string.append(this->loan_type + ",");
    item_string.append(::to_string(this->copies) + ",");
    item_string.append(::to_string(this->rental_fee));
    if (strcmp(this->item_type.c_str(), "game") != 0) {
        item_string.append("," + this->genre);
    }
    return item_string;
}

const string Item::LOAN_TYPE[] = {"2-day", "1-week"};
const string Item::ITEM_TYPE[] = {"record", "dvd", "game"};
const string Item::RENTAL_STATUS[] = {"available", "not_available"};
const string Item::GENRE[] = {"action", "horror", "drama", "comedy"};