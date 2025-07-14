/*54. Spiral Matrix
Given an m x n matrix, return all elements of the matrix in spiral order.*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> result;
        int top = 0, bottom = m - 1, left = 0, right = n - 1;

        while (top <= bottom && left <= right)
        {
            for (int i = left; i <= right; i++)
                result.push_back(matrix[top][i]);
            top++;

            for (int i = top; i <= bottom; i++)
                result.push_back(matrix[i][right]);
            right--;

            if (top <= bottom)
            {
                for (int i = right; i >= left; i--)
                    result.push_back(matrix[bottom][i]);
                bottom--;
            }

            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                    result.push_back(matrix[i][left]);
                left++;
            }
        }

        return result;
    }
};

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    Solution sol;
    vector<int> spiral = sol.spiralOrder(matrix);

    cout << "Spiral Order: ";
    for (int num : spiral)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
