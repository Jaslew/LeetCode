/*
暴力法，时间复杂度O(n)
244 ms, 在Two Sum的C++提交中击败了2.99% 的用户
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size(),temp;
        bool goon = true;
        vector<int> result(2);
        for(int i = 0; goon && i < n; ++i){     //从第一个数开始找
            temp = target - nums[i];
            for(int j = i + 1; j < n; ++j)      //匹配第二个数
                if(temp == nums[j]){            //匹配到则退出循环
                    result[0] = i;
                    result[1] = j;
                    goon = false;
                    break;
                }
        }
        return result;
    }
};
