/*39. Combination Sum
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(candidates, target, 0, current, result);
        return result;
    }

private:
    void backtrack(vector<int> &candidates, int target, int start, vector<int> &current, vector<vector<int>> &result)
    {
        if (target == 0)
        {
            result.push_back(current);
            return;
        }

        if (target < 0)
            return;

        for (int i = start; i < candidates.size(); ++i)
        {
            current.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i, current, result);
            current.pop_back();
        }
    }
};

int main()
{
    Solution sol;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> combinations = sol.combinationSum(candidates, target);

    cout << "Combinations that sum to " << target << ":\n";
    for (const auto &combination : combinations)
    {
        cout << "[ ";
        for (int num : combination)
        {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
