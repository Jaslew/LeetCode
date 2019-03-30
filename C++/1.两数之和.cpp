/*
暴力法，时间复杂度O(n)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size(),temp;
        bool goon = true;
        vector<int> result(2);
        for(int i = 0; goon && i < n; ++i){
            temp = target - nums[i];
            for(int j = i + 1; j < n; ++j)
                if(temp == nums[j]){
                    result[0] = i;
                    result[1] = j;
                    goon = false;
                    break;
                }
        }
        return result;
    }
};
