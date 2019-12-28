//
// Created by longb on 12/26/19.
//

#include <iostream>
#include "Helper.h"
#include "CustomerManager.h"

void CustomerManager::test() {
    this->customer_list.load();
    this->rent_an_item();
    this->display_all_customers();
}

void CustomerManager::add_customer() {
    cout << "Please provide information for new customer:" << endl;
    cout << "Customer id: ";
    string id = Helper::read_user_string();
    cout << "Customer name: ";
    string name = Helper::read_user_string();
    cout << "Customer address: ";
    string address = Helper::read_user_string();
    cout << "Customer phone: ";
    string phone = Helper::read_user_string();
    cout << "Customer tier: " << endl;
    int tier = Helper::prompt_user_option(Customer::TIER);
    // TODO: validate ID format
    Customer new_customer(id, name, address, phone, Customer::TIER[tier]);
    try {
        this->customer_list.add(new_customer);
    } catch (const char* error) {
        cout << error << endl;
        return;
    }
}

void CustomerManager::update_customer() {
    const string UPDATE_OPTIONS[] = {"name", "address", "phone", "tier", "confirm update", "."};
    cout << "Enter ID of the customer you want to update: ";
    string update_customer_id = Helper::read_user_string();
    Customer customer;
    try {
        customer = this->customer_list.get(update_customer_id);
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
                cout << "Customer name (old: '" << customer.get_name() << "'): ";
                string name = Helper::read_user_string();
                customer.set_name(name);
                break;
            }
            case 1: {
                cout << "Customer address (old: '" << customer.get_address() << "'): ";
                string address = Helper::read_user_string();
                customer.set_address(address);
                break;
            }
            case 2: {
                cout << "Customer phone (old: '" << customer.get_phone() << "'): ";
                string phone = Helper::read_user_string();
                customer.set_phone(phone);
                break;
            }
            case 3: {
                cout << "Customer tier (old: '" << customer.get_tier() << "'): " << endl;
                int tier = Helper::prompt_user_option(Customer::TIER);
                customer.set_tier(Customer::TIER[tier]);
                break;
            }
            case 4: {
                confirmed_update = true;
                break;
            }
            default: break;
        }
    }
    try {
        this->customer_list.update(update_customer_id, customer);
    } catch (const char* error) {
        cout << error << endl;
    }
}

void CustomerManager::promote_a_customer() {
    cout << "Enter ID of the customer you want to promote: ";
    string customer_id = Helper::read_user_string();
    Customer customer;
    try {
        customer = this->customer_list.get(customer_id);
        customer.promote();
        this->customer_list.update(customer.get_id(), customer);
    } catch (const char* error) {
        cout << error << endl;
        return;
    }
}

void CustomerManager::rent_an_item() {
    Item item;
    Customer customer;
    cout << "Enter ID of the item customer want to rent an item: ";
    string item_id = Helper::read_user_string();
    try {
        item = this->stock->get(item_id);
    } catch (const char* error) {
        cout << error << endl;
        return;
    }
    cout << "Enter ID of the customer who want to rent '" << item.get_title() << "': ";
    string customer_id = Helper::read_user_string();
    try {
        customer = this->customer_list.get(customer_id);
    } catch (const char* error) {
        cout << error << endl;
        return;
    }
    if (customer.get_rentals().exist(item_id)) {
        // if the customer already renting this item
        cout << "The customer already renting this item." << endl;
        return;
    }
    item.destock(1);
    customer.add_rental(item);
    this->customer_list.update(customer_id, customer);
    this->stock->update(item_id, item);
}

void CustomerManager::return_an_item() {
    Customer customer;
    Item item;
    cout << "Enter the ID of the customer who want to return an item: ";
    string customer_id = Helper::read_user_string();
    try {
        customer = this->customer_list.get(customer_id);
    } catch (const char* error) {
        cout << error << endl;
        return;
    }
    if (customer.get_rentals().size() == 0) {
        // this customer isn't holding any item
        cout << "This customer isn't holding any item." << endl;
        return;
    }
    this->display_all_items_of_a_customer(customer);
    cout << "Enter ID of the item customer want to return: ";
    string item_id = Helper::read_user_string();
    if (!customer.get_rentals().exist(item_id)) {
        cout << "Customer isn't renting this item." << endl;
        return;
    }
    try {
        item = this->stock->get(item_id);
    } catch (const char* error) {
        cout << "This item might be deleted from stock." << endl;
        // removing the item from the customer rental list anyway
        customer.get_rentals().remove(item_id);
        this->customer_list.update(customer.get_id(), customer);
        return;
    }
    item.restock(1);
    customer.get_rentals().remove(item_id);
    this->stock->update(item_id, item);
    this->customer_list.update(customer.get_id(), customer);
}

void CustomerManager::display_all_items_of_a_customer(Customer customer) {
    cout << "Items that '" << customer.get_name() << "' is renting: " << endl;
    for (int i = 0; i < customer.get_rentals().size(); i++) {
        Item item = customer.get_rentals().get(i);
        cout << item.get_id() << endl;
    }
}

void CustomerManager::display_all_customers() {
    cout << "Here are all the customers in the database: " << endl;
    LinkedList<Customer> all_customers = this->customer_list.get_all();
    for (int i = 0; i < all_customers.size(); i++) {
        Customer customer = all_customers.get(i);
        cout << customer.to_string() << endl;
    }
}

void CustomerManager::display_a_group_of_customers() {
    cout << "Customer tier you want to display: " << endl;
    int tier = Helper::prompt_user_option(Customer::TIER);
    LinkedList<Customer> all_customers = this->customer_list.get_all();
    for (int i = 0; i < all_customers.size(); i++) {
        Customer customer = all_customers.get(i);
        if (strcmp(customer.get_tier().c_str(), Customer::TIER[tier].c_str()) == 0) {
            cout << customer.to_string() << endl;
        }
    }
}

void CustomerManager::search_for_customers() {
    // TODO: add sorting
    cout << "Enter the keyword of the customer you want to search: ";
    string keyword = Helper::read_user_string();
    LinkedList<Customer> all_customers = this->customer_list.get_all();
    for (int i = 0; i < all_customers.size(); i++) {
        Customer customer = all_customers.get(i);
        if (customer.to_string().find(keyword) != string::npos) {
            cout << customer.to_string() << endl;
        }
    }
}

void CustomerManager::inject_item_stock(ItemStock* stock) {
    this->stock = stock;
}

void CustomerManager::set_db_file(string db_file) {
    this->customer_list.set_data_file_name(db_file);
}

void CustomerManager::load_customers() {
    try {
        this->customer_list.load();
    } catch (const char* error) {
        cout << error << endl;
    }
}

void CustomerManager::save_customers() {
    try {
        this->customer_list.save();
    } catch (const char* error) {
        cout << error << endl;
    }
}