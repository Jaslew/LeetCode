/*
简单
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

动态规划法(O(n)),递推关系：
dp[i] = nums[0];    i = 0
dp[i] = max(nums[i], dp[i-1] + nums[i]);    i > 0
返回dp数组中的最大值。

执行用时 : 20 ms, 在Maximum Subarray的C++提交中击败了18.72% 的用户
内存消耗 : 9.2 MB, 在Maximum Subarray的C++提交中击败了0.94% 的用户
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(),result;
        vector<int> dp(n);
        result = dp[0] = nums[0];
        for(int i = 1; i < n; ++i){
            dp[i] = max(nums[i], dp[i-1] + nums[i]);
            if(result < dp[i])
                result = dp[i];
        }
        return result;
    }
};
