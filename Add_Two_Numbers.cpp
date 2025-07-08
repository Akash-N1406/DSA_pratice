/*2. Add Two Numbers
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.*/

#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// The Solution class with addTwoNumbers
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *result = new ListNode();
        ListNode *current = result;
        int carry = 0;
        while (l1 || l2 || carry)
        {
            int sum = carry;
            if (l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
        }
        return result->next;
    }
};

// Helper function to create a linked list from a vector of digits
ListNode *createList(const vector<int> &digits)
{
    ListNode *dummy = new ListNode();
    ListNode *current = dummy;
    for (int digit : digits)
    {
        current->next = new ListNode(digit);
        current = current->next;
    }
    return dummy->next;
}

// Helper function to print a linked list
void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // Representing the numbers 342 and 465 as linked lists (in reverse order)
    vector<int> num1 = {2, 4, 3}; // represents 342
    vector<int> num2 = {5, 6, 4}; // represents 465

    ListNode *l1 = createList(num1);
    ListNode *l2 = createList(num2);

    Solution solution;
    ListNode *result = solution.addTwoNumbers(l1, l2);

    cout << "Result: ";
    printList(result); // Expected output: 7 -> 0 -> 8 (i.e., 807)

    return 0;
}
