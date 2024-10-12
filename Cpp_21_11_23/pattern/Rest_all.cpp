
#include <bits/stdc++.h>
using namespace std;

void doublesidePyramid_patter8(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n - i; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < i - 1; j++)
        {
            cout << "*";
        }
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
      cout << endl;

    }
    // cout<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << " ";
        }
        for (int j = 0; j <2*n-(2*i+1); j++)
        {
            cout << "*";
        }
        for (int j = 0; j <= i; j++)
        {
            cout << " ";
        }
      cout << endl;

    }
}

void doublesidetriangle_pattern9(int n)
{

}
void pyramid(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            cout<<" ";
        }
        
        for (int j = 0; j < 2*i+1; j++)
        {
            cout<<"*";
        }

            for (int j = 0; j < n-i-1; j++)
        {
            cout<<" ";
        }
        
        cout<<endl;
    }
    
}

void pattern10(int n)
{
    for (int i = 0; i < n; i++){
        for (int j = 0; j <i; j++){
            cout<<"*";
        }

      
    cout<<endl;
    }
    for (int i = 0; i < n; i++){
           for (int j = 0; j <n-i-1; j++){
            cout<<"*";
        }

      
    cout<<endl;
    }
}

void pattern10_1(int n)
{
    for (int i = 0; i <= 2*n-1; i++){
       
        if(i<6)
        {
               for (int j = 0; j <i; j++){
                    cout<<"*";
                }
        }
        else
        {
               for (int j = 0; j <2*n-i; j++){
                    cout<<"*";
                }
        }

        cout<<endl;

    }
   
}

void pattern_11(int n)
{
   
    bool flag = 0;
   
    for (int i = 0; i <= n; i++){
         
        for (int j = 0; j < i; j++)
        {
            if(flag==0)
            {
            flag=1;
            cout<<flag;
            }
            else
            {
            flag=1;
            cout<<flag;
            }
        }
        cout<<endl;
        
    }
}

void pattern11(int n)
{
  
int start =1;
 for(int i=0;i <=n;i++)
 {
        if(i%2==0)
        {
                start =0;
        }
        else
        {
            start =1;
        }
        for (int j = 0; j < i; j++)
        {
            cout<<start;
            start=1-start;
            // start==1?start=0:start=1;

        }
        cout<<endl;
        
 }
}
int main()
{
    cout<<"0%2"<<0%2<<endl;
    int n = 5;
    // doublesidePyramid_patter8(n);
    // pyramid(n);
    // pattern10(n);
    // 
      (n);
    pattern11(n);


    return 0;
}