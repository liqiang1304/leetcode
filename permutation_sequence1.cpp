#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
	public:
    string nextPermutation(int n, int k) {
		int *jcarr = new int[n+1];
		jc(n, jcarr);
		bool *num = new bool[n+1];
		int i,j;
		string result;
		k--;
		for(i=0; i<=n; ++i){
			num[i] = false;
		}
		for(i=0; i<n; ++i){
			int ds = k/jcarr[n-i-1];
			for(j=1; j<=n; ++j){
				if(!num[j]){
					if(ds == 0){
						break;
					}
					ds--;
				}
			}
			num[j] = true;
			char tmp = '0';
			tmp+=j;
			result += tmp;
			k = k%jcarr[n-i-1];
		}
		return result;
	}

	void jc(int n, int arr[]){
		arr[0] = 1;
		arr[1] = 1;
		for(int i=1;i<=n;i++){
			arr[i] = arr[i-1]*i;	
		}
	}
};

int main(){
	int n,k;
	cin >> n >> k;
	Solution *s = new Solution();
	cout<<s->nextPermutation(n,k)<<endl;
}
