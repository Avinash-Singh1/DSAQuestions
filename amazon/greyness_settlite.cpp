
#include <bits/stdc++.h>
using namespace std;

int maxGreyness(const vector<string>& pixels) {
    int n =pixels.size();
    int m = pixels[0].size();
    vector<int>count_row1s(n,0);
    vector<int>count_col1s(m,0);
    vector<int>count_row0s(m,0);
    vector<int>count_col0s(n,0);
    
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            if(pixels[i][j] == '1'){
                count_row1s[i]++;
                count_col1s[j]++;
            }
            else{
                count_row0s[i]++;
                count_col0s[j]++;
            }
        }
    }
    int maxgrey=INT_MIN;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int curr= (count_row1s[i]+count_col1s[j])-(count_row0s[i]+count_col0s[j]);
            maxgrey=max(maxgrey,curr);
        }
    }
    return maxgrey;
}

int main() {
    vector<string> pixels = {
        "101",
        "100",
        "110"
    };

    int result = maxGreyness(pixels);
    cout << "Maximum Greyness: " << result << endl;

    return 0;
}
