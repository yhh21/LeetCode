package test;

public class Leetcode0551 {
    public boolean checkRecord(String s) {
        char [] cs = s.toCharArray();
        int as = 0 , ls = 0;
        for (char c : cs) {
			if(c == 'A'){
				++as;
				ls = 0;
				if(as > 1){
					return false;
				}
			}else if (c == 'L') {
				++ls;
				if (ls > 2) {
					return false;
				}
			}else {
				ls = 0;
			}
		}
        return true;
    }
}
