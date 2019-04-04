/*
简单
判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
示例 1:
输入: 121
输出: true
示例 2:
输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。

执行用时 : 88 ms, 在Palindrome Number的C++提交中击败了96.66% 的用户
内存消耗 : 8.1 MB, 在Palindrome Number的C++提交中击败了93.02% 的用户
*/
class Solution {
public:
    bool isPalindrome(int x) {
        string y;
        int i,j;
        stringstream stream;    //转为字符串
        stream<<x;
        stream>>y;
        i = 0;
        j = y.size()-1;
        while(i < j){
            if(y[i] != y[j])    //ｉ指针从左到右扫,j指针从右到左扫
                return false;
            ++i;
            --j;
        }
        return true;
    }
};
