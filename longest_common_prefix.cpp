#include <iostream>
#include <vector>

using namespace std;

class Solution{
	public:
		string longestCommonPrefix(vector<string> &strs){
			if(strs.empty()) return "";
			for(int i=0; i<strs[0].size(); ++i){
				for(int j=0; j<strs.size(); ++j){
					if(strs[j][i] != strs[0][i]) return strs[0].substr(0, i);
				}
			}
			return strs[0];
		}
};

int main(){
	vector<string> strs;
	string str;
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> str;
		strs.push_back(str);
	}
	Solution *s = new Solution();
	cout << s->longestCommonPrefix(strs);
	return 0;
}
