
#include <bits/stdc++.h>
using namespace std;
vector<int> Batton_pass(int f, int time)
{
    int cyclelength = 2 * (f - 1);
    int eftime = (time - 1) % cyclelength + 1;
    int position;
    int passer;
    int reciever;
    if (eftime < f)
    {
        position = static_cast<int>(eftime);
        passer = position;
    }
    else
    {
        position = 2 * f - static_cast<int>(eftime);
        passer = position;
    }


    if (eftime < f)
    {
        reciever = (passer < f) ? passer + 1 : 1;
    }
    else
    {
        reciever = (passer >1) ? passer - 1 : f;
        // reciever = (passer < f) ? passer - 1 : f;
    }
    return {passer,reciever};
} 
int main()
{

    int f = 4;
    int time = 5;
    vector<int> result = Batton_pass(f, time);
    for(auto i: result){
        cout<<i<<" ";
    }

    return 0;
}