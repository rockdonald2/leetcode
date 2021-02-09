int _levels(TreeNode* node) {
    if (!node) {
        return 0;
    }
        
    int left{ 0 };
    int right{ 0 };
        
    if (node->left) {
        left += _levels(node->left);
    }
        
    if (node->right) {
        right += _levels(node->right);
    }
        
    return 1 + (left >= right ? left : right);
}

bool isBalanced(TreeNode* root) {
    if (!root) return true;
        
    int lh { _levels(root->left) };
    int rh { _levels(root->right) };
        
    if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right)) {
        return true;
    } 
        
    return false;
}

int main() {

    return 0;
}