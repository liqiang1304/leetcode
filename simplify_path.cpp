#include <iostream>
#include <vector>

using namespace std;

class Solution{
	public:
	string simplifyPath(string const& path){
		vector<string> vec;
		int i = 0;
		while(i<path.size()){
			int inc = 1;
			while(path[i+inc]!='/' && path[i+inc]!='\0') inc++;
			string sub = path.substr(i+1,inc-1);
			if(sub==".." && vec.size()!=0){
				vec.pop_back();	
			}else if(sub!="." && sub!="" && sub!=".."){
				vec.push_back(sub);
			}
			i+=inc;
		}
		string result = "";
		for(int i=0; i<vec.size(); i++){
			result += "/" + vec[i];
		}
		return result==""?"/":result;

	}

};

int main(){
	string path;
	cin >> path;
	Solution *s = new Solution();
	cout << s->simplifyPath(path);

	return 0;
}
