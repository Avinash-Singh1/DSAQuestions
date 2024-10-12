
#include <bits/stdc++.h>
using namespace std;
vector<int> Batton_pass(int f, int time)
{
    int cyclelenght= 2*(f-1);
    int effTime= (time-1)%cyclelenght +1;
    int position; int passer; int reciever;
    if(effTime<f)
    {
       position = effTime;
       passer=position; 
    }else{
       position = effTime;
       passer=position;
    }

 
}
int main()
{

    int f = 4;
    int time = 12;
    vector<int> result = Batton_pass(f, time);
    for(auto i: result){
        cout<<i<<" ";
    }

    return 0;
}