#include "common.h"
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    //迭代求解，但是只适用于一般情况
    TreeNode* search(TreeNode* root,int val) {
        if (root == nullptr) return nullptr;
        queue<TreeNode*> Q;
        Q.push(root);
        int ans = 0;
        // 深度计算，+1
        while (!Q.empty()) {
            int sz = (int)Q.size();
            // 搜索子节点
            while (sz > 0) {
                TreeNode* node = Q.front(); Q.pop();

				if (node->val == val) return node;

                if (node->left) Q.push(node->left);
                if (node->right) Q.push(node->right);
                sz -= 1;
            }
        }
        return nullptr;
    }

	//迭代求解，在搜索BST时有更好的性能
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root) {
            if (val == root->val) {
                return root;
            }
            root = val < root->val ? root->left : root->right;
        }
        return nullptr;
    }
};
Solution solution;


int main() {
    TreeNode* node5 = new TreeNode(5); TreeNode* node6 = new TreeNode(6);
    TreeNode* node3 = new TreeNode(3); TreeNode* node4 = new TreeNode(4, node5, node6);
    TreeNode* node7 = new TreeNode(7); TreeNode* node2 = new TreeNode(2, node3, node4);
    TreeNode* node1 = new TreeNode(1, node2, node7);

	solution.search(node1, 4);

}

/*
* 注意二叉搜索树的性质：
* 左子树的值小于根节点的值，右子树的值大于根节点的值。
* 
* 
* 示例：这是非二叉搜索树，只能用广度优先搜索
*               1
*             ↙ ↘
*           2       7
*         ↙ ↘
*       3       4
*             ↙ ↘
*           5       6
*
* 
* 
* 
*/