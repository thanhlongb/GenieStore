//
// Created by longb on 12/19/19.
//
#include <string>
#include <cstring>

using namespace std;

#ifndef GENIESTORE_ITEM_H
#define GENIESTORE_ITEM_H


class Item
{
public:
    explicit Item() {};
    explicit Item(string id, string title, string loan_type, string item_type,
         int copies, float rental_fee, string rental_status, string genre);
    void restock(int quantity);
    void destock(int quantity);
    string get_id();
    string get_title();
    string get_loan_type();
    string get_item_type();
    int get_copies();
    float get_rental_fee();
    string get_rental_status();
    string get_genre();
    string to_string();
    static const string LOAN_TYPE[];
    static const string ITEM_TYPE[];
    static const string RENTAL_STATUS[];
    static const string GENRE[];
private:
    string id;
    string title;
    string loan_type;
    string item_type;
    int copies;
    float rental_fee;
    string rental_status;
    string genre;
};



#endif //GENIESTORE_ITEM_H
