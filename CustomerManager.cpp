//
// Created by longb on 12/26/19.
//

#include <iostream>
#include "Helper.h"
#include "CustomerManager.h"

void CustomerManager::test() {
    this->customer_list.load();
    this->display_all_customers();
    this->display_a_group_of_customers();
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
    this->customer_list.add(new_customer);
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
    } catch (const char* error) {
        cout << error << endl;
        return;
    }
}

void CustomerManager::display_all_customers() {
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