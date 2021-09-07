#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> s1;
    s1.push(5);
    s1.push(4);
    s1.push(3);
    s1.push(2);
    cout<<s1.top()<<endl;
    cout<<s1.size()<<endl;
    s1.pop();
    cout<<s1.top()<<endl;
    return 0;
}
