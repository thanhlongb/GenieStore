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
private:
    string id = "";
    string title = "";
    string loan_type = LOAN_TYPE[0];
    string item_type = ITEM_TYPE[0];
    int copies = 0;
    float rental_fee = 0;
    string rental_status = RENTAL_STATUS[0];
    string genre = GENRE[0];
    bool is_valid_id(string id);
public:
    explicit Item() {};
    explicit Item(string raw_data);
    explicit Item(string id, string title, string loan_type, string item_type,
                  int copies, float rental_fee, string genre);
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
    void set_title(string title);
    void set_loan_type(string loan_type);
    void set_item_type(string item_type);
    void set_copies(int copies);
    void set_rental_fee(float rental_fee);
    void set_genre(string genre);
    string to_string();
    bool is_game();
    bool is_2_day_loan();
    static const string LOAN_TYPE[];
    static const string ITEM_TYPE[];
    static const string RENTAL_STATUS[];
    static const string GENRE[];
};



#endif //GENIESTORE_ITEM_H
