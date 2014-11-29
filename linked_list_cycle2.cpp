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
        ListNode *one = head, *two = head;
        bool isCycle = false;
        while(two && two->next){
            one = one->next;
            two = two->next->next;
            if(one==two){
                isCycle = true;
                break;
            }
        }
        if(isCycle){
            ListNode *find = head;
            while(find!=one){
                find = find->next;
                one = one->next;
            }
            return find;
        }else{
            return NULL;
        }
        
    }
};