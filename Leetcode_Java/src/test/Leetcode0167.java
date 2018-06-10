package test;

public class Leetcode0167 {
    public int[] twoSum(int[] numbers, int target) {
        int [] map = new int [20000];
        for (int i = 0; i < numbers.length; i++) {
			if(map[numbers[i] + 10000] > 0){
				return new int[]{map[numbers[i] + 10000] , i + 1};
			}
			map[target - numbers[i] + 10000] = i + 1;
		}	
        return null;
    }
}
