package test;

public class Leetcode0463 {
    public int islandPerimeter(int[][] grid) {
    	int rtn = 0;
    	final int M = grid.length , N = grid[0].length;
        for (int i = 0; i < M ; i++) {
			for (int j = 0; j < N; j++) {
				if(grid[i][j] == 1){
						if(i - 1 < 0 || grid[i - 1][j] == 0){
							++rtn;
						}
						if(i + 1 >= M || grid[i + 1][j] == 0){
							++rtn;
						}
						if(j - 1 < 0 || grid[i][j - 1] == 0){
							++rtn;
						}
						if(j + 1 >= N || grid[i][j + 1] == 0){
							++rtn;
						}
				}
			}
		}
        return rtn;
    }
}
