// ITERATIVE O(n), O(n)
bool searchInBT(TreeNode* root, int target) {
	  if(root == NULL) return false;
	  if(root->val == target) return true;  
	  if(root->val < target) 
      return searchInBT(root->left);
	  else 
      return searchInBT(root->right);
}
// ITERATIVE O(n), O(1)
TreeNode* searchInBT(TreeNode* root, int target) {
    while(root != NULL && root->val != target) {
	    if(root->val < target) {
		    root = root->right;
      } else {
        root = root->left;
      }
    }	
  return root;
}
