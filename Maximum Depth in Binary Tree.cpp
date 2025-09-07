int rec(TreeNode* root) {
	if(root == NULL) return 0;
	int left = rec(root->left);
  	int right = rec(root->right);
	return 1 + max(left, right);
} 

int maxHeight(TreeNode* root) {
	return rec(root);
}
