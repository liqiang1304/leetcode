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
		if(head==NULL || head->next==NULL) return head;
		ListNode dummpy(-1);
		dummpy.next = head;
		ListNode *pre = &dummpy;
		ListNode *cur = pre->next, *net = cur->next;
		while(net!=NULL){
			pre->next = net;
			cur->next = net->next;
			net->next = cur;
			pre = cur;
			cur = cur->next;
			net = cur?cur->next:NULL;	
		}
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
