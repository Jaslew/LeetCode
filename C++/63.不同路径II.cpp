/*
一个机器人位于一个 m x n 网格的左上角
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角
现在考虑网格(obstacleGrid)中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
网格中的障碍物和空位置分别用 1 和 0 来表示。
说明：m 和 n 的值均不超过 100。

动态规划问题，同题62，只是对于矩阵中每一个点需要先判断是否有障碍物。有障碍物则dp置0。
初始化第一行和第一列时当碰到一个点为障碍物时，这个点之后的所有点dp值都置0，代表路径数目为0。
递推式:
dp[i][j] = 1;     (i = 0 || j = 0) && 该点之前没有碰到障碍物
dp[i][j] = dp[i][j-1] + dp[i-1][j];   i != 0 && j != 0 && 该点没有障碍物
dp[i][j] = 0;     上述情况的补集

执行用时 : 16 ms, 在Unique Paths II的C++提交中击败了11.19% 的用户
内存消耗 : 9.1 MB, 在Unique Paths II的C++提交中击败了0.61% 的用户
*/

class Solution {
private:
    vector<vector<unsigned>> dp;
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();        //m为矩阵行数
        if(m == 0)                          //空矩阵则返回
            return 0;
        int i,j,n = obstacleGrid[0].size();     //n为矩阵列数
        dp = vector<vector<unsigned>>(m, vector<unsigned>(n,0));
        //初始化第一行
        j = 0;
        while(j < n && obstacleGrid[0][j] == 0){
            dp[0][j] = 1;
            ++j;
        }
        //初始化第一列
        i = 0;
        while(i < m && obstacleGrid[i][0] == 0){
            dp[i][0] = 1;
            ++i;
        }
        //从矩阵(1,1)开始按公式递推
        for(i = 1; i < m; ++i)
            for(j = 1; j < n; ++j)
                if(obstacleGrid[i][j] == 0)
                    dp[i][j] = dp[i][j-1] + dp[i-1][j];
        return dp[m-1][n-1];
    }
};
