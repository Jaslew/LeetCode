/*
中等
给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
例如，给定三角形：
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
说明：如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。

动态规划。
最后一行每个元素dp值为该元素值。从倒数第二行第一个元素开始从左往右，从下往上计算每个位置的dp值，dp计算公式为：
该位置元素值加上下一行和该位置相邻的两元素dp值较小的那个，设i,j代表行和列的位置，有：
dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + dp[i][j];

执行用时 : 12 ms, 在Triangle的C++提交中击败了16.50% 的用户
内存消耗 : 9.8 MB, 在Triangle的C++提交中击败了0.68% 的用户
*/
class Solution {
private:
    vector<vector<int>> dp;
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty())
            return 0;
        int m = triangle.size();
        dp = triangle;                        //初始化dp矩阵（复制矩阵结构和最后一行的值）
        for(int i = m-2; i >= 0; --i)         //从倒数第二行往上开始递推
            for(int j = 0; j <= i; ++j)      //重新计算该行每个元素dp值
                dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + dp[i][j];
        return dp[0][0];
    }
};
