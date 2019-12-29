#include <fstream>
#include <iostream>
#include "CustomerList.h"

void CustomerList::add(Customer customer) {
    try {
        this->customers.add(customer);
    } catch (const char* error) {
        throw error;
    }
}

void CustomerList::update(string customer_id, Customer customer) {
    this->customers.update(customer_id, customer);
}

Customer CustomerList::get(string customer_id) {
    Customer customer;
    try {
        customer = this->customers.get(customer_id);
    } catch (int error_code) {
        if (error_code == 404) {
            throw "Customer doesn't exist.";
        }
    }
    return customer;
}

LinkedList<Customer> CustomerList::get_all() {
    return this->customers;
}

void CustomerList::set_data_file_name(string data_file_name) {
    this->data_file_name = data_file_name;
}

void CustomerList::load() {
    string line;
    ifstream file(this->data_file_name);
    if (file.is_open()) {
        Customer customer;
        while (getline(file, line)) {
            if (line[0] == 'C') { // this line contains customer information
                try {
                    customer = Customer(line);
                    this->customers.add(customer);
                } catch (const char* error) {
                    throw error;
                }
            } else if (line[0] == 'I') { // this line contains item id
                try {
                    Item item(line);
                    customer.add_rental(item);
                    this->customers.update(customer.get_id(), customer);
                } catch (const char* error) {
                    throw error;
                }
            }
        }
    } else {
        // unable to open file
        throw "Unable to load customers from data file.";
    }
}

void CustomerList::save() {
    ofstream file(this->data_file_name);
    if (file.is_open()) {
        for (int i = this->customers.size() - 1; i >= 0; i--) {
            Customer customer = this->customers.get(i);
            file << customer.to_string() << endl;
            for (int o = customer.get_rentals().size() - 1; o >= 0; o--) {
                Item item = customer.get_rentals().get(o);
                file << item.get_id() << endl;
            }
        }
        file.close();
    } else {
        // unable to open file
        throw "Unable to save customers to data file.";
    }
}