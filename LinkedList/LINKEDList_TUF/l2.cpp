
#include <bits/stdc++.h>
using namespace std;
// Node class for a linked list
class Node {
public:
    int data;         // Data of the node
    Node* next;       // Pointer to the next node in the list
    // Constructor for a node with both data and next node provided
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
    // Constructor for a node with only data provided, next initialized to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};
// Function to print the linked list starting from the given head
void printLL(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}
// Function to delete the tail node of a linked list and return the new head
Node* deleteTail(Node* head) {
    // If the list is empty or has only one node, return NULL
    if (head == NULL || head->next == NULL)
        return NULL;
    // Initialize a temporary pointer to traverse the list
    Node* temp = head;
    // Traverse to the second last node in the list
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    // Delete the last node
    delete temp->next;
    // Set the next of the second last node to nullptr, effectively removing the last node
    temp->next = nullptr;
    // Return the head of the modified list
    return head;
}

Node* DeleteHead(Node* head){
    if(head==NULL){
        return NULL;
    }
    Node* temp =head;
    head =head->next;
    free(temp);
    return head;
}

Node* Delete_Tail(Node* head){
    if(head==NULL){
        return NULL;
    }
    Node* temp =head;
    while (temp->next->next!=NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next= nullptr;
    return head;
   
}
Node* Delete_Kth(Node* head,int k){
    if(head==NULL){ return nullptr;}
    int cnt =0;
    Node* temp =head;
    Node* prev =nullptr;
    while (temp!=NULL){
        cnt++;
        if(cnt ==k){
            prev->next=prev->next->next;
            break;
        }
        prev = temp;
        temp = temp->next;

    }
}
Node* Delete_By_Value(Node* head,int el){
    if(head==NULL){ 
        return nullptr;
    }
    int cnt =0;
    Node* temp =head;
    Node* prev =nullptr;
    if(temp->data==el)
    {
        head= head->next;
        delete temp;
        return head;
    }
    
        while (temp!=NULL){
            if (temp->data ==el){
                prev->next = temp->next;
                delete temp;
                return head;
            }
            prev= temp;
            temp =temp->next;
        }
    
}

int main() {
    // Initialize a vector with values for the linked list
    vector<int> arr = {12, 5, 8, 7};
    // Create a linked list with the values from the vector
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    // Call the deleteTail function to delete the last node
    // head = DeleteHead(head);
    // head = Delete_Tail(head);
    // head = Delete_Kth(head,2);
    // Print the linked list after deletion
    // printLL(head);
    // cout<<"\n"<<endl;
    head = Delete_By_Value(head,8);
    printLL(head);


}