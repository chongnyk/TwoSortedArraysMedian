class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int lengthOne = nums1.size();
        int lengthTwo = nums2.size();
        int indexOne = 0;
        int indexTwo = 0;
        int medianOne = 0;
        int medianTwo = 0;

        for(int i = 0; i <= (lengthOne + lengthTwo)/2; i++){
            medianTwo = medianOne;
            if(indexOne != lengthOne && indexTwo != lengthTwo){
                if(nums1[indexOne] > nums2[indexTwo]){
                    medianOne = nums2[indexTwo];
                    indexTwo++;
                }
                else {
                    medianOne = nums1[indexOne];
                    indexOne++;
                }
            } else if(indexOne < lengthOne){
                medianOne = nums1[indexOne];
                indexOne++;
            }
            else {
                medianOne = nums2[indexTwo];
                indexTwo++;
            }
        }

        if((lengthOne + lengthTwo) % 2 == 0){
            double result = (static_cast<double>(medianOne) + static_cast<double>(medianTwo))/2.0;
            return result;
        }
        else {
            double result = static_cast<double>(medianOne);
            return result;
        }
    }
};
