//
// Created by root on 22/05/21.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string s;
        vector<string> result;
        if(digits.length() == 0) return result;
        letter_comb(digits,result,s,0);
        return result;
    }
private:
    void letter_comb(string digits,vector<string> &res,string &curr,int index){
        if(digits.size() == index) {
            res.push_back(curr);
            return ;
        }
        for(int i = 0;i < str_comb(digits[index]).length();i++){
            curr.push_back(str_comb(digits[index])[i]);
            letter_comb(digits,res,curr,index+1);
            curr.pop_back();
        }
    }
    inline string str_comb(char digit){
        switch(digit){
            case '0':
            case '1': return "";
            case '2': return "abc";
            case '3': return "def";
            case '4': return "ghi";
            case '5': return "jkl";
            case '6': return "mno";
            case '7': return "pqrs";
            case '8': return "tuv";
            case '9': return "wxyz";
        }
        return "";
    }
};

int main_letter_combinations(){
    Solution s;
    vector<string> res;
    string str;
    s.letterCombinations("23");
    return 0;
}