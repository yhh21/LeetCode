package test;

public class Leetcode0169 {
    public int majorityElement(int[] nums) {
        int m = nums[0] , n = 1;
        for (int i = 1; i < nums.length; i++) {
			if(n == 0){
				++n;
				m = nums[i];
			}else if (m == nums[i]) {
				++n;
			}else {
				--n;
			}
		}
        return m;
    }
}
