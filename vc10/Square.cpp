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

	if(this->x > 360 || this->x < 0){
		remove();
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
					int r = square1->red + square2->red;
					int g = square1->green + square2->green;
					int b = square1->blue + square2->blue;

					if(r > g && r > b){
						square1->red = 255;
						square1->green = 0;
						square1->blue = 0;
						square2->red = 255;
						square2->green = 0;
						square2->blue = 0;
					}
					else if(g > b){
						square1->red = 0;
						square1->green = 255;
						square1->blue = 0;
						square2->red = 0;
						square2->green = 255;
						square2->blue = 0;
					}
					else{
						square1->red = 0;
						square1->green = 0;
						square1->blue = 255;
						square2->red = 0;
						square2->green = 0;
						square2->blue = 255;
					}
				}
			}
		}
	}
}

void Square::remove(){
	this->prev->next = this->next;
	this->next->prev = this->prev;
}