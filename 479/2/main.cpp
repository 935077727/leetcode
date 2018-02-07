/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>  
#include <sstream>
using namespace std;

 struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode *p1 = l1, *p2 = l2, *fa=NULL;
		int in = 0;
		while (p1 && p2) {
			p1->val += p2->val + in;
			in = 0;
			if (p1->val > 9) {
				p1->val %= 10;
				in = 1;
			}
			fa = p1;
			p1 = p1->next; p2 = p2->next;
		}
		if (p2) {
			fa->next = p2; p1 = p2;
		}
		while (in) {
			if (p1 == NULL) {
				p1 = new ListNode(0);
				fa->next = p1;
			}
			p1->val += in; in = 0;
			if (p1->val > 9) {
				p1->val %= 10;
				in = 1;
			}
			fa = p1; p1 = p1->next;
		}
		return l1;
	}
};

void trimLeftTrailingSpaces(string &input) {
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
	}));
}

void trimRightTrailingSpaces(string &input) {
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
	}).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
	vector<int> output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	stringstream ss;
	ss.str(input);
	string item;
	char delim = ',';
	while (getline(ss, item, delim)) {
		output.push_back(stoi(item));
	}
	return output;
}

ListNode* stringToListNode(string input) {
	// Generate list from the input
	vector<int> list = stringToIntegerVector(input);

	// Now convert that list into linked list
	ListNode* dummyRoot = new ListNode(0);
	ListNode* ptr = dummyRoot;
	for (int item : list) {
		ptr->next = new ListNode(item);
		ptr = ptr->next;
	}
	ptr = dummyRoot->next;
	delete dummyRoot;
	return ptr;
}

string listNodeToString(ListNode* node) {
	if (node == nullptr) {
		return "[]";
	}

	string result;
	while (node) {
		result += to_string(node->val) + ", ";
		node = node->next;
	}
	return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
	string line;
	while (1) {
		//ListNode* l1 = stringToListNode(line);
		//getline(cin, line);
		//ListNode* l2 = stringToListNode(line);

		ListNode* l1 = new ListNode(2);
		ListNode* ptr = l1;
		ptr->next = new ListNode(4);
		ptr = ptr->next;
		ptr->next = new ListNode(3);
		ptr = ptr->next;
		

		ListNode* l2 = new ListNode(5);
		ptr = l2;
		ptr->next = new ListNode(6);
		ptr = ptr->next;
		ptr->next = new ListNode(4);
		ptr = ptr->next;


		ListNode* ret = Solution().addTwoNumbers(l1, l2);

		//string out = listNodeToString(ret);
		//cout << out << endl;
	}
	return 0;
}