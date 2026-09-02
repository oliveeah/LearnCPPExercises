#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;

        if (list2 == nullptr && list1 == nullptr)
            return nullptr;

        ListNode *head = new ListNode();
        ListNode *current = head;
        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val < list2->val)
            {
                current->next = list1;
                list1 = list1->next;
            }
            else
            {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }
        if (list1 != nullptr)
        {
            current->next = list1;
        }
        if (list2 != nullptr)
        {
            current->next = list2;
        }
        return head->next;
    }
};

int main()
{
    ListNode *list1 = new ListNode(1, new ListNode(3, new ListNode(5)));
    ListNode *list2 = new ListNode(2, new ListNode(4, new ListNode(6)));

    Solution solution;
    ListNode *mergedList = solution.mergeTwoLists(list1, list2);

    // Print the merged list
    ListNode *current = mergedList;
    while (current != nullptr)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}