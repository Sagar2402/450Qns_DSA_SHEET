#include<bits/stdc++.h>
using namespace std;
vector<int> singleNumber(vector<int> nums)
{
        // Code here.
        int i;
        int xora=0;
        vector<int> result;
        for(i=0;i<nums.size();i++)
        {
            xora=xora^nums[i];
        }
        int j=0;
        int xora1=xora;
        while(xora1%2==0)
        {
            xora1=xora1>>1;
            j++;
        }
        xora1=0;
        for(i=0;i<nums.size();i++)
        {
            int num1=nums[i];
            num1=num1>>j;
            if(num1%2!=0)
            {
                xora1=xora1^nums[i];
            }
        }
        for(i=0;i<nums.size();i++)
        {
            if((xora1^nums[i])==xora)
            {
                result.push_back(xora1);
                result.push_back(nums[i]);
                break;
            }
        }
        return result;

}
int main()
{
    vector<int> n;
    n.push_back(1);
    n.push_back(2);
    n.push_back(1);
    n.push_back(4);
    n.push_back(5);
    n.push_back(5);
    vector<int> result;
    result=singleNumber(n);
    for(int i=0;i<result.size();i++)
        cout<<result[i]<<"\t";
    return 0;
}
