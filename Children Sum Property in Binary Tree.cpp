void rec(TreeNode* root) {
    if(root == NULL) return;

    int left = (root->left) ? root->left->val : 0;
    int right = (root->right) ? root->right->val : 0;

    if(left + right >= root->val) {
        root->val = left + right;
    } else {
        if(root->left) root->left->val = root->val;
        if(root->right) root->right->val = root->val;
    }

    rec(root->left);
    rec(root->right);

    int total = (root->left ? root->left->val : 0) + 
                (root->right ? root->right->val : 0);

    if(total >= root->val) root->val = total;
}

TreeNode* CSP(TreeNode* root) {
    rec(root);
    return root;
}
