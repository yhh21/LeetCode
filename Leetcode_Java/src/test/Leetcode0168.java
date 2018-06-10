package test;

public class Leetcode0168 {
	public String convertToTitle(int n) {
		StringBuffer stringBuffer = new StringBuffer();
        while(n > 0 ){
        	n--;
        	stringBuffer.insert(0, (char)('A' + n % 26));
        	n /= 26;
        }
        return stringBuffer.toString();
    }
}
