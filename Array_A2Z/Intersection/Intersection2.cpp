
#include <bits/stdc++.h>
using namespace std;

int main(){
   
 vector<int> arr1={1,2,2,3,3,4,5,6};
 vector<int> arr2={2,3,3,5,6,6,7};
 vector<int> visited={0,0,0,0,0,0,0};
 vector<int> answer;


 int n =arr1.size();
 int m =arr2.size();
 for (int i = 0; i < n; i++)
 {
    for (int  j = 0; j < m; j++)
    {
        if(arr1[i]==arr2[j] && visited[j] ==0)
        {
            answer.push_back(arr1[i]);
            visited[j]=1;
            break;
        }
        if(arr2[j]>arr1[i]) break;
    }
    
 }

 for(auto it: answer)
 {
    cout<<it<<endl;
 }
 
   
 return 0;  
}