/*
		  iS      iE -> leftTree
Inorder   : [40, 20, 50] -> leftSide
             10, -> root 
            [60, 30] -> rightSide
             iS   iE -> rightTree
		   0   1   2   3   4   5 

Postorder : [[40, 50, 20], [60, 30], 10]

     10
   /   \
  20    30
 /  \   /
40  50 60
*/
TreeNode* buildTree(vector<int>& inOrder, 
    vector<int>& postOrder, 
    int postStart, int postEnd, 
    int inStart, int inEnd, 
    unordered_map<int, int>& inMap) {
    // postOrder -> inOrderIdx
	if (postStart > postEnd || inStart > inEnd) return NULL;
   	TreeNode* root = new TreeNode(postOrder[postEnd]);

    	int rootIndex = inMap[root->val];  // 3
    	int rightSize = inEnd - rootIndex; // 3 - 0 = 3 
	int leftSize = rootIndex - inStart;

root->left = buildTree(
        inOrder, postOrder,
        postStart, postStart + leftSize - 1,   // postorder left
        inStart, rootIndex - 1,                // inorder left
        inMap);

root->right = buildTree(
        inOrder, postOrder,
        postStart + leftSize, postEnd - 1,     // postorder right
        rootIndex + 1, inEnd,                  // inorder right
        inMap);

return root;
}
