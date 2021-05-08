#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string res;
        int place=1;
        while(num > 0){
            res = roman_for_digit(num % 10,place++) + res;
            num /= 10;
        }
        return res;
    }

private:
    inline string roman_for_digit(int num,int place){
        switch (place) {
            case 1: switch(num){
                    case 1: return "I";
                    case 2: return "II";
                    case 3: return "III";
                    case 4: return "IV";
                    case 5: return "V";
                    case 6: return "VI";
                    case 7: return "VII";
                    case 8: return "VIII";
                    case 9: return "IX";
                    default: return "";
            }
            case 2: switch(num){
                    case 1: return "X";
                    case 2: return "XX";
                    case 3: return "XXX";
                    case 4: return "XL";
                    case 5: return "L";
                    case 6: return "LX";
                    case 7: return "LXX";
                    case 8: return "LXXX";
                    case 9: return "XC";
                    default: return "";
            }
            case 3: switch(num){
                    case 1: return "C";
                    case 2: return "CC";
                    case 3: return "CCC";
                    case 4: return "CD";
                    case 5: return "D";
                    case 6: return "DC";
                    case 7: return "DCC";
                    case 8: return "DCCC";
                    case 9: return "CM";
                    default: return "";
                }
            case 4: switch(num){
                    case 1: return "M";
                    case 2: return "MM";
                    case 3: return "MMM";
                    case 4: return "MMMM";
                    default: return "";
                }
        }
    }
};

int main_int_roman(){
    Solution s;

    cout<<endl<<s.intToRoman(1994);
}