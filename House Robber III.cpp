struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// returns {robThis, skipThis}
pair<int,int> dfs(TreeNode* root) {
    if (!root) return {0, 0};

    auto left = dfs(root->left);
    auto right = dfs(root->right);

    // If we rob this node, we cannot rob its children
    int robThis = root->val + left.second + right.second;

    // If we skip this node, we take the max of rob/skip from children
    int skipThis = max(left.first, left.second) + max(right.first, right.second);

    return {robThis, skipThis};
}

int getMaxReturns(TreeNode* root) {
    auto res = dfs(root);
    return max(res.first, res.second);
}
