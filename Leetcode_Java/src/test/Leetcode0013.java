package test;

public class Leetcode0013 {
    public int romanToInt(String s) {
    	int [] map = new int [128];
    	map['M'] = 1000;
    	map['D'] = 500;
    	map['C'] = 100;
    	map['L'] = 50;
    	map['X'] = 10;
    	map['V'] = 5;
    	map['I'] = 1;
        int sum = 0;
        char [] cs = s.toCharArray();
        for(int i = 0; i < cs.length - 1 ; ++i){
            if(map[cs[i]] < map[cs[i + 1]])
                sum -= map[cs[i]];
            else
                sum += map[cs[i]];
        }
        return sum + map[cs[cs.length - 1]];
    }
}
