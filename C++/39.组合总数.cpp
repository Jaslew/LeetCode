/*
中等
给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的数字可以无限制重复被选取。
说明：
所有数字（包括 target）都是正整数。
解集不能包含重复的组合。

回溯法。

执行用时 : 832 ms, 在Combination Sum的C++提交中击败了0.97% 的用户
内存消耗 : 175.3 MB, 在Combination Sum的C++提交中击败了0.72% 的用户
*/
class Solution {
private:
    vector<vector<int>> result;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        dfs(candidates, temp, 0, target);
        return result;
    }
    void dfs(vector<int> candidates, vector<int> temp, int i, int target){
        if(target == 0){
            result.push_back(temp);
            return;
        }
        if(target < 0 || i >= candidates.size())
            return;
        temp.push_back(candidates[i]);
        dfs(candidates, temp, i, target-candidates[i]);
        temp.pop_back();
        dfs(candidates, temp, i + 1, target);
    }
};
