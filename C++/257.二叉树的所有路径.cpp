/*
简单
给定一个二叉树，返回所有从根节点到叶子节点的路径。
说明: 叶子节点是指没有子节点的节点。
示例:
输入:
   1
 /   \
2     3
 \
  5
输出: ["1->2->5", "1->3"]
解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3

深度遍历。

执行用时 : 16 ms, 在Binary Tree Paths的C++提交中击败了11.47% 的用户
内存消耗 : 12.1 MB, 在Binary Tree Paths的C++提交中击败了0.67% 的用户
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
    vector<string> result;
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root, "");
        return result;
    }
    void dfs(TreeNode *p, string temp){
        if(p == NULL)
            return;
        stringstream stream;    //整型转字符串
        string s;
        stream<<p->val;
        stream>>s;
        if(p->left == NULL && p->right == NULL){
            temp += s;
            result.push_back(temp);
            return;
        }
        temp += s + "->";
        dfs(p->left, temp);   //遍历子节点
        dfs(p->right, temp);
    }
};
