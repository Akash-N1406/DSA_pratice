/*34. Find First and Last Position of Element in Sorted Array
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int findFirst(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        int ans = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {
                if (ans == -1)
                    ans = mid;
                ans = min(ans, mid);
                high = mid - 1;
            }
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return ans;
    }

    int findLast(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        int ans = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {
                if (ans == -1)
                    ans = mid;
                ans = max(ans, mid);
                low = mid + 1;
            }
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return ans;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int first = findFirst(nums, target);
        if (first == -1)
            return {-1, -1};
        int last = findLast(nums, target);
        return {first, last};
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> result = sol.searchRange(nums, target);

    cout << "First and Last Position of " << target << ": ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
