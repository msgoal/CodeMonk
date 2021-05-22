#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    Solution(){}
    vector<int> twoSum(vector<int>& nums, int target) {
        int s = 0;
        map<int,int> mape;
        for(int i=0;i<nums.size();i++){
            int ele = target-nums[i];
            if(mape.find(ele)!=mape.end()){
                nums.clear();
                nums.push_back(mape[ele]);
                nums.push_back(i);
            }
            mape[nums[i]]=i;
        }
        return nums;
    }

    vector<vector<int>> twoSum_2ptr(vector<int> nums,int target,int start){
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
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

int main_two_sum(){
    vector<int> nums({3,2,4});

    Solution x;
    for(auto i : x.twoSum(nums,6)){
        cout<<i<<" ";
    }
}