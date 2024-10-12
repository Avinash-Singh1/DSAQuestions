#pragma GCC optimize("Ofast","unroll-loops","-ffast-math","march=native")
#include <bits/stdc++.h>
#include <vector>
#include <sstream>
#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;
typedef long double ld;
#define SZ 1234567
typedef long long ll;
const int MOD=998244353;
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define all(c) (c).begin(), (c).end()
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fi first
#define se second
ll gcdmul[50005];
ll qz[50005];
class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int S=1;
        for(auto t:nums) S=max(S,t+1);
        for(int i=0;i<S;++i)  {
            gcdmul[i]=0;
        }
        for(auto t:nums) ++gcdmul[t];
        for(int i=1;i<S;++i) {
            int tt=0;
            for(int j=i;j<S;j+=i) tt+=gcdmul[j];
            gcdmul[i]=(ll)tt*(tt-1)/2;
        }
        for(int i=S-1;i>=1;--i) {
            for(int j=i+i;j<S;j+=i) {
                gcdmul[i]-=gcdmul[j];
            }
        }
        for(int i=1;i<S;++i) {
            qz[i]=qz[i-1]+gcdmul[i];
        }
        vector<int> res;
        for(auto t:queries) {
            res.push_back(lower_bound(qz+1,qz+S,t+1)-qz);
        }
        return res;
    }
};