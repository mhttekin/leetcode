struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* removeElements(ListNode* head, int val)
{
  if(head == nullptr) return nullptr;
  ListNode* start = head;
  
  while(start != nullptr)
  {
    if(start->val == val && start == head)
    {
      head = head->next;
    }else if(start->next->val == val)
    {
      start->next = start->next->next;
    }
    start = start->next;
  }
  return head;
}
