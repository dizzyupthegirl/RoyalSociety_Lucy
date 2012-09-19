#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "Resources.h"
#include "RoyalSociety_LucyApp.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class RoyalSociety_LucyApp : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	void prepareSettings(Settings* settings);


  private:
	static const int windowWidth = 1024;
	static const int windowHeight = 1024;
	node* first_item;
	Surface* mySurface;
	Shape sky;
};

void insertAfter(node* position, Shape shape){
	node* my_node = new node;
	my_node -> data = shape;
	my_node -> next = position -> next;
	position -> next = my_node;
}

void RoyalSociety_LucyApp::prepareSettings(Settings* settings){
	settings->setWindowSize(windowWidth, windowHeight);
	settings->setResizable(false);
}

void RoyalSociety_LucyApp::setup()
{
	mySurface = new Surface(windowWidth, windowHeight, false);
	sky = new Shape;
}

void RoyalSociety_LucyApp::mouseDown( MouseEvent event )
{
}

void RoyalSociety_LucyApp::update()
{
	uint8_t* dataArray = (*mySurface).getData();
	sky.rectangle(dataArray, 10, 10, 50, 50, Color8u(1,1,1));
}

void RoyalSociety_LucyApp::draw()
{
	gl::draw(*mySurface);
}

CINDER_APP_BASIC( RoyalSociety_LucyApp, RendererGl )
