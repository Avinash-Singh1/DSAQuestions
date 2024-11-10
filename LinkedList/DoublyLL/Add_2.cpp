#include <iostream>

using namespace std;

// Definition for singly-linked list.
class ListNode {
public:
    int val;          // Value of the node
    ListNode* next;   // Pointer to the next node

    // Constructor
    ListNode(int x) : val(x), next(nullptr) {}
};

// Solution class with addTwoNumbers method
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyNode = new ListNode(0);
        ListNode* temp = dummyNode;

        int carry =0; 

        while (l1!=NULL && l2 != NULL)
        {   int sum =0;
            if(l1){
                 sum+=l1->val;
                 l1= l1->next;
            }
            if(l2){
                sum+=l2->val;
                l2= l2->next;

            }

            sum += carry;
            carry= sum/10;
            ListNode* newNode = new ListNode(sum%10);
            temp->next = newNode;
            temp=temp->next;
        }
        return dummyNode->next;

    }
};

// Function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to create a linked list from an array
ListNode* createList(int arr[], int size) {
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;

    for (int i = 1; i < size; ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    // Create two linked lists: l1 = 2 -> 4 -> 3 (represents 342)
    int arr1[] = {2, 4, 3};
    ListNode* l1 = createList(arr1, 3);

    // Create the second linked list: l2 = 5 -> 6 -> 4 (represents 465)
    int arr2[] = {5, 6, 4};
    ListNode* l2 = createList(arr2, 3);

    // Create a Solution object and use it to add the two numbers
    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);

    // Print the resulting linked list
    cout << "Resulting linked list: ";
    printList(result);

    // Free the allocated memory for the linked lists
    // You would normally implement a function to free nodes here to avoid memory leaks.

    return 0;
}
