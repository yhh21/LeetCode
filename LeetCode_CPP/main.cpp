#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include "ListNode.h"

#include "Leetcode0020.h"
using namespace std;

int main() {
    vector<string> test;

    test.push_back("flower");
    test.push_back("flow");
    test.push_back("flight");

    auto res = Leetcode0020::isValid("([)]");

    cout << res;

    int pause;
    cin >> pause;
    return 0;
}