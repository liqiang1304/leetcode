#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//TLE? 
class Solution{
	public:
		vector<vector<int> > method(vector<int> &num){
			vector<vector<int> > result;
			int size = num.size();
			if(size<3) return result;
			sort(num.begin(), num.end());
			for(int i=0; i<size-2; ++i){
				int head = i+1; int tail= size-1;
				while(head < tail){
					int total = num[i] + num[head] + num[tail];
					if(total<0){
						++head;
					}else if(total>0){
						--tail;
					}else{
						vector<int> tmp;
						tmp.push_back(num[head]);
						tmp.push_back(num[i]);
						tmp.push_back(num[tail]);
						result.push_back(tmp);
						// result.push_back({num[head], num[i], num[tail]});
						++head;
						--tail;
					}
				}
			}
			sort(result.begin(), result.end());
			result.erase(unique(result.begin(), result.end()), result.end());
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
	Solution *solution = new Solution();
	// cout << solution->method(a, target);
	vector<vector<int> > result = solution->method(a);
	for(int i=0; i<result.size(); i++){
		vector<int> tmp = result[i];
		for(int j=0; j<3; j++){
			cout << tmp[j] << " ";
		}
		cout << endl;
	}
}