
#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *Next;
    Node *Back;
    Node(int data1, Node *Next1, Node *Back1)
    {
        data=data1;
        Next=Next1;
        Back=Back1;
    }
    public:
    Node(int data1)
    {
        data=data1;
        Next=nullptr;
        Back=nullptr;
    }
};

Node *convertToDLL(vector<int> arr){
    Node * head= new Node(arr[0]);
    Node *Prev=head;
    Node * temp = head;
   for(int i=1;i<arr.size();i++)
   {
    
    Node *newNode = new Node(arr[i]);
    temp->Next= newNode;
    newNode->Back = temp;
    temp=newNode;
   }
return head;    
}

Node *DeleteHead(Node* head)
{
    if(head==NULL || head->Next==NULL)
    {
        free(head);
        return NULL;
    }else
    {
        Node *prev =head;
        head=head->Next;
        head->Back=NULL;
        prev->Next=NULL;
    


        return head;
    }

}
Node *DeleteTail(Node* head)
{ 
    if(head==NULL || head->Next==NULL){
        free(head);
        return NULL;
    }
    else
    {
           Node *temp= head;
           while(temp!= NULL)
            {  
                // if(temp->Next->Next ==nullptr)
                if(temp->Next ==NULL)
                {
                    // working
                    // Node *NodetoDelete= temp->Next;
                    // NodetoDelete->Back=NULL;
                    // temp->Next=NULL;
                    // free(NodetoDelete);

                    // or Working 2

                    Node * prev = temp->Back;
                    prev->Next = NULL;
                    temp->Back=NULL;
                    // return head;
                    break;
                }
                temp=temp->Next;
            }
       return head;
 
   }
}

Node *RemoveKth(Node *head,int k)
{ 
    if(head==NULL) return head;
    else{
          int cnt =0;
            Node *temp = head;
            while (temp!= NULL)
            { cnt++;
                if(cnt==k)
                {
                    break;
                }
                temp= temp->Next;
                
            }
            
        Node * prev= temp->Back;
        Node * front= temp->Next;

        if(prev == NULL && front==NULL)
        {
            free(temp);
            return head;
        }
        else if(prev==NULL) // head
        {
            Node *NewHead =DeleteHead(head);
            return head;
        }
        else if(front == NULL)
        {
            Node *NewT =DeleteHead(head);
            return head;
        }
        else
        {
            prev->Next = front;
            front->Back = prev;
            temp->Next=NULL;
            temp->Back=NULL;
            free(temp);
            return head;
        }
    }
}

void deleteNodeByValue(Node * temp)
{
     Node* prev =temp->Back;
     Node* Front = temp->Next;
    if(temp == NULL || Front ==NULL ) {
        prev->Next = nullptr;
        temp->Back = nullptr;
        free(temp);
        return;
    }
    else{
       prev->Next=Front;
       Front->Back=prev;
       temp->Next=temp->Back =nullptr;
       free(temp);
    }
}

Node* InsertHead(Node * head, int el)
{
    Node * NewHead= new Node(el,head,nullptr);
    // cout<<NewHead->data;
    head->Back= NewHead;
    return NewHead;
}

Node * InsertBeforeTail(Node * head, int el)
{
 if(head->Next==NULL)
    {
        InsertHead(head,el);
    }
    else{
        Node * Tail = head;
        while (Tail->Next!=NULL)
        {
            Tail= Tail->Next;
        }
        Node *prev = Tail->Back;
        Node * NewNode = new Node(455,Tail,prev);
        prev->Next = NewNode;
        return head;
        
        
    }
}
Node * InsertAtKth(Node* head, int k, int el)
{  
    cout<<"th"<<endl;
    if(k==1)
    {
       return  InsertHead(head, el);
        
    }
    
        Node *temp = head;
        int cnt=0;
        while(temp!= NULL)
        {
            cnt++;
            if(cnt== k)
            {
                break;
            }
            temp= temp->Next;
        }
      
           Node *Prev = temp->Back;
        // Node * NewNode = new Node(55,temp,prev);
           Node * Newnode2= new Node(el,temp,Prev);
           Prev->Next = Newnode2;
           temp->Back=Newnode2;
           return head;
    
}

void InsertBeforeGivenNode(Node * temp, int val)
{
    Node * prev = temp->Back;
    Node * NewNode = new Node(900,temp,prev);
    prev->Next= NewNode;
    temp->Back= NewNode;


}
int main(){
   vector<int> arr={4,5,23,2,66};
   for(auto i:arr)
   {
    cout<<" "<<i<<" ";
   }

   Node *Head= convertToDLL(arr);
   Node *temp =Head;
    // while (temp!=NULL)
    // {   if(temp->data == 23)
    //     {
    //         cout<<"My Back is: "<<temp->Back->data<<endl;
    //     }
    //     cout<<temp->data<<endl;
    //     // cout << temp->data << " ";
    //     temp = temp->Next;
    // }

//start
    // cout<<"\nDelete Head: "<<endl;
    // Node *NewHead=DeleteHead(Head);
    // cout<<"newhead: "<<NewHead->data<<endl;
    // cout<<"newhead: "<<NewHead->Next->data<<endl;
    // while (NewHead!=NULL)
    // {
    //     cout<<NewHead->data<<endl;
    //     NewHead=NewHead->Next;
    // }
//End

// Start
    cout<<"\nDelete Tail of DLL: "<<endl;
    Node *NewHead=DeleteTail(Head);
    Node *KthEl=NewHead;
    cout<<NewHead->data;
    while (NewHead!=NULL)
    {
        cout<<"i: "<<NewHead->data<<endl;
        NewHead=NewHead->Next;
    }
//End
   
// start
cout<<"Delete Kth eleemnt"<<endl;
Node* DeletedKthHead= RemoveKth(KthEl,3);
while (DeletedKthHead!=NULL)
    {
        cout<<DeletedKthHead->data<<endl;
        DeletedKthHead=DeletedKthHead->Next;
    }
// end

//start
cout<<"Delete By Value: "<<endl;
Node* NewNodeForinsertion=KthEl;
deleteNodeByValue(KthEl->Next);
  while (KthEl!=NULL)
    {
        cout<<"i: "<<KthEl->data<<endl;
        KthEl=KthEl->Next;
    }
// end

// start
cout<<"Insert at Head: "<<endl;
Node* NewHeadInserted=InsertHead(NewNodeForinsertion,89);
while (NewHeadInserted!=NULL)
{
    cout<<" "<<NewHeadInserted->data<<" ";
    NewHeadInserted=NewHeadInserted->Next;
}
//end


//start 
cout<<"\nInsert Before Tails:\n";
Node* NodeBTail =InsertBeforeTail(Head,999);
while (NodeBTail != nullptr)
{
    cout<<" "<<NodeBTail->data<<" ";
    NodeBTail=NodeBTail->Next;
}
// end

// start 
cout<<"\nInsert Before Kth:\n";
Head =InsertAtKth(Head,888,2);
Node * va= Head;
while (va!=NULL)
{
    cout<<'temp: '<<va->data<<endl;
}
// End

cout<<"Insert  Before Given Node: "<<endl;
InsertBeforeGivenNode(Head,900);

while (Head)
{
    cout<<Head->data<<" ";
    Head=Head->Next;
}

 return 0;  
}