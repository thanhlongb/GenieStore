#ifndef GENIESTORE_NODE_H
#define GENIESTORE_NODE_H


template <class T> class node {
private:
    T data;
    node* next;
public:
    node(T data) {
        this->data = data;
        this->next = nullptr;
    }
    ~node() {
        // TODO: implement ~node()
    }
    T get_data() {
        return this->data;
    }
    void set_data(T data) {
        this->data = data;
    }
    node* get_next() {
        return this->next;
    }
    void set_next(node* next) {
        this->next = next;
    }
};


#endif //GENIESTORE_NODE_H
