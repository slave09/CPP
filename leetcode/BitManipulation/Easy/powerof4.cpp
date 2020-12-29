class Solution {
public:
	bool isPowerOfFour(int n) {
		if(n <= 0 ) return false;
		if( n == 1) return true;
		return  (__builtin_popcount(n) == 1) && __builtin_ctz(n) % 2 == 0;
	}
};