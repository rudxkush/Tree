// it might be this node’s right lies both the node or on left
// or it might be one is on the left and the other is on the right.
TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q) {
	while(true) {
    if(root->val > p->val && root->val > q->val) {
      root = root->left;
    } else if(root->val < p->val && root->val < q->val) {
      root = root->right;
    } else {
    	return root;
    }
  }
}
