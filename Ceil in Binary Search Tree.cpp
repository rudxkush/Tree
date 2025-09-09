// The ceil of a key in a BST is the smallest value in the tree that // is greater than or equal to the key.

TreeNode* findCeil(TreeNode* root, int key) {
	  TreeNode* ans = NULL;
	  while(root != NULL) {
		  if(root->val == target) return root;
	    else if(root->val < target) {
		    root = root->right;
      } else {
	      ans = root;
	      root = root->left;
      }
    }
  return ans;
}

