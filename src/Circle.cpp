#include "Circle.h"

Circle::Circle(){
	radius = 0.0f;
	center_x = 0.0f;
	center_y = 0.0f;
	Color8u color = Color8u(0,0,0);
	dataArray = NULL;
}

void Circle::set(uint8_t* dataArray_new, float radius_new, float center_x_new, float center_y_new, Color8u color_new){
	dataArray = dataArray_new;
	radius = radius_new;
	center_x = center_x_new;
	center_y = center_y_new;
	color = color_new;
}

void Circle::draw(){
	for(int y=0; y<=windowHeight; y++){
		for(int x=0;x<=windowWidth; x++){
			if ((pow(x-center_x,2) + (pow(y-center_y,2))) <= (pow(radius,2))){
				dataArray[3*(x + y * windowWidth)] = color.r;
				dataArray[3*(x + y * windowWidth)+1] = color.g;
				dataArray[3*(x + y * windowWidth)+2] = color.b;
			}
		}
	}
}