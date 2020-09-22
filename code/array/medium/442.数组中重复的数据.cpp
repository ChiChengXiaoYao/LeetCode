/*
 * @lc app=leetcode.cn id=442 lang=cpp
 *
 * [442] 数组中重复的数据
 *
 * https://leetcode-cn.com/problems/find-all-duplicates-in-an-array/description/
 *
 * algorithms
 * Medium (67.27%)
 * Likes:    272
 * Dislikes: 0
 * Total Accepted:    23.7K
 * Total Submissions: 35.3K
 * Testcase Example:  '[4,3,2,7,8,2,3,1]'
 *
 * 给定一个整数数组 a，其中1 ≤ a[i] ≤ n （n为数组长度）, 其中有些元素出现两次而其他元素出现一次。
 * 
 * 找到所有出现两次的元素。
 * 
 * 你可以不用到任何额外空间并在O(n)时间复杂度内解决这个问题吗？
 * 
 * 示例：
 * 
 * 
 * 输入:
 * [4,3,2,7,8,2,3,1]
 * 
 * 输出:
 * [2,3]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // 不占用额外空间，则在原地标记，同时保留原有信息
        // 数组长度n，取值1-n
        // 下标0→n-1分别对应值1→n
        // 可以取负数/+n等操作
        // TODO：胡思乱想：是不是能用信息熵来确定是否可以在保留原信息的基础上增加附加信息？（熵增）
        vector<int> result;
        for(auto num:nums){
            // 取反操作之后可能为负/同理+n操作要取余
            num = abs(num);
            if(nums[num-1]>0)
                nums[num-1]=-nums[num-1];
            // 是值num导致下标num-1对应的值被取反，不要push错
            else
                result.push_back(num);
        }
        return result;
    }
};
// @lc code=end

