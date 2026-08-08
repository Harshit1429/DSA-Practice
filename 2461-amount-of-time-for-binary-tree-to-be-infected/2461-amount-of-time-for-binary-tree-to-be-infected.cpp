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

    unordered_map<TreeNode*, TreeNode*> parent;
    int ans = 0;

    int amountOfTime(TreeNode* root, int start) {

        TreeNode* startNode = buildParent(root, start);

        unordered_set<TreeNode*> vis;

        dfs(startNode, vis, 0);

        return ans;
    }

    // Create parent mapping and find start node
    TreeNode* buildParent(TreeNode* root, int start) {

        if (root == nullptr)
            return nullptr;

        TreeNode* startNode = nullptr;

        if (root->val == start)
            startNode = root;

        if (root->left != nullptr) {

            parent[root->left] = root;

            TreeNode* temp = buildParent(root->left, start);

            if (temp != nullptr)
                startNode = temp;
        }

        if (root->right != nullptr) {

            parent[root->right] = root;

            TreeNode* temp = buildParent(root->right, start);

            if (temp != nullptr)
                startNode = temp;
        }

        return startNode;
    }

    void dfs(TreeNode* node,
             unordered_set<TreeNode*>& vis,
             int time) {

        if (node == nullptr || vis.count(node))
            return;

        vis.insert(node);

        ans = max(ans, time);

        // Left
        dfs(node->left, vis, time + 1);

        // Right
        dfs(node->right, vis, time + 1);

        // Parent
        if (parent.count(node)) {
            dfs(parent[node], vis, time + 1);
        }
    }
};