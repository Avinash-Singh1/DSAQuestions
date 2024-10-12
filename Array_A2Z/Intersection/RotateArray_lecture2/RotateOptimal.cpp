
#include <bits/stdc++.h>
using namespace std;
void movezeros(vector<int> v, int n)
{
    vector<int> temp;
    for(auto i :v){
        if(i!=0){
            temp.push_back(i);
        }
    }
     cout<<"temp array \n";
    //  print the templ values
       for(auto i :temp){
      cout<<i<<" ";
    }

    for (int i = temp.size(); i < n; i++)
    {
        temp.push_back(0);
    }

         cout<<"TEm array \n";
    //  print the templ values
       for(auto i :temp){
      cout<<i<<" ";
    }
    


}

void BetterApproach(vector<int>& v, int n){
    int i,j;
    for( i=0; i<n;i++){
        if(v[i]==0){
            j=i;
            break;
        }
    }

    for (int j =i+1; j < n; j++)
    {
        if(v[i]!=0){
            swap(v[i],v[j]);
            j++;
        }
    }
    
}

int main()
{

    cout << "enter the size of array";
    int n, value;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        v.push_back(value);
    }

    BetterApproach(v, n);

    // cout<<""<<<<endl;
    for (auto i = v.begin(); i != v.end(); i++)
    {
        cout << *i << " ";
    }

    // movezeros(v, n);

    return 0;
}