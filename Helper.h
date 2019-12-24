//
// Created by longb on 12/22/19.
//
#include <string>

using namespace std;

#ifndef GENIESTORE_HELPER_H
#define GENIESTORE_HELPER_H


class Helper {
public:
    static int prompt_user_option(const string options[]);
    static string read_user_string();
    static int read_user_int();
    static float read_user_float();
    static int get_size(const string options[]);
    static void print_options(const string options[], int count);
private:
};


#endif //GENIESTORE_HELPER_H
