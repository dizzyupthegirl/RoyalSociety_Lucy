#include "Shape.h"

void insertAfter(node* position, Shape data);

class node{
	public:
		Shape data;
		node* next;
};