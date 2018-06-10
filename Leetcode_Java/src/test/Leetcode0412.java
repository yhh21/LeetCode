package test;

import java.util.LinkedList;
import java.util.List;

public class Leetcode0412 {
    public List<String> fizzBuzz(int n) {
    	LinkedList<String> list = new LinkedList<>();
        for(int i = 1 ; i <= n ; ++i){
        	if(i%15 == 0){
        		list.add("FizzBuzz");
        		continue;
        	}
        	if(i%5 == 0){
        		list.add("Buzz");
        		continue;
        	}
        	if(i%3 == 0){
        		list.add("Fizz");
        		continue;
        	}
        	list.add(new Integer(i).toString());
        }
        return list;
    }
}
