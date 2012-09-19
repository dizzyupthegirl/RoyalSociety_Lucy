#include "Rectangle.h"

Rectangle::Rectangle(){
	x1 = 0;
	y1 = 0;
	x2 = 0;
	y2 = 0;
	color = Color8u(0,0,0);
	dataArray = NULL;
}

void Rectangle::set(uint8_t* dataArray_new, int x1_new, int y1_new, int x2_new, int y2_new, Color8u color_new){
	dataArray = dataArray_new;
	x1 = x1_new;
	y1 = y1_new;
	x2 = x2_new;
	y2 = y2_new;
	color = color_new;
}

void Rectangle::draw(){
	int draw;

	//draw horizonal edges
	for(draw = x1; draw <= x2; draw++){
		dataArray[3*(draw + y1 * windowWidth)] = color.r;
		dataArray[3*(draw + y1 * windowWidth)+1] = color.g;
		dataArray[3*(draw + y1 * windowWidth)+2] = color.b;

		dataArray[3*(draw + y2 * windowWidth)] = color.r;
		dataArray[3*(draw + y2 * windowWidth)+1] = color.g;
		dataArray[3*(draw + y2 * windowWidth)+2] = color.b;
	}

	//draw vertical edges
	for(draw = y1; draw <= y2; draw++){
		dataArray[3*(x1 + draw * windowWidth)] = color.r;
		dataArray[3*(x1 + draw * windowWidth)+1] = color.g;
		dataArray[3*(x1 + draw * windowWidth)+2] = color.b;

		dataArray[3*(x2 + draw * windowWidth)] = color.r;
		dataArray[3*(x2 + draw * windowWidth)+1] = color.g;
		dataArray[3*(x2 + draw * windowWidth)+2] = color.b;
	}

	for(int x=0; x<=windowWidth; x++){
		for(int y=0; y<=windowHeight; y++){
			if(x>x1 && x<x2 && y>y1 && y<y2){
					dataArray[3*(x + y * 1024)] = color.r;
					dataArray[3*(x + y * 1024)+1] = color.g;
					dataArray[3*(x + y * 1024)+2] = color.b;
			}
		}
	}
}