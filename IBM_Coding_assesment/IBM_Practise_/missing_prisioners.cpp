
#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<vector<int>> locations = { {1, 1},
                                      {1, 2},
                                      {2, 1},
                                      {4, 4},
                                      {4, 6},
                                      {9, 4},
                                      {9, 6} };

    int x_missing=0;
    int y_missing=0;

    set<int> x_coordinates;
    set<int> y_coordinates;
    for(auto i:locations){
        x_coordinates.insert(i[0]);
        y_coordinates.insert(i[1]);
    }

   for(auto x: x_coordinates){
       int count=0;
       for(auto i:locations){
        if(i[0]==x){
            count++;
        }
       }
       if(count==1)
       {
        x_missing=x;
       }
   }

    for(auto y: y_coordinates){
       int count=0;
       for(auto i:locations){
        if(i[0]==y){
            count++;
        }
       }
       if(count==1)
       {
        y_missing=y;
       }
   }

   cout<<"Missing prisioner: ["<<x_missing<<", "<<y_missing<<"]"<<endl;



    return 0;
}