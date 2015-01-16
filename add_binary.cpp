#include <iostream>
#include <algorithm>

using namespace std;

string addBinary(string a, string b){
	string result;
	int sizea = a.size();
	int sizeb = b.size();
	int maxSize = sizea>sizeb?sizea:sizeb;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int jw = 0;
	for(int i=0; i<maxSize; i++){
		int ai = i<sizea?a[i]-'0':0;
		int bi = i<sizeb?b[i]-'0':0;
		int val = (ai+bi+jw)%2;
		jw = (ai+bi+jw)/2;
		result.insert(result.begin(), val+'0');
	}
	if(jw==1){
		result.insert(result.begin(), '1');
	}
	return result;
}

int main(){
	string str1, str2;
	cin >> str1;
	cin >> str2;
	cout << addBinary(str1, str2) << endl;
	return 0;
}
