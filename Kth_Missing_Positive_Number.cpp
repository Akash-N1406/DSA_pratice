/*1539. Kth Missing Positive Number
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Return the kth positive integer that is missing from this array.*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int left = 0, right = arr.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int missing = arr[mid] - (mid + 1);
            if (missing < k)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left + k;
    }
};

int main()
{
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;

    Solution sol;
    int result = sol.findKthPositive(arr, k);

    cout << "The " << k << "th missing positive number is: " << result << endl;

    return 0;
}
