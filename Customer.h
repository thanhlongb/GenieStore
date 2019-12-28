//
// Created by longb on 12/26/19.
//

#include <string>
#include "Item.h"
#include "LinkedList.h"

using namespace std;

#ifndef GENIESTORE_CUSTOMER_H
#define GENIESTORE_CUSTOMER_H


class Customer {
private:
    string id = "";
    string name = "";
    string address = "";
    string phone = "";
    string tier = Customer::TIER[0];
    int point = 0;
    LinkedList<Item> rentals;
public:
    explicit Customer() {};
    explicit Customer(string raw_data);
    explicit Customer(string id, string name, string address, string phone, string tier);
    string get_id();
    string get_name();
    string get_address();
    string get_phone();
    string get_tier();
    LinkedList<Item> get_rentals();
    int get_point();
    void set_name(string name);
    void set_address(string address);
    void set_phone(string phone);
    void set_tier(string tier);
    void add_rental(Item item);
    void rent_item(Item item);
    void return_item(string item_id);
    void promote();
    string to_string();
    bool is_guest();
    bool is_regular();
    bool is_vip();
    static const string TIER[];
};


#endif //GENIESTORE_CUSTOMER_H
