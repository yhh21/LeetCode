package test;

public class Leetcode0283 {
	public void moveZeroes(int[] nums) {
		int zn = 0;
        for (int i = 0; i < nums.length; i++) {
			if(nums[i] == 0){
				++zn;
			}else {
				nums[i - zn] = nums[i];
			}
		}
        for (int i = 1 ; i <= zn ; i++) {
			nums[nums.length - i] = 0;
		}
    }
}
