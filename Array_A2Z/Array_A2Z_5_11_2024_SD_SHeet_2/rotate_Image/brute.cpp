class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        // brute
        int n =matrix.size();
        vector<vector<int>>dummy = matrix;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dummy[j][n-i-1]=matrix[i][j];
            }
        }
        // return dummy;
        matrix=dummy;
    }
};