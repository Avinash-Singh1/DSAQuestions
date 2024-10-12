

#include <bits/stdc++.h>
using namespace std;


int main() {
    std::string input = "123 456 789";
    std::istringstream iss(input);

    int a, b, c;
    iss >> a >> b >> c;

    std::cout << "First number: " <<  typeid(a).name() << std::endl;
    std::cout << "Second number: " << b << std::endl;
    std::cout << "Third number: " << c << std::endl;

    return 0;
}
