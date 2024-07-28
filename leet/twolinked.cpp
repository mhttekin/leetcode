#include <unordered_map>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

ListNode* getIntersectionNode(ListNode *headA, ListNode* headB) 
{
  if(!headA || !headB ) return nullptr;
  
  unordered_map<ListNode*, int> map;
  while(headA != nullptr)
  {
    map[headA] = 1;
    headA = headA->next;
  }
  while(headB != nullptr)
  {
    if(map.find(headB) != map.end())
    {
      return headB;
    }
    headB = headB->next;
  }
  return nullptr;
}
