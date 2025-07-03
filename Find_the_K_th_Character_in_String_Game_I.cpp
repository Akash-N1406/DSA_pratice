/*Find the K-th Character in String Game I
Alice and Bob are playing a game. Initially, Alice has a string word = "a".

You are given a positive integer k.

Now Bob will ask Alice to perform the following operation forever:

Generate a new string by changing each character in word to its next character in the English alphabet, and append it to the original word.
For example, performing the operation on "c" generates "cd" and performing the operation on "zb" generates "zbac".

Return the value of the kth character in word, after enough operations have been done for word to have at least k characters.

Note that the character 'z' can be changed to 'a' in the operation.*/

#include <iostream>
using namespace std;

class Solution
{
public:
    char kthCharacter(int k)
    {
        k -= 1;
        int transformations = __builtin_popcount(k);
        return 'a' + (transformations % 26);
    }
};

int main()
{
    Solution sol;
    int k;

    cout << "Enter a value for k: ";
    cin >> k;

    char result = sol.kthCharacter(k);
    cout << "The kth character is: " << result << endl;

    return 0;
}
