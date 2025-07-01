/*206. Reverse Linked List
Given the head of a singly linked list, reverse the list, and return the reversed list.*/

#include <iostream>
#include <vector>
using namespace std;

// Definition of ListNode as given
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;

        while (curr != nullptr)
        {
            ListNode *nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }

        return prev;
    }
};

// Helper function to print the linked list
void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a linked list from a vector of values
ListNode *createList(const vector<int> &vals)
{
    if (vals.empty())
        return nullptr;
    ListNode *head = new ListNode(vals[0]);
    ListNode *current = head;
    for (size_t i = 1; i < vals.size(); ++i)
    {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    return head;
}

int main()
{
    vector<int> values = {1, 2, 3, 4, 5};
    ListNode *head = createList(values);

    cout << "Original List: ";
    printList(head);

    Solution solution;
    ListNode *reversedHead = solution.reverseList(head);

    cout << "Reversed List: ";
    printList(reversedHead);

    return 0;
}
