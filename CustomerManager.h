//
// Created by longb on 12/26/19.
//

#include "CustomerList.h"
#include "ItemStock.h"
#ifndef GENIESTORE_CUSTOMERMANAGER_H
#define GENIESTORE_CUSTOMERMANAGER_H


class CustomerManager {
private:
    CustomerList customer_list;
    ItemStock* stock;
public:
    void test();
    void add_customer();
    void update_customer();
    void promote_a_customer();
    void rent_an_item();
    void return_an_item();
    void display_all_items_of_a_customer(Customer customer);
    void display_all_customers();
    void display_a_group_of_customers();
    void search_for_customers();
    void inject_item_stock(ItemStock* stock);
    void set_db_file(string db_file);
    void load_customers();
    void save_customers();
};


#endif //GENIESTORE_CUSTOMERMANAGER_H
