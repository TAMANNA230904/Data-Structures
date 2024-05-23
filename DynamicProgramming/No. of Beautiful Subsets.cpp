You are given an array nums of positive integers and a positive integer k.

A subset of nums is beautiful if it does not contain two integers with an absolute difference equal to k.

Return the number of non-empty beautiful subsets of the array nums.

A subset of nums is an array that can be obtained by deleting some (possibly none) elements from nums. Two subsets are different if and only if the chosen indices
to delete are different.

  class Solution {
public:
void solve(vector<int>& nums,int i, int k,unordered_map<int,int> &mp,int &ans){
    if(i>=nums.size()){
        ans++;
        return;
    }
    solve(nums,i+1,k,mp,ans);
    if(!mp[nums[i]-k]  && !mp[nums[i]+k]){
        mp[nums[i]]++;
        solve(nums,i+1,k,mp,ans);
        mp[nums[i]]--;
    }
}
    int beautifulSubsets(vector<int>& nums, int k) {
       unordered_map<int,int> mp;
       int ans=0;
       solve(nums,0,k,mp,ans);
       return ans-1;
       
    }
};
