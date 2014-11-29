#include <iostream>
#include <vector>

using namespace std;

class Solution{
	public:
		int method(vector<int> &gas, vector<int> &cost){
			int result = -1;
			int total=0, sum=0;
			for(int i=0; i<gas.size(); ++i){
				sum += gas[i] - cost[i];
				total += gas[i] - cost[i];
				if(sum < 0){
					sum = 0;
					result = i;
				}
			}
			return (total>0)?result+1:-1;
		}
};

int main(){
	int n,tmp;
	cin >> n;
	vector<int> gas,cost;
	for(int i=0; i<n; i++){
		cin>>tmp;
		gas.push_back(tmp);	
	}
	for(int i=0; i<n; i++){
		cin>>tmp;
		cost.push_back(tmp);
	}
	Solution *s = new Solution();
	cout << s->method(gas, cost);
}
