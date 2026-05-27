class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int l =0;
       int m =0;
       int a= nums1.size();
       int b= nums2.size();
       vector<int>temp;
       while(l<a && m<b){
          if(nums1[l] <nums2[m]){
             temp.push_back(nums1[l]);
             l++;
          }
          else if(nums1[l] >nums2[m]){
            temp.push_back(nums2[m]);
             m++;
          }
          else{
             temp.push_back(nums2[m]);
             temp.push_back(nums1[l]);
             l++;
             m++;
          }
       }
       while(l<a){
          temp.push_back(nums1[l]);
             l++;
       }
       while(m<b){
         temp.push_back(nums2[m]);
             m++;
       }
       int size = temp.size();
       double result;
       if(size % 2==0){
           int med=size/2;
           int second=med-1;
           result=(double) (temp[med]+temp[second])/2;
           
       }
       else{
           int med=size/2;
           result=temp[med];
       }
        return result;
    }
};