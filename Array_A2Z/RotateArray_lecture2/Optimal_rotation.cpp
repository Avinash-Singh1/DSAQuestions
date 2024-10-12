
#include <bits/stdc++.h>
using namespace std;
void OptimalLeftRotate(int arr[], int n, int d)
{
    if(n==0)    {
        return;
    }
    else{
        d= d%n;

        reverse(arr,arr+d);
        reverse(arr+d,arr+n);
        reverse(arr,arr+n);
    }

}

void reverse(int arr[],int s,int e)
{
    if(s<e)
    {
        int tem= arr[s];
        arr[s]=arr[e];
        arr[e]=tem;
        s++;
        e--;
    }
}





int main()
{

    int n = 7;
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int d = 3;

    cout << "Before rotation:" << endl;
    for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
    cout << endl;

    OptimalLeftRotate(arr, n, d);
    cout << "After rotation:" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;

}