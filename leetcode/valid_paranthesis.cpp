#include <iostream>
#include <stack>

using namespace std;


class Solution {
public:
    bool isValid(string s) {
        int len = s.length();
        stack<char> stk;
        for(int i=0;i<len;i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                stk.push(s[i]);
            else{
                if(stk.empty()) return false;
                char ch = stk.top();
                switch(s[i]){
                    case ']':if(ch == '['){
                                stk.pop();
                              }else return false;
                            break;
                    case '}':if(ch == '{'){
                                stk.pop();
                             }else return false;
                             break;
                    case ')':if(ch == '('){
                                stk.pop();
                            }else return false;
                            break;
                }
            }
        }
        return stk.size() == 0;
    }
};

int main_valid_paranthesis(){
    Solution s;

    cout<<s.isValid("]");

    return 0;
}