#include "common.h"


struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
Solution solution;
void printList(ListNode* head)
{
    cout << "------printList-------"<<endl;

    while (head != nullptr)
    {
        cout << head->val << endl;
        head = head->next;
    }
    cout << "----------------------"<<endl;
}


int main() {
    vector<int> m_vec = { 1,2,3 };
    ListNode* node3 = new ListNode(3);
    ListNode* node2 = new ListNode(2, node3);
    ListNode* node1 = new ListNode(1, node2);
    printList(node1);
    solution.reverseList(node1);
    printList(node3);
}

/*  
* 
* 在两端虚设空结点方便思考，但是实际操作时仍然从“1”结点开始操作
* 如下：
* ∅ → 1 → 2 → 3 → ∅
*/