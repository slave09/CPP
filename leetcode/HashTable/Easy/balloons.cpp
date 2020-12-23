class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char,int>letters;
        int ans = 0;
        auto index = NULL;
        string balloon = "balloon";
        for(auto t : text) letters[t]++;
        do{
            for(auto str : balloon){
                index = str;
                if(letters[str] < 1) return ans;
                letters[str]--;
            }
            ans++;
        }while(letters[index] > 0);
        return ans;
    }
};