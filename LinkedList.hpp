#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "Student.hpp"
#include <iostream>
using namespace std;

class LinkedList {
private:
    struct Node {
        Student data;
        Node* next;
        Node(const Student& data) : data(data), next(nullptr) {}
    };
    Node* head;
    int length;
public:
    LinkedList() : head(nullptr), length(0) {}
    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void append(const Student& data) {
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

    int remove(int id) {        // position where it was removed
        if (head == nullptr) {
            return -1;
        }
        
        // Special case: removing head
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

    int getLength() {
        return length;
    }

    void addCourse(int id, Course course) {
        Node* curr = head;
        while (curr != nullptr) {
            if (curr->data.getId() == id) {
                curr->data.addCourse(course);
                return;
            }
            curr = curr->next;
        }
        cout << "Student not found." << endl;
    }
};

#endif
