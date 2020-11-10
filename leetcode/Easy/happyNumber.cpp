class Solution {
public:
  
    int squareSumOfDigits(int n){
      int sum = 0;
      while(n){
        sum += (n%10)*(n%10);
        n /= 10;
      }
      return sum;
    }
  
    bool isHappy(int n) {
      int slow ,fast;
      slow = fast = n;
      do{
        slow = squareSumOfDigits(slow);
        fast = squareSumOfDigits(fast);
        fast = squareSumOfDigits(fast);
        if (fast == 1) return true;
      }while(fast != slow);
      return false;
    }
};