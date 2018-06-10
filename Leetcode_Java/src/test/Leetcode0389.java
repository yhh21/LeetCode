package test;

public class Leetcode0389 {
    public char findTheDifference(String s, String t) {
    	int N = s.length();
        int [] map = new int [128];
        for (int i = 0; i < N ; ++i) {
			++map[s.charAt(i)];
			--map[t.charAt(i)];
		}
        --map[t.charAt(N)];
        for (int i = 'a'; i <= 'z'; ++i) {
			if(map[i] < 0){
				return (char)i;
			}
		}
        return '?';
    }
}
