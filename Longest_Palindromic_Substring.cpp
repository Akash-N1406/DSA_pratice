/*5. Longest Palindromic Substring
Given a string s, return the longest palindromic substring in s.*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        if (n == 0)
            return "";

        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int maxLength = 1;
        int start = 0;

        // Substrings of length 1
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = true;
        }

        // Substrings of length 2
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = true;
                start = i;
                maxLength = 2;
            }
        }

        // Substrings of length >= 3
        for (int len = 3; len <= n; len++)
        {
            for (int i = 0; i <= n - len; i++)
            {
                int j = i + len - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1])
                {
                    dp[i][j] = true;
                    if (len > maxLength)
                    {
                        start = i;
                        maxLength = len;
                    }
                }
            }
        }

        return s.substr(start, maxLength);
    }
};

int main()
{
    Solution sol;

    // Test case 1
    string input1 = "babad";
    cout << "Input: " << input1 << endl;
    cout << "Longest Palindromic Substring: " << sol.longestPalindrome(input1) << endl;

    // Test case 2
    string input2 = "cbbd";
    cout << "\nInput: " << input2 << endl;
    cout << "Longest Palindromic Substring: " << sol.longestPalindrome(input2) << endl;

    // Test case 3
    string input3 = "a";
    cout << "\nInput: " << input3 << endl;
    cout << "Longest Palindromic Substring: " << sol.longestPalindrome(input3) << endl;

    // Test case 4
    string input4 = "ac";
    cout << "\nInput: " << input4 << endl;
    cout << "Longest Palindromic Substring: " << sol.longestPalindrome(input4) << endl;

    return 0;
}
