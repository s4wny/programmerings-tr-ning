package dynamicconectivety;


public class QuickUnionUF 
{
	private int[] id;
	
	public QuickUnionUF(int N)
	{
		id = new int[N];
		for(int i = 0; i<N; i++) id[i] = i;
	}
	

	
	private int root(int i)
	{
		while (i != id[i]) i = id[i];
		return i;
	}
	
	public boolean connected(int p, int q)
	{
		return root(p) == root(q);
	}
	
	public void union(int p, int q)
	{
		int i = root(q);
		int j = root(p);
		id[i] = j;
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
