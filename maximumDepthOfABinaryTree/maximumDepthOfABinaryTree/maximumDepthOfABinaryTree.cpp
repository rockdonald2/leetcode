#include <iostream>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode* root) {
    // ha a binary tree ures
    if (root == NULL) {
        return 0;
    }

    // elertunk egy leaf-hez
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }

    if (root->left == NULL) {
        return maxDepth(root->right) + 1;
    }

    if (root->right == NULL) {
        return maxDepth(root->left) + 1;
    }

    int lHeight = maxDepth(root->left);
    int rHeight = maxDepth(root->right);

    return (lHeight >= rHeight ? lHeight : rHeight) + 1;
}

int main() {

	return 0;
}