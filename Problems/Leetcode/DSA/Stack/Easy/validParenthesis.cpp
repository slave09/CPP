class Solution {
    
    bool closing_bracket(char c){
        return c == ']' || c =='}' || c == ')';
    }
    
    char opening_bracket(char c){
        if(c == ']') return '[';
        if(c == ')') return '(';
        if(c == '}') return '{';
        return '0';
    }
public:
    bool isValid(string s) {
        
        if(s.size() % 2 != 0) return false;
        
        stack<char>stk;
        
        for(int i = 0; i < s.size(); ++i){
            
            if(!closing_bracket(s[i])) stk.push(s[i]);
            
            else{
                if(stk.empty()) return false;
                char brack = stk.top();
                if(opening_bracket(s[i]) != brack) return false;
                stk.pop();
            }
        }
        return stk.empty() ? true : false;
    }
};