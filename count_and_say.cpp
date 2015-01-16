#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    string doit(string s){
        string result = "";
        for(int i=0; i<s.size(); i++){
            int numCnt = 1;
            while(s[i+1] == s[i]){
                numCnt++;
                i++;
            }
            char tmp1 = '0'+numCnt;
            char tmp2 = s[i];
            result += tmp1;
            result += tmp2;
        }
        return result;
    }

    string countAndSay(int n) {
        string begin = "1";
        for(int i=1; i<n; i++){
            begin = doit(begin);
        }
        return begin;
    }
};

int main(){
    int n;
    cin >> n;
    Solution *s = new Solution();
    cout << s->countAndSay(n);
    return 0;
}
