//
// Created by longb on 12/22/19.
//
#include <iostream>
#include "Helper.h"

// TODO: allow user to cancel the input

int Helper::prompt_user_option(const string options[]) {
    int user_option = 0;
    // FIXME: fix the warning the following line is showing
    int options_size = Helper::get_size(options);
    print_options(options, options_size);
    do {
        cout << "Your option: ";
        user_option = read_user_int();
        if (user_option <= 0 || user_option > options_size) {
            cout << "invalid option, try again!" << endl;
        } else {
            break;
        }
    } while (true);
    return user_option;
}

void Helper::print_options(const string options[], int count) {
    for (int i = 0; i < count; i++) {
        cout << "[" << i + 1 << "] " << options[i] << endl;
    }
}

string Helper::read_user_string() {
    const int MAX_INPUT_LENGTH = 100;
    char user_string[MAX_INPUT_LENGTH] = {};
    cin.getline(user_string, MAX_INPUT_LENGTH); //Take in user input from console
    return string(user_string);
}

int Helper::read_user_int() {
    int user_int = -1;
    do {
        cin >> user_int;
        if (user_int < 0) {
            cout << "invalid int number, try again!" << endl;
            // FIXME: shit gone wild when user enter a string
        } else {
            break;
        }
    } while (true);
    return user_int;
}

float Helper::read_user_float() {
    float user_float = -1;
    do {
        cin >> user_float;
        if (user_float < 0) {
            cout << "invalid float number, try again!" << endl;
            // FIXME: shit gone wild when user enter a string
        } else {
            break;
        }
    } while (true);
    return user_float;
}

int Helper::get_size(const string options[]) {
    cout << options[0] << endl;
    cout << sizeof(options[1]) << "/" << sizeof(options[0]) << endl;
    return sizeof(options) / sizeof(options[0]);
}
