package test;

public class Leetcode0268 {
    public int missingNumber(int[] nums) {
    	int sum = 0;
    	for (int i : nums) {
			sum += i;
		}
    	return nums.length * (nums.length + 1) / 2 - sum;
    	
//    	1.
//    	Arrays.sort(nums);
//        for (int i = 0; i < nums.length; i++) {
//			if(nums[i] != i){
//				return i;
//			}
//		}
//        return nums.length;
    }
}

