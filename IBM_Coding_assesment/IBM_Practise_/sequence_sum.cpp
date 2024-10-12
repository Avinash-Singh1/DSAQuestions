
#include <bits/stdc++.h>
using namespace std;

int sum_sequence(int i,int j,int k){
    int sum =0;
    for(int a=i;a<=j;a++){
        sum+=a;
    }
    for (int  b = j-1; b !=k; b--)
    {
        sum+=b;
    }

    
    return sum;
    
    

}
int main(){
   
 int i =0; int j =5; int k=1;  
   int result= sum_sequence(i,j,k);
 return 0;  
}