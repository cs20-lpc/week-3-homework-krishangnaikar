#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
using namespace std;

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& data) : data(data), next(nullptr) {}
    };
    Node* head;
    int length;

    void copyFrom(const LinkedList& other) {
        head = nullptr;
        length = 0;
        Node* curr = other.head;
        while (curr != nullptr) {
            append(curr->data);
            curr = curr->next;
        }
    }

    void clearNodes() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        length = 0;
    }

public:
    LinkedList() : head(nullptr), length(0) {}
    LinkedList(const LinkedList& other) : head(nullptr), length(0) {
        copyFrom(other);
    }
    ~LinkedList() {
        clearNodes();
    }
    void append(const T& data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            length = 1;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        length++;
    }

    int remove(int id) {
        if (head == nullptr) {
            return -1;
        }
        
        if (head->data.getId() == id) {
            Node* temp = head;
            head = head->next;
            delete temp;
            length--;
            return 0;
        }
        
        int pos = 1;
        Node* prev = head;
        Node* curr = head->next;
        while (curr != nullptr) {
            if (curr->data.getId() == id) {
                prev->next = curr->next;
                delete curr;
                length--;
                return pos;
            }
            pos++;
            prev = curr;
            curr = curr->next;
        }
        return -1;
    }

    void search(int id) {
        Node* curr = head;
        while (curr != nullptr) {
            if (curr->data.getId() == id) {
                cout << curr->data << endl;
                return;
            }
             curr = curr->next;
        }
        cout << "Student not found." << endl;
    }

    void display() {
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->data << endl;
            curr = curr->next;
        }
    }

    int getLength() const {
        return length;
    }


    const T& get(int pos) const {
        if (pos < 0 || pos >= length) {
            throw out_of_range("Position out of bounds.");
        }
        Node* curr = head;
        for (int i = 0; i < pos; i++) curr = curr->next;
        return curr->data;
    }

    T& getRef(int pos) {
        Node* curr = head;
        for (int i = 0; i < pos; i++) curr = curr->next;
        return curr->data;
    }

    const T& getRef(int pos) const {
        Node* curr = head;
        for (int i = 0; i < pos; i++) curr = curr->next;
        return curr->data;
    }

    

    LinkedList& operator=(const LinkedList& other) {
        if (this != &other) {
            clearNodes();
            copyFrom(other);
        }
        return *this;
    }



};

#endif
