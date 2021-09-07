#include <bits/stdc++.h>
using namespace std;
stack<int> sortFunction(stack<int> &mainStack)
{
  stack<int> AuxStack;
  while (!mainStack.empty())
  {
    // pop out the first element
    int temp = mainStack.top();
    mainStack.pop();
    while (!AuxStack.empty() && AuxStack.top() > temp)
    {
      // pop from Auxstack and push it to the mainstack
      mainStack.push(AuxStack.top());
      AuxStack.pop();
    }
    // push temp in end
    AuxStack.push(temp);
  }
  return AuxStack;
}
// main function
int main()
{
  stack<int> mainStack;
  mainStack.push(78);
  mainStack.push(103);
  mainStack.push(31);
  mainStack.push(19);
  mainStack.push(67);
  mainStack.push(83);
  mainStack.push(47);
  // Declaring AuxStack
  stack<int> AuxStack = sortFunction(mainStack);
  cout << "Sorted numbers in decreasing order are:"<<endl;
  while (!AuxStack.empty())
  {
    cout << AuxStack.top()<< " ";
    mainStack.push(AuxStack.top());
    AuxStack.pop();
  }
  cout<<endl;
  cout<<"Sorted numbers in increasing order are:"<<endl;
  while(!mainStack.empty()){
      cout<<mainStack.top()<<" ";
      mainStack.pop();
  }
}
