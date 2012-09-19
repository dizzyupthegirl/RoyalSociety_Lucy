#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "Resources.h"
#include "RoyalSociety_LucyApp.h"
#include "Rectangle.h"
#include "Circle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class RoyalSociety_LucyApp : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void keyDown(KeyEvent event);
	void update();
	void draw();
	void prepareSettings(Settings* settings);


  private:
	static const int windowWidth = 1024;
	static const int windowHeight = 1024;
	node* first_item;
	Surface* mySurface;
	Shape* sky;
};

void insertAfter(node* position, Shape shape){
	node* my_node = new node;
	my_node -> data = shape;
	my_node -> next = position -> next;
	position -> next = my_node;
}

//unfinished
void RoyalSociety_LucyApp::keyDown(KeyEvent event){
	if(event.getChar() == '/'){
		gl::Texture;
	}
}

void RoyalSociety_LucyApp::prepareSettings(Settings* settings){
	settings->setWindowSize(windowWidth, windowHeight);
	settings->setResizable(false);
}

void RoyalSociety_LucyApp::setup()
{
	mySurface = new Surface(windowWidth, windowHeight, false);
	sky = new Circle();
}

void RoyalSociety_LucyApp::mouseDown( MouseEvent event )
{
}

void RoyalSociety_LucyApp::update()
{
	uint8_t* dataArray = (*mySurface).getData();
	sky->set(dataArray,100.0f,100.0f,10.0f,Color8u(0,0,0));
	sky->draw();
}

void RoyalSociety_LucyApp::draw()
{
	//gl::draw(*mySurface);
	gl::drawSolidCircle(Vec2f(500.0f, 500.0f), 50.0f);
}

CINDER_APP_BASIC( RoyalSociety_LucyApp, RendererGl )
