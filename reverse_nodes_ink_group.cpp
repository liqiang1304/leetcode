#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){};
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head, int k) {
		if(head==NULL || head->next==NULL || k<2) return head;
		ListNode dummpy(-1);
		dummpy.next = head;
		ListNode *pre = head, *cur = &dummpy;
		ListNode *next = pre;
		while(next!=NULL){
			int step = k-1;
			while(next!=NULL && step){
				step--;
				next = next->next;	
			}
			if(next!=NULL){
				ListNode *tmp = next->next;
				cur->next = reverseIt(pre, k);
				cur = pre;
				cur->next = tmp;
				pre = tmp;
				next = tmp;
			}
		}
		return dummpy.next;
	}

	ListNode *reverseIt(ListNode *begin, int k){
		ListNode *mid = begin->next;
		ListNode *tmp;
		k -=2;
		while(k){
			tmp = mid->next;
			mid->next = begin;
			begin = mid;
			mid = tmp;
			k--;
		}
		mid->next = begin;
		return mid;
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
