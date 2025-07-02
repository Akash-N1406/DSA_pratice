/*2099. Find Subsequence of Length K With the Largest Sum
You are given an integer array nums and an integer k. You want to find a subsequence of nums of length k that has the largest sum.

Return any such subsequence as an integer array of length k.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> maxSubsequence(vector<int> &nums, int k)
    {
        // Min-heap to keep the top k elements (value, index)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

        for (int i = 0; i < nums.size(); ++i)
        {
            minHeap.emplace(nums[i], i);
            if (minHeap.size() > k)
            {
                minHeap.pop();
            }
        }

        // Extract elements into a vector
        vector<pair<int, int>> topK;
        while (!minHeap.empty())
        {
            topK.push_back(minHeap.top());
            minHeap.pop();
        }

        // Sort by original index to maintain relative order
        sort(topK.begin(), topK.end(), [](const auto &a, const auto &b)
             { return a.second < b.second; });

        // Extract values
        vector<int> result;
        for (const auto &p : topK)
        {
            result.push_back(p.first);
        }

        return result;
    }
};

int main()
{
    Solution solution;

    // Example input
    vector<int> nums = {3, 5, 2, 9, 1};
    int k = 3;

    vector<int> result = solution.maxSubsequence(nums, k);

    // Output result
    cout << "Max subsequence of length " << k << ": ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
