package dynamicconectivety;

import java.util.Arrays;

public class WeightedQuickUnionUF  {
	
	private int[] id;
	private int[] sz;
	/* Be careful not to confuse union-by-size with union-by-height—the former uses the size of the tree (number of nodes) while the latter 
		uses the height of the tree (number of links on longest path from the root of the tree to a leaf node). 
		Both variants guarantee logarithmic height. There is a third variant known as union-by-rank that is also widely used.
	*/
	
	public WeightedQuickUnionUF(int N)
	{
		id = new int[N];
		sz = new int[N];
		for(int i = 0; i<N; i++) 
		{
			id[i] = i;
			sz[i] = 1;
		}
	}
	
	
	private int len(int i)
	{
		return sz[i]-1;
	}
	
	
	
	private int root(int i)
	{
		while (i != id[i]) 
		{
			i = id[i];
			id[i] = id[id[i]]; //optimization
		}
			
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
		if(i == j) return;
		
		if(sz[i] > sz[j]) { id[i] = j; sz[j] += sz[i];}
		else 			  { id[j] = i; sz[i] += sz[j];}
		
	}
	
	
	public void print()
	{
		StdOut.println(Arrays.toString(id));
	}
	
	
	
	public static void main(String[] args)
	{
		int N = StdIn.readInt();
		WeightedQuickUnionUF  uf = new WeightedQuickUnionUF(N);
		for (int i = 0 ; i<N; i++)
		{
			int a = StdRandom.uniform(0,N);
			int b = StdRandom.uniform(0,N);
			
			uf.union(a, b);
			
			
		}
		
		for (int i = 0 ; i<N; i++)
		{
			StdOut.print(uf.len(i)+" ");

		}
		
		
	}
}


