/*
困难
有 n 个气球，编号为0 到 n-1，每个气球上都标有一个数字，这些数字存在数组 nums 中。
现在要求你戳破所有的气球。每当你戳破一个气球 i 时，你可以获得 nums[left] * nums[i] * nums[right] 个硬币。
这里的 left 和 right 代表和 i 相邻的两个气球的序号。注意当你戳破了气球 i 后，气球 left 和气球 right 就变成了相邻的气球。
求所能获得硬币的最大数量。
说明:
你可以假设 nums[-1] = nums[n] = 1，但注意它们不是真实存在的所以并不能被戳破。
0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
示例:
输入: [3,1,5,8]
输出: 167 
解释: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
     coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167

记忆化搜索（递归 + 动态规划）。
nums数组首和尾各扩增一个数值1，以便于计算。
设二维数组dp[start][end],表示扩增后nums数组下标start到end的dp值（即[start,end]区间里能获得硬币的最大数量）。假设下标middle指示的位置为
这个区间里最后一个戳破气球的位置，则dp[start][middle-1]表示该位置左半部分已经戳破气球得到的奖赏，dp[middle+1][end]表示该位置右半部分已经
戳破气球得到的奖赏。此时middle位置上的气球与(start-1)，(end+1)位置上的气球相邻,最后戳破middle位置上的气球，因而得到的总奖赏为:
nums[start-1]*nums[middle]*nums[end+1] + dp[start][middle-1] + dp[middle+1][end];
对于[start,end]区间每一个位置都尝试作为最后一个戳破的气球位置,寻找总奖赏最大的作为该区间的dp值，并记录，以便下次用到该区间时，dp值不需重新计算。
特殊情况:当middle指向start或end位置时，继续递归会出现start > end 的情况，此时只需返回0。

执行用时 : 52 ms, 在Burst Balloons的C++提交中击败了1.33% 的用户
内存消耗 : 9.5 MB, 在Burst Balloons的C++提交中击败了0.00% 的用户

总结：
因为使用到了递归，如果在dfs函数里传递nums数组，结果可能超时，所以将nums数组作为复制为类的一个属性，不对其进行传递。
对于递归类算法应尽可能减少参数传递。
*/
class Solution {
private:
    vector<vector<int>> dp;
    vector<int> mnums;
public:
    int maxCoins(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int n;
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        n = nums.size();
        dp = vector<vector<int>>(n, vector<int>(n, 0));   //初始化所有区间dp值为0
        mnums = nums;                                     //复制nums数组为类成员变量
        return dfs(1, n-2);
    }
    int dfs(int start, int end){
        int middle, left, right;
        if(start > end)                                   //特殊情况
            return 0;
        if(dp[start][end] != 0)                           //备忘录中记录有该数据，返回该数据，不必从新计算
            return dp[start][end];
        for(middle = start; middle <= end; ++middle){     //对区间的每一个位置尝试性作为最后一个戳破的位置，找到最优的位置
            left = dfs(start, middle-1);                  //区间[start，middle-1]的dp值
            right = dfs(middle+1, end);                   //区间[middle+1，start]的dp值
            dp[start][end] = max(dp[start][end], left + right + mnums[start-1] * mnums[middle] * mnums[end+1]);   //加入备忘录
        }
        return dp[start][end];
    }
};
