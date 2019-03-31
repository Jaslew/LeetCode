/*
困难
给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。
你可以对一个单词进行如下三种操作：
插入一个字符
删除一个字符
替换一个字符

动态规划( O(mn) )。
设word1长度为m,word2长度为n;设i,j分别为指向word1,word2的指针。
创建 (m+1)*(n+1) 的矩阵dp用于存储最少编辑次数，dp[i][j]表示word1前i个字符与word2前j个字符所使用最少操作数。
dp[0][0]总是0，表示两个空字符串所需最少操作次数，dp矩阵的第一行和第一列值代表其中一个字符串为空时的最少操作次数。
递推时分以下两种情况:
(1) 第i个字符与第j个字符相同：
此时dp[i][j] = dp[i-1][j-1],即跳过该字符。
(2) 第i个字符与第j个字符不相同：
有3种方案：（I）将第i个字符与第j-1个字符匹配;(II)将第i-1个字符与第j个字符匹配;(III)将第i-1个字符与第j-1个字符匹配;
对应dp值分别为:（I）dp[i][j-1] + 1;（II）dp[i-1][j] + 1;（III）dp[i-1][j-1] + 1;
dp[i][j]应取上述3种方案的最小值。
最后返回dp[m][n]。

执行用时 : 24 ms, 在Edit Distance的C++提交中击败了15.54% 的用户
内存消耗 : 11.2 MB, 在Edit Distance的C++提交中击败了4.60% 的用户
*/
class Solution {
private:
    vector<vector<int>> dp;
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        dp = vector<vector<int>>(m+1, vector<int>(n+1));        //创建 (m+1)*(n+1) 的矩阵
        dp[0][0] = 0;       //初始化最左上角元素,对应两个空字符串时的情况
        for(int i = 1; i <= m; ++i)     //初始化第一列，对应 word2为空字符串时的情况
            dp[i][0] = i;
        for(int j = 1; j <= n; ++j)     //初始化第一行，对应 word1为空字符串时的情况
            dp[0][j] = j;
        for(int i = 1; i <= m; ++i)     //其他情况按注释里的其它递推
            for(int j = 1; j <= n; ++j){
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min_3(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1;
            }
        return dp[m][n];
    }
    
    int min_3(int a, int b, int c){     //返回三个数中的最小值
        return a < b ? (a < c ? a : c):(b < c ? b : c);
    }
};
