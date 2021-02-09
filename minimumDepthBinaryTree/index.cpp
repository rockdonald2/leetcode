int _levels(TreeNode* node) {
    if (!node) {
        return 0;
    }
    
    int l{ 0 };
    int r{ 0 };
    
    if (node->left) {
        l += _levels(node->left);
    }
    
    if (node->right) {
        r += _levels(node->right);
    }
    
    if (l == 0) {
        return 1 + r;
    } else if (r == 0) {
        return 1 + l;
    } else {
        return 1 + (l <= r ? l : r);
    }
}

int minDepth(TreeNode* root) {
    return _levels(root);
}