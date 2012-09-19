#include "Shape.h"
#include "Rectangle.h"

class node{
	public:
		Shape data;
		node* next;
};

void insertAfter(node* position, Shape data);