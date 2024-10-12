
#include <bits/stdc++.h>
using namespace std;
int MissedLectures(int numOfChapters,int b,int e)
{ 
    vector<int> classes;

    // calculate the total classes take place
    int noOfLectures = numOfChapters *(e+1);

    // populate the classes vector with chapter pattern [0,1,2 numofChapters [0,1,2,3,0,1,2,3...]]
    for(int i=0;i<noOfLectures;i++)
    {
        classes.push_back(i%numOfChapters);   // cycle through chapters
    }

    // count distinct chapters in the speciefied range[ b,e]
    unordered_set<int> distinctChapters;
    for(int i=b;i<=e;i++)
    {
        distinctChapters.insert(classes[i]);
    }
 
    return distinctChapters.size();

}
int main(){
   
 int numOfChapters=4; // number of chapters
 int b =3; // start of the range 
 int e = 5; // end of the the range

 int missed= MissedLectures(numOfChapters,b,e);
 cout<<"Number of Missed Lectures: "<<missed<<endl;  
   
 return 0;  
}