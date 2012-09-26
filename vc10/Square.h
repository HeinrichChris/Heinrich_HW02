// While it is acceptible for this assignment, you will usually want to create your shape separate from your List Node
class Square{
public:
	Square();

	Square* next;
	Square* prev;

	float x;
	float y;

	float size;

	// consider making these 3 variables uint8_t since you cast them in draw anyways
	float red;
	float green;
	float blue;

	int speed;
	bool falls;

	void draw();
	void update();
	void remove();
};

void insertAfter(Square* new_square, Square* insert_here);
void collide(Square* square1, Square* square2);
