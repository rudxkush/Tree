// The floor of a key in a BST is the greatest value in the tree that // is Smaller than or equal to the key.
TreeNode* findFloor(TreeNode* root, int key) {
    TreeNode* ans = NULL;
    while (root != NULL) {
        if (root->val == target)
            return root;
        else if (root->val < target) {
            ans = root;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return ans;
}
