package test;

public class Leetcode0009 {
	public boolean isPalindrome(int x) {
		//1.���ò�˵Leetcode������ʱ���Ǹ����ٵĹ�ϵ�ܴ�MDZZ
        if(x < 0 || (x%10 == 0 && x > 10)){
        	return false;
        }
        int r = 0;//��ת�����
        int t = x;
        for(; t != 0 ; ){
        	r = r * 10 + t % 10;
        	t /= 10;
        }
        return x == r;
    }
}
