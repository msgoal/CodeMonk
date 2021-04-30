#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int indx = 0,current_index = 0,len = s.size();
        int k = 2 * numRows - 2;
        string ret;
        if(numRows == 1) return s;
        for(int i=0;i<numRows;i++){
            current_index = i;
            while(current_index < len){
                ret += s[current_index];
                indx = current_index + (numRows - i - 1) + ((numRows - 2) - i + 1);
                if(i > 0 && i < numRows-1 && indx < len){
                    ret += s[indx];
                }
                current_index += k;
            }
        }
        return ret;
    }
};

int main_zigzag(){
    Solution s;
    cout<<s.convert("A",1);
}