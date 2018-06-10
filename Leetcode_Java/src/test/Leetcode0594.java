package test;

import java.util.Arrays;

public class Leetcode0594 {
    public int findLHS(int[] nums) {
    	Arrays.sort(nums);
    	int t1 = 0 , t1n = 0 , t2n = 0;
    	int res = 0;
    	for (int i = 0; i < nums.length; i++) {
			if(nums[t1] == nums[i]){
				++t1n;
			}else if (nums[i] - nums[t1] == 1) {
				++t2n;
			}else {
				if (t2n != 0 && nums[t1] + 2 == nums[i]) {
					t1 = i - 1;
					t1n = t2n;
					t2n = 1;
				}else {
					t1 = i;
					t1n = 1;
					t2n = 0;
				}
			}
			if(t2n > 0){
				res = Math.max(res, t1n + t2n);
			}
		}
    	return res;
    	
//    	1.
//        HashMap<Integer, Integer> map = new HashMap<>();
//        for (int i = 0; i < nums.length; i++) {
//			map.put(nums[i], map.getOrDefault(nums[i], 0) + 1);
//		}
//        int res = 0;
//        for (int i : map.keySet()) {
//			if(map.containsKey(i + 1)){
//				res = Math.max(res, map.get(i) + map.get(i + 1));
//			}
//		}
//        return res;
    }
}
