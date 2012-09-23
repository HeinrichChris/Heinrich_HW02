
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

	void draw();
	void update();
};

void insertAfter(Square* new_square, Square* insert_here);

