#include<bits/stdc++.h>
using namespace std;
int romanToDecimal(string str) {
        // code here
        int i,j;
        int result=0;
        for(i=0;i<str.length()-1;i++)
        {
            if(str[i]=='M')
                result+=1000;
            else if(str[i]=='D')
            {
                if(str[i+1]=='M')
                    result-=500;
                else
                    result+=500;
            }
            else if(str[i]=='C')
            {
                if(str[i+1]=='M'||str[i+1]=='D')
                    result-=100;
                else
                    result+=100;
            }
            else if(str[i]=='L')
            {
                if((str[i+1]=='M'||str[i+1]=='C'||str[i+1]=='D'))
                    result-=50;
                else
                    result+=50;
            }
            else if(str[i]=='X')
            {
                if((str[i+1]=='M'||str[i+1]=='C'||str[i+1]=='D'||str[i+1]=='L'))
                    result-=10;
                else
                    result+=10;
            }
            else if(str[i]=='V')
            {
                if((str[i+1]=='M'||str[i+1]=='C'||str[i+1]=='D'||str[i+1]=='L'||str[i+1]=='X'))
                    result-=5;
                else
                    result+=5;

            }
            else if(str[i]=='I')
            {
                if((str[i+1]=='M'||str[i+1]=='C'||str[i+1]=='D'||str[i+1]=='L'||str[i+1]=='X'||str[i+1]=='V'))
                    result-=1;
                else
                    result+=1;
            }

        }
        i=str.length()-1;
            if(str[i]=='M')
                result+=1000;
            else if(str[i]=='D')
                result+=500;
            else if(str[i]=='C')
                result+=100;
            else if(str[i]=='L')
                result+=50;
            else if(str[i]=='X')
                result+=10;
            else if(str[i]=='V')
                result+=5;
            else if(str[i]=='I')
                result+=1;

        return result;
    }
int main()
{
    cout<<romanToDecimal("V")<<endl;
    return 0;
}
