
#include <vector>
using namespace std;
#include <iostream>

// Definition for singly-linked list.
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (!l1 && !l2)
            return nullptr;

        vector<int> l1Stack;
        vector<int> l2Stack;

        while (l1)
        {
            l1Stack.push_back(l1->val);
            l1 = l1->next;
        }
        while (l2)
        {
            l2Stack.push_back(l2->val);
            l2 = l2->next;
        }

        int carry{};
        ListNode *head{};
        ListNode *tail{};
        for (auto i{0uz}; i < max(l1Stack.size(), l2Stack.size()); ++i)
        {
            int l1temp{}, l2temp{}, total{};

            if (i < l1Stack.size())
                l1temp = l1Stack[i];

            if (i < l2Stack.size())
                l2temp = l2Stack[i];

            total = l1temp + l2temp + carry;
            carry = total / 10;
            total %= 10;

            ListNode *node = new ListNode(total);

            if (!head)
                head = node;
            else
                tail->next = node;

            tail = node;
        }

        if (carry > 0)
            tail->next = new ListNode(carry);

        return head;
    }
};

int main()
{
    Solution solution;
    // ListNode *result = solution.addTwoNumbers(new ListNode(2), new ListNode(3));
    ListNode l1Seventh{9};
    ListNode l1Sixth{9, &l1Seventh};
    ListNode l1Fifth{9, &l1Sixth};
    ListNode l1Fourth{9, &l1Fifth};
    ListNode l1Third{9, &l1Fourth};
    ListNode l1Second{9, &l1Third};
    ListNode l1First{9, &l1Second};
    ListNode l2Fourth{9};
    ListNode l2Third{9, &l2Fourth};
    ListNode l2Second{9, &l2Third};
    ListNode l2First{9, &l2Second};

    for (ListNode *node{solution.addTwoNumbers(&l1First, &l2First)}; node; node = node->next)
        cout << node->val;
    cout << '\n';
}