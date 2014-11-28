#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){};
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head, int n) {
		ListNode *first = head;
		ListNode *sec = head;
		for(int i=0; i<n; ++i){
			first = first->next;	
		}
		while(first!=NULL && first->next){
			first = first->next;
			sec = sec->next;	
		}
		if(first!=NULL){
			sec->next = sec->next->next;
			return head;
		}else{
			return head->next;	
		}
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
	cin >> n;
    Solution *s = new Solution();
    ListNode *re = s->deleteDuplicates(dummp.next, n);
    while(re != NULL){
		cout << re->val << endl;
		re = re->next;
    }
}
