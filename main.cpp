#include <iostream>
#include "node.h"

using namespace std;

// traverse a linked list
// const: promise that we don't change the Node and we protect what is at the memory address
// const Node* head: Node itself is constant, not allowed to change the Node
// Node* const head: can't change the memory address, but can change what is at the address
// const Node* const head: do both -- Node AND memory address is constant
void printReadings(const Node* head) {
    for (const Node* current = head; current != nullptr; current = current->next) {
        cout << current->value << " -> ";
    }
    cout << "nullptr\n";
}

// void printReadings(const Node* current) {
//     for (; current != nullptr; current = current->next) {
//         cout << current->value << " -> ";
//     }
//     cout << "nullptr\n";
// }

int totalReadings(const Node* head) {
    int total = 0;
    for (const Node* current = head; current != nullptr; current = current->next) {
        total += current->value;
    }
    return total;
}

// does the same thing as we've been doing but more automated since it's a function
Node* addReading(Node* head, int value) {
    Node* node = new Node;
    node->value = value;
    node->next = head;
    // head = node;        // changes only this function's copy of head
    return node; // return memory address of the new start of the list
}

void deleteReadings(Node* head) {
    while (head != nullptr) {
        Node* following = head->next;   // save the next address first
        delete head;
        head = following;
    }
}

int main() {
    // Node firstItemInList(5, nullptr); // create with nullptr since it's the first Node
    // int array[1] = {5}; // equivalent to this
    
    Node* head = addReading(nullptr, 8);
    head = addReading(head, 2);
    head = addReading(head, 9);
    head = addReading(head, 5);
    head = addReading(head, 0);

    // Node* fourth = new Node; // create on heap; the tail
    // fourth->value = 8; // equivalent to *(third).value = 2;
    // fourth->next = nullptr; // nothing after

    // // {2}
    // Node* third = new Node; // create on heap; the tail
    // third->value = 2; // equivalent to *(third).value = 2;
    // third->next = fourth; // nothing after

    // // {9, 2}
    // Node* second = new Node;
    // second->value = 9;
    // second->next = third;

    // // {5, 9, 2}
    // Node* first = new Node; // the head
    // first->value = 5;
    // first->next = second;

    // Node* head = first;

    // addReadingBroken(head, 0); // main's copy of head will be exactly the same value, not updated by function
    // head = addReading(head, 0);

    cout << "The total value held in the linked list is " << totalReadings(head) << endl;
    printReadings(head);

    // cout << head->value << endl;
    // cout << head->next->value << endl;
    // cout << head->next->next->value << endl;

    // delete first;
    // delete second;
    // delete third;
    // delete head; // only the first node is deleted; it's a problem because you've allocated memory 5 times but only delete one; we need to deallocate everything -> deleteReading
    deleteReadings(head); // uses the head as a starting point
    head = nullptr;
    // first = nullptr;
    // second = nullptr;
    // third = nullptr;

    return 0;
}