#include <iostream>

struct Node
{
	int data;
	Node* next;
};

void Print(Node* head)
{
	if (head == nullptr)
		return;

	std::cout << head->data << " ";

	Print(head->next);
}

Node* Reverse(Node *head)
{
	// Complete this method
	if (head == nullptr)
		return nullptr;

	if (head->next == nullptr)
		return head;

	Node* temp = Reverse(head->next);

	head->next->next = head;

	head->next = nullptr;

	Print(temp);
	std::cout << std::endl;

	return temp;
}

int main(void)
{
	Node* node1 = new Node();
	Node* node2 = new Node();
	Node* node3 = new Node();
	Node* node4 = new Node();
	Node* node5 = new Node();

	node1->data = 11;
	node2->data = 12;
	node3->data = 13;
	node4->data = 14;
	node5->data = 15;

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = nullptr;

	Node* reverse = Reverse(node1);

	Print(reverse);

	getchar();

	return 0;
}