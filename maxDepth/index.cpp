int maxDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    } else if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }
    
    int left = 0;
    if (root->left) {
        left = 1 + this->maxDepth(root->left);
    }
    
    int right = 0;
    if (root->right) {
        right = 1 + this->maxDepth(root->right);
    }
    
    return left > right ? left : right;
}