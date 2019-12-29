#include "Helper.h"
#include "Customer.h"

Customer::Customer(string raw_data) {
    int current_index = 0;
    this->id = Helper::read_next_word(raw_data, &current_index);
    if (!is_valid_id(this->id)) throw "Invalid customer id.";
    this->name = Helper::read_next_word(raw_data, &current_index);
    this->address = Helper::read_next_word(raw_data, &current_index);
    this->phone = Helper::read_next_word(raw_data, &current_index);
    Helper::read_next_word(raw_data, &current_index); // skipping total borrowed items count
    this->tier = Helper::read_next_word(raw_data, &current_index);
    if (this->is_vip()) {
        this->reward_point = atoi(Helper::read_next_word(raw_data, &current_index).c_str());
    }
}

Customer::Customer(string id, string name, string address, string phone, string tier) {
    if (!is_valid_id(id)) throw "Invalid customer id.";
    this->id = id;
    this->name = name;
    this->address = address;
    this->phone = phone;
    this->tier = tier;
}

string Customer::get_id() {
    return this->id;
}

string Customer::get_name() {
    return this->name;
}

string Customer::get_address() {
    return this->address;
}

string Customer::get_phone() {
    return this->phone;
}

string Customer::get_tier() {
    return this->tier;
}

LinkedList<Item> Customer::get_rentals() {
    return this->rentals;
}

void Customer::set_name(string name) {
    this->name = name;
}

void Customer::set_address(string address) {
    this->address = address;
}

void Customer::set_phone(string phone) {
    this->phone = phone;
}

void Customer::set_tier(string tier) {
    this->tier = tier;
}

void Customer::rent_item(Item item) {
    if (this->is_guest()) {
        if (this->rentals.size() >= 2)
            throw "Guest customer can rent 2 items at a time.";
        if (item.is_2_day_loan())
            throw "Guest can't rent '2-day' loan type items.";
    } else if (this->is_vip()) {
        this->reward_point += 10;
    }
    this->rentals.add(item);
}

void Customer::add_rental(Item item) {
    this->rentals.add(item);
}

void Customer::use_reward_point() {
    this->reward_point -= 100;
}

void Customer::return_item(string item_id) {
    this->rentals.remove(item_id);
}

void Customer::promote() {
    if (this->rentals.size() > 3) {
        if (this->is_guest()) {
            this->tier = TIER[1];
        } else if (this->is_regular()) {
            this->tier = TIER[2];
        } else if (this->is_vip()) {
            throw "VIP customer can't be promoted.";
        }
    } else {
        throw "Customer must rented more than 3 items to be promoted.";
    }
}

string Customer::to_string() {
    //ID,Name,Address,Phone,Number of rentals,customer type followed by a list
    string customer_string = "";
    customer_string.append(this->id + ",");
    customer_string.append(this->name + ",");
    customer_string.append(this->address + ",");
    customer_string.append(this->phone + ",");
    customer_string.append(::to_string(this->rentals.size()) + ",");
    customer_string.append(this->tier);
    if (this->is_vip()) {
        customer_string.append("," + ::to_string(this->reward_point));
    }
    return customer_string;
}

bool Customer::is_valid_id(string id) {
    if (id.length() != 4) return false;
    if (id.at(0) != 'C') return false;
    if (!isdigit(id.at(1)) ||
        !isdigit(id.at(2)) ||
        !isdigit(id.at(3))) return false;
    return true;
}

bool Customer::is_eligible_for_free_item() {
    return (this->is_vip() && this->reward_point >= 100);
}

bool Customer::is_guest() {
    return (strcmp(this->tier.c_str(), TIER[0].c_str()) == 0);
}
bool Customer::is_regular() {
    return (strcmp(this->tier.c_str(), TIER[1].c_str()) == 0);
}
bool Customer::is_vip() {
    return (strcmp(this->tier.c_str(), TIER[2].c_str()) == 0);
}

const string Customer::TIER[] = {"Guest", "Regular", "VIP", "."};
