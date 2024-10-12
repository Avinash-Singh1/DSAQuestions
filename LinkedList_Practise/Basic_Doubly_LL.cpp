
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *back;
    Node(int data1, Node *Next1, Node *back1)
    {
        data = data1;
        next = Next1;
        back = back1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};
Node *ConvArr_To_LL(Node *head, vector<int> arr)
{
    Node *Mover = head;
    //   Array to LL
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        temp->back = Mover;
        Mover->next = temp;
        Mover = Mover->next;
    }
}

Node *DeleteHead(Node *head)
{
    Node *Prev = head;
    head = head->next;
    head->back = nullptr;
    Prev->next = nullptr;
    return head;
}
int main()
{
    vector<int> arr = {2, 5, 8, 7};
    Node *head = new Node(arr[0]);
    ConvArr_To_LL(head, arr);
    Node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        if (cnt == 3)
        {
            cout << temp->back->data << endl;
            break;
        }
        temp = temp->next;
    }

    return 0;
}