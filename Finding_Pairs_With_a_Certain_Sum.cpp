/*1865. Finding Pairs With a Certain Sum
You are given two integer arrays nums1 and nums2. You are tasked to implement a data structure that supports queries of two types:

Add a positive integer to an element of a given index in the array nums2.
Count the number of pairs (i, j) such that nums1[i] + nums2[j] equals a given value (0 <= i < nums1.length and 0 <= j < nums2.length).
Implement the FindSumPairs class:

FindSumPairs(int[] nums1, int[] nums2) Initializes the FindSumPairs object with two integer arrays nums1 and nums2.
void add(int index, int val) Adds val to nums2[index], i.e., apply nums2[index] += val.
int count(int tot) Returns the number of pairs (i, j) such that nums1[i] + nums2[j] == tot.*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class FindSumPairs
{
private:
    vector<int> num1;
    vector<int> num2;
    map<int, int> freqMp2;

public:
    FindSumPairs(vector<int> &nums1, vector<int> &nums2)
    {
        this->num1 = nums1;
        this->num2 = nums2;
        for (int n : nums2)
            freqMp2[n]++;
    }

    void add(int index, int val)
    {
        freqMp2[num2[index]]--;
        num2[index] += val;
        freqMp2[num2[index]]++;
    }

    int count(int tot)
    {
        int cnt = 0;
        for (int a : num1)
        {
            int b = tot - a;
            if (freqMp2.count(b))
            {
                cnt += freqMp2[b];
            }
        }
        return cnt;
    }
};

int main()
{
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {3, 4, 5};

    FindSumPairs *obj = new FindSumPairs(nums1, nums2);

    cout << "Initial count for total 7: " << obj->count(7) << endl; // Expecting 2 (1+6, 2+5, 3+4)

    obj->add(1, 1); // nums2 becomes {3, 5, 5}
    cout << "Count after add(1, 1) for total 7: " << obj->count(7) << endl;

    obj->add(0, 2); // nums2 becomes {5, 5, 5}
    cout << "Count after add(0, 2) for total 7: " << obj->count(7) << endl;

    delete obj;
    return 0;
}
