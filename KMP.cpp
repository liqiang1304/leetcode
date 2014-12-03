#include <iostream>

using namespace std;

int *initKMP(string str){
	int size = str.size();
	int *next = new int[size];
	int j = -1;
	next[0] = -1;
	if(size==1) return next;
	for(int i=1; i<size; i++){
		while((j>=0)&&(str[j+1]!=str[i])) j=next[j];
		if(str[j+1]==str[i]) j++;
		next[i] = j;
	}
	return next;
}

int findStr(string original, string index){
	int *next = initKMP(index);
	int originalSize = original.size();
	int indexSize = index.size();
	int j = -1;
	if(indexSize==0) return 0;
	for(int i=0; i<originalSize; i++){
		while((j>=0)&&(original[i]!=index[j+1])) j = next[j];
		if(original[i]==index[j+1]) j++;
		if(j==indexSize-1){
			return i-indexSize+1;
		}
	}
	return -1;
}

int main(){
	string str1, str2;
	cin >> str1;
	cin >> str2;
	cout << findStr(str1, str2) << endl;
	return 0;
}
