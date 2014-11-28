#include <iostream>
#include <vector>

using namespace std;

class Solution{
	public:
		int candy(vector<int> &ratings){
			int total = 1, incLength = 1, decLength = 0, tmpinc = 1;
			int size = ratings.size();
			if(size == 0) return 0;
			for(int i=0; i<size-1; i++){
				if(ratings[i]>ratings[i+1]){
					incLength = 1;
					decLength++;
					if(tmpinc<=decLength){
						total++;
					}
					total += decLength;				
				}else{
					if(ratings[i]==ratings[i+1]){
						incLength = 1;
					}else{
						incLength++;			
					}
					decLength = 0;
					total += incLength;
					tmpinc = incLength;
				}			
			}
			return total;
		}
};

int main(){
	int n, tmp;
	vector<int> ratings;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>tmp;
		ratings.push_back(tmp);
	}
	Solution *s = new Solution();
	cout<<s->candy(ratings)<<endl;
}
