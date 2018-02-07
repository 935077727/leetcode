
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm> 



using namespace std;

struct ListNode {
    int val;
    ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* dummyRoot = new ListNode(0);
		ListNode* ptr = dummyRoot;
		int  sum = 0;
		int  res = 0;
		int integer = 0;
		if (l1 == NULL || l2 == NULL)
		{
			return NULL;
		}
		while (l1 || l2)
		{
			int a = l1 ? l1->val : 0;
			int b = l2 ? l2->val : 0;
			sum = a + b + integer;
			integer = sum / 10;
			res = sum % 10;

			ptr->next = new ListNode(res);
			ptr = ptr->next;

			if (l1)
			{
				l1 = l1->next;
			}
			if (l2)
			{
				l2 = l2->next;
			}

		}
		if (integer)
		{
			ptr->next = new ListNode(integer);
			
		}
		return dummyRoot->next;
	
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
	vector<int> list = {2 ,4,3};//stringToIntegerVector(input);

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
ListNode* creatList(int a ,int b ,int c) {
	// Generate list from the input
	vector<int> list;//= a;//stringToIntegerVector(input);

	list.push_back(a);
	/*list.push_back(b);
	list.push_back(c);*/

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
	
	
		ListNode* l1 = creatList(5,4,3);
		
		ListNode* l2 = creatList(5,6,4);

		ListNode* ret = Solution().addTwoNumbers(l1, l2);

		string out = listNodeToString(ret);
		cout << out << endl;
	
	return 0;
}