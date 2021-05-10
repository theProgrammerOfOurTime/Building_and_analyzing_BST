#pragma once
#include <iostream>
#include <algorithm>

template <class Item>
class BST
{
private:
	struct node
	{
		Item item;
		node* left;
		node* rigth;
		node(Item item)
		{
			this->item = item;
			left = rigth = nullptr;
		}
	};
	node* head;
	void insertRec(node*&, Item, int);
	int height = 0; //number of hierarchy levels
public:
	BST() : head(nullptr) {}
	void insert(Item);
	int getHeight();
};

template<class Item>
int BST<Item>::getHeight()
{
	return height;
}

template<class Item>
void BST<Item>::insertRec(node*& link, Item item, int height)
{
	this->height = std::max(this->height, height);
	if (link == nullptr) { link = new node(item); return; }
	if (link->item < item) { insertRec(link->rigth, item, height + 1); }
	if (link->item > item) { insertRec(link->left, item, height + 1); }
	return;
}

template <class Item>
void BST<Item>::insert(Item item)
{
	insertRec(head, item, 0);
	return;
}