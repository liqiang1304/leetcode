#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){};
};

ListNode *sortPart(ListNode *begin, ListNode *end){
	int key = begin->val;
	ListNode *l = begin, *r = begin->next;
	while(r!=end){
		if(r->val < key){
			l = l->next;
			swap(l->val, r->val);
		}
		r = r->next;
	}
	swap(l->val, begin->val);
	return l;
}

void listQsort(ListNode *head, ListNode *tail){
	if(head!=tail){
		ListNode *mid = sortPart(head, tail);
		listQsort(head, mid);
		listQsort(mid->next, tail);
	}
}


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
    listQsort(dummp.next, NULL);
	ListNode *re = dummp.next;
    while(re != NULL){
		cout << re->val << endl;
		re = re->next;
    }
}
