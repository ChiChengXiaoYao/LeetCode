/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 *
 * https://leetcode-cn.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (64.09%)
 * Likes:    601
 * Dislikes: 0
 * Total Accepted:    148.5K
 * Total Submissions: 227.9K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
 * 
 * 示例:
 * 
 * 输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
 * 输出:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * 说明：
 * 
 * 
 * 所有输入均为小写字母。
 * 不考虑答案输出的顺序。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // 1、排序后Hash O(nklogk)/O(nk) 71.11%/40.69%
    // vector<vector<string>> groupAnagrams(vector<string>& strs) {
    //     unordered_map<string,vector<string>> map;
    //     for(auto& str:strs){
    //         string key = str;
    //         sort(key.begin(),key.end());
    //         map[key].emplace_back(str);//emplace_back和push_back类似
    //     }

    //     vector<vector<string>> ans;
    //     for(auto it=map.begin();it!=map.end();++it)
    //         ans.emplace_back(it->second);
    //     return move(ans);
    // }

    // 2、统计字符串中各字符的数量，以此作为key进行Hash，减小复杂度
    // O(n(k+26))/O(n(k+26)) 91.09%/11.42%
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 自定义Hash函数，抄的官方的，还没搞懂
        auto arrayHash = [fn = hash<int>{}] (const array<int, 26>& arr) -> size_t {
            return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) {
                return (acc << 1) ^ fn(num);
            });
        };

        unordered_map<array<int,26>,vector<string>,decltype(arrayHash)> map(0,arrayHash);
        for (auto& str: strs) {
            array<int, 26> counts{};
            int length = str.length();
            // 统计一个字符串中各个字母出现的次数
            for (int i = 0; i < length; ++i) {
                counts[str[i] - 'a']++;
            }
            map[counts].emplace_back(str);
        }

        vector<vector<string>> ans;
        for(auto it=map.begin();it!=map.end();++it)
            ans.emplace_back(it->second);
        return move(ans);
    }
};
// @lc code=end

