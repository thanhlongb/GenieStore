//
// Created by longb on 12/22/19.
//
#include <iostream>
#include "Helper.h"

// TODO: allow user to cancel the input

int Helper::prompt_user_option(const string options[]) {
    int user_option = 0;
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
    return --user_option;
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
    if (user_string[0] == '\0') return Helper::read_user_string();
    return user_string;
}

int Helper::read_user_int() {
    int user_int = -1;
    if (cin >> user_int) {
        return user_int;
    }
    cin.clear();
    cin.ignore(100000, '\n');
    return Helper::read_user_int();
}

float Helper::read_user_float() {
    float user_float = -1;
    if (cin >> user_float) {
        return user_float;
    }
    cin.clear();
    cin.ignore(100000, '\n');
    return Helper::read_user_float();
}

string Helper::read_next_word(string text, int* current_index, string delimiter) {
    int next_index = text.find(delimiter, *current_index);
    string next_word = text.substr(*current_index, next_index - *current_index);
    *current_index = next_index + 1;
    return next_word;
}

int Helper::get_size(const string options[]) {
    int size = 0;
    while (strcmp(options[size].c_str(), ".") != 0) {
        size++;
    }
    return size;
}
