class Solution {
public:
	int kthFactor(int n, int k) {
		vector<int>v;
		if( k > ((n+1)/2) ) return -1;
		for(int i = 0; i < n; ++i){
			if(n % (i+1) == 0) v.push_back(i+1);
			if(v.size() == k) return v.back();
		}
		return -1;
	}
};