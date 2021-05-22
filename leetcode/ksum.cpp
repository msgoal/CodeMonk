#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        return ksum(nums,target,0,4);
    }
private:
    vector<vector<int>> ksum(vector<int>& nums, int target, int start, int k){
        vector<vector<int>> res;
        if(nums.size() < k)
            return res;

        if(k == 2){
            return twoSum(nums,target,start);
        }else{
            for(int i=start;i<nums.size()-k+1;i++){
                if(i > start && nums[i-1] == nums [i])
                    continue;
                for(auto v : ksum(nums,target-nums[i],start+1,k-1)){
                    res.push_back({nums[i]});
                    res.back().insert(end(res.back()), begin(v), end(v));
                }
            }
        }
        return res;
    }

    vector<vector<int>> twoSum(vector<int> nums,int target,int start){
        vector<vector<int>> res;
        int l=start,u = nums.size()-1,s;
        while (l < u){
            s = nums[l] + nums[u];
            if(s > target || (u < nums.size()-1 && nums[u] == nums[u+1]))
                u--;
            else if(s < target || (l > start && nums[l] == nums[l-1]))
                l++;
            else
                res.push_back({nums[l++],nums[u--]});
        }
        return res;
    }
};

int main_wait(){

    vector<int> v{1,0,-1,0,-2,2};
    Solution s;

    s.fourSum(v,0);
    return 0;
}