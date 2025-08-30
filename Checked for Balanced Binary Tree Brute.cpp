int getHeight(TreeNode* root) {
	if(root == NULL) return 0;
	int left = getHeight(root->left);
  int right = getHeight(root->right);
	return 1 + max(left, right);
} 
bool recCheck(TreeNode* root) {
	if(root == NULL) return true;
	int left = getHeight(root->left);
	int right = getHeight(root->right);
	
	if(abs(left - right) > 1) return false;

  bool isLeftBalanced = recCheck(root->left); 
  bool isRightBalanced = recCheck(root->right);
  return isLeftBalanced && isRightBalanced;
}
bool checkBalance(TreeNode* root) {
	return recCheck(root);
}

