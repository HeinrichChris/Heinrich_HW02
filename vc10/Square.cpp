#include "Square.h"
#include "cinder/gl/gl.h"

using namespace ci;

Square::Square()
{
	next = this;
	prev = this;

	red = 0;
	green = 0;
	blue = 0;

	x = 0.0f;
	y = 0.0f;
	size = 0.0f;

	falls = true;
	speed = 5;
}

// This method inserts a single Square after another square
void insertAfter(Square* new_square, Square* insert_here){
	new_square->next = insert_here->next;
	new_square->prev = insert_here;
	insert_here->next->prev = new_square;
	insert_here->next = new_square;
}

// This method updates the instance of Square
// You should probably shouldn't include collision detection here.  Put it in the HW02App.cpp update() instead
// By putting collision detection here, you are calling a lot of unnecessary checks.  For example, you would only have to do
// A,B A,C A,D
// B,C, B,D
// C,D
// in a list of A...D instead of checking every one multiple times like what happens here
void Square::update(){
	if(falls == true)
		this->y+=speed;
	else
		this->y-=speed;

	// You might want to make a more descriptive name for your pointers in the future
	// "that" says nothing about what the pointer is or what it is used for.
	Square* that = this->next;

	while(that!=this){
		// if you saw this line out of context, could you tell me what this and that are?
		collide(this,that);
		that = that->next;
	}

	if(this->x > 360 || this->x < 0){
		remove();
	}
}

// This method draws the Square to the app window
void Square::draw(){
	gl::color(Color8u((uint8_t)red,(uint8_t)green,(uint8_t)blue)); // Why aren't your colors already uint8_t?
	gl::drawSolidRect(Rectf(x,y,x+size,y+size));
}

// This method checks collisions and changes colors of the Squares if a collision occurs
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

// This method removes the Square from the Linked List that it is in.
// This does not delete the Square
void Square::remove(){
	this->prev->next = this->next;
	this->next->prev = this->prev;
}