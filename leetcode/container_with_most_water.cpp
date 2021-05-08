#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,u=height.size()-1,maxarea=0;
        while(l < u){
            maxarea = max(maxarea, min(height[l],height[u]) * (u - l));
            if(height[l] <= height[u])
                l++;
            else
                u--;
        }
        return maxarea;
    }
};

int main_container(){
    Solution s;

    vector<int> v{4,3,2,1,4};

    cout<<s.maxArea(v);
}