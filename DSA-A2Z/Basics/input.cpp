
#include <bits/stdc++.h>
using namespace std;

void dosmething(int &num)
{
    num += 5;
    cout << "\n"<< num << endl;
}
int main()
{

    int num = 10;
        cout << "num2:" << num << endl;

    dosmething(num);
    cout << "num2:" << num << endl;
    return 0;
}