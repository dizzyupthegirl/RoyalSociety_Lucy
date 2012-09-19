#include "VerticalLine.h"

VerticalLine::VerticalLine(){
	dataArray = NULL;
	y1 = 0;
	y2 = 0;
	x = 0;
	color = Color8u(0,0,0);
}

void VerticalLine::set(uint8_t* dataArray_new, int y1_new, int y2_new, int x_new, Color8u color_new){
	dataArray = dataArray_new;
	y1 = y1_new;
	y2 = y2_new;
	x = x_new;
	color = color_new;
}

void VerticalLine::draw(){
	for(int draw = y1; draw <= y2; draw++){
		for(int count = x-1; count <= x+1; count++){
			dataArray[3*(count + draw * windowWidth)] = 0;
			dataArray[3*(count + draw * windowWidth)+1] = 0;
			dataArray[3*(count + draw * windowWidth)+2] = 0;
		}
	}
}