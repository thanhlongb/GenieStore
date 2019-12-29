#include <iostream>
#include "ItemManager.h"
#include "CustomerManager.h"
#include "Helper.h"

using namespace std;

void setup();
void show_main_interface();
void show_item_manage_interface();
void show_customer_manage_interface();
void print_exit_message();
void wait_for_reading();
void confirm_exit();
void finalize();

ItemManager item_manager;
CustomerManager customer_manager;
bool user_want_exit = false;

int main(int argc, char *argv[]) {
    if (argc == 3) {
        item_manager.set_db_file(argv[1]);
        customer_manager.set_db_file(argv[2]);
    }
    setup();
    cout << "Welcome to Genie’s video store!" << endl;
    while (!user_want_exit) {
        show_main_interface();
        wait_for_reading();
    }
    finalize();
    return 0;
}

void setup() {
    item_manager.load_items();
    customer_manager.load_customers();
    customer_manager.inject_item_stock(item_manager.get_stock_pointer());
}

void finalize() {
    item_manager.save_items();
    customer_manager.save_customers();
    print_exit_message();
    exit(0);
}

void show_main_interface() {
    string options[] = {
            "Manage items",
            "Manage customers",
            "Rent an item",
            "Return an item",
            "Search for items",
            "Display all items",
            "Display all out-of-stock items",
            "Display all customers",
            "Display a group of customers",
            "Search for customers",
            "Exit",
            "."
    };
    cout << "Enter an option below:" << endl;
    int user_selection = Helper::prompt_user_option(options);
    switch (user_selection) {
        case 0: { show_item_manage_interface(); break; }
        case 1: { show_customer_manage_interface(); break; }
        case 2: { customer_manager.rent_an_item(); break; }
        case 3: { customer_manager.return_an_item(); break; }
        case 4: { item_manager.search_for_items(); break; }
        case 5: { item_manager.display_all_items(); break; }
        case 6: { item_manager.display_out_of_stock_items(); break; }
        case 7: { customer_manager.display_all_customers(); break; }
        case 8: { customer_manager.display_a_group_of_customers(); break; }
        case 9: { customer_manager.search_for_customers(); break; }
        case 10: { confirm_exit(); break; }
        default: break;
    }
}

void show_item_manage_interface() {
    string options[] = {
            "Add new item",
            "Update an item",
            "Delete an item",
            "Restock an item",
            "."
    };
    cout << "Enter an option below:" << endl;
    int user_selection = Helper::prompt_user_option(options);
    switch (user_selection) {
        case 0: { item_manager.add_item(); break; }
        case 1: { item_manager.update_item(); break; }
        case 2: { item_manager.delete_item(); break; }
        case 3: { item_manager.restock_item(); break; }
        default: break;
    }
}

void show_customer_manage_interface() {
    string options[] = {
            "Add new customer",
            "Update information of a customer",
            "Promote an existing customer",
            "."
    };
    cout << "Enter an option below:" << endl;
    int user_selection = Helper::prompt_user_option(options);
    switch (user_selection) {
        case 0: { customer_manager.add_customer(); break; }
        case 1: { customer_manager.update_customer(); break; }
        case 2: { customer_manager.promote_a_customer(); break; }
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
    cout << "<< PRESS ENTER TO CONTINUE >>" << endl;
    system("read"); // FIXME: change this thing to "pause" on Windows
}

void confirm_exit() {
    cout << "Please enter \"Exit\" to confirm: ";
    string user_input = Helper::read_user_string();
    if (strcmp(user_input.c_str(), "Exit") == 0) {
        cout << "Exit confirmed, items and customers information will be saved." << endl;
        user_want_exit = true;
    } else {
        cout << "Exit not confirmed." << endl;
    }
}

