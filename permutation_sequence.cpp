#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
	public:
    string nextPermutation(int n, int k) {
		bool *flag = new bool[n];
		string rst;
		for(int i=0; i<n; i++){
			flag[i] = false;
		}
		k--;
		for(int i=n-1; i>=0; i--){
			int j = jc(i);
			int result = k/j;
			int ys = k%j;
			k = ys;
			char tmp = '1';
			for(int i=1;i<=n;++i){
				if(!flag[i-1] && result!=0){
					result--;
				}
				if(result==0 && !flag[i-1]){
					flag[i-1] = true;
					tmp = tmp + i;
					rst += tmp;
					break;
				}
			}
		}
		return rst;
		
	}

	int jc(int n){
		if(n==0) return 1;
		int result = 1;
		for(int i=1;i<=n;i++){
			result *= i;	
		}
		return result;
	}
};

int main(){
	int n,k;
	cin >> n >> k;
	Solution *s = new Solution();
	cout<<s->nextPermutation(n,k)<<endl;
}
