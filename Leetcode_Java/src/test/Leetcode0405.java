package test;

public class Leetcode0405 {
    public String toHex(int num) {
    	char [] cs = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
    	if (num == 0) {
			return "0";
		}
    	StringBuilder res = new StringBuilder();
        while (num != 0) {
			res.insert(0, cs[num & 15]);
			num >>>= 4;
		}
        return res.toString();
    }
}
