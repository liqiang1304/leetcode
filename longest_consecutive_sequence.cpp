#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
	public:
		int method(vector<int> &num){
			int size = num.size();
			if(size == 0) return 0;
			int maxLength = 0;
			unordered_map<int, int> map;
			for(int i = 0; i<size; ++i){
				if(map.find(num[i]) != map.end()) continue;
				map[num[i]] = 1;
				int left =0, right=0;
				if(map.find(num[i]+1) != map.end()){
					right = mergeCluster(map, num[i], num[i]+1);
					cout << "right: " << right;
				}
				if(map.find(num[i]-1) != map.end()){
					left = mergeCluster(map, num[i]-1, num[i]);
					cout << "left: " << left << endl;
				}
				int tmp = (right<left)?left:right;
				maxLength = (maxLength<tmp)?tmp:maxLength;
			}
			return maxLength?maxLength:1;
		}

		int mergeCluster(unordered_map<int, int> &map, int left, int right){
			int upper = right + map[right] - 1;
			int lower = left - map[left] + 1;
			int length = upper - lower + 1;
			map[upper] = length;
			map[lower] = length;
			return length;
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
	Solution *solution = new Solution();
	cout << solution->method(a) << endl;
}
