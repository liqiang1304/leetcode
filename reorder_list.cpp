#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){};
};

class Solution {
public:
    void deleteDuplicates(ListNode *head) {
		if(head==NULL || head->next==NULL) return ;
		ListNode *one = head, *two = head;
		ListNode *pre;
		while(two && two->next){
			pre = one;
			one = one->next;
			two = two->next->next;	
		}
		pre->next = NULL;
		ListNode *new_head = reverse(one);
		ListNode *cur = head;
		while(cur->next){
			ListNode *tmp = cur->next;
			cur->next = new_head;
			new_head = new_head->next;
			cur->next->next = tmp;
			cur = tmp;	
		}
		cur->next = new_head;
	}

	ListNode *reverse(ListNode *head){
		if(head==NULL || head->next==NULL) return head;
		ListNode *prev = head;
		for(ListNode *cur = head->next,*next = cur->next; cur;
			prev = cur, cur = next, next = next?next->next:NULL){
			cur->next = prev;	
		}
		head->next = NULL;
		return prev;
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
    s->deleteDuplicates(dummp.next);
	ListNode *head = dummp.next;
    while(head != NULL){
		cout << head->val << endl;
		head = head->next;
    }
}
