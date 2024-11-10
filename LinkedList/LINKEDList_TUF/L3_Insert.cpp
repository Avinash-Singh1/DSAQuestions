
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

Node* Insert_At_kth(Node* head,int val,int k){
    if(head==NULL){
        if(k==1){
            return new Node(val);
        }
        else{
            return NULL;
        }
    }
    // if(k==1){
    //     Node* temp=new Node(val,head);
    //     return temp;
    // }

    int cnt =0;
    Node* temp = head;
    Node* prev = nullptr;
    while(temp!= NULL)
    {
        cnt++;
        if(cnt==k-1){
            Node * x = new Node(val);
            x->next=temp->next;
            temp->next=x;
            return head;
        }
        prev=temp;
        temp=temp->next;

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
    head = Insert_At_kth(head,18,2);
    printLL(head);

}