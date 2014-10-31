#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
	public:
    void nextPermutation(vector<int> &num) {
	    vector<int> tmpvec;
		int len = num.size();
		int size =len-1;
	    while(size>0){
			if(num[size]>num[size-1]){
				break;
			}
			size--;
		}
	    if(size==0){
			sort(num.begin(), num.end());
		}else{
			size--;
			int tmp = num[size];
			int tmpMin = 999;
			int tmpi = 0;
			for(int i=size+1; i<len; i++){
				if(tmpMin>num[i] && num[i]>tmp){
					tmpMin = num[i];
					tmpi = i;
				}
			}
			for(int i=size; i<len; i++){
				if(i!=tmpi){
					tmpvec.push_back(num[i]);
				}
			}
			sort(tmpvec.begin(), tmpvec.end());
			for(int i=size+1; i<len; i++){
				num[i]=tmpvec[i-size-1];
			}
			num[size] = tmpMin;
		}
	}
};

int main(){
	int n,tmp;
	vector<int> num;
	cin >> n;
	for(int i=0; i<n; ++i){
		cin >> tmp;
		num.push_back(tmp);
	}
	Solution *s = new Solution();
	s->nextPermutation(num);
	for(int i=0;i<n;++i){
		cout<<num[i]<<",";
	}
}
