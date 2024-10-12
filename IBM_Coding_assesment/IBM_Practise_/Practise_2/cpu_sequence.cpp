#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>

using namespace std;



vector<int> exclusiveTime(int n, vector<string>& logs) {
    vector<int> result(n,0);
    stack<int> st;
    int prevtime=0;

    for(auto s: logs){
        stringstream ss(s);
        string token;
        vector<string> logsparts;
        while(getline(ss,token,':')){
            logsparts.push_back(token);
        }
        int functionid = stoi(logsparts[0]);
        string action= logsparts[1];
        int timestamp = stoi(logsparts[2]);

        if(action == "start")
        {   if(!st.empty()){
                result[st.top()]+=timestamp-prevtime;
            } 

            st.push(functionid);
            prevtime =timestamp;
        }else{

        }

    }
   
}

int main() {   
   
    int n = 2;
vector<string> logs = {"0:start:0", "1:start:2", "1:end:5", "0:end:6"};

    
    vector<int> result = exclusiveTime(n, logs);
    
    for (int time : result) {
        cout << time << " ";
    }
    
    return 0;
}
