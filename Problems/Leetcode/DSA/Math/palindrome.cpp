class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int temp = x;
        long long palindrome = 0;
        while(temp ){
            palindrome = 10 * palindrome + temp % 10;
            temp /= 10;
        }
        return x == palindrome;
    }
};