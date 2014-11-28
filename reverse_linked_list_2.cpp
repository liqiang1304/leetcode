#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){};
};

class Solution{
public:
	ListNode *method(ListNode *head, int m, int n){
		ListNode *dummy(-1);
		dummy.next = head;

		ListNode *prev = &dummy;
		for(int i=0; i<m-1; ++i){
			prev = prev->next;	
		}
		ListNode* const head2 = prev;
		prev = head2->next;
		ListNode *cur = prev->next;
		for(int i=m; i<n; ++i){
			prev->next = cur->next;
			cur->next = head2->next;
			head2->next = cur;
			cur = pre->next; 	
		}
		return dummy.next;
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
	cin >> m >> n;
	Solution *s = new Solution();
	ListNode *re = s->method(dummp.next, m, n);
	while(re != NULL){
		cout << re->val << endl;
		re = re->next;
	}
}
