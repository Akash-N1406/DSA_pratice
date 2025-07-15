/*493. Reverse Pairs
Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:

0 <= i < j < nums.length and
nums[i] > 2 * nums[j].*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    void merge(vector<int> &nums, int start, int mid, int end)
    {
        int i = start;
        int j = mid + 1;
        vector<int> temp;
        while (i <= mid && j <= end)
        {
            if (nums[i] < nums[j])
            {
                temp.push_back(nums[i]);
                i++;
            }
            else
            {
                temp.push_back(nums[j]);
                j++;
            }
        }
        while (i <= mid)
        {
            temp.push_back(nums[i]);
            i++;
        }
        while (j <= end)
        {
            temp.push_back(nums[j]);
            j++;
        }
        for (int k = 0; k < temp.size(); k++)
            nums[start + k] = temp[k];
    }

    int countPairs(vector<int> &nums, int start, int mid, int end)
    {
        int count = 0;
        int right = mid + 1;
        for (int i = start; i <= mid; i++)
        {
            while (right <= end && (long long)nums[i] > 2LL * nums[right])
                right++;
            count += right - (mid + 1);
        }
        return count;
    }

    int mergeSort(vector<int> &nums, int start, int end)
    {
        int count = 0;
        if (start >= end)
            return count;
        int mid = start + (end - start) / 2;
        count += mergeSort(nums, start, mid);
        count += mergeSort(nums, mid + 1, end);
        count += countPairs(nums, start, mid, end);
        merge(nums, start, mid, end);
        return count;
    }

public:
    int reversePairs(vector<int> &nums)
    {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {1, 3, 2, 3, 1};
    cout << "Input: {1, 3, 2, 3, 1}" << endl;
    cout << "Reverse Pairs: " << sol.reversePairs(nums) << endl;

    vector<int> nums2 = {2, 4, 3, 5, 1};
    cout << "Input: {2, 4, 3, 5, 1}" << endl;
    cout << "Reverse Pairs: " << sol.reversePairs(nums2) << endl;

    return 0;
}
