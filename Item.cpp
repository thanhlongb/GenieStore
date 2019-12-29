#include "Helper.h"
#include "Item.h"

Item::Item(string raw_data) {
    if (Helper::find_char_occurrence(raw_data, ',') == 0) {
        this->id = raw_data;
    } else {
        int current_index = 0;
        this->id = Helper::read_next_word(raw_data, &current_index);
        if (!is_valid_id(this->id)) throw "Invalid item id.";
        this->title = Helper::read_next_word(raw_data, &current_index);
        this->item_type = Helper::read_next_word(raw_data, &current_index);
        this->loan_type = Helper::read_next_word(raw_data, &current_index);
        this->copies = atoi(Helper::read_next_word(raw_data, &current_index).c_str());
        this->rental_fee = atof(Helper::read_next_word(raw_data, &current_index).c_str());
        this->genre = Item::GENRE[0];
        if (!this->is_game()) {
            this->genre = Helper::read_next_word(raw_data, &current_index);
        }
    }
}

Item::Item(string id, string title, string loan_type, string item_type,
           int copies, float rental_fee, string genre) {
    if (!is_valid_id(id)) throw "Invalid item id.";
    this->id = id;
    this->title = title;
    this->loan_type = loan_type;
    this->item_type = item_type;
    this->copies = copies;
    this->rental_fee = rental_fee;
    this->rental_status = this->get_rental_status();
    this->genre = genre;
}

void Item::restock(int quantity) {
    if (quantity > 0) {
        if (this->is_out_of_stock()) {
            this->rental_status = RENTAL_STATUS[0];
        }
        this->copies += quantity;
    }
}

void Item::destock(int quantity) {
    if (quantity > 0) {
        this->copies -= quantity;
        if (this->is_out_of_stock()) {
            this->rental_status = RENTAL_STATUS[1];
        }
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
    return (this->copies == 0) ? Item::RENTAL_STATUS[1] : Item::RENTAL_STATUS[0];
}

string Item::get_genre() {
    return this->genre;
}

void Item::set_title(string title) {
    this->title = title;
}

void Item::set_loan_type(string loan_type) {
    this->loan_type = loan_type;
}

void Item::set_item_type(string item_type) {
    this->item_type = item_type;
}

void Item::set_copies(int copies) {
    this->copies = copies;
}

void Item::set_rental_fee(float rental_fee) {
    this->rental_fee = rental_fee;
}

void Item::set_genre(string genre) {
    this->genre = genre;
}

string Item::to_string() {
    //ID,Title,Rent type,Loan type,Number of copies,rental fee,[genre]
    string item_string = "";
    item_string.append(this->id + ",");
    item_string.append(this->title + ",");
    item_string.append(this->item_type + ",");
    item_string.append(this->loan_type + ",");
    item_string.append(::to_string(this->copies) + ",");
    item_string.append(::to_string(this->rental_fee).substr(0, ::to_string(this->rental_fee).find(".") + 3));
    if (!this->is_game()) {
        item_string.append("," + this->genre);
    }
    return item_string;
}

bool Item::is_out_of_stock() {
    return (this->copies == 0);
}

bool Item::is_game() {
    return (strcmp(this->item_type.c_str(), "Game") == 0);
}

bool Item::is_valid_id(string id) {
    if (id.length() != 9) return false;
    if (id.at(0) != 'I') return false;
    if (!isdigit(id.at(1)) ||
        !isdigit(id.at(2)) ||
        !isdigit(id.at(3)) ||
        !isdigit(id.at(5)) ||
        !isdigit(id.at(6)) ||
        !isdigit(id.at(7)) ||
        !isdigit(id.at(8))) return false;
    if (id.at(4) != '-') return false;
    return true;
}

bool Item::is_2_day_loan() {
    return (strcmp(this->loan_type.c_str(), "2-day") == 0);
}

const string Item::LOAN_TYPE[] = {"2-day", "1-week", "."};
const string Item::ITEM_TYPE[] = {"Record", "DVD", "Game", "."};
const string Item::RENTAL_STATUS[] = {"available", "borrowed", "."};
const string Item::GENRE[] = {"Action", "Horror", "Drama", "Comedy", "."};