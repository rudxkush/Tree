bool inOrderCheck(TreeNode* root, long long &prev) {
    	if (root == NULL) return true;
    	if (!inOrderCheck(root->left, prev)) return false;

    	if (root->val <= prev) return false;
    	prev = root->val;

    	if (!inOrderCheck(root->right, prev)) return false;
	    return true;
}

bool checkBST(TreeNode* root) {
      long long prev = LLONG_MIN; 
      return inOrderCheck(root, prev);
}
