
#include <bits/stdc++.h>
using namespace std;
// struct Node
// or
class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *convertArr2LL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}
Node *DeleteHead(Node *head)
{
    if (head == NULL)
        return head;
    Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

// delete tail 
Node *DeleteTail(Node *head)
{
    if (head == NULL || head->next ==nullptr) return NULL;
       
    Node *temp = head;
    while(temp->next->next != nullptr)
    {
        temp=temp->next;
    }
   
    free(temp->next);
    temp->next=NULL;
    return head;
}

Node *DeleteKth(Node* head, int k)
{
    if (head == NULL ) return head;
    if( k == 1)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    int cnt =0;
    Node *temp = head;
    Node *prev = NULL;

    while (temp != NULL)
    {
        cnt++;
        if(cnt==k)
        {
            prev->next = temp->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    
    return head;

}


Node *DeleteEl(Node *head, int el)
{
    cout<<"El: "<<el<<endl;
    if (head == NULL ) return NULL;
       
    Node *temp = head;
    Node *prev = NULL;
    cout<<temp->data<<endl;

    while(temp)
    {   cout<<"temp_>data: "<<temp->data<<endl;
        if(temp->data==el)
        {
            prev->next=temp->next;
            free(temp);
            break;
        }
    prev= temp;
    temp=temp->next;
    }
   
  
    return head;
}


Node *InsertAtPosition(Node *head, int el, int k)
{
    if(head ==NULL)
    {
        if(k==1) return new Node(el);
        else return NULL;

    }
    else{
        if(k==1)
        {
            Node *Temp = new Node(el);
            Temp->next = head;
            return Temp;
        }
        else{
            int cnt =0;
            Node *temp = head;
            while(temp!= NULL){
                cnt++;
                cout<<"cnt: "<<cnt<<endl;
                if(cnt== k-1)
                {
                    Node *x= new Node(el);
                    x->next= temp->next;
                    temp->next=x;
                    break;
                }
                temp= temp->next;

            }
            return head;


        }
    }
}

int main()
{
    vector<int> arr = {2, 5, 8, 7};
    Node *head = convertArr2LL(arr);
    //    Node* y = new Node(arr[0]);
    //    cout<<y->data;
    //    cout<<head->data;
    Node *temp = head;

    while (temp!=NULL)
    {
        cout<<temp->data<<endl;
        // cout << temp->data << " ";
        temp = temp->next;
    }

// start
    // cout << "Deleted Head Successfully" << endl;
    // Node* New2 =   DeleteHead(head);
    // cout << "\n New LinkedList: " << endl;
    // while (New2)
    // {
    //     cout << New2->data << " ";
    //     New2 = New2->next;
    // }
//end

// start
    // cout << "Deleted Tail Successfully" << endl;
    // Node* New =   DeleteTail(head);
    // cout << "\n New LinkedList: " << endl;
    // while (New)
    // {
    //     cout << New->data << " ";
    //     New = New->next;
    // }
//end    

// start
    // cout << "Deleted kth Successfully" << endl;
    // Node* New =   DeleteKth(head,2);
    // cout << "\n New LinkedList: " << endl;
    // while (New)
    // {
    //     cout << New->data << " ";
    //     New = New->next;
    // }
// end

// start
    // cout << "Deleted elemnt by value Successfully" << endl;
    // Node* New =   DeleteEl(head,12);
    // cout << "\nDelelted elment LinkedList: " << endl;
    // while (New)
    // {
    //     cout << New->data << " ";
    //     New = New->next;
    // }
// end


// start
 Node* Insertposition =   InsertAtPosition(head,12,3);
    cout << "\nInserted elment in LinkedList: " << endl;
    while (Insertposition)
    {
        cout << Insertposition->data << " ";
        Insertposition = Insertposition->next;
    }
// End

    return 0;
}