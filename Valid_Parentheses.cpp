/*20. Valid Parentheses
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

1.Open brackets must be closed by the same type of brackets.
2.Open brackets must be closed in the correct order.
3.Every close bracket has a corresponding open bracket of the same type.*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        if (s.size() % 2 != 0)
        {
            return false;
        }
        for (char ch : s)
        {
            if (ch == '(' || ch == '[' || ch == '{')
            {
                st.push(ch);
            }
            else
            {
                if (st.empty())
                    return false;

                char top = st.top();
                if ((ch == ')' && top != '(') ||
                    (ch == ']' && top != '[') ||
                    (ch == '}' && top != '{'))
                {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};

int main()
{
    Solution sol;
    string testCases[] = {
        "()",
        "()[]{}",
        "(]",
        "([)]",
        "{[]}",
        "",
        "[({})]",
        "((((",
        "(()))"};

    for (const string &test : testCases)
    {
        cout << "Input: " << test << " -> Output: "
             << (sol.isValid(test) ? "true" : "false") << endl;
    }

    return 0;
}
