#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

vector<int> exclusiveTime(int n, vector<string> &logs)
{
    vector<int> ans(n, 0);
    stack<int>funcstk;
    int prevtime=0;

    for (int i = 0; i < 2 * n; i++)
    {
         stringstream ss(logs[i]);
        string token;
        vector<string> logParts;
        while(getline(ss,token,':')){
            logParts.push_back(token);
        }
        int functionId=stoi(logParts[0]);
        string action=logParts[1];
        int timestamp=stoi(logParts[2]);
        if(action=="start"){
            if(!funcstk.empty()){
                ans[funcstk.top()]+=timestamp-prevtime;
            }
            funcstk.push(functionId);
            prevtime=timestamp;

        }else{
            ans[funcstk.top()]+=timestamp-prevtime+1;
            funcstk.pop();
            prevtime=timestamp+1;
        }
    }
    return ans;
}

int main()
{

    int n = 2;
    vector<string> logs = {"0:start:0", "1:start:2", "1:end:5", "0:end:6"};

    vector<int> result = exclusiveTime(n, logs);

    for (int time : result)
    {
        cout << time << " ";
    }

    return 0;
}
