#include <iostream>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int sign = 1,c = 0,num = 0,flag = false;
        for(int i=0;i<s.length();i++){
            if((s[i] == '-' || s[i] == '+') && !flag){
                sign = s[i] == '-' ? -1 : 1;
                flag = true;
                continue;
            }else if(isdigit(s[i])){
                if (num > INT32_MAX / 10 ||
                    (num == INT32_MAX / 10 && s[i] - '0' > INT32_MAX % 10)) {
                    return (sign == 1) ? INT32_MAX : INT32_MIN;
                }
                num = num * 10 + (s[i]-48);
                c++;
                flag = true;
                continue;
            }else if(isspace(s[i]) && !flag) continue;
            else {
                return (c == 0)? 0 : sign*num;
            }
        }
        return sign*num;
    }
};

int main_atoi(){
    Solution s;

    cout<<s.myAtoi("+0 123");
    return 0;
}