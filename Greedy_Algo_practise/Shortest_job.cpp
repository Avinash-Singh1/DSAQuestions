
#include <bits/stdc++.h>
using namespace std;

float shortestJobFirst(vector<int> jobs)
{
    int t=0; int wtime=0;
    int n =jobs.size();
    sort(jobs.begin(),jobs.end());
    // 1 2 3 4 7
    for(auto i: jobs){
        wtime+=t;
        t+=i;
    }
    return (wtime/n);
}
int main(){
   
vector<int> jobs = {4, 3, 7, 1, 2};
    
    cout << "Array Representing Job Durations: ";
    for(int i = 0; i < jobs.size(); i++){
        cout << jobs[i] << " ";
    }
    cout << endl;
    
    float ans = shortestJobFirst(jobs);
    cout << "Average waiting time: "<< ans;
    cout << endl;

    return 0;
}
                            
                        