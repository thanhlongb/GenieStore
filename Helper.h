//
// Created by longb on 12/22/19.
//
#include <string>

using namespace std;

#ifndef GENIESTORE_HELPER_H
#define GENIESTORE_HELPER_H


class Helper {
public:
    static int prompt_user_option(char* options[]);
    static string read_user_input();
};


#endif //GENIESTORE_HELPER_H
