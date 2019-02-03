# [21. Merge Two Sorted Lists (Easy)](https://leetcode.com/problems/merge-two-sorted-lists/description/)

<p>Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.</p>

<p><b>Example:</b>
</p><pre><b>Input:</b> 1-&gt;2-&gt;4, 1-&gt;3-&gt;4
<b>Output:</b> 1-&gt;1-&gt;2-&gt;3-&gt;4-&gt;4
</pre>
<p></p>

**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft), [Facebook](https://leetcode.com/company/facebook), [Google](https://leetcode.com/company/google), [Adobe](https://leetcode.com/company/adobe), [Apple](https://leetcode.com/company/apple), [Bloomberg](https://leetcode.com/company/bloomberg), [Yahoo](https://leetcode.com/company/yahoo), [Arista Networks](https://leetcode.com/company/arista-networks), [Uber](https://leetcode.com/company/uber), [Indeed](https://leetcode.com/company/indeed), [Cisco](https://leetcode.com/company/cisco), [Tencent](https://leetcode.com/company/tencent), [Airbnb](https://leetcode.com/company/airbnb), [Oracle](https://leetcode.com/company/oracle), [IBM](https://leetcode.com/company/ibm), [Huawei](https://leetcode.com/company/huawei), [Paypal](https://leetcode.com/company/paypal), [Yandex](https://leetcode.com/company/yandex)

**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/)

**Similar Questions**:
* [Merge k Sorted Lists (Hard)](https://leetcode.com/problems/merge-k-sorted-lists/)
* [Merge Sorted Array (Easy)](https://leetcode.com/problems/merge-sorted-array/)
* [Sort List (Medium)](https://leetcode.com/problems/sort-list/)
* [Shortest Word Distance II (Medium)](https://leetcode.com/problems/shortest-word-distance-ii/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/merge-two-sorted-lists
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0), *tail = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};
```