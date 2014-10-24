#include<iostream>

using namespace std;

class Solution{
	public:
		int method(int A[], int n, int target){
			int head = 0, tail = n;
			while(head!=tail){
				int mid = (head + tail)/2;
				if(target == A[mid]) return mid;
				if(A[head] <= A[mid]){
					if(target>=A[head] && target<A[mid]){
						tail = mid;
					}else{
						head = mid+1;
					}
				}else{
					if(target>A[mid] && target<=A[tail-1]){
						head = mid+1;
					}else{
						tail = mid;
					}
				}			
			}
			return -1;
		}
};

int main(){
	int n;
	int A[100];
	cin >> n;
	for(int i=0; i<n; ++i){
		cin >> A[i];
	}
	int tar;
	cin >> tar;
	Solution *solution = new Solution();
	cout << solution->method(A, n, tar) <<endl;
}
