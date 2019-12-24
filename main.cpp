#include <iostream>
#include "ItemManager.h"
#include "ItemStock.h"
#include "Item.h"
#include "Helper.h"
using namespace std;

int main() {
    cout << "Hello, World!" << endl;
//    const string loan_type[] = {"", "world", "my", "name"};
//    cout << sizeof(Item::GENRE) / sizeof(loan_type[0]);
    ItemManager manager;
    manager.add_item();
    manager.add_item();
    manager.display_all_items();
//    string a = "";
//    a.append("frick");
//    cout << a;
//    ItemStock stock;
//    Item a;
//    try {
//        a = stock.get(19);
//    } catch (int error_code) {
//        cout << error_code;
//    }
//
//    cout << a.get_id();
//    char* options[2] = {"hello", "world"};
//    int a = Helper::prompt_user_option(options);
//    cout << "option -> " << a << endl;
//    Item item("I1234", "Table", "One", "dvd", 12, 123.3, "OK", "action");
//    Item item2("I1234", "Dick", "One", "dvd", 12, 123.3, "OK");
//    ItemStock stock;
//    stock.add(item);
//    Item it = stock.get(item.get_id());
//    cout << it.to_string();
//    cout << stock.get(0).get_title() << endl;
//    stock.update(item2.get_id(), item2);
//    cout << stock.get(0).get_title() << endl;
//    cout << "size = " << stock.size() << endl;
//    stock->remove("I1234");
//    cout << "size = " << stock->size() << endl;
//    for (int i = 0; i < stock.size(); ++i) {
//        Item current_item = stock.get(i);
//        cout << current_item.get_id() << endl;
//    }
    return 0;
}

