package test;

public class Leetcode0645 {
    public int[] findErrorNums(int[] nums) {
        //n = 2 - 10000 , 1 - n
    	final int N = nums.length + 1;
    	boolean [] map = new boolean [N];
    	int [] res = new int [2];
    	for (int i : nums) {
			if(map[i]){
				res[0] = i;
			}else {
				map[i] = true;
			}
		}
    	for (int i = 1; i < N; i++) {
			if(!map[i]){
				res[1] = i;
			}
		}
    	return res;
    }
}
