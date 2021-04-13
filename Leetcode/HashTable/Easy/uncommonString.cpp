class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        map<string, int> word_count;
        vector<string> result;
        stringstream s(A);
        string word;
        while(s >> word) word_count[word] ++;
         stringstream t(B);
        while(t >> word) word_count[word]++;
        for(auto w : word_count)
            if(w.second == 1) result.push_back(w.first);
        return result;
    }
};