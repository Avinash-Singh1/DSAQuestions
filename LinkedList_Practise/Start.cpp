
#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data1, Node* Next1){
        data=data1;
        next=Next1;
    }
    Node(int data1){
        data=data1;
        next = nullptr;
    }
};
Node * DeleteHead(Node * head){
    Node * Temp = head;
    head = head->next;
    free(Temp);
    return head;
}
Node * DeleteTailsOfLL(Node * head){
    Node * temp =head;

    while (temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
    return head;
}
Node * DeleteKth(Node * head, int k){
    Node * temp =head;
    Node * Prev = NULL;
    int cnt =0;
    while (temp!=NULL)
    {   cnt++;
        if(cnt==k)
        {
            Prev->next = temp->next;
            free(temp);
            break;
        }
        Prev=temp;
        temp=temp->next;
    }

    
    return head;
}

Node * DeleteKthByValue(Node * head, int k){
    Node * temp =head;
    Node * Prev = NULL;
    int cnt =0;
    while (temp!=NULL)
    {   
        if(temp->data==k)
        {
            Prev->next = temp->next;
            free(temp);
            break;
        }
        Prev=temp;
        temp=temp->next;
    }

    
    return head;
}
Node * InsertAtKth(Node * head,int k, int el){
    Node * temp =head;
    Node * Prev = NULL;
    int cnt =0;
    while (temp!=NULL)
    {   cnt++;
        if(cnt==k-1)
        {   Node* x =new Node(88);
            x->next = temp->next;
            temp->next = x;
            break;
        }
        temp=temp->next;
    }

    return head;
}

int main(){
   vector<int> arr= {2,5,8,7};
   Node * head = new Node(arr[0]);
   Node* Mover= head;
//   Array to LL
   for (int i = 1; i < arr.size(); i++)
   {
        Node * temp = new Node(arr[i]);
        Mover->next = temp;
        Mover= Mover->next;
   }

// Delete Head
//    Node * NewHead =DeleteHead(head);
//    while (NewHead!= NULL)
//    {
//     // cout<<NewHead->data<<endl;
//     NewHead=NewHead->next;
//    }

    // Delete Tail
    // Node *DelteTail=DeleteTailsOfLL(head);
    // while(DelteTail != NULL){
    //     cout<<"del: "<<DelteTail->data<<endl;
    //     DelteTail=DelteTail->next;
    // }

    // Delete Kth Element
    Node * DelteTail = DeleteKth(head, 2);
    //  while(DelteTail != NULL){
    //     cout<<"del: "<<DelteTail->data<<endl;
    //     DelteTail=DelteTail->next;
    // }

    // Delete By Value
    // Node * DelteByVal = head;
    // Node * DelteByVal = DeleteKthByValue(head, 7);
    // while(DelteByVal != NULL){
    //     cout<<"del: "<<DelteByVal->data<<endl;
    //     DelteByVal=DelteByVal->next;
    // }

    // Insert at kth Position
    Node * InsertedKth = InsertAtKth(head, 2, 10);
    while(InsertedKth != NULL){
        cout<<"del: "<<InsertedKth->data<<endl;
        InsertedKth=InsertedKth->next;
    }
    

   
 return 0;  
}