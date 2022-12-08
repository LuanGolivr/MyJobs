#include <cstddef>

/*
    Time complexity: O(N * M)
    Space complexity: O(N)
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    bool ans = false;

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot) return true;
        if(!root) return false;

        if(dfs(root, subRoot)) return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

private:
    bool dfs(TreeNode* root, TreeNode* subRoot){
        if(!root && !subRoot){
            return true;
        }

        if(root == NULL || subRoot == NULL){
            return false;
        }

        if(root->val != subRoot->val){
            return false;
        }

        if(!dfs(root->left, subRoot->left) || !dfs(root->right, subRoot->right)){
            return false;
        }

        return true;
    }
};