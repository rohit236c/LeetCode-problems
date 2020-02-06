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
ListNode* reverse(ListNode*&head, ListNode*prev) {
	if (head == NULL) {
		cout << "List is empty!!!";
		return NULL;
	}
	if (head->next == NULL) return head;


	ListNode* newHead = reverse(head->next, head);

	ListNode* temp = head->next;
	head->next->next = head;
	head->next = prev;

	return newHead;

}
ListNode* removeNthFromEnd(ListNode* head, int n) {
	if (head == NULL) return head;
	int cnt = 0;
	ListNode* temp = head;
	while (temp != NULL) {
		cnt++;
		temp = temp->next;
	}
	if (cnt == 1 && n >= 1) return NULL;
	int del = cnt - n;
	temp = head;
	while (del > 1) {
		temp = temp->next;
		del--;
	}
	if (del >= 1) {
		temp->next = temp->next->next;
	}
	else if (cnt == n) {
		return head->next;
	}
	return head;
}
void swap(ListNode* &cur, ListNode* &prev) {
	ListNode* t = prev;
	prev = cur;
	cur = t;
}
ListNode* swapPairs(ListNode* &head) {
	if (head == NULL) return head;
	if (head->next == NULL) return head;

	ListNode* prev = head;
	ListNode* cur = head->next;
	ListNode* temp;
	while (cur != NULL or prev->next != NULL) {
		temp = cur->next;
		swap(cur->val, prev->val);
		//-------------//
		prev = temp;
		cur = prev->next;
	}
	return head;
}
void easySet() {
	ListNode* head = NULL;
	for (int i = 5; i >= 1; i--) {
		insertAtHead(head, i);
	}
	print(head);
	// ListNode* mid = middleNode(head);
	// ListNode*t = removeNthFromEnd(head, 5);
	ListNode* t = swapPairs(head);
	print(t);
	// cout << mid->val;
	// ListNode* rev = reverse(head, NULL);
	// print(rev);

}

int main() {

	easySet();
	return 0;
}