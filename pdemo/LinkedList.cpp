#include "libary/LinkedList.h"

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr) {}

template <typename T>
LinkedList<T>::~LinkedList() {
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}
template <typename T>
void LinkedList<T>::add(const T& data) {
    Node<T>* newNode = new Node<T>(data);
    newNode->next = head;
    head = newNode;
}

template <typename T>
void LinkedList<T>::clear() {
    while (head) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}
template <typename T>
bool LinkedList<T>::remove(bool (*compareFunc)(const T&, const string&), const string& key) {
    Node<T>* current = head;
    Node<T>* prev = nullptr;

    while (current) {
        if (compareFunc(current->data, key)) {
            if (prev) {
                prev->next = current->next;
            } else {
                head = current->next;
            }
            delete current;
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}

template <typename T>
void LinkedList<T>::display(void (*displayFunc)(const T&)) const {
    Node<T>* current = head;
    while (current) {
        displayFunc(current->data);
        current = current->next;
    }
}

template <typename T>
Node<T>* LinkedList<T>::find(bool (*compareFunc)(const T&, const string&), const string& key) const {
    Node<T>* current = head;
    while (current) {
        if (compareFunc(current->data, key)) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

template <typename T>
void LinkedList<T>::saveToFile(const string& filename, void (*saveFunc)(ofstream&, const T&)) const {
    ofstream file(filename, ios::trunc);
    if (file.is_open()) {
        Node<T>* current = head;
        while (current) {
            saveFunc(file, current->data);
            current = current->next;
        }
        file.close();
    } else {
        cout << "Khong the mo file " << filename << " de luu.\n";
    }
}

template <typename T>
void LinkedList<T>::loadFromFile(const string& filename, T (*loadFunc)(ifstream&)) {
    ifstream file(filename);
    if (file.is_open()) {
        while (!file.eof()) {
            T data = loadFunc(file);
            if (file.fail() || file.eof()) {
                break;
            }
            add(data);
        }
        file.close();
    } else {
        cout << "Khong the mo file " << filename << " de doc.\n";
    }
}
