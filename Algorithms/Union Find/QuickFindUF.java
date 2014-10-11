package dynamicconectivety;

import java.util.Arrays;




public class QuickFindUF 
{

	private int[] id;
	
	public QuickFindUF(int N)
	{
		id = new int[N];
		for (int i = 0; i<N; i++)
			id[i] = i;
	}
	
	public boolean connected(int p, int q)
	{return id[p] == id[q];}
	
	public void union(int p, int q)
	{
		int pid = id[p];
		int qid = id[q];
		for(int i = 0; i < id.length; i++)
			if(id[i] == pid) id[i] = qid;
	}
	
	public void print()
	{
		StdOut.println(Arrays.toString(id));
	}
	
	public static void main(String[] args)
	{
		int N = StdIn.readInt();
		QuickFindUF uf = new QuickFindUF(N);
		for (int i = 0 ; i<N; i++)
		{
			int a = StdRandom.uniform(0,N);
			int b = StdRandom.uniform(0,N);
			
			uf.union(a, b);
			
		}
	}
	
}




