#include <iostream>

struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    
    while (current != nullptr) {
        next = current->next;   // Store next node
        current->next = prev;   // Reverse current node's pointer
        prev = current;         // Move pointers one position ahead
        current = next;
    }
    
    return prev;   // 'prev' is now the new head
}

int main() {
    // Example usage
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    
    std::cout << "Original list: ";
    printList(head);
    
    head = reverseList(head);
    
    std::cout << "Reversed list: ";
    printList(head);
    
    return 0;
}
