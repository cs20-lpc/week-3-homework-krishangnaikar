// #include "Student.hpp"
// #include <iostream>
// using namespace std;
// template <typename T>
// class LinkedList {
// private:
//     struct Node {
//         T data;
//         Node* next;
//         Node(const T& data) : data(data), next(nullptr) {}
//     };
//     Node* head;
//     int length;
// public:
//     LinkedList() : head(nullptr), length(0) {}
//     ~LinkedList() {
//         while (head != nullptr) {
//             Node* temp = head;
//             head = head->next;
//             delete temp;
//         }
//     }
//     void append(const T& data) {
//         Node* newNode = new Node(data);
//         if (head == nullptr) {
//             head = newNode;
//             return;
//         }
//         Node* temp = head;
//         while (temp->next != nullptr) {
//             temp = temp->next;
//         }
//         temp->next = newNode;
//         length++;
//     }

//     int remove(int id) {        // position where it was removed
//         if (head == nullptr) {
//             return -1;
//         }
//         int pos = 0;
//         Node* temp = head->next;
//         Node* curr = head;
//         while (curr != nullptr) {
//             if (curr->data.getId() == id) {
//                 curr->next = temp->next;
//                 delete temp;
//                 length--;
//                 return pos+1;
//             }
//             pos++;
//             curr = curr->next;
//         }
//         return -1;
//     }



//     void search(int id) {
//         Node* curr = head;
//         while (curr != nullptr) {
//             if (curr->data.getId() == id) {
//                 cout << curr->data << endl;
//                 return;
//             }
//              curr = curr->next;
//         }
//         cout << "Student not found." << endl;
//     }

//     void display() {
//         Node* curr = head;
//         while (curr != nullptr) {
//             cout << curr->data << endl;
//             curr = curr->next;
//         }
//     }

//     int getLength() {
//         return length;
//     }

//     void addCourse(int id, Course course) {
//         Node* curr = head;
//         while (curr != nullptr) {
//             if (curr->data.getId() == id) {
//                 curr->data.addCourse(course);
//                 return;
//             }
//             curr = curr->next;
//         }
//         cout << "Student not found." << endl;
//     }
// };