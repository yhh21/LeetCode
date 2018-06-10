package test;


public class Leetcode0506 {
	
	int [] ts;
	
    public String[] findRelativeRanks(int[] nums) {
        String [] res = new String[nums.length];
        ts = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
			ts[i] = i;
		}
        fastsort(nums, 0, nums.length - 1);
        for (int i = 0; i < ts.length; i++) {
			if(i == 0){
				res[ts[i]] = "Gold Medal";
			}else if (i == 1) {
				res[ts[i]] = "Silver Medal";
			}else if (i == 2) {
				res[ts[i]] = "Bronze Medal";
			}else {
				res[ts[i]] = "" + (i + 1);
			}
		}
        return res;
    }
    
    private void fastsort(int[] nums ,int s , int e) {
    	if(s >= e){
    		return;
    	}
		int i = s , j = e;
		int t = nums[i] , tn = ts[i];
		while(i < j){
			while(nums[j] <=  t && i < j){//从后数较t大
				--j;
			}
			nums[i] = nums[j];
			ts[i] = ts[j];
			while(nums[i] > t && i < j){//从前数较t小
				++i;
			}
			nums[j] = nums[i];
			ts[j] = ts[i];
		}
		nums[i] = t;
		ts[i] = tn;
		
		fastsort(nums, s, i);
		fastsort(nums, i + 1, e);
	}
}
