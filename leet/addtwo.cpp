#include <cmath>
#include <cstdio>
#include <iostream>

struct ListNode 
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x): val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
int convert(ListNode* ll)
{
  int index {0};
  int result {0};
  while(ll->next != nullptr || ll->val != 0)
  {
    if(ll->val != 0)
    {
      if(index == 0)
      {
        result += ll->val;
      }
      else { 
          result += pow(10,index) * ll->val;
      }
    }
    index += 1;
    printf("index: %d\n", index);
    ll = ll->next;
  }
       
  return result;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
  int res1 = convert(l1);
  res1 += convert(l2);
  
  ListNode list;
  ListNode* ptr = &list;

  if(res1 == 0)
  {
    return new ListNode(0);
  }
  while (res1 > 0)
  {
    ptr->next = new ListNode(res1 % 10);
    res1 /= 10;
    ptr = ptr->next;
  }

  return list.next;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val;
        if (head->next != nullptr) {
            std::cout << " -> ";
        }
        head = head->next;
    }
    std::cout << std::endl;
}

int main ()
{
  // List1
  ListNode node1(9);
  ListNode node2(0, &node1);
  ListNode node3(1, &node2);
  
  //List2
  ListNode node4(8);
  ListNode node5(7, &node4);
  ListNode node6(5, &node5);

  ListNode* result = addTwoNumbers(&node6, &node3); 
 
  return 0;
}
