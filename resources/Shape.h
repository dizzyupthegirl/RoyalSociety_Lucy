#pragma once
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "Resources.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Shape{
	public:
		void draw();

	private:
		static const int windowWidth = 1024;
		static const int windowHeight = 1024;
}