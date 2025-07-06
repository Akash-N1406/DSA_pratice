/*678. Valid Parenthesis String
Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".*/

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool checkValidString(string s)
    {
        int low = 0;
        int high = 0;
        for (char ch : s)
        {
            if (ch == '(')
            {
                low++;
                high++;
            }
            else if (ch == ')')
            {
                low--;
                high--;
            }
            else
            {         
                low--;  
                high++; 
            }
            if (high < 0)
            {
                return false; 
            }
            if (low < 0)
            {
                low = 0; 
            }
        }
        return low == 0;
    }
};

int main()
{
    Solution sol;

    // Test cases
    string s1 = "(*))";
    string s2 = "(*()";
    string s3 = "(*)))";
    string s4 = "(*))(";
    string s5 = "((*)";
    string s6 = "(()*";
    string s7 = "(((******))";

    cout << boolalpha;                                      
    cout << "Test 1: " << sol.checkValidString(s1) << endl; 
    cout << "Test 2: " << sol.checkValidString(s2) << endl;  
    cout << "Test 3: " << sol.checkValidString(s3) << endl; 
    cout << "Test 4: " << sol.checkValidString(s4) << endl;  
    cout << "Test 5: " << sol.checkValidString(s5) << endl;  
    cout << "Test 6: " << sol.checkValidString(s6) << endl;  
    cout << "Test 7: " << sol.checkValidString(s7) << endl;  

    return 0;
}
