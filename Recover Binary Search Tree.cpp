struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* firstNode = NULL;
TreeNode* secondNode = NULL;
TreeNode* prevNode = new TreeNode(INT_MIN);

void inorder(TreeNode* root) {
    if (!root) return;

    inorder(root->left);

    // Detect inversion
    if (prevNode && prevNode->val > root->val) {
        if (firstNode == NULL) firstNode = prevNode;
        secondNode = root;
    }
    prevNode = root;

    inorder(root->right);
}

void recoverTree(TreeNode* root) {
    inorder(root);
    if (firstNode && secondNode) swap(firstNode->val, secondNode->val);
}
