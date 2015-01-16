#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int mapping(string c){
        if(c == "M") return 1000;
        if(c == "CM") return 900;
        if(c == "D") return 500;
        if(c == "CD") return 400;
        if(c == "C") return 100;
        if(c == "XC") return 90;
        if(c == "L") return 50;
        if(c == "XL") return 40;
        if(c == "X") return 10;
        if(c == "IX") return 9;
        if(c == "V") return 5;
        if(c == "IV") return 4;
        if(c == "I") return 1;
        return 0;        
    }

    int romanToInt(string s) {
        int result = 0;
        for(int i=0; i<s.size(); i++){
            string str = s.substr(i,2);
            int tmp = mapping(str);
            if(tmp) i++;
            else{
                str = s.substr(i,1);
                tmp = mapping(str);
            }
            result += tmp;
        }
        return result;
    }
};

int main(){
    string str;
    cin >> str;
    Solution *s = new Solution();
    cout << s->romanToInt(str);
    return 0;
}
