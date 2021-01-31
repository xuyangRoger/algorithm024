/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


#include <iostream>
#include <vector>
#include <memory>

 struct ListNode {
     int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;

        ListNode* preHead = new ListNode(-1);
        ListNode* prev = preHead;

        while(l1 && l2)
        {
            if(l1->val <= l2->val)
            {
                prev->next = l1;
                l1 = l1->next;
            }
            else
            {
                prev->next = l2;
                l2 = l2->next;
            }

            prev = prev->next;
        }
        prev->next = l1 ? l1 : l2;
        return preHead->next;
    }

    ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;

        if(l1->val <= l2->val)
        {
            l1->next = mergeTwoLists2(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists2(l1, l2->next);
            return l2;
        }

    }


    std::shared_ptr<ListNode>  creatList(std::vector<int> aVec)
    {
        std::shared_ptr<ListNode> head = std::make_shared<ListNode>(ListNode(aVec[0]));
        ListNode* prev = head.get();

        for(int i = 1; i < aVec.size(); i++)
        {
            ListNode*  anode = new ListNode(aVec[i]);
            prev->next = anode;
            prev = prev->next;
        }

        return head;
    }
};

int main()
{
    Solution aSol;
    std::shared_ptr<ListNode> aRet = aSol.creatList(std::vector<int>{1,2,4});

    ListNode* l1 = aRet.get();

    aRet = aSol.creatList(std::vector<int>{1,3,4});

    ListNode* l2 = aRet.get();

    ListNode* aRetNode = aSol.mergeTwoLists(l1, l2);

    while(aRetNode)
    {
        std::cout << aRetNode->val << " ";
        aRetNode = aRetNode->next;
    }
    std::cout << "mergeTwoLists" << std::endl;

    aRet = aSol.creatList(std::vector<int>{1,1,2,5});

    l1 = aRet.get();

    aRet = aSol.creatList(std::vector<int>{0,2,3,4});

    l2 = aRet.get();

    aRetNode = aSol.mergeTwoLists2(l1, l2);

    while(aRetNode)
    {
        std::cout << aRetNode->val << " ";
        aRetNode = aRetNode->next;
    }
    std::cout << "mergeTwoLists2" << std::endl;

    return 0;
}