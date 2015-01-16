#include <iostream>

using namespace std;

string preProcess(string s){
	int size = s.size();
	if(size==0) return "^$";
	string returnStr = "^";
	for(int i=0; i<size; i++){
		returnStr = returnStr + "#" + s[i];
	}
	returnStr += "#$";
	return returnStr;
}

string longestPalidrome(string s){
	string T = preProcess(s);
	int size = T.size();
	int *p = new int[size];
	int c=0, r=0;
	for(int i=1; i< size-1; i++){
		int j = 2*c - i;
		p[i] = (r>i)?min(r-i,p[j]):0;
		while(T[i+p[i]+1]==T[i-p[i]-1]) p[i]++;
		if(i+p[i]>r){
			c=i;
			r=i+p[i];
		}
	}

	int maxLen = 0;
	int centerIndex = 0;
	for(int i=1; i<size-1; i++){
		if(p[i]>maxLen){
			maxLen = p[i];
			centerIndex = i;
		}
	}
	delete[] p;
	return s.substr((centerIndex-1-maxLen)/2, maxLen);
}

int main(){
	string str;
	cin >> str;
	cout<<longestPalidrome(str)<<endl;
	return 0;
}
