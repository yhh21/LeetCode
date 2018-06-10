package test;

//import java.util.Arrays;

public class Leetcode0561 {
    public int arrayPairSum(int[] nums) {
    	int [] map = new int [20001];
    	for (int i : nums) {
    		map[i + 10000]++;
		}
    	int d = 0;
    	int n = 0;
    	for (int i = 0; i < 20001; ++i) {
			if(map[i] != 0){
				n += (map[i] + 1 - d) / 2 * (i - 10000);
				d = (map[i] - d + 2) % 2;
			}
		}
    	return n;
    	
//    	1.
//        Arrays.sort(nums);
//        int n = 0;
//        for(int i = 0 ; i < nums.length ; i += 2){
//        	n += nums[i];
//        }
//        return n;
    }
}
