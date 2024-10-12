
#include <bits/stdc++.h>
using namespace std;
int minFlips(string pwd) {
    int countFlips = 0;
    for(int i = 0; i < pwd.size() - 1; i += 2) {
        if(pwd[i] != pwd[i + 1]) {
            countFlips++;
        }
    }
    return countFlips;
}

int main(){
  //Q1 
  char arr[20];
  int i;
  for(i=0;i<10;i++)
  *(arr+i)=65 +1;
  *(arr+i)=0;
  cout<<arr; 
  // Q1 out: BBBBBBBB 9 times

//Q2
   string pwd="101011";
   int res=minFlips(pwd);
   cout<<"res: "<<res<<endl;
// Q2 out: 2 

//Q3 
 int a=5,b=10,c=15;
  int*arr[]={&a,&b,&c};
  cout<<arr[1];
// Q3 out: adress


// Q4 Fibonachi
 int a=0,b=1,i,c,n,j;    
    cout<<"Enter the limit: ";   
    cin>>n;    
    for(i=1; i<=n; i++)    
    {    
        a=0;    
        b=1;    
        cout<<b<<"\t";   
        for(j=1; j<i; j++)   
        {    
            c=a+b;    
          cout<<c<<"\t";    
            a=b;    
            b=c;  
        }    
        cout<<"\n";    
    }  
 // 




     return 0;  
}