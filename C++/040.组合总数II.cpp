/*
中等
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的每个数字在每个组合中只能使用一次。
说明：
所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。 

回溯法。

执行用时 : 592 ms, 在Combination Sum II的C++提交中击败了0.96% 的用户
内存消耗 : 140 MB, 在Combination Sum II的C++提交中击败了0.90% 的用户
*/

class Solution {
private:
    set<vector<int>> result;    //利用set去重
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(), candidates.end(), greater<int>());     //从大到小排序
        dfs(candidates, temp, 0, target);
        return vector<vector<int>>(result.begin(), result.end());
    }
    void dfs(vector<int> candidates, vector<int> temp, int i, int target){
        if(target == 0){        //符合条件
            result.insert(temp);
            return;
        }
        if(target < 0 || i >= candidates.size())
            return;
        temp.push_back(candidates[i]);      //将指针i指向的数字放入临时结果,同时i指向下一个位置
        dfs(candidates, temp, i + 1, target-candidates[i]);
        temp.pop_back();                    //跳过i指向的这个数字,同时i指向下一个位置
        dfs(candidates, temp, i + 1, target);
    }
};
