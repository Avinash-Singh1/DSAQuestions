#include<bits/stdc++.h>

using namespace std;
class Stack {
int top; int size; int * arr;
public:
    Stack() {
         top=-1;
         this->size=100;
         arr=new int[size];
    }
    void push(int data) {
       
          arr[++top] =data;
      
    }
    int pop(){
       
            int x =arr[top];
            top--;
            return x;
        
    } 
    int Size(){
        return top+1;
    }
    int Top()
    {
        return arr[top];
    }
};
int main() {

  Stack s;
  s.push(6);
  s.push(3);
  s.push(7);
  cout << "Top of stack is before deleting any element " << s.Top() << endl;
  cout << "size of stack before deleting any element " << s.Size() << endl;
  cout << "The element deleted is " << s.pop() << endl;
  cout << "size of stack after deleting an element " << s.Size() << endl;
  cout << "Top of stack after deleting an element " << s.Top() << endl;
  return 0;
}