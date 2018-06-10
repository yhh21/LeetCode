package test;

public class Leetcode0001 {
	public int[] twoSum(int[] nums, int target) {
		int [] hash = new int[Short.MAX_VALUE];
		final int M = 999;
		int c, i ;
		
		for(i = 0 ; i < nums.length ; ++i) {
			c = target - nums[i] + M;
			if(hash[c] == 0){
				hash[nums[i] + M] = i + 1 ;
				continue;
			}
			return new int[]{hash[c] - 1 ,i};
		}
		return null;
		
		
//		2.如果数组有序
//		int i = 0, j = nums.length - 1;
//		for(;;){
//			for(; nums[i] + nums[j] > target; --j);
//			if(nums[i] + nums[j] < target){
//				++i;
//				continue;
//			}
//			return new int[]{i,j};
//		}
		
//		1.
//        for(int i = 0 ; i < nums.length ; ++i ){
//        	for(int j = nums.length - 1 ; j > i ; --j){
//        		if(nums[i] + nums[j] < target){
//        			continue;
//        		}else if(nums[i] + nums[j] == target){
//        			return new int[]{i,j};
//        		}
//        	}
//        }
//		return null;
    }
}
