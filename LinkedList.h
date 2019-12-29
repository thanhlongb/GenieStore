#include <string>
#include <iostream>
#include "node.h"

using namespace std;

#ifndef GENIESTORE_LINKEDLIST_H
#define GENIESTORE_LINKEDLIST_H


template <class T> class LinkedList {
private:
    node<T> * head;
    node<T> * get_node(int index) {
        int current_index = 0;
        node<T>* current_node = this->head;
        while (current_node != nullptr && current_index != index) {
            current_node = current_node->get_next();
            current_index++;
        }
        return current_node;
    }
public:
    LinkedList() {
        this->head = nullptr;
    }
    ~LinkedList() {
        // TODO: implement ~LinkedList
    }
    void add(T data) {
        // TODO: check if item id is duplicated
        if (exist(data.get_id())) {
            throw "Duplicate id.";
        }
        node<T> * new_node = new node<T>(data);
        if (this->head == nullptr) {
            this->head = new_node;
        } else {
            new_node->set_next(this->head);
            this->head = new_node;
        }
    }
    void remove(string id) {
        node<T>* current_node = this->head;
        if (current_node->get_data().get_id() == id) {
            this->detach_head();
        } else {
            while ((current_node->get_next()->get_data().get_id() != id) && (current_node->get_next()->get_next() != nullptr)) {
                current_node = current_node->get_next();
            }
            if (current_node->get_next()->get_data().get_id() == id) {
                if (current_node->get_next()->get_next() != nullptr) {
                    this->detach_tail();
                } else {
                    node<T>* tmp_node = current_node->get_next();
                    current_node->set_next(tmp_node->get_next());
                    delete tmp_node;
                }
            }
        }
    }
    void update(string id, T data) {
        node<T>* current_node = this->head;
        while (current_node != nullptr && current_node->get_data().get_id() != id) {
            current_node = current_node->get_next();
        }
        if (current_node != nullptr) {
            current_node->set_data(data);
        }
    }
    void detach_head() {
        node<T>* new_head = this->head->get_next();
        delete this->head;
        this->head = new_head;
    }
    void detach_tail() {
        node<T>* current_node = this->head;
        node<T>* previous_node = nullptr;
        if (current_node != nullptr) {
            while (current_node->get_next() != nullptr) {
                previous_node = current_node;
                current_node = current_node->get_next();
            }
            delete current_node;
            previous_node->set_next(nullptr);
        }
    }
    void swap(int first_node_index, int second_node_index) {
        node<T>* first_node = this->get_node(first_node_index);
        node<T>* second_node = this->get_node(first_node_index);
        cout << first_node->get_data().get_title() << " and " << second_node->get_data().get_title() << endl;
        T temp = first_node->get_data();
        first_node->set_data(second_node->get_data());
        second_node->set_data(temp);
        cout << first_node_index << " swapped with " << second_node_index << endl;
        cout << first_node->get_data().get_title() << " and " << second_node->get_data().get_title() << endl;
    }
    int size() {
        int size = 0;
        node<T>* current_node = this->head;
        while (current_node != nullptr) {
            size++;
            current_node = current_node->get_next();
        }
        return size;
    }
    T get(string id) {
        node<T>* current_node = this->head;
        while (current_node != nullptr && strcmp(current_node->get_data().get_id().c_str(), id.c_str()) != 0) {
            current_node = current_node->get_next();
        }
        if (current_node == nullptr) {
            throw 404;
        }
        return current_node->get_data();
    }
    bool exist(string id) {
        T data;
        try {
            this->get(id);
            return true;
        } catch (const int error_code) {
            return false;
        }
    }
    T get(int index) {
        return this->get_node(index)->get_data();
    }
};


#endif //GENIESTORE_LINKEDLIST_H
