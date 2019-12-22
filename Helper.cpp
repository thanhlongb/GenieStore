//
// Created by longb on 12/22/19.
//
#include <iostream>
#include "Helper.h"

int Helper::prompt_user_option(char* options[]) {
    int user_option = 0;
    // FIXME: fix the warning the following line is showing
    int options_size = sizeof(options)/sizeof(options[0]);
    cout << "Choose on of these options: " << endl;
    for (int i = 0; i <= options_size; i++) {
        cout << "[" << i + 1 << "] " << options[i] << endl;
    }
    do {
        cout << ">> Enter your option: ";
        cin >> user_option;
        if (user_option <= 0 || user_option > options_size) {
            cout << "You entered invalid input, try again!" << endl;
            // FIXME: shit gone wild when user enter an non-integer
        } else {
            break;
        }
    } while (true);
    return --user_option;
}

string Helper::read_user_input() {
    const int MAX_INPUT_LENGTH = 100;
    char user_input[MAX_INPUT_LENGTH] = {};
    cin.getline(user_input, MAX_INPUT_LENGTH); //Take in user input from console
    return string(user_input);
}