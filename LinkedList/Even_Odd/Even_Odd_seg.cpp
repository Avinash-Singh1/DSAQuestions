#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }
};

ListNode *head, *tail; // head and tail of the LinkedList

void PrintList(ListNode *head) // Function to print the LinkedList
{
    ListNode *curr = head;
    for (; curr != nullptr; curr = curr->next)
        cout << curr->val << "-->";
    cout << "null" << endl;
}

void InsertatLast(int value) // Function for creating a LinkedList
{

    ListNode *newnode = new ListNode(value);
    if (head == nullptr)
        head = newnode, tail = newnode;
    else
        tail = tail->next = newnode;
}

ListNode *SegregatetoOddEVen()
{
   ListNode* oddHead = new ListNode(-1),*oddTail=oddHead;
   ListNode* evenHead = new ListNode(-1),*evenTail=evenHead;

   ListNode* curr =head,*temp;
   while (curr!=NULL)
   {
     temp =curr;
     curr = curr->next;
     temp->next=nullptr;
     if(temp->val%2==0){
        evenTail->next=temp;
        evenTail=temp;
     }else{
        oddTail->next=temp;
        oddTail=temp;
     }
   }
   evenTail->next=oddHead->next;
   return evenHead->next;

   
} 
ListNode *SegregatetoOddEVen2()
{
    // creating Heads of Odd and Even LinkedLists
    ListNode *oddHead = new ListNode(-1), *oddTail = oddHead;
    ListNode *evenHead = new ListNode(-1), *evenTail = evenHead;
    ListNode *curr = head, *temp;
    while (curr)
    {
        // Breaking the Link of the curr Node.
        temp = curr;
        curr = curr->next;
        temp->next = nullptr;

        if (temp->val%2==1) // If odd Node,append to odd LinkedList
        {
            oddTail->next = temp;
            oddTail = temp;
        }
        else // If Even Node,append to even LinkedList
        {
            evenTail->next = temp;
            evenTail = temp;
        }
    }
    evenTail->next = oddHead->next; 
    // Appending Odd LinkedList at end of EvenLinkedList
    return evenHead->next;
} 

int main()
{
    InsertatLast(1);
    InsertatLast(2);
    InsertatLast(3);
    InsertatLast(4);
    cout << "Initial LinkedList : " << endl;
    PrintList(head);
    ListNode *newHead = SegregatetoOddEVen();
    cout << "LinkedList After Segregration " << endl;
    PrintList(newHead);
    return 0;
}