#include <stdio.h>

typedef struct {
    int val;
    struct ListNode *next; } ListNode;

ListNode* RevertList(ListNode* l1){
    ListNode* prev = NULL; ListNode* next = NULL;
    ListNode* current = l1;
    while (current != NULL) {
        next = current -> next; current -> next = prev;
        prev = current; current = next;}  return prev;
}
