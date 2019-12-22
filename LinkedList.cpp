////
//// Created by longb on 12/19/19.
////
//
//#include "LinkedList.h"
//
//LinkedList::LinkedList() {
//    this->head = NULL;
//}
//
//LinkedList::~LinkedList() {
//    // do this later
//}
//
//void LinkedList::add(T data) {
//    node* new_node = new node(data);
//    if (this->head = NULL) {
//        this->head = new_node;
//    } else {
//        new_node->set_next(this->head);
//        this->head = new_node;
//    }
//}
//
//void LinkedList::detach_head() {
//    node* new_head = this->head->get_next();
//    delete this->head;
//    this->head = new_head;
//}
//
//void LinkedList::detach_tail() {
//    node* current_node = this->head;
//    node* previous_node = NULL;
//    if (current_node != NULL) {
//        while (current_node->get_next() != NULL) {
//            previous_node = current_node;
//            current_node = current_node->get_next();
//        }
//        delete current_node;
//        previous_node->set_next(NULL);
//    }
//}
//
//void LinkedList::remove(string id) {
//    node* current_node = this->head;
//    if (current_node->get_data()->get_id() == id) {
//        this->detach_head();
//    } else {
//        while ((current_node->get_next()->get_data()->get_id() != id) && (current_node->get_next()->get_next() != NULL)) {
//            current_node = current_node->get_next();
//        }
//        if (current_node->get_next()->get_data()->get_id() == id) {
//            if (current_node->get_next()->get_next() != NULL) {
//                this->detach_tail();
//            } else {
//                node* tmp_node = current_node->get_next();
//                current_node->set_next(tmp_node->get_next());
//                delete tmp_node;
//            }
//        }
//    }
//}
//
//int LinkedList::size() {
//    int size = 0;
//    node* current_node = this->head;
//    while (current_node != NULL) {
//        size++;
//        current_node = current_node->get_next();
//    }
//    return size;
//}
//
//T* LinkedList::get(string id) {
//    node* current_node = this->head;
//    while (current_node != NULL && current_node->get_data()->get_id() != id) {
//        current_node = current_node->get_next();
//    }
//    return current_node->get_data();
//}