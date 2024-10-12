#include <iostream>
#include <vector>
#include <utility> // For std::pair
#include <string>
#include <algorithm> // For std::sort

using namespace std;

// Function that returns a pair
pair<int, string> getPersonInfo() {
    int age = 30;
    string name = "Alice";
    return make_pair(age, name);
}

int main() {
    // Type aliases to avoid using std:: repeatedly
    using Person = pair<int, string>;
    using People = vector<Person>;
    // pair <int, pair<int,string>> p2 ={45,{77,"avinash"}};


    // cout<<"p2: "<<p2.second.first<<endl<<"p2 name";

    // 1. Basic Usage
    // Person person;
    // person.first = 25;
    // person.second = "John";
    
    // cout << "Person: " << person.second << ", Age: " << person.first << endl;
    

    
    // 2. Using Pairs in Containers
    People people;
    people.push_back(make_pair(25, "John"));
    people.push_back(make_pair(30, "Alice"));
    people.push_back(make_pair(22, "Bob"));
    
    for(const auto& p : people) {
        cout << "Person: " << p.second << ", Age: " << p.first << endl;
    }
    
    //-- Sorting pairs based on the first element (age)
    sort(people.begin(), people.end());
    
    cout << "Sorted by age:" << endl;
    for(const auto& p : people) {
        cout << "Person: " << p.second << ", Age: " << p.first << endl;
    }
    
    // 3.-- Pairs as Return Values
    Person personInfo = getPersonInfo();
    cout << "Returned Person: " << personInfo.second << ", Age: " << personInfo.first << endl;
    
    // 4.-- Comparing Pairs
    Person person1 = make_pair(20, "Charlie");
    Person person2 = make_pair(20, "David");
    
    if(person1 < person2) {
        cout << person1.second << " is less than " << person2.second << endl;
    } else {
        cout << person1.second << " is not less than " << person2.second << endl;
    }

    
    return 0;
}
