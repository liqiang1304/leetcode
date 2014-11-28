#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){};
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if(head==NULL) return head;
        ListNode l1(-1);
        ListNode l2(-1);
        ListNode *les = &l1, *lar = &l2;
        for(ListNode *cur = head; cur; cur = cur->next){
            if(cur->val<x){
                les->next = cur;
                les = cur;
            }else{
                lar->next = cur;
                lar = cur;
            }
        }
        if(l2.next!=NULL){
            les->next = l2.next;
            lar->next = NULL:
        }
        return l1.next;
    }
};

int main(){
    int n,tmp;
    ListNode dummp(-1);
    ListNode *pre = &dummp;
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> tmp;
        pre->next = new ListNode(tmp);
        pre = pre->next;
    }
    int m;
    cin >> m ;
    Solution *s = new Solution();
    ListNode *re = s->partition(dummp.next, m);
    while(re != NULL){
        cout << re->val << endl;
        re = re->next;
    }
}
