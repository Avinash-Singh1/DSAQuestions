
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Define a Node class for doubly linked list
class Node {
public:
    // Data stored in the node
    int data;   
  
    Node* next;     
    // Pointer to the previous node in the list
    //(backward direction)
    Node* back;     

   
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }

  
    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

// Function to convert an array
// to a doubly linked list
Node* convertArr2DLL(vector<int> arr) {
    // Create the head node with
    //the first element of the array
    
    Node* head = new Node(arr[0]);
    
    // Initialize 'prev' to the head node
    Node* prev = head;            

    for (int i = 1; i < arr.size(); i++) {
        // Create a new node with data from the
        //array and set its 'back' pointer to
        //the previous node
        
        Node* temp = new Node(arr[i], nullptr, prev);
        
        prev->next = temp; 
        
        prev = temp;       
    }
    // Return the head of the doubly linked list
    return head;  
}


void print(Node* head) {
    while (head != nullptr) {
        // Print the data in the tail node
        cout << head->data << " ";  
         // Move to the next node
        head = head->next;         
    }
}

 
// Function to reverse a doubly linked list
// In-place link exchange method
Node* reverseDLL(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head; 
    }
    Node* prev= NULL;
    Node* cur=head;

    while (cur!=NULL)
    {
        prev = cur->back;
        cur->back= cur->next;
        cur->next=prev;
        cur=cur->back;
        // prev= cur;
    }
    
    return prev->back;

}


int main() {
    vector<int> arr = {12, 5, 8, 7, 4};
    Node* head = convertArr2DLL(arr);
    cout << endl << "Doubly Linked List Initially:  " << endl;
    print(head);
    cout << endl << "Doubly Linked List After Reversing " << endl;
    
     // Insert a node with value 10 at the end
    head = reverseDLL(head);
    print(head);

    return 0;
}

