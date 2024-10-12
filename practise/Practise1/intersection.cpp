
#include <bits/stdc++.h>
using namespace std;

int main(){
   
  int a[] = {1, 1,1, 2, 3};
    int b[] = {1,2, 3, 4, 4,6};
    int n1 = 5;
    int n2 = 6;
    int visited[n2]={0};
    cout<<" vis"<<endl;
    for(auto i : visited)
{
    cout<<" "<<i<<" ";
}
   
vector<int> answer;  
for (int  i = 0; i < n1; i++)
{
    for (int j = 0; j < n2; j++)
    {
        if(a[i]==b[j] && visited[j]==0)
        {
            answer.push_back(a[i]);
            visited[j]=1;
            break;
        }
        if(b[j]>a[i]) break;
    }
    
}

for(auto i : answer)
{
    cout<<" i "<<i<<" ";
}

   
 return 0;  
}