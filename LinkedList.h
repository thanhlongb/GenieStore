//
// Created by longb on 12/19/19.
//
#include <string>
#include "node.h"

using namespace std;

#ifndef GENIESTORE_LINKEDLIST_H
#define GENIESTORE_LINKEDLIST_H


template <class T> class LinkedList {
private:
    node<T> * head;
public:
    LinkedList() {
        this->head = NULL;
    }
    ~LinkedList() {
        // TODO: implement ~LinkedList
    }
    void add(T data) {
        node<T> * new_node = new node<T>(data);
        if (this->head == NULL) {
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
            while ((current_node->get_next()->get_data().get_id() != id) && (current_node->get_next()->get_next() != NULL)) {
                current_node = current_node->get_next();
            }
            if (current_node->get_next()->get_data().get_id() == id) {
                if (current_node->get_next()->get_next() != NULL) {
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
        while (current_node != NULL && current_node->get_data().get_id() != id) {
            current_node = current_node->get_next();
        }
        if (current_node != NULL) {
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
        node<T>* previous_node = NULL;
        if (current_node != NULL) {
            while (current_node->get_next() != NULL) {
                previous_node = current_node;
                current_node = current_node->get_next();
            }
            delete current_node;
            previous_node->set_next(NULL);
        }
    }
    int size() {
        int size = 0;
        node<T>* current_node = this->head;
        while (current_node != NULL) {
            size++;
            current_node = current_node->get_next();
        }
        return size;
    }
    T get(string id) {
        node<T>* current_node = this->head;
        while (current_node != NULL && strcmp(current_node->get_data().get_id().c_str(), id.c_str()) != 0) {
            current_node = current_node->get_next();
        }
        if (current_node == NULL) {
            throw 404;
        }
        return current_node->get_data();
    }
    T get(int index) {
        int current_index = 0;
        node<T>* current_node = this->head;
        while (current_node != NULL && current_index != index) {
            current_node = current_node->get_next();
            current_index++;
        }
        return current_node->get_data();
    }
};


#endif //GENIESTORE_LINKEDLIST_H
