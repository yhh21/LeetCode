#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "ListNode.h"

#include "Leetcode0069.h"
#include "Leetcode0025.h"
using namespace std;

int main() {
    vector<int> test;

    test.push_back(-2);
    test.push_back(3);
    test.push_back(1);//-2,1,-3,4,-1,2,1,-5,4
    test.push_back(2);
    auto res = Leetcode0069::mySqrt(2147395600);
    cout << res;


    ListNode *head = new ListNode(0);
    ListNode *current = head;
    for (int i = 0; i < 5; ++i) {
        current->next = new ListNode(i + 1);
        current = current->next;
    }

    auto tmp = new Leetcode0025();
    tmp->reverseKGroup(head->next, 2);


    return 0;
}