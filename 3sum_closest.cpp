#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>

using namespace std;

class Solution{
	public:
		int method(vector<int> &num, int target){
			int result = 2147483647;
			sort(num.begin(), num.end());
			int size = num.size();
			for(int i=1; i<size-1; ++i){
				int head = 0, tail = size-1;
				while(head<i && tail>i){
					int sum = num[i] + num[head] + num[tail] - target;
					if(sum < 0){
						head++;
					}else{
						tail--;
					}
					result = (abs(result)>abs(sum))?sum:result;
				}
			}
			return result+target;
		}
};

int main(){
	vector<int> a;
	int n, tmp;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> tmp;
		a.push_back(tmp);
	}
	int target;
	cin >> target;
	Solution *solution = new Solution();
	cout << solution->method(a, target);
}