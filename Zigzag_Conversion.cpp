/*6. Zigzag Conversion
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1 || s.length() <= numRows)
            return s;
        vector<string> rows(numRows);
        int currentRow = 0;
        bool goingDown = false;
        for (char c : s)
        {
            rows[currentRow] += c;
            if (currentRow == 0 || currentRow == numRows - 1)
            {
                goingDown = !goingDown;
            }
            currentRow += goingDown ? 1 : -1;
        }
        string result = "";
        for (string ch : rows)
        {
            result += ch;
        }
        return result;
    }
};

int main()
{
    Solution sol;
    string input = "PAYPALISHIRING";
    int numRows = 3;

    string output = sol.convert(input, numRows);
    cout << "Converted string: " << output << endl;

    return 0;
}
