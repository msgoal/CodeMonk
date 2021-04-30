#include <vector>
#include <iostream>
#include <map>

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
};

int main_two_sum(){
    vector<int> nums({3,2,4});

    Solution x;
    x.twoSum(nums,6);
}