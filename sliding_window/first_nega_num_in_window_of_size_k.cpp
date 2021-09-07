vector<long long> printFirstNegativeInteger(long long int a[],
                                             long long int n, long long int k)
{
    vector<long long> result;
    long long int i=0,j=0;
    queue<long long> result1;
    for(j=0;j<k;j++)
    {
        if(a[j]<0)
            result1.push((long long)a[j]);
    }
    for(;i<=n-k;i++,j++)
    {
        if(result1.empty()==false)
        {
            result.push_back((long long)result1.front());
        }
        else
        {
            result.push_back(0);
        }
        if(a[j]<0)
            result1.push(a[j]);
        if(result1.empty()==false && result1.front()==a[i])
        {
            result1.pop();
        }
    }
    return result;

 }
