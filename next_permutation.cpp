#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
    void nextPermutation(vector<int> &num) {
	        vector<int> tmp;
	        int size = num.size() - 1;
	        while(size>0){
			            if(num[size]>num[size-1]){
						                break;
						            }
			        }
	        if(size==0){
			            sort(num.begin(), num.end());
			        }else{
					            
					        }
	    }
};
