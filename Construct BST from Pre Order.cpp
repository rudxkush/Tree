// Brute: create a node on this index and then split the left and 
// right part to create the rest .
TreeNode* constructBST(vector<int>& preOrder, int start, int end) {
    if (start > end) return NULL;
    TreeNode* root = new TreeNode(preOrder[start]);
    int j = start + 1;
    while (j <= end && preOrder[j] < preOrder[start]) 
        j++;
    
    root->left = constructBST(preOrder, start + 1, j - 1);
    root->right = constructBST(preOrder, j, end);
    return root;
}

TreeNode* conversion(vector<int>& preOrder) {
    if (preOrder.empty()) return NULL;
    return constructBST(preOrder, 0, preOrder.size() - 1);
}

// Better: Generate the inOrder by sorting the preOrder given and 
// then using the already explained BT construction Code.

// Optimal: Use the upper bound and use this logic:
// parent[-inf, +inf] 
// left[-inf, parent->val]
// right[parent->val, inf]   

TreeNode* constructBST(vector<int>& preOrder, int& i, int upperBound) {
	if(i == preOrder.size() || preOrder[i] > upperBound) return ;
    	
	TreeNode* root = new TreeNode(preOrder[i++]);
	root->left = constructBST(preOrder, i, root->val);
	root->right = constructBST(preOrder, i, upperBound);
	return root;
}
TreeNode* conversion(vector<int>& preOrder) {
    int i = 0;
    return constructBST(preOrder, i, INT_MAX);
}
