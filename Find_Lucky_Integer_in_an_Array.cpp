/*1394. Find Lucky Integer in an Array
Given an array of integers arr, a lucky integer is an integer that has a frequency in the array equal to its value.

Return the largest lucky integer in the array. If there is no lucky integer return -1.*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    int findLucky(vector<int> &arr)
    {
        map<int, int> mp;
        int lucky_num = -1;

        for (int num : arr)
        {
            mp[num]++;
        }

        for (auto pair : mp)
        {
            if (pair.second == pair.first)
            {
                lucky_num = pair.first;
            }
        }

        return lucky_num;
    }
};

int main()
{
    Solution sol;

    // Sample test cases
    vector<int> arr1 = {2, 2, 3, 4};
    vector<int> arr2 = {1, 2, 2, 3, 3, 3};
    vector<int> arr3 = {2, 2, 2, 3, 3};
    vector<int> arr4 = {7, 7, 7, 7, 7, 7, 7}; // 7 appears 7 times -> lucky

    cout << "Test 1: " << sol.findLucky(arr1) << endl; // Output: 2
    cout << "Test 2: " << sol.findLucky(arr2) << endl; // Output: 3
    cout << "Test 3: " << sol.findLucky(arr3) << endl; // Output: -1
    cout << "Test 4: " << sol.findLucky(arr4) << endl; // Output: 7

    return 0;
}
