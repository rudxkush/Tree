// Get the next (ascending) and the before (descending) elements from // the
// BST. Now apply the classic two-pointer two-sum logic on them to find the
// target. Time: O(n), Space: O(h)

class nextAndPrev {
private:
  stack<TreeNode *> st1, st2;
  void pushLeft(TreeNode *node) {
    while (node != NULL) {
      st1.push(node);
      node = node->left;
    }
  }

  void pushRight(TreeNode *node) {
    while (node != NULL) {
      st2.push(node);
      node = node->right;
    }
  }

public:
  void setUpBoth(TreeNode *root) {
    pushLeft(root);
    pushRight(root);
  }
  bool hasNext() { return !st1.empty(); }
  bool hasPrev() { return !st2.empty(); }
  int next() {
    TreeNode *node = st1.top();
    st1.pop();
    int val = node->val;
    if (node->right)
      pushLeft(node->right);
    return val;
  }

  int prev() {
    TreeNode *node = st2.top();
    st2.pop();
    int val = node->val;
    if (node->left)
      pushRight(node->left);
    return val;
  }
};
class twoSum {
public:
  bool findTarget(TreeNode *root, int target) {
    nextAndPrev itr;
    itr.setUpBoth(root);
    int i = itr.next();
    int j = itr.prev();

    while (i < j && itr.hasNext() && itr.hasPrev()) {
      if (i + j == target)
        return true;
      else if (i + j < target)
        i = itr.next();
      else
        j = itr.prev();
    }
    return false;
  }
};
