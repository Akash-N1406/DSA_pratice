/*229. Majority Element II
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int ele1, ele2;
        int count1 = 0, count2 = 0;
        for (int num : nums)
        {
            if (count1 == 0 && num != ele2)
            {
                count1++;
                ele1 = num;
            }
            else if (count2 == 0 && num != ele1)
            {
                count2++;
                ele2 = num;
            }
            else if (num == ele1)
                count1++;
            else if (num == ele2)
                count2++;
            else
            {
                count1--;
                count2--;
            }
        }
        vector<int> ans;
        int n = nums.size();
        int target = (n / 3) + 1;
        count1 = 0;
        count2 = 0;
        for (int num : nums)
        {
            if (num == ele1)
                count1++;
            else if (num == ele2)
                count2++;
        }
        if (count1 >= target)
            ans.push_back(ele1);
        if (count2 >= target)
            ans.push_back(ele2);
        return ans;
    }
};

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    Solution sol;
    vector<int> result = sol.majorityElement(nums);

    cout << "Majority elements (more than n/3 times) are:\n";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
