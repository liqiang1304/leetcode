#include <iostream>

using namespace std;

class Solution{
	public:
		int method(int A[], int n){
			int *max_left = new int[n];
			int *max_right = new int[n];
			for(int i=1; i<n; ++i){
				max_left[i] = max(max_left[i-1],A[i-1]);
				max_right[n-i-1] = max(max_right[n-i],A[n-i]);
			}
			int result = 0;
			for(int i=0; i<n; ++i){
				int height = min(max_left[i], max_right[i]);
				if(height>A[i]){
					result += height-A[i];
				}
			}
			delete max_left;
			delete max_right;
			return result;
		}
};

int main(){
	int n,tmp;
	cin >> n;
	int *A = new int[n];
	for(int i=0; i<n; i++){
		cin>>A[i];
	}
	Solution *solution = new Solution();
	cout << solution->method(A,n);
}
