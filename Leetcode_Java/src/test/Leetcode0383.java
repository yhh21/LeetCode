package test;

public class Leetcode0383 {
    public boolean canConstruct(String ransomNote, String magazine) {
        int [] map = new int[128];
        char [] cs1 = ransomNote.toCharArray();
        char [] cs2 = magazine.toCharArray();
        for (char c : cs2) {
			++map[c];
		}
        for (char c : cs1) {
			--map[c];
			if(map[c] < 0){
				return false;
			}
		}
        return true;
    }
}
