/*118. Pascal's Triangle
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    vector<int> getRow(int row)
    {
        vector<int> rowNum;
        rowNum.push_back(1);
        int num = 1;
        for (int col = 1; col < row; col++)
        {
            num = num * (row - col);
            num /= col;
            rowNum.push_back(num);
        }
        return rowNum;
    }

public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;
        for (int i = 1; i <= numRows; i++)
        {
            ans.push_back(getRow(i));
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    int numRows;
    cout << "Enter number of rows: ";
    cin >> numRows;

    vector<vector<int>> result = sol.generate(numRows);

    cout << "Pascal's Triangle:" << endl;
    for (const auto &row : result)
    {
        for (int num : row)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
