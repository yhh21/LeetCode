package test;

public class Leetcode0492 {
    public int[] constructRectangle(int area) {
    	for (int i = (int)Math.sqrt(area); i > 0; --i) {
			if(area % i == 0){
				return new int[]{area/i,i};
			}
		}
        return null;
    }
}
