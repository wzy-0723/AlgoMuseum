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
    void dfs(TreeNode* node, vector<int>& seq) {
        if (nullptr == node) return;
        if (!node->left && !node->right) {
            seq.push_back(node->val);
        }
        else {
            if (node->left) {
                dfs(node->left, seq);
            }
            if (node->right) {
                dfs(node->right, seq);
            }
        }
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> seq1, seq2;
        dfs(root1, seq1);
        dfs(root2, seq2);
        return seq1 == seq2;
    }
};
Solution solution;


int main() {
    TreeNode* node5 = new TreeNode(5); TreeNode* node6 = new TreeNode(6);
    TreeNode* node3 = new TreeNode(3); TreeNode* node4 = new TreeNode(4, node5, node6);
    TreeNode* node7 = new TreeNode(7); TreeNode* node2 = new TreeNode(2, node3, node4);
    TreeNode* node1 = new TreeNode(1, node2, node7);

    cout << "leafSimilar：" << solution.leafSimilar(node1, node2);
    
}

/*
* 示例：
*               1
*             ↙ ↘
*           2       7
*         ↙ ↘     
*       3       4       
*             ↙ ↘
*           5       6
*
* 取该树根1为root1，该树的子节点2为root2
* 不能迭代求解叶子序列，因为得出的序列不一定是从左向右的，例如root1获得的seq为{7，3，5，6}
* 而使用递归的话可以优先递归左子树，一定能得出从左向右的叶序列seq
*/