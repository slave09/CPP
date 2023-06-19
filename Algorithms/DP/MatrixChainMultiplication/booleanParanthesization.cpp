/*
 # Boolean Paranthesization

 - determine the number of ways we can parenthesize a given boolean expression such that it evaluates to true.

 Constraints:
    The boolean expression consists of symbols 'T' (representing true) and 'F' (representing false) as well as operators '&', '|', and '^'.
    The expression can have a length of N, where N is a positive integer.
    The symbols and operators must be placed in a valid boolean expression format.
    Parentheses can be added to change the order of evaluation.
*/

#include<bits/stdc++.h>
using namespace std;

int numOfWaysToParan(string s, int front, int end, int isTrue){
    if(front > end) return 0;
    if(front == end) return (isTrue && s[front] == 'T') || (!isTrue && s[front] == 'F'); 

    int ans = 0;

    for(int k = front + 1; k < end; k += 2){
        int left_true = numOfWaysToParan(s, front, k - 1, true);
        int left_false = numOfWaysToParan(s, front, k - 1, false);
        int right_true =  numOfWaysToParan(s, k + 1, end, true);
        int right_false = numOfWaysToParan(s, k + 1, end, false);
        if(s[k] == '|') ans += isTrue ? (left_true * right_false) + (left_false*right_true) + (left_true*right_true) : left_false * right_false; 
        else if(s[k] == '&') ans += isTrue ?  left_true * right_true : (left_true * right_false) + (left_false*right_true) + (left_false*right_false); 
        else if(s[k] == '^') ans += isTrue ? (left_true * right_false) + (left_false*right_true) : (left_false * right_false) + (left_true*right_true) ; 
    }
    return ans;
}

int main(){
    string s = "T^F&T";
    cout << "Number Of Ways to Paranthesize : " << numOfWaysToParan(s, 0, s.size() - 1, true) << endl;
    return 0;
}