/*268. Missing Number
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int sum = n * (n + 1) / 2;
        int numSum = 0;
        for (int num : nums)
            numSum += num;
        return sum - numSum;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {3, 0, 1}; // Example input; missing number is 2
    int result = sol.missingNumber(nums);
    cout << "Missing number: " << result << endl;
    return 0;
}
