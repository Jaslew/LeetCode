/*
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

使用暴力搜索，找到后即退出

执行用时 : 176 ms, 在Two Sum的C++提交中击败了16.17% 的用户
内存消耗 : 9.1 MB, 在Two Sum的C++提交中击败了0.82% 的用户
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
