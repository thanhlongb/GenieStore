//
// Created by longb on 12/26/19.
//

#include "CustomerList.h"
#ifndef GENIESTORE_CUSTOMERMANAGER_H
#define GENIESTORE_CUSTOMERMANAGER_H


class CustomerManager {
private:
    CustomerList customer_list;
public:
    void test();
    void add_customer();
    void update_customer();
    void promote_a_customer();
    void display_all_customers();
    void display_a_group_of_customers();
    void search_for_customers();
};


#endif //GENIESTORE_CUSTOMERMANAGER_H
