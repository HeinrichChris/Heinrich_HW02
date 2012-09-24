#include "Square.h"
#include "cinder/gl/gl.h"

using namespace ci;

Square::Square()
{
	next=prev=this;
	red = green = blue = 0;
	x=y=size=0.0f;
	falls = true;
	speed = 5;
}

void insertAfter(Square* new_square, Square* insert_here){
	new_square->next = insert_here->next;
	new_square->prev = insert_here;
	insert_here->next->prev = new_square;
	insert_here->next = new_square;
}

void Square::update(){
	if(falls == true)
		this->y+=speed;
	else
		this->y-=speed;

	Square* that = this->next;

	while(that!=this){
		collide(this,that);
		that = that->next;
	}
}

void Square::draw(){
	gl::color(Color8u((uint8_t)red,(uint8_t)green,(uint8_t)blue));
	gl::drawSolidRect(Rectf(x,y,x+size,y+size));
}

void collide(Square* square1, Square* square2){
	if(square1->x < square2->x+square2->size){
		if(square1->x >= square2->x){
			if(square1->y < square2->y+square2->size){
				if(square1->y >= square2->y){
					if(square1->red + square2->red >255){
						square1->red = 255;
						square2->red = 255;
					}
					else{
						square1->red = square1->red + square2->red;
						square2->red = square1->red + square2->red;
					}
					if(square1->green + square2->green >255){
						square1->green = 255;
						square2->green = 255;
					}
					else{
						square1->green = square1->green + square2->green;
						square2->green = square1->green + square2->green;
					}
					if(square1->blue + square2->blue >255){
						square1->blue = 255;
						square2->blue = 255;
					}
					else{
						square1->blue = square1->blue + square2->blue;
						square2->blue = square1->blue + square2->blue;
					}
				}
			}
		}
	}
}