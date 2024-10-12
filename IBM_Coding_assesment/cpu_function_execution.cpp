#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

vector<int> exclusiveTime2(int n, vector<string>& logs) {
    vector<int> result(n, 0);  // Vector to store exclusive times for each function
    stack<int> stk;            // Stack to keep track of function ids
    vector<int> startTime(n, 0); // Vector to store start times of functions
    int prevTime = 0;         // To keep track of previous log time

    for (const string& log : logs) {
        // Parse log
        int id, time;
        char type;
        stringstream ss(log);
        ss >> id;
        ss.ignore();  // Ignore the ':'
        ss >> type;
        ss.ignore();  // Ignore the ':'
        ss >> time;

        if (type == 's') { // Start log
            if (!stk.empty()) {
                // Update the exclusive time of the function on top of the stack
                result[stk.top()] += (time - prevTime);
            }
            // Push the current function on the stack
            stk.push(id);
            // Update the start time for the current function
            startTime[id] = time;
        } else { // End log
            // Pop the function from the stack
            int top = stk.top();
            stk.pop();
            // Calculate the exclusive time for the function
            result[top] += (time - startTime[top] + 1);
            // Update the previous time
            prevTime = time + 1;
        }
    }

    return result;
}


vector<int> exclusiveTime(int n, vector<string>& logs) {
    vector<int> result(n, 0);  // Vector to store exclusive times for each function
    stack<int> funcStack;            // Stack to keep track of function ids
    int prevTime = 0;         // To keep track of previous log time

    for (const string& log : logs) {
        stringstream ss(log);
        string token;
        vector<string> logParts;
        while(getline(ss,token,':')){
            logParts.push_back(token);
        }
        int functionId = stoi(logParts[0]);
        string action= logParts[1];
        int timestamp=stoi(logParts[2]);

        if(action == "start"){
            if(!funcStack.empty()){
                result[funcStack.top()] += timestamp - prevTime;
            }
            funcStack.push(functionId);
            prevTime = timestamp;
        }
        else{

            result[funcStack.top()]+=timestamp - prevTime+1;
            funcStack.pop();
            prevTime =timestamp+1;
        }
      

    }

    return result;
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
