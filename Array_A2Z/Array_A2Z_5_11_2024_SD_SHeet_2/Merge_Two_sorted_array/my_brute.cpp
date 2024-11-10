#include<vector>

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
	// Write your code here.
	int i=0,j=0;
	int n =a.size();
	int m =b.size();
	vector<int>ans;
	while(i<n && j<m){
		 if(a[i]<=b[j]){
			ans.push_back(a[i]);;
			i++;
		}else{
			ans.push_back(b[j]);;
			j++;
		}
	}

	while(i<n){
		ans.push_back(a[i]);;
			i++;
	}
	while(j<m){
			ans.push_back(b[j]);;
			j++;
	}

	  for (int i = 0; i < n + m; i++) {
        if (i < n) a[i] = ans[i];
        else b[i - n] = ans[i];
    }
	
	
}