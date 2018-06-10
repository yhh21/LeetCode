package test;

public class Leetcode0496 {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
    	int t = 0, j = 0;
    	
    	IC:
        for (int i = 0; i < nums1.length; ++i) {
        	t = nums1[i];
			for (j = 0; j < nums2.length; ++j) {
				if(nums2[j] != t){
					continue;
				}else {
					break;
				}
			}
			for(++j ; j < nums2.length ; ++j){
				if(nums2[j] > t){
					nums1[i] = nums2[j];
					continue IC;
				}
			}
			nums1[i] = -1;
		}
    	return nums1;
    }
}
