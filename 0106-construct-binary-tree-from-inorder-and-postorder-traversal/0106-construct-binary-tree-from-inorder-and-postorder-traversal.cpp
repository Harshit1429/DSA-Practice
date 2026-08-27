/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int> inorderIndex;
    int postIndex;

    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder,
                              int left, int right) {
        if(left > right) return nullptr;

        // Last element in postorder is root
        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        int idx = inorderIndex[rootVal];

        // IMPORTANT: build right subtree first
        root->right = buildTreeHelper(inorder, postorder, idx + 1, right);
        root->left  = buildTreeHelper(inorder, postorder, left, idx - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postIndex = postorder.size() - 1;

        for(int i = 0; i < inorder.size(); i++)
            inorderIndex[inorder[i]] = i;

        return buildTreeHelper(inorder, postorder, 0, inorder.size() - 1);
    }
};