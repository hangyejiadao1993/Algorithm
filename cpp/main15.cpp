#include <iostream>
#include <vector>
using namespace std;

/*
Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.
Example 1:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7
Target = 9
Output: True
Example 2:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7
Target = 28
Output: False
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

 class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        // One way is to convert the BST to a sorted list
        // and then find the two elements going
        // through the list
        if (root == NULL) {
            return false;
        }
        vector<int> v;
        preOrderTraversal(root, v);
        
        int startIdx = 0;
        int endIdx = v.size()-1;
        
        while (startIdx < endIdx) {
            if (v[startIdx] + v[endIdx] == k) {
                return true;
            }
            if (v[startIdx] + v[endIdx] > k) {
                endIdx -= 1;
            } else {
                startIdx += 1;
            }
        }
        return false;
    }
    
    void preOrderTraversal(TreeNode *root, vector<int>& v) {
        if (root == NULL) {
            return;
        }
        preOrderTraversal(root->left, v);
        v.push_back(root->val);
        preOrderTraversal(root->right, v);
    }
};

int main(int argc, char const *argv[])
{

    int arr[] = {2, 0, 3, -4, 1};

    for (size_t i = 0; i < 5; i++)
    {
        for (size_t j = i + 1; j < 5; j++)
        {

            if (arr[i] + arr[j] == -1)
            {
                cout << "True" << endl;
            }
        }
    }

    return 0;
}
