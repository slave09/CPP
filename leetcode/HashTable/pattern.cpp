#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char,string>map;
        unordered_map<string,char>map2;
        stringstream str(s);
        string word;
        int i = 0;
        while(str >> word){
            char key = pattern[i++];
            if( map.find(key) != map.end() ){
                if (map[key] != word || map2[word] != key) return false;
                else map.erase(key);
            }
            else if (map2.find(word) != map2.end()){
                if(map2[word] != key) return false;
                else map[key] = word;
            }
            else{
                map[key] = word;
                map2[word] = key;
            }
        }
        return  i < pattern.length() ? false : true;
    }
};

int main(){
  Solution newPattern;
  cout<<newPattern.wordPattern("abba","dog cat cat dog");
  return 0;
}

