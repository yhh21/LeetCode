package test;

public class Leetcode0520 {
	public boolean detectCapitalUse(String word) {
		int u = 0;
		boolean low = false;
        char [] cs = word.toCharArray();
        for (int i = 0; i < cs.length; ++i) {
			if(cs[i] <= 'Z'){
				if(low){
					return false;
				}
				++u;
			}else {
				low = true;
				if (u > 1) {
					return false;
				}
			}
		}
        return (u == 1 && cs[0] <= 'Z') || u == 0 || !low;
    }
}
