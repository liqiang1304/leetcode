#include <iostream>

using namespace std;

class Solution{
public:
	bool isMatch(const char *s, const char *p){
		bool star = false;
		const char *str, *ptr;
		str = s; ptr = p;
		while(*str!='\0'){
			switch(*ptr){
				case '?':
					str++;
					ptr++;
					break;
				case '*':
					s = str; p = ptr;
					while(*p=='*') p++;
					star = true;
					if(*p=='\0') return true;
					str = s;
					ptr = p;
					break;
				default:
					if(*str!=*ptr){
						if(!star) return false;
						s++;
						str = s;
						ptr = p;
					}else{
						str++;
						ptr++;
					}
			}
		}
		while (*ptr == '*') ptr++;
		return (*ptr == '\0');
	}
};

int main(){
	char *a = new char[100];
	char *b = new char[100];
	cin >> a;
	cin >> b;
	Solution *s = new Solution();
	cout << s->isMatch(a, b);

	return 0;
}
