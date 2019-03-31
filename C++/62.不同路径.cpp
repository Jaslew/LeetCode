/*
中等
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
问总共有多少条不同的路径？

典型 dp 问题，设dp值为路径数，则有以下递推式：
(1) dp[i][j] = 1;  i=0或j=0
(2) dp[i][j] = dp[i][j-1] + dp[i-1][j];   i != 0 && j != 0

执行用时 : 12 ms, 在Unique Paths的C++提交中击败了11.66% 的用户
内存消耗 : 8.4 MB, 在Unique Paths的C++提交中击败了0.68% 的用户
*/
class Solution {
private:
    vector<vector<int>> dp;
public:
    int uniquePaths(int m, int n) {
        //m为列，n为行,dp矩阵初始化全为1
        dp = vector<vector<int>>(n, vector<int>(m,1));
        for(int i = 1; i < n; ++i)
            for(int j = 1; j < m; ++j)      //从矩阵下标为(1,1)的格子开始
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
        return dp[n-1][m-1];
    }
};
