#include <iostream>
#include <queue>
using namespace std;
void case1()
{
    priority_queue<int> pq;

    // Insert elements
    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);

    // Print elements in priority order
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
}
int main() {

    // Output: 30 20 10 5
    return 0;
}
