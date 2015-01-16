#include <iostream> 

using namespace std;

class Solution {
	public:
    string intToRoman(int num) {
		int arab[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
		string roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
		string str;
		int i = 0;
		while(num){
			int count = num/arab[i];
			num = num % arab[i];
			for(int j=0; j<count; j++) str+=roman[i];
			++i;
		}
		return str;
	}
};

int main(){
	int n;
	cin >> n;
	Solution *s = new Solution();
	cout << s->intToRoman(n);
	return 0;
}
