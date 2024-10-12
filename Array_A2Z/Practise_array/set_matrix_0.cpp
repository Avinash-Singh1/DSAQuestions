
#include <bits/stdc++.h>
using namespace std;
void setrow_Zero(vector<vector<int>> &matrix, int row, int col, int i)
{
    for (int j = 0; j < col; j++)
    {
        if (matrix[i][j] != 0)
        {
            matrix[i][j] = -1;
        }
    }
}
void setcol_Zero(vector<vector<int>> &matrix, int row, int col,int j)
{
    for (int i = 0; i < col; i++)
    {
        if (matrix[i][j] != 0)
        {
            matrix[i][j] = -1;
        }
    }
}
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int row, int col)
{

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == 0)
            {
                setrow_Zero(matrix, row, col, i);
                setcol_Zero(matrix, row, col, j);
            }
        }
    }

    // convert the -1 to 0
    
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j]=0;
            }
        }
    }
    return matrix;

}

int main()
{
    vector<vector<int>> matrix = {{1, 1,1, 1}, {1, 0,1, 1}, {1, 1, 1,0},{1, 1, 1,0}};
    int n = matrix.size();
    int m = matrix[0].size();
    cout<<m<<n<<endl;
     for (auto it : matrix)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << "\n";
    }
    vector<vector<int>> ans = zeroMatrix(matrix, n, m);

    cout << "The Final matrix is: n\n";
    for (auto it : ans)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << "\n";
    }
    return 0;
}
