package test;

public class Leetcode0557 {
    public int distributeCandies(int[] candies) {
        boolean [] map = new boolean[200001];
    	int s = 0;
        for (int i : candies) {
        	if(!map[i + 100000]){
        		++s;
        		map[i + 100000] = true;
        		if(s >= candies.length / 2) {
                    return candies.length / 2;
                }
        	}
		}
        return s;
    }
}
