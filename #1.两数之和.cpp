/*暴力搜索，超时*/
class Solution{
private:
    vector<int> result;
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> temp;
        bool flag = false;
        if(nums.size() >= 2)
            dfs(nums, temp, 0, target, flag);
        return result;
    }
    /*
     * temp记录临时结果
     * i为nums的指针
     * flag标记是否找到结果
     * */
    void dfs(vector<int> nums, vector<int> temp, int i, int target, bool &flag){
        if(temp.size() >= 2){
            if(target == 0){
                result.assign(temp.begin(), temp.end());
                flag = true;
            }
            return;
        }
        if(flag || i >= nums.size())       //已经找到或指针i指向数组外时返回
            return;
        temp.push_back(i);                                  //将这个数装入
        dfs(nums, temp, i + 1, target - nums[i], flag);        //i指向下一个数，target对应减小
        temp.pop_back();                                    //跳过这个数
        dfs(nums, temp, i + 1, target, flag);                  //i指向下一个数，target不变
    }
};
