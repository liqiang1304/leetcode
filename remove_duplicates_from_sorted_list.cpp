#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){};
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head==NULL) return head;
        ListNode dummpy(-1);
        ListNode *noDup = &dummpy;
        noDup->next = head;
        noDup = noDup->next;
        for(ListNode *cur = head->next; cur; cur=cur->next){
            if(noDup->val == cur->val){
                continue;
            }else{
                noDup->next = cur;
                noDup = cur;
            }
        }
        noDup->next = NULL;
        return dummpy.next;
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
    Solution *s = new Solution();
    ListNode *re = s->deleteDuplicates(dummp.next);
    while(re != NULL){
        cout << re->val << endl;
        re = re->next;
    }
}
