#include <unordered_map>
#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode* next) : val(x), next(next) {}
 };

bool hasCycle(ListNode *head) 
{
  if(head == nullptr || head->next == nullptr) return false;
  unordered_map<ListNode*, int> list;
  while(head != nullptr)
  {
    if(list.find(head) == list.end()) list[head] = 1;
    else return true;
    
    head = head->next;
  }
  return false;
}

int main()
{
  ListNode p1 (1);
  ListNode p2 (2,&p1);
  cout << hasCycle(&p2);
  return 0;
}
