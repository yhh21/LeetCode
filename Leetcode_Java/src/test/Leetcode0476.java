package test;

public class Leetcode0476 {
    public int findComplement(int num) {
    	int mask = ~0; //掩码初始为二进制全部是1
    	int i = num;
    	while(i != 0){
    		mask <<= 1;  //左移掩码
    		i /= 2;
    	}
    	return ~num & ~mask;
    }
}
