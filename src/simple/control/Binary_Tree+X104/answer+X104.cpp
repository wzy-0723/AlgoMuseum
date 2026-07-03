#include "common.h"


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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }

    //递归求解
    int maxDepth_iterate(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }

    //迭代求解（广度优先搜索
    int CalcLeafSeq_recursion(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<TreeNode*> Q;
        Q.push(root);
        int ans = 0;
        // 深度计算，+1
        while (!Q.empty()) {
            int sz = (int)Q.size();
            // 搜索子节点
            while (sz > 0) {
                TreeNode* node = Q.front(); Q.pop();
                if (node->left) Q.push(node->left);
                if (node->right) Q.push(node->right);
                sz -= 1;
            }
            ans += 1;
        }
        return ans;
    }
};
Solution solution;
int main()
{
    TreeNode* node5 = new TreeNode(5);TreeNode* node6 = new TreeNode(6);
    TreeNode* node3 = new TreeNode(3); TreeNode* node4 = new TreeNode(4, node5, node6);
    TreeNode* node7 = new TreeNode(7); TreeNode* node2 = new TreeNode(2, node3, node4);
    TreeNode* node1 = new TreeNode(1, node2, node7);

    cout << "maxDepth:" << solution.CalcLeafSeq_recursion(node1) << endl;
    return 0;
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
* 迭代：
* 每搜索完一层res+1，每层开始搜索的时候获取搜索数量sz
* 搜索到某个节点时压入其子节点，直到sz为0也就是没有子节点了
*/