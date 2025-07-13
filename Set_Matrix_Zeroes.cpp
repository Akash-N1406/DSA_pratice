/*73. Set Matrix Zeroes
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int col0 = 1;
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    if (j != 0)
                        matrix[0][j] = 0;
                    else
                        col0 = 0;
                }
            }
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        if (matrix[0][0] == 0)
        {
            for (int j = 1; j < n; j++)
            {
                matrix[0][j] = 0;
            }
        }

        if (col0 == 0)
        {
            for (int i = 0; i < m; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}};

    cout << "Original Matrix:\n";
    for (auto row : matrix)
    {
        for (auto val : row)
            cout << val << " ";
        cout << endl;
    }

    sol.setZeroes(matrix);

    cout << "\nMatrix after setZeroes:\n";
    for (auto row : matrix)
    {
        for (auto val : row)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}
