package test;

public class Leetcode0409 {
    public int longestPalindrome(String s) {
        int [] map = new int [128];
        char [] cs = s.toCharArray();
        for (char c : cs) {
			++map[c];
		}
        int res = 0;
        boolean flag = true;
        for (int i = 'A'; i <= 'z'; i++) {
			if(flag && map[i] % 2 == 1){
				flag = false;
				res += 1;
			}
			if(map[i] >= 2)
				res += map[i] - map[i] % 2;
		}
        return res;
    }
}
