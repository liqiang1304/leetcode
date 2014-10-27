#include <iostream>

using namespace std;

class Solution{
public: 
	bool method(int A[], int n, int target){
		int head = 0, tail = n;
		while(head!=tail){
			int mid = (head + tail)/2;
			if(target == A[mid]) return true;
			if(A[head]>A[mid]){
				if(target>A[mid] && target<=A[tail-1]){
					head = mid + 1;	
				}else{
					tail = mid;	
				}
			}else if(A[head]<A[mid]){
				if(target>=A[head] && target<A[mid]){
					tail = mid;	
				}else{
					head = mid + 1;	
				}
			}else{
				head ++;	
			}
		}
		return false;
	}
};

int main(){
	int n;
	cin >> n;
	int A[100];
	for(int i=0; i<n; ++i){
		cin >> A[i];
	}
	int target;
	cin >> target;
	Solution *so = new Solution();
	cout << so->method(A, n, target) << endl;
}
