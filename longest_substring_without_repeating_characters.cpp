#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring1(string s) {
        map<string,int> val_map;
        int i=0,n=s.size(),max=0,last_index=0;
        string substr="";
        while(i < n){
            string ch = "";
            ch += s[i];

            if(!(val_map.find(ch)!=val_map.end())) {
                val_map[ch] = i;
                substr.append(ch);
            }else{
                i = val_map[ch]+1;
                max = (max < substr.length())? substr.length() : max;
                val_map.clear();
                substr.clear();

                ch = "";
                ch += s[i];
                val_map[ch]=i;
                substr.append(ch);
            }
            i++;
        }
        return  (max < substr.length())? substr.length() : max;
    }

    int lengthOfLongestSubstring(string s){
        map<char,int> val_map;
        int i=0,n = s.length(),cur_val=0,max=0,index=0;
        while(i < n){

            if(val_map.count(s[i]) && val_map[s[i]] >= index){
                index = val_map[s[i]];
                cur_val = i - index - 1;
            }

            val_map[s[i]] = i;
            cur_val++;

            if(max < cur_val)
                max = cur_val;

            i++;
        }
        return max;
    }
};



int main_longest_substring(){
    Solution s;

    cout<<s.lengthOfLongestSubstring("abba");
}

