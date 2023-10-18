#include "base.hpp"

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *sortLinkedList(ListNode *head) {
    auto res=head;
    ListNode* tmp;
    while(head->next){
      if(head->next->val>=0){
        head=head->next;
      }
      else{
        tmp=head->next;
        head->next=tmp->next;
        tmp->next=res;
        res=tmp;
      }
    }
    return res;
  }
};

int main() {}