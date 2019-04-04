/*
中等
给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的数字可以无限制重复被选取。
说明：
所有数字（包括 target）都是正整数。
解集不能包含重复的组合。

回溯法。
事先对数组做从大到小排序（经测试做排序时间消耗降低约200ms,内存消耗降低约50MB）。

执行用时 : 628 ms, 在Combination Sum的C++提交中击败了0.97% 的用户
内存消耗 : 123.5 MB, 在Combination Sum的C++提交中击败了0.72% 的用户
*/
class Solution {
private:
    vector<vector<int>> result;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(), candidates.end(), greater<int>());     //从大到小排序
        dfs(candidates, temp, 0, target);
        return result;
    }
    void dfs(vector<int> candidates, vector<int> temp, int i, int target){
        if(target == 0){        //符合条件
            result.push_back(temp);
            return;
        }
        if(target < 0 || i >= candidates.size())
            return;
        temp.push_back(candidates[i]);      //将指针i指向的数字放入临时结果
        dfs(candidates, temp, i, target-candidates[i]);         //重复使用i所指的数字,同时target减去该数值
        temp.pop_back();        //将临时结果中最后一个数取出
        dfs(candidates, temp, i + 1, target);           //i指向下一个数
    }
};
