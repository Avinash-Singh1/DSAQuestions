#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> array(n);

    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        array[i].resize(k);
        for (int j = 0; j < k; j++)
        {
            cin >> array[i][j];
        }
    }

    // process query
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << array[a][b] << endl;
    }

    return 0;
}
