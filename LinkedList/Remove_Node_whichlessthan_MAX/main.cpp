#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to reverse a linked list
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr != nullptr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

ListNode* removeNodes(ListNode* head) {
    // Step 1: Reverse the list
    head = reverseList(head);
    
    // Step 2: Traverse the reversed list and remove nodes
    ListNode* curr = head;
    ListNode* maxNode = head; // Maximum node seen so far
    while (curr != nullptr && curr->next != nullptr) {
        if (curr->next->val < maxNode->val) {
            // Remove curr->next
            ListNode* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        } else {
            curr = curr->next;
            maxNode = curr;
        }
    }
    
    // Step 3: Reverse the list back to restore the original order
    return reverseList(head);
}

// Function to print the linked list
void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr != nullptr) {
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

// Example usage
int main() {
    ListNode* head1 = new ListNode(9);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(13);
    head1->next->next->next = new ListNode(3);
    head1->next->next->next->next = new ListNode(8);
    head1->next->next->next->next = new ListNode(10);
    
    std::cout << "Original list: ";
    printList(head1);
    
    ListNode* result1 = removeNodes(head1);
    
    std::cout << "Modified list: ";
    printList(result1);
    
    return 0;
}
