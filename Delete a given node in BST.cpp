TreeNode* findRightMostInLeft(TreeNode* node) {
    while(node->right != NULL) {
        node = node->right;
    }
    return node;
}

TreeNode* helper(TreeNode* parent) {
    if(parent->left == NULL) return parent->right;
    else if(parent->right == NULL) return parent->left;
    TreeNode* leftChild = parent->left;
    TreeNode* rightMost = findRightMostInLeft(leftChild);
    rightMost->right = parent->right;
    return leftChild;
}

TreeNode* deleteFromBST(TreeNode* root, int key) {
    if(root == NULL) return NULL;
    if(root->val == key) 
        return helper(root);

    TreeNode* temp = root;
    while(root != NULL) {
        if(root->val > key) {
            if(root->left != NULL && root->left->val == key) {
                root->left = helper(root->left);
                break;
            } else {
                root = root->left;
            }
        } else {
            if(root->right != NULL && root->right->val == key) {
                root->right = helper(root->right);
                break;
            } else {
                root = root->right;
            }
        }
    }
    return temp;
}
