/*4. Median of Two Sorted Arrays
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    vector<int> MergeandSort(vector<int> &nums1, vector<int> &nums2)
    {
        int i = 0, j = 0;
        vector<int> result;

        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] < nums2[j])
            {
                result.push_back(nums1[i++]);
            }
            else
            {
                result.push_back(nums2[j++]);
            }
        }
        while (i < nums1.size())
        {
            result.push_back(nums1[i++]);
        }
        while (j < nums2.size())
        {
            result.push_back(nums2[j++]);
        }
        return result;
    }

public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> result = MergeandSort(nums1, nums2);
        int len = result.size();
        if (len % 2 != 0)
        {
            return result[len / 2];
        }
        return (result[len / 2] + result[(len / 2) - 1]) / 2.0;
    }
};

int main(){
    Solution sol;
    vector<int> num1 = {1, 3};
    vector<int> num2 = {2};
    cout << "Median: " << sol.findMedianSortedArrays(num1, num2);
}
