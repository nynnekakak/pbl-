#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include "Node.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList();
    ~LinkedList();

    Node<T>* begin() {
        return head; 
    }

    void add(const T& data);
    void clear();
    bool remove(bool (*compareFunc)(const T&, const string&), const string& key);
    void display(void (*displayFunc)(const T&)) const;
    Node<T>* find(bool (*compareFunc)(const T&, const string&), const string& key) const;
    void saveToFile(const string& filename, void (*saveFunc)(ofstream&, const T&)) const;
    void loadFromFile(const string& filename, T (*loadFunc)(ifstream&));
};


#endif
