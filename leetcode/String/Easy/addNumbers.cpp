class Solution {
public:
    string addStrings(string num1, string num2) {
        int index1 = num1.size() - 1;
        int index2 = num2.size() - 1;
        int carry = 0;
        string res = "";
        while(index1 >= 0 && index2 >= 0){
            res += to_string((num1[index1] - '0' + num2[index2] - '0' + carry) % 10);
            if((num1[index1] - '0' + num2[index2] - '0' + carry)  < 10)
                carry = 0;
            else carry = 1;
            index1--, index2--;
        }
        while(index1 >= 0){
            res += to_string((num1[index1] - '0' + carry) % 10);
            if((num1[index1] - '0' + carry) < 10)
                carry = 0;
            else carry = 1;
            index1--;
            
        }
         while(index2 >= 0){
            res += to_string((num2[index2] - '0' + carry) % 10);
            if((num2[index2] - '0' + carry)  < 10)
                carry = 0;
            else carry = 1;
             index2--;
        }
        if(carry == 1) res += "1";
        reverse(res.begin(), res.end());
        return res;
    }
};