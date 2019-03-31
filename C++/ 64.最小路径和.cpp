/*
中等
给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
说明：每次只能向下或者向右移动一步。

动态规划( O(n^2) )。
从矩阵右下角开始逆推，最右下角元素dp值为grid对应位置元素值；
最后一行每个位置dp值为其右边dp值与当前元素grid值之和，最后一列每个位置dp值为其下边dp值与当前元素grid值之和；
非最后一行且非最后一列元素dp值为其下面或右面较小dp值与当前位置grid元素值之和。

递推关系如下：
dp[i][j] = grid[i][j];      最后一个元素（最右下角）
dp[i][j] = dp[i][j+1] + grid[i][j];     最后一行
dp[i][j] = dp[i+1][j] + grid[i][j];     最后一列
dp[i][j] = min(dp[i][j+1], dp[i+1][j]) + grid[i][j];        其它
返回dp[0][0]

执行用时 : 24 ms, 在Minimum Path Sum的C++提交中击败了8.88% 的用户
内存消耗 : 10.7 MB, 在Minimum Path Sum的C++提交中击败了0.00% 的用户
*/
class Solution {
private:
    vector<vector<unsigned>> dp;
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;
        int m = grid.size(),n = grid[0].size();     //m,n为总行数，总列数
        dp = vector<vector<unsigned>>(m,vector<unsigned>(n));
        dp[m-1][n-1] = grid[m-1][n-1];      //初始化最后一个元素(最右下角)
        for(int j = n-2; j >= 0; --j)       //初始化最后一行
            dp[m-1][j] = dp[m-1][j+1] + grid[m-1][j];
        for(int i = m-2; i >= 0; --i)       //初始化最后一列
            dp[i][n-1] = dp[i+1][n-1] + grid[i][n-1];
        for(int i = m-2; i >= 0; --i)       //从倒数第二行倒数第二列的位置开始往上递推至第一个位置
            for(int j = n-2; j >=0; --j)
                dp[i][j] = min(dp[i][j+1], dp[i+1][j]) + grid[i][j];
        return dp[0][0];
    }
};
