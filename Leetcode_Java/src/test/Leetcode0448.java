package test;

import java.util.LinkedList;
import java.util.List;

public class Leetcode0448 {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        boolean [] map = new boolean [nums.length + 1];
        for (int i : nums) {
			map[i] = true;
		}
        LinkedList<Integer> list = new LinkedList<>();
        for(int i = 1 ; i <= nums.length ; ++i){
        	if(!map[i]){
        		list.add(i);
        	}
        }
        return list;
    }
}
