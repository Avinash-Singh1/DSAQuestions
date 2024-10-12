
#include <bits/stdc++.h>
using namespace std;

void classifyTriangle(vector<string> sides) {
    
    for(auto i:sides){
        stringstream ss(i);
        int side1,side2,side3;
        ss>>side1>>side2>>side3;
        cout<<side1<<" "<<side2<<" "<<side3<<endl;
        if((side1+side2>side3) && (side1<side2+side3) && (side1+side3>side2)){
            if(side1==side2 && side2 == side3)
            {
                cout<< "Equilateral\n";
            }
            else if (side1==side2|| side2 ==side3 ||side1==side3){
                cout<< "Isoceles Traingle\n";
            }
            else{
                cout<< "None of these\n";
            }
        }
    }
  
 
}

int main() {
    vector<string> triangleToy = {"2 2 1","3 3 3","3 4 5","1 1 3"};

    classifyTriangle(triangleToy);
    // cout << "The triangle is " << result << endl;

    return 0;
}