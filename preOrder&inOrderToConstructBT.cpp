/*
Requirements needed to construct a Unique Binary Tree
		  iS      iE -> leftTree
Inorder   : [40, 20, 50] -> leftSide
             10, -> root 
            [60, 30] -> rightSide
             iS   iE -> rightTree
		   0   1   2   3   4   5 
Preorder  : [10, -> root
			  pS      pE -> left
                 [20, 40, 50,] -> left 
[30, 60] -> right
pS   pE

     10
   /   \
  20    30
 /  \   /
40  50 60
*/
TreeNode* buildTree(vector<int>& inOrder, 
      vector<int>& preOrder, 
      int preStart, int preEnd, 
      int inStart, int inEnd, 
      unordered_map<int, int>& inMap) {
           // preOrder -> inOrderIdx
        	if (preStart > preEnd || inStart > inEnd) return NULL;
       	  TreeNode* root = new TreeNode(preOrder[preStart]);
    
        	int rootIndex = inMap[root->val];  // 3
        	int leftSize = rootIndex - inStart; // 3 - 0 = 3 
    
          root-> left = buildTree(inOrder, preOrder, preStart + 1, preStart + leftSize, inStart, rootIndex - 1, inMap);
          root->right = buildTree(inOrder, preOrder, preStart + leftSize + 1, preEnd, rootIndex + 1, inEnd, inMap);	
          return root;
}
