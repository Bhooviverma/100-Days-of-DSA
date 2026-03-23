struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    // If both p and q are smaller → go left
    if (p->val < root->val && q->val < root->val)
        return lowestCommonAncestor(root->left, p, q);

    // If both p and q are greater → go right
    if (p->val > root->val && q->val > root->val)
        return lowestCommonAncestor(root->right, p, q);

    // Otherwise → this is the split point (LCA)
    return root;
}