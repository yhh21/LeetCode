package test;

public class Leetcode0476 {
    public int findComplement(int num) {
    	int mask = ~0; //�����ʼΪ������ȫ����1
    	int i = num;
    	while(i != 0){
    		mask <<= 1;  //��������
    		i /= 2;
    	}
    	return ~num & ~mask;
    }
}
