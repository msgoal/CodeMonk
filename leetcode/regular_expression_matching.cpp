#include <iostream>

using namespace std;

enum Result{
    FALSE,TRUE
};
class Solution {
public:
    bool isMatchrec(string s, string p) {
        if(p.empty()) return s.empty();

        bool charMatch = !s.empty() && (s[0] == p[0] || p[0] == '.');

        if(p.length() >= 2 && p[1] == '*'){
            return isMatchrec(s,p.substr(2)) ||
                    (charMatch && isMatchrec(s.substr(1),p));
        }else{
            return charMatch && isMatchrec(s.substr(1),p.substr(1));
        }
    }
};

//implement top-down and bottom up in DP

int main_regular_expression_matching(){
    Solution s;

    cout<<endl<<s.isMatchrec("aab","c*a*b");
}