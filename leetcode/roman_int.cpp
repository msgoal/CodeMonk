#include <iostream>
#include "string"

using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int last_val= number_to_roman(s[0]),ans=last_val,x;
        for(int i=1;i<s.length();i++){
            x = number_to_roman(s[i]);
            if(x <= last_val)
                ans += x;
            else{
                ans = ans - last_val + (x - last_val);
            }
            last_val = x;
        }
        return ans;
    }
private:
    inline int number_to_roman(char c){
        switch(c){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return 0;
    }
};
int main_roman_int(){
    Solution s;
    cout<<endl<<s.romanToInt("");
}