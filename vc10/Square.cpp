#include "Square.h"
#include "cinder/gl/gl.h"

using namespace ci;

Square::Square()
{
	next=prev=this;
	red = green = blue = 0;
	x=y=size=0.0f;
}

void insertAfter(Square* new_square, Square* insert_here){
	new_square->next = insert_here->next;
	new_square->prev = insert_here;
	insert_here->next->prev = new_square;
	insert_here->next = new_square;
}

void Square::update(){

}

void Square::draw(){
	gl::color(Color8u((uint8_t)red,(uint8_t)green,(uint8_t)blue));
	gl::drawSolidRect(Rectf(x,y,x+size,y+size));
}