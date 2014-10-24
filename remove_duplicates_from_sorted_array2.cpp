#include<iostream>

using namespace std;

class Solution{
	public:
		int method(int A[], int n){
			if(n<=2) return n;
			int currNum = A[0];
			int numTimes = 0;
			int length = 0;
			for(int i=0; i<n; i++){
				if(currNum == A[i] && numTimes != 2){
					A[index] = A[i];
					numTimes++;
					length++;	
				}
				if(currNum != A[i]){
					A[index] = A{i};
					length++;
					currNum = A[i];
					numTimes = 1;
				}
			}
			return length;
		}
};

int main(){
	int n;
	int A[100];
	cin >> n;
	for(int i=0; i<n; ++i){
		cin >> A[i];
	}
	Solution *solution = new Solution();
	cout << solution->method(A, n);
}
