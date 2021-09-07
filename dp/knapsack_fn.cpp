class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int t[1001][1001];
    int ks(int w, int wt[], int val[], int n)
    {
        if(n==0 || w==0)
            return 0;
        if(t[n][w]!=-1)
            return t[n][w];
        if(wt[n-1]<=w)
        {
            t[n][w]=max(val[n-1]+ks(w-wt[n-1],wt,val,n-1),ks(w,wt,val,n-1));
            return t[n][w];
        }
        else
        {
            t[n][w]=ks(w,wt,val,n-1);
            return t[n][w];
        }
    }
    int knapSack(int W, int wt[], int val[], int n)
    {
        memset(t,-1,sizeof(t));
        return ks(W,wt,val,n);
    }
};
