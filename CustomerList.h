//
// Created by longb on 12/26/19.
//

#ifndef GENIESTORE_CUSTOMERLIST_H
#define GENIESTORE_CUSTOMERLIST_H


#include "Customer.h"
#include "LinkedList.h"

class CustomerList {
private:
    LinkedList<Customer> customers;
    string data_file_name = "customers.txt";
public:
    CustomerList() {};
    void add(Customer customer);
    void update(string customer_id, Customer customer);
    Customer get(string customer_id);
    LinkedList<Customer> get_all();
    void set_data_file_name(string data_file_name);
    void load();
    void save();
};


#endif //GENIESTORE_CUSTOMERLIST_H
