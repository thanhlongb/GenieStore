#include <iostream>
#include "Helper.h"

int Helper::prompt_user_option(const string options[]) {
    int user_option = 0;
    int options_size = Helper::get_size(options);
    print_options(options, options_size);
    do {
        cout << "Your option: ";
        user_option = read_user_int();
        if (user_option <= 0 || user_option > options_size) {
            cout << "Invalid option, try again!" << endl;
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

int Helper::find_char_occurrence(string input_string, char c) {
    int count = 0;
    for (int i = 0; i < input_string.length(); i++) {
        if (input_string.at(i) == c) count++;
    }
    return count;
}

void Helper::sort(LinkedList<Item>* list, bool ascending_order) {
    Helper::quicksort(list, 0, list->size() - 1);
}

int Helper::partition(LinkedList<Item>* list, int low, int high) {
    string pivot = list->get(high).get_title(); // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (strcmp(list->get(j).get_title().c_str(), pivot.c_str()) < 0) {
            i++; // increment index of smaller element
            list->swap(i, j);
        }
    }
    list->swap(i + 1, high);
    return (i + 1);
}

void Helper::quicksort(LinkedList<Item>* list, int low, int high) {
    if (low < high) {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = Helper::partition(list, low, high);

        // Separately sort elements before
        // partition and after partition
        Helper::quicksort(list, low, pi - 1);
        Helper::quicksort(list, pi + 1, high);
    }
}