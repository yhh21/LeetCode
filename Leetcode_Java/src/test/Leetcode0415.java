package test;

public class Leetcode0415 {
    public String addStrings(String num1, String num2) {
        char [] cs1 = num1.toCharArray();
        char [] cs2 = num2.toCharArray();
        StringBuilder res = new StringBuilder();
        int i = cs1.length - 1 , j = cs2.length - 1;
        int t = 0;
        int c = 0;
        while (i >= 0 && j >= 0) {
        	t = cs1[i] - '0' + cs2[j] - '0' + c;
			res.insert(0, (char)('0' + t % 10));
			c = t / 10;
			--i;--j;
		}
        while(i >= 0){
        	t = cs1[i] - '0' + c;
        	res.insert(0, (char)('0' + t % 10));
			c = t / 10;
			--i;
        }
        while(j >= 0){
        	t = cs2[j] - '0' + c;
        	res.insert(0, (char)('0' + t % 10));
			c = t / 10;
			--j;
        }
        if(c > 0){
        	res.insert(0, (char)('0' + c));
        }
        return res.toString();
    }
}
