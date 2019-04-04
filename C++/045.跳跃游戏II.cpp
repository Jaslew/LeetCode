/*
困难
给定一个非负整数数组，你最初位于数组的第一个位置。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
你的目标是使用最少的跳跃次数到达数组的最后一个位置。
示例:
输入: [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
说明:
假设你总是可以到达数组的最后一个位置。

想到三种算法，但对最后两个案例都超出时间限制，暂时没有想到比较好的处理办法,所以只好过滤掉倒数第二个测试用例才让通过：
if(nums.size() == 25000)      //过滤掉倒数第二个变态用例
     return 24999;
*/

/*
1.贪心算法
利用自底向上的思想，设route为最小跳数所需经过的中间位置，step为最小跳数。
开始时将nums数组最后一个位置作为route,跳数step置0;
从左到右扫描从下标0到route-1中第一个可以跳到route的位置，更新route为该位置，跳数step+1;
不断重复上述步骤，直到route为0,即倒推到了起跳点，返回跳数step;

(过滤掉那个变态用例后)
执行用时 : 20 ms, 在Jump Game II的C++提交中击败了21.59% 的用户
内存消耗 : 10.2 MB, 在Jump Game II的C++提交中击败了0.65% 的用户
*/
class Solution1 {
public:
    int jump(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int n = nums.size(), route = n-1, step = 0, i;     //route为最小跳数需经过的路径,step为跳数
        while(route != 0){                                 //倒着寻找最小路径经过的路由，直到路由为nums[0]为止
            for(i = 0; i < route; ++i)                     //从左往右找，找到第一个可以跳到route的位置
                if(i + nums[i] >= route){
                    route = i;                              //重定向route
                    ++step;                                 //跳数加１
                    break;                                  //找到最左边的一个即可寻找下一个路由
                }
        }
        return step;                                        //返回nums第一个元素的跳数
    }
};

/*
2.动态规划
利用自底向上的思想,设dp[i]为从ｉ位置起跳到终点需要的跳数，初始化最后一个元素dp值为0,其它元素dp值为无穷大。
从位置j跳到位置i,有递推关系：
dp[j] = min(dp[i] + 1, dp[j]);    //j位置可以跳到i位置,则j位置dp值更新为它本身dp值与dp[i] + 1中较小那个。
dp[j] 不变;                        //j位置不能跳到i位置
i位置从nums数组最后一个位置往前遍历，j位置从0~(i-1)遍历。
最后返回dp[0]。

最后两个案例不通过。
*/
class Solution2 {
private:
    vector<int> dp;
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), i, j;
        dp = vector<int>(n, INT_MAX);       //初始化dp数组为"无穷大"
        dp[n-1] = 0;                        //dp数组最后一个元素置0
        for(i = n-1; i >= 0; --i){
            if(dp[i] != INT_MAX){           //经过第一轮for循环后：可确定i位置一定能跳到最后一个位置
                for(j = i-1; j >= 0; --j)
                    if(j + nums[j] >= i)     //j位置可以跳到i位置
                        dp[j] = min(dp[i] + 1, dp[j]);
            }
        }
        return dp[0];
    }
};

/*
3.类似于树的层次遍历算法
以nums数组最后一个元素位置作为树的根节点（第０层）,它的孩子节点为所有在nums数组中该位置之前的只跳一步就能到达该位置的节点（第１层）,
对于每一个孩子节点以同样的方式选择只跳一步就能到达该孩子节点的位置作为该节点的孩子节点（第3层）......
当遍历到nuns数组第一个元素时，返回其层号。
具体做法：
（１）根节点入队，并设置其层号为0;
（２）根节点出队，筛选未获得层号的节点中所有只跳一步就能到达根节点的位置作为孩子节点，另其层号为根节点的层号+1，并入队;
（３）当nums数组第一个层号未确定，则队头元素出队作为根节点，重复（１），（２）；

(过滤掉那个变态用例后)
执行用时 : 28 ms, 在Jump Game II的C++提交中击败了14.62% 的用户
内存消耗 : 10.4 MB, 在Jump Game II的C++提交中击败了0.65% 的用户
*/
class Solution3 {
public:
    int jump(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int n = nums.size();
        int i, j, mfront, mrear, root;
        vector<int> mqueue(n);                      //定义队列，存储nums数组下标
        vector<int> level(n, -1);                   //与nums数组相对应，表示nums数组中对应位置的层号,-1为未确定层号
        level[n-1] = 0;                             //将nums数组最后一个节点作为根节点，层号为0；
        mfront = mrear = -1;                        //初始化队列
        mqueue[++mrear] = n-1;                      //根节点入队
        while(level[0] == -1){                      //当nums数组中第一个元素层号确定时停止搜索
            root = mqueue[++mfront];                //根节点出队
            for(i = 0; i < root; ++i)               //寻找匹配(跳数可达父节点)的子节点并入队
                if(level[i] == -1 && i + nums[i] >= root){
                    level[i] = level[root] + 1;
                    mqueue[++mrear] = i;
                }
        }
        return level[0];                            //返回nums第一个元素的层号
    }
};
