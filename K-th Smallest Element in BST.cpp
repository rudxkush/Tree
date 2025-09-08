// inOrder (L-root-R) of any given BST is always going to be sorted.

int ans = 0, counter = 0;
void inOrderTraversal(TreeNode* root, int k) {
    	if (root == NULL) return;

    	inOrderTraversal(root->left, k);

    	counter++;
    	if (counter == k) {
     	   ans = root->val;
    	   return;    
}
    	inOrderTraversal(root->right, k);
}

int kthSmallest(TreeNode* root, int k) {
    	ans = 0; counter = 0;
    	inOrderTraversal(root, k);
    	return ans;
}
