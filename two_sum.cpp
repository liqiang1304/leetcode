#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
	public:
		vector<int> method(vector<int> &numbers, int target){
			std::vector<int> result;
			unordered_map<int, int> map;
			int size = numbers.size();
			for(int i=0; i<size; i++){
				map[numbers[i]] = i;
			}
			for(int i=0; i<size; i++){
				if(map.find(target-numbers[i])!=map.end()){
					result.push_back(i+1);
					result.push_back(map[target-numbers[i]]+1);
					break;
				}
			}
			return result;
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
	// cout << solution->method(a, target);
	vector<int> result = solution->method(a, target);
	for(int i=0; i<result.size(); ++i){
		cout << result[i] << endl;
	}
}