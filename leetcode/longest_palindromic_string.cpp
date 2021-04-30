#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() < 1) return "";
        if (s.length() == 1) return s;
        int start = 0, end = 0;
        for (int i = 0; i < s.length(); i++) {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i + 1);
            int len = max(len1, len2);
            if (len > abs(end - start + 1)) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start,end-start+1);
    }

private:
    int expandAroundCenter(string s, int left, int right) {
        int L = left, R = right;
        while (L >= 0 && R < s.length() && s[L] == s[R]) {
            L--;
            R++;
        }
        return R - L - 1;
    }
};

int main_longest_pal_string(){
    Solution s;
    cout<<s.longestPalindrome("cbbd");
    //string z = "cbbd";//cbbd
    //cout<<endl<<z.substr(1,3);
}
