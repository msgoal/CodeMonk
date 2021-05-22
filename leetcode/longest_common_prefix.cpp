#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix_using_vertical_scanning(vector<string>& strs) {
        char prefix;
        int prefix_count,flag=0;
        for(int i=0;i<strs[0].length();i++){
            prefix = strs[0][i];
            for(int j=1;j<strs.size();j++){
                if(i == strs[j].size() || prefix != strs[j][i])
                    return strs[0].substr(0,i);
            }
        }
        return strs[0];
    }
    string longestCommonPrefix(vector<string>& strs){

    }
};

int main_cxz(){
    Solution s;
    vector<string> v{"flower","flow","flight"};
    cout<<s.longestCommonPrefix_using_vertical_scanning(v);
}