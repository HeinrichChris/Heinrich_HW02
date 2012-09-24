
class Square
{
public:
	Square();

	Square* next;
	Square* prev;

	float x;
	float y;
	float size;
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

