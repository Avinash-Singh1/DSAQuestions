#include<bits/stdc++.h>

using namespace std;
class Queue {
    
 int s; int e; int cur; int maxsize; int * arr;
 public:
 Queue(){
    s=-1;
    e=-1;
    cur=0;
    maxsize=16;
    arr = new int[maxsize];
 }
 Queue(int maxupdated){
    s=-1;
    e=-1;
    cur=0;
    (*this).maxsize=maxupdated;
    arr = new int[maxsize];
 }
 void push(int val)
 {
    if(cur== maxsize) cout<<"Q full\n" ;
    if(e==-1){
        s=0;
        e=0;
    }
    else{
        e= (e+1)%maxsize;
    }
    arr[e]=val;
    cur++;
 }
 int pop(int val)
 {
    if(cur== maxsize) cout<<"Q full\n" ;
    if(e==-1){
        s=0;
        e=0;
    }
    else{
        e= (e+1)%maxsize;
    }
    arr[e]=val;
    cur++;
 }

};

int main() {
  Queue q(6);
  q.push(4);
  q.push(14);
  q.push(24);
  q.push(34);
//   cout << "The peek of the queue before deleting any element " << q.top() << endl;
//   cout << "The size of the queue before deletion " << q.size() << endl;
//   cout << "The first element to be deleted " << q.pop() << endl;
//   cout << "The peek of the queue after deleting an element " << q.top() << endl;
//   cout << "The size of the queue after deleting an element " << q.size() << endl;

  return 0;
}