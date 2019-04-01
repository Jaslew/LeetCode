/*
中等
给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
说明: 叶子节点是指没有子节点的节点。
示例:
给定如下二叉树，以及目标和 sum = 22，
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
返回:
[
   [5,4,11,2],
   [5,8,4,5]
]

深度遍历。

执行用时 : 84 ms, 在Path Sum II的C++提交中击败了1.49% 的用户
内存消耗 : 36.2 MB, 在Path Sum II的C++提交中击败了0.60% 的用户
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    vector<vector<int>> result;
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> temp;
        dfs(root, temp, sum);
        return result;
    }
    void dfs(TreeNode *p, vector<int> temp, int sum){
        if(p == NULL)
            return;
        if(p->left == NULL && p->right == NULL){         //叶子节点
            sum -= p->val;
            if(sum == 0){     //符合题意
                temp.push_back(p->val);
                result.push_back(temp);
            }
            return;
        }
        sum -= p->val;
        temp.push_back(p->val);
        dfs(p->left, temp, sum);
        dfs(p->right, temp, sum);
    }
};
