
#include <bits/stdc++.h>
using namespace std;

int main(){
   
 int n =6;
int start =1;
 for(int i=0;i <n;i++)
 {
        if(i%2==0)
        {
                start =0;
        }
        else
        {
            start =1;
        }
        for (int j = 0; j < i; j++)
        {
            cout<<start;
            start=1-start;
            // start==1?start=0:start=1;

        }
        cout<<endl;
        
 }
   
 return 0;  
}