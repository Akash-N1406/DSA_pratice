/*2566. Maximum Difference by Remapping a Digit
You are given an integer num. You know that Bob will sneakily remap one of the 10 possible digits (0 to 9) to another digit.

Return the difference between the maximum and minimum values Bob can make by remapping exactly one digit in num.

Notes:

When Bob remaps a digit d1 to another digit d2, Bob replaces all occurrences of d1 in num with d2.
Bob can remap a digit to itself, in which case num does not change.
Bob can remap different digits for obtaining minimum and maximum values respectively.
The resulting number after remapping can contain leading zeroes.*/

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int minMaxDifference(int num)
    {
        string str_num = to_string(num);
        string str_max = str_num;
        string str_min = str_num;

        for (char &c : str_num)
        {
            if (c != '9')
            {
                for (char &ch : str_max)
                {
                    if (ch == c)
                    {
                        ch = '9';
                    }
                }
                break;
            }
        }

        for (char &c : str_num)
        {
            if (c != '0')
            {
                for (char &ch : str_min)
                {
                    if (ch == c)
                    {
                        ch = '0';
                    }
                }
                break;
            }
        }

        return stoi(str_max) - stoi(str_min);
    }
};

int main()
{
    Solution sol;

    int num = 9288;
    int result = sol.minMaxDifference(num);

    cout << "Input: " << num << endl;
    cout << "Min-Max Difference: " << result << endl;

    return 0;
}
