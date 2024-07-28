#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
{
  ListNode list;
  ListNode* result = &list;
  vector<int> sorted;

  while( list1 != nullptr)
  {  
    sorted.push_back(list1->val);
    list1 = list1->next;
  }
  while( list2 != nullptr)
  {
    sorted.push_back(list2->val);
    list2 = list2->next;
  } 
  sort(sorted.begin(),sorted.end());
  
  for(int i = 0; i < sorted.size(); i++)
  {
    result->next = new ListNode(sorted[i]);
    result = result->next;
  }
   
  return list.next;
}

int main() 
{
  ListNode p1(4);
  ListNode p2(2,&p1);
  ListNode p3(1,&p2);

  ListNode p4(4);
  ListNode p5(3,&p4);
  ListNode p6(1,&p5);

  ListNode* result =  mergeTwoLists(&p6, &p3); 

  while(result->next != nullptr){
    cout << result->val << " ";
    result = result->next;
  }
  return 0; 
}
