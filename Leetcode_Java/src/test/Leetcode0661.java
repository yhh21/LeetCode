package test;

public class Leetcode0661 {
    public int[][] imageSmoother(int[][] M) {
    	int MY = M.length , MX = M[0].length;
    	int k = 0;
    	int[][] rtn = new int[MY][MX];
    	for (int i = 0; i < MY; i++) {
			for (int j = 0; j < MX; j++) {
				k = 0;
				for (int ii = i - 1; ii <= i + 1; ii++) {
					if(ii >= 0 && ii < MY){
						for (int jj = j - 1; jj <= j + 1; jj++) {
							if(jj >= 0 && jj < MX){
								++k;
								rtn[i][j] += M[ii][jj];
							}
						}
					}
				}
				rtn[i][j] /= k;
			}
		}
    	return rtn;
    }
}
