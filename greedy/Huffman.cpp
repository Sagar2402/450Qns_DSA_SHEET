#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    char data;
    int freq;
    node *left, *right;
    node(char data1, int freq1)
    {
        left=right=NULL;
        data=data1;
        freq=freq1;
    }
};
struct compare {
    bool operator()(node* l, node* r)

    {
        return (l->freq > r->freq);
    }
};
void preorder(node* top,string str)
{
    if(top==NULL)
        return;
    if(top->data!='$')
        cout<<top->data<<"\t"<<top->freq<<"\t"<<str<<endl;
    preorder(top->left,str+'0');
    preorder(top->right, str+'1');
}
void HuffmanCodes(char data[], int freq[], int size)
{
    node *left, *right, *top;
    priority_queue<node*, vector<node*>, compare> minHeap;
    for (int i = 0; i < size; ++i)
        minHeap.push(new node(data[i], freq[i]));
    while(minHeap.size()!=1)
    {
        left=minHeap.top();
        minHeap.pop();
        right=minHeap.top();
        minHeap.pop();
        top=new node('$',left->freq+right->freq);
        top->left=left;
        top->right=right;
        minHeap.push(top);
    }
    string str="";
    preorder(top,str);
}
int main()
{
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    HuffmanCodes(arr, freq, 6);
    return 0;
}
