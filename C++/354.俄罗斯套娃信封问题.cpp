/*
困难
给定一些标记了宽度和高度的信封，宽度和高度以整数对形式 (w, h) 出现。当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。
请计算最多能有多少个信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。
说明:
不允许旋转信封。
示例:
输入: envelopes = [[5,4],[6,4],[6,7],[2,3]]
输出: 3 
解释: 最多信封的个数为 3, 组合为: [2,3] => [5,4] => [6,7]。

动态规划。
先对信封按照宽度第一优先，高度第二优先从小到大排序。第一个信封dp为1，之后每一个信封dp等于排在它前面的信中封宽高都小于它且dp值最大的信封的dp加1。
返回dp数组中最大值。

执行用时 : 632 ms, 在Russian Doll Envelopes的C++提交中击败了2.45% 的用户
内存消耗 : 11.4 MB, 在Russian Doll Envelopes的C++提交中击败了3.28% 的用户
*/
class Solution {
private:
    vector<int> dp;
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if(envelopes.empty())
            return 0;
        int n = envelopes.size(), result = 1;
        sort(envelopes.begin(), envelopes.end(), myCompare);        //按规则排序
        dp = vector<int>(n, 1);
        for(int i = 1; i < n; ++i){
            for(int j = i-1; j >= 0; --j)
                if(envelopes[j].first < envelopes[i].first && envelopes[j].second < envelopes[i].second && dp[j] >= dp[i])
                    dp[i] = dp[j] + 1;
            if(result < dp[i])
                result = dp[i];
        }
        return result;
    }
    //定义排序函数,优先按宽度从小到大，若宽度一样则按高度从小到大排序
    static bool myCompare(const pair<int, int> &A, const pair<int, int> &B){
        if(A.first != B.first)
            return A.first < B.first;
        else
            return A.second < B.second;
    }
};
