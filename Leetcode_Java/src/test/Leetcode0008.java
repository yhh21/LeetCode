package test;

public class Leetcode0008 {
	public int myAtoi(String str) {
		int i = 0;
		double d = 0;
		char c;
		char sign = '+';
		for(i = 0 ; i < str.length() ; ++i){
			c = str.charAt(i);
			if( c == ' '){
				continue;
			}else if( c >= '0' && c <= '9'){
				break;
			}else if(c == '+' || c == '-'){
				sign = c;
				if(i + 1 < str.length()){
					c = str.charAt(i + 1);
					++i;
				}else {
					return 0;
				}
				if( c < '0' || c > '9'){
					return 0;
				}
				break;
			}else {
				return 0;
			}
		}
		//Êý×Ö
		for(; i < str.length() ; ++i){
			c = str.charAt(i);
			if( c >= '0' && c <= '9'){
				d = d * 10 + c - '0';
			}else {
				break;
			}
		}
		d *= sign=='+' ? 1 : -1;
		if(d > Integer.MAX_VALUE){
			return Integer.MAX_VALUE;
		}if(d < Integer.MIN_VALUE){
			return Integer.MIN_VALUE;
		}
        return (int)d;
    }
}
