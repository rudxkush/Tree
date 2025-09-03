// Best case (perfect tree): O(log² n)
// Worst case (skew tree): O(n²)
int getHeight(TreeNode* root, bool isLeft) {
    int h = 0;
    while (root) {
        h++;
        root = (isLeft ? root->left : root->right);
    }
    return h;
}

void rec(TreeNode* root, int& countNodes) {
    if (!root) return;

    int left = getHeight(root, true);
    int right = getHeight(root, false);

    if (left == right) {
        countNodes += (1 << left) - 1;
        return;
    }

    countNodes++;
    rec(root->left, countNodes);
    rec(root->right, countNodes);
}

int totalNodes(TreeNode* root) {
    int countNodes = 0;
    rec(root, countNodes);
    return countNodes;
}
