class Solution {
public:
  int myAtoi(string s) {

    bool neg = false;
    int integer = 0;
    int index = 0;

    while(s[index] == ' ') index++;

    for(int i = index; i < s.size(); ++i){

      if(i == index && s[i] == '-') neg = true;
      else if(i == index && s[i] == '+') neg = false;

      else if(s[i] >= '0' && s[i] <= '9'){
        
        if(integer > INT_MAX / 10 ||
          (integer == INT_MAX / 10 && s[i] - '0' > INT_MAX % 10))
          return neg ? INT_MIN : INT_MAX;
      integer = (10 * integer) + (s[i] - '0');
    }

    else return !neg ? integer : -1 * integer;     
  }
  
  return !neg ? integer : -1 * integer;
}
};