#include <iostream>

using namespace std;

class Solution{
public: 
    double method(int A[], int m, int B[], int n){
		int total = m + n;
		if(total&1){
			return find_kth(A,m,B,n,total/2+1);
		}else{
			return (find_kth(A, m, B, n, total/2) + find_kth(A, m, B, n, total/2+1))/2.0;
		}
    }

	int find_kth(int A[], int m, int B[], int n, int k){
		if(m == 0) return B[k-1];
		if(m > n) return find_kth(B, n, A, m, k);
		if(k==1) return (A[0]>B[0])?B[0]:A[0];

		int ia = (k/2>m)?m:k/2, ib = k - ia;
		if(A[ia-1]<B[ib-1]){
			return find_kth(A+ia, m-ia, B, n, k-ia);
		}else if(A[ia-1]>B[ib-1]){
			return find_kth(A, m, B+ib, n-ib, k-ib);
		}else{
			return A[ia-1];
		}
	}
};

int main(){
    int m;
    cin >> m;
    int A[100],B[100];
    for(int i=0; i<m; ++i){
        cin >> A[i];
    }
    int n;
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> B[i];
    }
    Solution *so = new Solution();
    cout << so->method(A, m, B, n) << endl;
}
