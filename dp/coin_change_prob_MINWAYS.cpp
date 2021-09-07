class Solution{

	public:
	int minCoins(int coins[], int n, int v)
	{
	    // Your code goes here
	    int t[n+1][v+1];
	    int i,j;
	    for(i=0;i<=n;i++)
	        t[i][0]=0;
	    for(i=0;i<=v;i++)
	        t[0][i]=INT_MAX - 1;
	    for(i=1;i<=v;i++)
	    {
	        if(i%coins[0]==0)
	            t[1][i]=i/coins[0];
	        else
	            t[1][i]=INT_MAX-1;
	    }
	    for(i=2;i<=n;i++)
	    {
	        for(j=1;j<=v;j++)
	        {
	            if(j>=coins[i-1])
	            {
	                t[i][j]=min((1+t[i][j-coins[i-1]]),t[i-1][j]);
	            }
	            else
	            {
	                t[i][j]=t[i-1][j];
	            }
	        }
	    }
	    if(t[n][v]==INT_MAX-1)
	        return -1;
	    return t[n][v];
	}

};
