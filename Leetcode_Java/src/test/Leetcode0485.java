package test;

public class Leetcode0485 {
    public int findMaxConsecutiveOnes(int[] nums) {
        int rtn = 0 , t = 0;
        for (int i : nums) {
			if(i == 0){
				if(t > rtn){
					rtn = t;
				}
				t = 0;
				continue;
			}
			++t;
		}
        return Math.max(rtn, t);
    }
}
