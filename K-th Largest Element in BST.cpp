// Another way of saying kth largest : (N - k)th Smallest
int ans = 0, counter = 0;
void reverseInOrder(TreeNode* root, int k) {
    if (!root) return;
    reverseInOrder(root->right, k);
    counter++;
    if (counter == k) {
        ans = root->val;
        return;
    }
    reverseInOrder(root->left, k);
}

int kthLargest(TreeNode* root, int k) {
    ans = 0; counter = 0;
    reverseInOrder(root, k);
    return ans;
}
