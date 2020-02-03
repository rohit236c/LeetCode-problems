#include<bits/stdc++.h>
using namespace std;

class ListNode {
public:
	int val;
	ListNode *next;
	ListNode(int x) {
		val = x;
		next = NULL;
	}
};
void insertAtHead(ListNode* &head, int data) {
	ListNode *newHead = new ListNode(data);
	if (head == NULL) {
		head = newHead;
		return;
	}

	newHead->next = head;
	head = newHead;
}
void print(ListNode*head) {
	while (head != NULL) {
		cout << head->val << " -> ";
		head = head->next;
	}
	cout << endl;
}
ListNode* middleNode(ListNode* head) {
	if (head == NULL) return head;
	ListNode* slow = head;
	ListNode* fast = head;
	while (fast != NULL && fast->next != NULL ) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;

}
void easySet() {
	ListNode*head = NULL;
	for (int i = 6; i >= 1; i--) {
		insertAtHead(head, i);
	}
	print(head);
	ListNode*mid = middleNode(head);
	cout << mid->val;

}

int main() {

	easySet();
	return 0;
}