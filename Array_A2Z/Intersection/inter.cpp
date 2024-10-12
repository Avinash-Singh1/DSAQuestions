
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n = 7;
    vector<int> a = {1, 2, 2, 3,3,4, 5, 6};
    vector<int> b = {2,3,3,5,6,6,7};
    int n1 =8, n2=7;
    vector<int>visited={0,0,0,0,0,0,0,0};
    set<int>ans;
   

   for (int i = 0; i < n1; i++)
   {
        for (int j = 0; j < n2; j++)
        {
            if(a[i] ==b[j] && visited[i]==0){
                ans.insert(a[i]);
                visited[i]=1;
                break;
            }
            if(b[j]>a[i]) break;
        }
        
   }
   for(auto it: ans){
    cout<<it<<" "<<endl;
   }
   
    return 0;

}