package test;

public class Leetcode0217 {
    public boolean containsDuplicate(int[] nums) {
    	if(nums.length < 2){
    		return false;
    	}
        int i = nums[0];
        for (int j = 1; j < nums.length; j++) {
			i ^= nums[j];
		}
        return i == 0;
    }
}
