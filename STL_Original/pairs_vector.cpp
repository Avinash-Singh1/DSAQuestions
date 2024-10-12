
#include <bits/stdc++.h>
using namespace std;
// Function that returns a pair
pair<int, string> getPersonInfo() {
    int age = 30;
    string name = "Alice";
    return make_pair(age, name);
}

int main(){
   
   
   using Person =pair<int, string>;
    using People =vector<Person>;
    People people = { { 1, "John" }, { 2, "Jane"}};
    people.push_back(make_pair(56,"jk singh"));
    people.push_back(make_pair(46,"Santosh singh"));
    
    Person PersonInfo=getPersonInfo();
    cout<<"Returned Personal Info"<<PersonInfo.first<<endl;
    cout<<"Returned Second Info"<<PersonInfo.second<<endl;
    // for (auto& p : people) {
    // cout<<"person "<<p.second<< " age: "<<p.first<<endl;
    // }
    

    return 0;  
}