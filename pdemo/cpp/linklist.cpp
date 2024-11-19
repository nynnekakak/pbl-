
#include "libary/linklist.h"
#include <iostream>

using namespace std;

template<typename T>
LinkedList<T>::LinkedList() {
    root = nullptr;
    n = nullptr;
    current = nullptr;
    size_ll = 0;
}

template<typename T>
typename LinkedList<T>::node* LinkedList<T>::createnode(T data) {
    n = new node(data);
//    n->data = data;
//    n->next = nullptr;
    return n;
}

template<typename T>
void LinkedList<T>::add(T data) {
    if (root == nullptr) {
        root = createnode(data);
        current = root;
        size_ll++;
    } else {
        current->next = createnode(data);
        current = current->next;
        size_ll++;
    }
}

template<typename T>
T& LinkedList<T>::operator[](int location) {
	if(location>size_ll){
		cout<<"Khong ton tai\n";
		exit(1);
	}
    int counter = 0;
    node* s = nullptr;
    s = root;
    T* returnval;

    while (s != nullptr) {
        counter++;
        if (counter  == location) {
            returnval = &s->data;
        }
        s = s->next;
    }

    return *returnval;
}

template<typename T>
void LinkedList<T>::del(int location) {
    int counter = 0;
    node* d = nullptr;
    node* d_next = nullptr;
    d = root;

    if (location == 0) {
        root = root->next;
        delete d;
    }
    

    while (d != nullptr) {
        counter++;
        if (counter == location) {
            d_next = d->next;
            d->next=d_next->next;
            delete d_next;
        }
        d = d->next;
    }
    size_ll--;	
}

template<typename T>
int LinkedList<T>::size() {
    return size_ll;
}

