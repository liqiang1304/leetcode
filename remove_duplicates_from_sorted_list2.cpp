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
		if(head == NULL) return head;
		ListNode dummp(-1);
		ListNode *cur = head;
		ListNode *newList = &dummp;
		ListNode *nxt = cur->next;
		while(cur != NULL){
			bool isRepeat = false;
			while(nxt != NULL && nxt->val == cur->val){
				nxt = nxt->next;	
				isRepeat = true;
			}
			if(isRepeat){
				cur = nxt;
				if(nxt!=NULL)nxt = nxt->next;
				else break;
			}else if(!isRepeat){
				newList->next = cur;
				newList = newList->next;
				cur = cur->next;
				if(cur!=NULL) nxt = cur->next;
				else break;
			}
			
		}
		newList->next = NULL;
		return dummp.next;
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
