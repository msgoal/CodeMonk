#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        int l,u;
        int diff = INT32_MAX;
        sort(nums.begin(),nums.end());

        for(int i=0;i<len-2 && diff != 0;i++){
            l = i + 1;
            u = len - 1;
            while( l < u){
                int sum = nums[i] + nums[l] + nums[u];
                if (abs(target - sum) < abs(diff))
                    diff = target - sum;
                if (sum < target)
                    ++l;
                else
                    --u;
            }
        }
        return target-diff;
    }
};

int main_3sum_closest(){

    Solution s;
    vector<int> v{};

    cout<<endl<<s.threeSumClosest(v,9);
    return 0;
}