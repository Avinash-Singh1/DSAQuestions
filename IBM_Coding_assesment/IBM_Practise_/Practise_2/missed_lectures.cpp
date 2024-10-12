
#include <bits/stdc++.h>
using namespace std;
int MissedLectures(int numOfChapters,int b,int e)
{ 
vector<int>classes;
unordered_map<int,int> mpp;
 int noOfLectures = numOfChapters*(e+1);
    for (int i = 0; i < noOfLectures; i++)
    {
        classes.push_back(i%numOfChapters);
    }
    for(int i=b; i<=e;i++){
        mpp[classes[i]]++;
    }

    for(auto i: mpp){
        cout<<i.first<< " "<<i.second<<endl;
    }
    return mpp.size();
    

   
    
    
}
int main(){
   
 int numOfChapters=4; // number of chapters
 int b =3; // start of the range 
 int e = 5; // end of the the range

 int missed= MissedLectures(numOfChapters,b,e);
 cout<<"Number of Missed Lectures: "<<missed<<endl;  
   
 return 0;  
}