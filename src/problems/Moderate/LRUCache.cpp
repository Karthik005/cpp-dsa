#include <unordered_map>
#include <utility>
#include <string>
#include <stdexcept>
#include <iostream>

using namespace std;

struct node {
    int key; 
    string value;
    node* prev;
    node* next;
};

void delete_node(node* del_node) {
    if (del_node->prev != nullptr) {
        del_node ->prev->next = del_node->next;
    }
    if (del_node->next != nullptr) {
        del_node->next->prev = del_node->prev;
    }
    delete del_node;
}

void delete_list(node* start_node) {
    while(start_node != nullptr) {
        node* temp_node = start_node;
        start_node = start_node->next;
        delete temp_node;
    }
}

class LRUCache {
    private:
    unordered_map<int, node*> key_map;
    node * start;
    node * end;
    int max_size;

    public:
    LRUCache(int max_size_) : start(nullptr), end(nullptr), max_size(max_size_) {}

    void insert(int key, string value) {
        if (max_size > key_map.size()) {
            key_map[key] = new node{key, value, end, nullptr};
            if (start == nullptr){
                start = key_map[key];
            } else {
                end->next = key_map[key];
            }
            end = key_map[key];
        } else {
            node * temp_node = start;
            start = start->next;
            key_map.erase(temp_node->key);
            delete_node(temp_node);
            insert(key, value);
        }
    }

    string retrieve(int key) {
        if (key_map.find(key) == key_map.end()) {
            throw out_of_range("No such key");
        }
        string value = key_map[key]->value;
        if (end != key_map[key]) {
            if (start == key_map[key]) start = start->next;
            delete_node(key_map[key]);
            key_map[key] = new node{key, value, end, nullptr};
            end->next = key_map[key];
            end = key_map[key];
        }
        return value;
    }
    void print_all() const {
        node * iter = start;
        while(iter != nullptr) {
            cout <<iter->key <<"," << iter->value << endl;
            iter = iter->next;
        }
    }
};

int main() {
    LRUCache cache(3);
    cache.insert(10,"apple");
    cache.insert(11,"apple");
    cache.insert(12,"apple");
    cache.insert(13,"apple");
    cache.retrieve(13);
    cache.print_all();
}
