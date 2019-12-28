#include <iostream>
#include "ItemManager.h"
#include "CustomerManager.h"
#include "Helper.h"

using namespace std;

void setup();
void operate();
void print_exit_message();
void wait_for_reading();

ItemManager item_manager;
CustomerManager customer_manager;

int main(int argc, char *argv[]) {
    if (argc == 3) {
        item_manager.set_db_file(argv[1]);
        customer_manager.set_db_file(argv[2]);
    }
    setup();
    cout << "Welcome to Genie’s video store!" << endl;
    while (true) {
        operate();
        wait_for_reading();
    }
    return 0;
}

void setup() {
    item_manager.load_items();
    customer_manager.load_customers();
    customer_manager.inject_item_stock(item_manager.get_stock_pointer());
}

void operate() {
    string options[] = {
            "Add new item",
            "Update an item",
            "Delete an item",
            "Promote an existing customer",
            "Rent an item",
            "Return an item",
            "Display all items",
            "Display out of stock items",
            "Display all customers",
            "Display a group of customers",
            "Search for items",
            "Search for customers",
            "Exit",
            "."
    };
    cout << "Enter an option below:" << endl;
    int user_selection = Helper::prompt_user_option(options);
    switch (user_selection) {
        case 0: { item_manager.add_item(); break; }
        case 1: { item_manager.update_item(); break; }
        case 2: { item_manager.delete_item(); break; }
        case 3: { customer_manager.promote_a_customer(); break; }
        case 4: { customer_manager.rent_an_item(); break; }
        case 5: { customer_manager.return_an_item(); break; }
        case 6: { item_manager.display_all_items(); break; }
        case 7: { item_manager.display_out_of_stock_items(); break; }
        case 8: { customer_manager.display_all_customers(); break; }
        case 9: { customer_manager.display_a_group_of_customers(); break; }
        case 10: { item_manager.search_for_items(); break; }
        case 11: { customer_manager.search_for_customers(); break; }
        case 12: {
            item_manager.save_items();
            customer_manager.save_customers();
            print_exit_message();
            exit(0);
        }
        default: break;
    }
}

void print_exit_message() {
    const char* exitMessage =
            "ASSIGNMENT GROUP 1\n"
            "s3748575,s3748575@rmit.edu.vn,ThanhLong,Bui\n"
            "s3742774,s3742774@rmit.edu.vn,QuangTrung,Ngo\n"
            "s3757281,s3757281@rmit.edu.vn,MinhQuang,Tran\n";
    cout << exitMessage << endl;
}

void wait_for_reading() {
    cout << "PRESS ENTER TO CONTINUE" << endl;
    system("read"); // FIXME: change this thing to "pause" on Windows
}

