class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;
        int j=nums1.size()-1;
        int k=n-1;
       
        while(k>=0 && i>=0)
        {
            if(nums1[i]<nums2[k])
            {
                nums1[j--]=nums2[k--];
            }
            else{
nums1[j--]=nums1[i--];
            }
            

        }
      while(k>=0)
      {
        nums1[j--]=nums2[k--];
      }
    }
};