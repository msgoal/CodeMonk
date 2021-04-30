#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        if(x == 0) return 0;
        int rem,n = abs(x);
        long res=0;
        int sign=x/n;

        while(n != 0){
            rem = n % 10;
            if(!(res*10 >= INT32_MIN && res*10 <= INT32_MAX))
                return 0;
            res = res * 10 + rem;
            n = n/10;
        }
        return sign*res;
    }
};
int main_reverse_integer(){
    Solution s;
    cout<<endl<<" Result : "<<s.reverse(1534236469);
}