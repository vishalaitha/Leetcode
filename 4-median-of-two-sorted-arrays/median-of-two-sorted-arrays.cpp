class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        nums2.insert(nums2.begin(),nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        if(nums2.size()&1){
            // cout<<<<endl;
            return nums2[nums2.size()/2]; 
        }
        else{
            return (nums2[nums2.size()/2-1]+nums2[nums2.size()/2])/2.00;
        }
        return 0.00;

    }
};