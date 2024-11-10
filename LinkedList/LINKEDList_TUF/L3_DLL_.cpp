#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Define a Node class for doubly linked list
class Node {
public:
    // Data stored in the node
    int data;   
    // Pointer to the next node in the list (forward direction)
    Node* next;     
    // Pointer to the previous node in the list (backward direction)
    Node* back;     

    // Constructor for a Node with both data, a reference to the next node, and a reference to the previous node
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }

    // Constructor for a Node with data, and no references to the next and previous nodes (end of the list)
    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

// Function to convert an array to a doubly linked list
Node* convertArr2DLL(vector<int> arr){
   if(arr.size()<=0) return NULL;
   Node* head = new Node(arr[0]);
   Node* prev = head;
   for(int i=1; i<arr.size(); i++) {
       Node* temp = new Node(arr[i],nullptr,prev);
       prev->next=temp;
       prev=temp;
   }
   return head;
}

// Function to convert an array to a doubly linked list
Node* DeleteTail(Node* head) {
    // If the list is empty
    if (head == nullptr) {    
        return nullptr;
    }
    // If the list has only one node
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }
    // Traverse to the second last node
    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    // Delete the last node and update the second last node's pointers
    Node* tail = temp->next;
    temp->next = nullptr;    // Remove the link to the last node
    delete tail;             // Delete the last node

    return head;             // Return the updated head
}


// Function to print the elements of the doubly linked list
void print(Node* head) {
    while (head != nullptr) {
        cout<<head->data<<" ";
        head= head->next;        
    }
}



int main() {
    vector<int> arr = {12, 5, 8, 7, 4};
    Node* head = convertArr2DLL(arr);

    cout << "Doubly Linked List Initially: " << endl;
    print(head);


    cout << endl << "Doubly Linked List After Inserting at the tail with value 10: " << endl;
     // Insert a node with value 10 at the end
    DeleteTail(head);
    print(head);

    return 0;
}