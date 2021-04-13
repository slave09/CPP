class Solution {
public:
	int hammingWeight(uint32_t n) {
		int mask = 1;
		int bits = 0;

		for(int i = 0; i < 32; ++i){
			if(n & (mask << i)) bits++;
		}

		return bits;
	}
};

class Solution {
public:
	int hammingWeight(uint32_t n) {
		int ans = 0;
		while(n > 0){
			ans++;
			n &= (n-1);
		}
		return ans;
	}
};