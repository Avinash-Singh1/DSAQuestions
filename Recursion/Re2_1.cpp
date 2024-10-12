// sum offirst N Number
#include <bits/stdc++.h>
using namespace std;
int submission_of_n(int n, int sum)
{

    if (n < 1)
    {
        cout << "sum: " << sum;
        return sum;
    }
    else
    {
        submission_of_n(n - 1,sum+n );
    }
}
int main()
{

    int n;
    cout << "Enter number" << endl;
    cin >> n;

    int result = submission_of_n(n, 0);
    cout << "Sum: " << result << endl;

    return 0;
}