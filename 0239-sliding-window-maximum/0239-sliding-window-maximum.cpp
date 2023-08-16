class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int>ms;
        vector<int>v;
        int n=nums.size();
        for(int i=0;i<k;i++) ms.insert(nums[i]);
        v.push_back(*(--ms.end()));
        for(int i=k;i<n;i++){
            ms.erase(ms.find(nums[i-k]));
            ms.insert(nums[i]);
            v.push_back(*(--ms.end()));
        }
        return v;
    }
};