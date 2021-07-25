class Solution {
public:
    string defangIPaddr(string address) {
        string res = "";
        for(auto ad : address){
            if(ad == '.')
                res = res + '[' + ad + ']';
            else res += ad;
        }
        return res;
    }
};