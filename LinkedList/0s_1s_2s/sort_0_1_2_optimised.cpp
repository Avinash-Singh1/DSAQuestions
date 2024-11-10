
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

Node* Sort_0_1_2(Node* head){
    if(head==NULL || head->next== NULL){ 
        return head;
    }

    Node* temp = head;
    Node*zeroHead =new Node(-1),*zeroTail=zeroHead;
    Node*oneHead =new Node(-1),*oneTail=oneHead;
    Node*twoHead =new Node(-1),*twoTail=twoHead;

    while(temp!=NULL)
    {
       if(temp->data==0){
        zeroTail->next=temp;
        zeroTail=temp;

       }
       else if(temp->data==1){
         oneTail->next=temp;
         oneTail=temp;
       }
       else{
         twoTail->next=temp;
         twoTail=temp;
       }
       temp=temp->next;
    }

    zeroTail->next=oneHead->next;
    oneTail->next=twoHead->next;
    twoTail->next=NULL;
   
    return zeroHead->next;
   
}

int main() {
    // Initialize a vector with values for the linked list
    vector<int> arr = {1,0,1,2,0,1,0};
    // Create a linked list with the values from the vector
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    head->next->next->next->next = new Node(arr[4]);
    head->next->next->next->next->next = new Node(arr[5]);
    head->next->next->next->next->next->next = new Node(arr[6]);
    // Call the deleteTail function to delete the last node
    // head = DeleteHead(head);
    // head = Delete_Tail(head);
    // head = Delete_Kth(head,2);
    // Print the linked list after deletion
    // printLL(head);
    // cout<<"\n"<<endl;
    
    printLL(head);
    cout<<"After modification: \n";
    head = Sort_0_1_2(head);
    printLL(head);


}