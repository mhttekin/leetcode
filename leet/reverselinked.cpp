struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* reverseList(ListNode* head) 
{
  if(head == nullptr) return nullptr;
  ListNode* temp = head;
  while(head != nullptr)
  {
    if(head->next != nullptr)
    {
      temp = new ListNode(head->next->val, temp);
      head->next = head->next->next;
    }else {
      head = nullptr;
      continue;
    }
  }
  return temp;
}
