#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
class Stack
{
    int top=0;
public:
    int a[MAX];
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};
bool Stack::push(int x)
{
    if (top >= (MAX - 1))
    {
        cout << "Stack Overflow";
        return false;
    }
    else
    {
        a[++top] = x;
        cout << x << " pushed into stack\n";
        return true;
    }
}

int Stack::pop()
{
    if (top < 0)
    {
        cout << "Stack Underflow";
        return 0;
    }
    else
    {
        int x = a[top--];
        return x;
    }
}
int Stack::peek()
{
    if (top < 0)
    {
        cout << "Stack is Empty";
        return 0;
    }
    else
    {
        int x = a[top];
        return x;
    }
}
bool Stack::isEmpty()
{
    return (top < 0);
}
int main()
{
    class Stack s;
    s.push(10);
    s.push(20);
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    return 0;
}
