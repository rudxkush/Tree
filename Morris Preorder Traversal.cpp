vector<int> getPreOrder(TreeNode* root) {
    vector<int> res;
    TreeNode* curr = root;

    while (curr != NULL) {
        if (curr->left == NULL) {
            res.push_back(curr->val);
            curr = curr->right;
        } else {
            TreeNode* prev = curr->left;
            while (prev->right != NULL && prev->right != curr) {
                prev = prev->right;
            }
            if (prev->right == NULL) {
                res.push_back(curr->val); // visit before going left
                prev->right = curr;
                curr = curr->left;
            } else {
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }
    return res;
}
