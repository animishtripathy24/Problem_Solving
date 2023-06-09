class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //if the both is empty in this case we return null
        if(list1==NULL && list2==NULL)
        {
            return NULL;
        }
        //if the first list is empty in this case we return second list
        if(list1==NULL)
        {
            return list2;
        }
        //if the second list is empty in this case we return first list
        if(list2==NULL)
        {
            return list1;
        }

        //mark the list1 pointer pointer to the smallest node at first
        if(list1->val > list2->val)
        {
            swap(list1,list2);
        }
        ListNode* res=list1;

        while(list1 != NULL && list2 != NULL)
        {
            //make a temporary pointer
            ListNode* temp=NULL;
            while(list1 != NULL &&  list1->val <= list2->val)
            {
                temp=list1;
                list1=list1->next;
            }
            temp->next=list2;
            swap(list1,list2);
        }
        //we must have to return the res pointer as it was pointing to the list1
        return res;
    }
};
