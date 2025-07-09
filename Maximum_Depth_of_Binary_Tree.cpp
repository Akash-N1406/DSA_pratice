/*104. Maximum Depth of Binary Tree
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.*/

#include <iostream>
#include <algorithm> // for std::max

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return 1 + max(leftDepth, rightDepth);
    }
};

int main()
{
    // Create a sample tree:
    //      1
    //     / \
    //    2   3
    //   /
    //  4

    TreeNode *node4 = new TreeNode(4);
    TreeNode *node2 = new TreeNode(2, node4, nullptr);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *root = new TreeNode(1, node2, node3);

    Solution sol;
    int depth = sol.maxDepth(root);
    cout << "Maximum Depth of Tree: " << depth << endl;

    // Clean up memory
    delete node4;
    delete node2;
    delete node3;
    delete root;

    return 0;
}
