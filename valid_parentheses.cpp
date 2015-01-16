#include <iostream>
#include <stack>

using namespace std;

class Solution{
	public:
	bool isValid(string const& s){
		string left = "({[";
		string right = ")}]";
		stack<char> stk;

		for(int i=0; i<s.size(); i++){
			char c = s[i];
			if(left.find(c)!=string::npos){
				stk.push(c);
			}else{
				if(stk.empty() || stk.top()!= left[right.find(c)]) return false;
				else stk.pop();
			}
		}
		return stk.empty();
	}
};

int main(){
	string str;
	cin >> str;

	Solution *s = new Solution();
	cout << s->isValid(str);

	return 0;
}
