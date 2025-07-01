/*3. Longest Substring Without Repeating Characters
Given a string s, find the length of the longest substring without duplicate characters.*/

#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> seen;
        int left = 0, right = 0;
        int maxLength = 0;

        while (right < s.size())
        {
            if (seen.find(s[right]) == seen.end())
            {
                seen.insert(s[right]);
                maxLength = max(maxLength, right - left + 1);
                right++;
            }
            else
            {
                seen.erase(s[left]);
                left++;
            }
        }

        return maxLength;
    }
};

int main()
{
    Solution sol;

    string input1 = "abcabcbb";
    cout << "Input: " << input1 << endl;
    cout << "Output: " << sol.lengthOfLongestSubstring(input1) << endl;

    string input2 = "bbbbb";
    cout << "Input: " << input2 << endl;
    cout << "Output: " << sol.lengthOfLongestSubstring(input2) << endl;

    string input3 = "pwwkew";
    cout << "Input: " << input3 << endl;
    cout << "Output: " << sol.lengthOfLongestSubstring(input3) << endl;

    string input4 = "";
    cout << "Input: (empty string)" << endl;
    cout << "Output: " << sol.lengthOfLongestSubstring(input4) << endl;

    return 0;
}
