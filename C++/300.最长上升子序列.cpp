/*
中等
给定一个无序的整数数组，找到其中最长上升子序列的长度。
示例:
输入: [10,9,2,5,3,7,101,18]
输出: 4 
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
说明:
可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
你算法的时间复杂度应该为 O(n2) 。
进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?

动态规划( O(n^2) )。
初始化第一个元素dp值为1，递推关系:对于每个位置dp值的计算方式为，遍历该位置之前的所有的值小于该元素的dp值最大者，然后加1，若找不到则默认为1.
dp[i] = dp[j] + 1;    j为i指针之前小于i指向的元素且dp值是最大的元素下标
返回dp数组最大值。

执行用时 : 60 ms, 在Longest Increasing Subsequence的C++提交中击败了2.01% 的用户
内存消耗 : 8.7 MB, 在Longest Increasing Subsequence的C++提交中击败了0.53% 的用户
*/

class Solution {
private:
    vector<int> dp;
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int n = nums.size(), result = 1;
        dp = vector<int>(n,1);
        for(int i = 1; i < n; ++i){                  //i指向nums数组
            for(int j = i-1; j >= 0; --j){          //j指向dp数组,检查0~(i-1)之间的数
                if(nums[j] < nums[i] && dp[j] >= dp[i])
                    dp[i] = dp[j] + 1;
            }
            if(dp[i] > result)
                result = dp[i];     //result记录最大长度
        }
        return result;
    }
};
