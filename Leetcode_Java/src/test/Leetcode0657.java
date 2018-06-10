package test;

public class Leetcode0657 {
//	The valid robot moves are R (Right), L (Left), U (Up) and D (down).
	public boolean judgeCircle(String moves) {
		int lr = 0, ud = 0;
		char c = ' ';
		for (int i = 0; i < moves.length(); i++) {
			c = moves.charAt(i);
			if(c == 'L'){
				lr++;
				continue;
			}
			if(c == 'R'){
				lr--;
				continue;
			}
			if(c == 'U'){
				ud++;
				continue;
			}
			if(c == 'D'){
				ud--;
				continue;
			}
		}
		if(lr == 0 && ud == 0)
			return true;
		else
			return false;
    }
}
