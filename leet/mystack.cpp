#include <queue>
using namespace std;

  class mystack 
  {
    public:
    queue<int> stack;
    queue<int> reverse;
    mystack() = default;

    void push(int x) 
    {
      stack.push(x);
    }
    int pop()
    {
      
      do
      {
        reverse.push(stack.front());
        stack.pop();
      }
      while(stack.size() > 1);
      int i = stack.front();
      stack = reverse;
      while(reverse.size() > 0)
      {
        reverse.pop();
      }
      return i;
    }
    int top()
    {
      return stack.back();
    }
    bool empty()
    {
      return stack.empty();
    }
};

