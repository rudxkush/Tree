class nodeValue{
public:
	  int minVal, maxVal, maxSize;
  	nodeValue(int minVal, int maxVal, int maxSize) {
  		this->minVal = minVal;
  		this->maxVal = maxVal;
  		this->maxSize = maxSize;
  }
}
nodeValue postOrder(TreeNode* root) {
	  if(root == NULL) return nodeValue(INT_MAX, INT_MIN, 0);

  	auto left = postOrder(root->left);
  	auto right = postOrder(root->right);
  
  	if(root->val > left.maxVal && root->val < right.minVal) {
  		  return nodeValue(min(root->val, left.minVal),
                        max(root->val, right.maxVal),
                        left.maxSize + right.maxSize + 1);
    }
  return nodeValue(INT_MIN,INT_MAX, max(left.maxSize, right.maxSize));
}

int findLargestBstInBt(TreeNode* root) {
	  return postOrder(root).maxSize;	
}
