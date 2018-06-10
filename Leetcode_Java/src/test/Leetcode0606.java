package test;

public class Leetcode0606 {
	public String tree2str(TreeNode t) {
		StringBuffer stringBuffer = new StringBuffer();
		tree2strbuf(t, stringBuffer);
		return stringBuffer.toString();
    }
	
	private void tree2strbuf(TreeNode t , StringBuffer stringBuffer) {
		if(t == null){
			return;
		}
		stringBuffer.append(t.val);
		if(t.right != null){
			stringBuffer.append("(").append(tree2str(t.left)).append(")").append("(").append(tree2str(t.right)).append(")");
		}else if(t.left != null){
			stringBuffer.append("(").append(tree2str(t.left)).append(")");
		}
	}
}
