
#include <bits/stdc++.h>
using namespace std;

vector<int> batonPass(int friends, long long time)
{
    int passer, receiver;
    int cycleLength = (friends - 1) * 2;
    long long effectiveTime = (time - 1) % cycleLength + 1;
    int position;
    if (effectiveTime < friends)
    {
        position = static_cast<int>(effectiveTime);
        passer = position;
    }
    else
    {
        position = 2 * friends - static_cast<int>(effectiveTime);
        passer = position;
    }

    if (effectiveTime < friends)
    {

        receiver = (position < friends) ? position + 1 : 1;
    }
    else
    {

        receiver = (position > 1) ? position - 1 : friends;
    }

    return {passer, receiver};
}

int main()
{

    int friends = 4;
    long long time = 5;
    vector<int> result = batonPass(friends, time);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}