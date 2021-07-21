class Solution {
public:
  vector<int> countBits(int num) {
    vector<int>result;
    result.push_back(0);
    long int sum = 1;
    int end = 1;
    
    for(int i = 1; i <= num; ++i){
     if(i == end){
       result.push_back(1);
       end = 2 * end;
     }
     else if( i % 2 == 0)
       result.push_back(result[end/2] + result[i - end/2]);
     else result.push_back(result[i-1]+1);
   }
   return result;
 }
};