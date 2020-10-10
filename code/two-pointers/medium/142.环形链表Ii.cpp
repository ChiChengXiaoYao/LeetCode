/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 *
 * https://leetcode-cn.com/problems/linked-list-cycle-ii/description/
 *
 * algorithms
 * Medium (52.00%)
 * Likes:    660
 * Dislikes: 0
 * Total Accepted:    125.8K
 * Total Submissions: 240.2K
 * Testcase Example:  '[3,2,0,-4]\n1'
 *
 * 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
 * 
 * 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。
 * 
 * 说明：不允许修改给定的链表。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：head = [3,2,0,-4], pos = 1
 * 输出：tail connects to node index 1
 * 解释：链表中有一个环，其尾部连接到第二个节点。
 * 
 * 
 * 
 * 
 * 示例 2：
 * 
 * 输入：head = [1,2], pos = 0
 * 输出：tail connects to node index 0
 * 解释：链表中有一个环，其尾部连接到第一个节点。
 * 
 * 
 * 
 * 
 * 示例 3：
 * 
 * 输入：head = [1], pos = -1
 * 输出：no cycle
 * 解释：链表中没有环。
 * 
 * 
 * 
 * 
 * 
 * 
 * 进阶：
 * 你是否可以不用额外空间解决此题？
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        /// 1.hash表，一旦遇到重复的节点即说明存在环，且首次遇到的重复节点即为环入口，时间/空间O(n)
        
        /// 2.快慢指针：设圈外长a，圈内b处相遇，圈内剩余长度c，相遇时fast套了n圈
        ///     slow路径：a+b
        ///     fast路径：a+(b+c)n+b=2(a+b) （是slow路径的2倍）
        ///     化简：a+b=(b+c)n，slow长度刚好是n个环的长度
        ///     则fast是2n个环的周长
        ///     从链表头开始计数，环的初始位置：a+(b+c)n
        ///     当前slow=a+b=(b+c)n，则再走a即可到达初始点
        ///     a=slow当前向前走到初始环的位置=链表头向前走到初始环的位置
        ///     
        /// 换种解释：f=2s,f=s+(b+c)n→s=(b+c)n（slow走了n个环，fast走了2n个环）
        ///
        ///     slow指针一定没有走完整个环：slow入环时，fast一定在环内；
        ///         fast是slow的两倍速度，slow走完一环时fast走完两环；
        ///         fast与slow的初始距离差<一环（追及问题），故在slow走完一环前相遇。
        ListNode *slow=head,*fast=head;
        do{
            // 无环的情况
            if(!fast||!fast->next)  return NULL;
            fast=fast->next->next;
            slow=slow->next;
        }while(slow!=fast);
        // 将fast重置为指向链表头的指针，进行第二次相遇操作
        fast=head;
        while(fast!=slow){
            fast=fast->next;
            slow=slow->next;
        }
        return fast;
    }
};
// @lc code=end

