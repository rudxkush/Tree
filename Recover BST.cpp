// Optimal: Time - O(n), space - O(h)
TreeNode *first = NULL, second = NULL, prev = NULL;
void inOrderSwapCorrection(TreeNode *root) {
  if (root == NULL)
    return;

  inOrderSwapCorrection(root->left);
  if (prev != NULL && root->val < prev->val) {
    if (first == NULL) {
      first = prev;
    } else {
      second = root;
    }
  }
  prev = root;
  inOrderSwapCorrection(root->right);
}
TreeNode *recoverBst(TreeNode *root) {
  first = second = prev = NULL;
  inOrderSwapCorrection(root);
  if (first && second)
    swap(first->val, second->val);
  return root;
}
