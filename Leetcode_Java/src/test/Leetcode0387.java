package test;

public class Leetcode0387 {
    public int firstUniqChar(String s) {
    	int [] map = new int [128];
    	for (int i = 0; i < s.length(); i++) {
			if(map[s.charAt(i)] == 0 && s.lastIndexOf(s.charAt(i)) == i){
				return i;
			}else {
				++map[s.charAt(i)];
			}
		}
    	return -1;
    	
//    	1.
//        int [] map = new int [128];
//        for (int i = 0; i < s.length(); i++) {
//			++map[s.charAt(i)];
//		}
//        for (int i = 0; i < s.length(); i++) {
//			if(map[s.charAt(i)] == 1){
//				return i;
//			}
//		}
//        return -1;
    }
}
