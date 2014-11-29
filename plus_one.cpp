#include <iostream>
#include <vector>

using namespace std;
 
class Solution{
    public:
    vector<int> method(vector<int> &digits) {
        int size = digits.size();
        int jw = 0;
        for(int i=0; i<size; ++i){
            digits[i] = digits[i] + jw + 1;
            jw = digits[i]/10;
            digits[i] = digits[i]%10;
        }
        if(jw) digits[size] = 1;
        return digits;
    }
};

int main(){
    vector<int> a;
    int n, tmp;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> tmp;
        a.push_back(tmp);
    }
    Solution *solution = new Solution();
}