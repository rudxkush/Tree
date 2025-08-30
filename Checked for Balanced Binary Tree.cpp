int recCheck(TreeNode* root) {
	if(root == NULL) return 0;

	int left = recCheck(root->left);
	if(left == -1) return -1;
	int right = recCheck(root->right);
	if(right == -1) return -1;
	if(abs(left - right) > 1) return -1;

	return 1 + max(left, right);
}

bool checkBalance(TreeNode* root) {
	return recCheck(root) != -1;
}
