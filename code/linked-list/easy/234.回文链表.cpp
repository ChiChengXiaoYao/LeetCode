/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 *
 * https://leetcode-cn.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (50.47%)
 * Likes:    1244
 * Dislikes: 0
 * Total Accepted:    357.8K
 * Total Submissions: 709K
 * Testcase Example:  '[1,2,2,1]'
 *
 * 给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,2,2,1]
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [1,2]
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点数目在范围[1, 10^5] 内
 * 0 <= Node.val <= 9
 * 
 * 
 * 
 * 
 * 进阶：你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head||!head->next) {
            return true;
        }
        auto half = endOfFirstHalf(head);
        auto second_half = reverseList(half->next);

        auto p1=head,p2=second_half;
        bool result = true;
        while(p2) {
            if(p1->val!=p2->val) {
                result = false;
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        // 判断完成之后记得恢复链表
        half = reverseList(second_half);
        return result;
    }

    // 翻转链表
    ListNode* reverseList(ListNode* head) {
        if(!head||!head->next) {
            return head;    
        }
        auto a=head,b=a->next;
        while (b) {
            auto temp = b->next;
            // 反转指针
            b->next = a;
            // 移动指针
            a = b;
            b = temp;
        }
        head->next = nullptr;
        return a;
    }

    // 快慢指针
    ListNode* endOfFirstHalf(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next!=nullptr && fast->next->next!=nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};
// @lc code=end

