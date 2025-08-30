int rec(TreeNode* root, int& res) {
	// Base Condition
if(root == NULL) return 0;
	
	// Hypothesis
	int leftDiameter = rec(root->left, res);
	int rightDiameter = rec(root->right, res);
	
	// Induction
	// Height of current node
	int temp = 1 + max(leftDiameter, rightDiameter);

	// Diameter passing through current node
	int ans = 1 + leftDiameter + rightDiameter;

	res = max(res, ans); // updating global

	return temp;
}

int diameterBinaryTree(TreeNode* root) {
	int res = 0;
	rec(root, res);
	return res - 1; // as they have asked the number of edges
}
