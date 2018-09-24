 #include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

typedef struct Position
{
	int x;
	int y;

	void print()
	{
		cout << x << " , " <<  y << endl;
	}

}Coordinates;

enum WarHead { EXPLOSIVE, NUCLEAR };

typedef struct Enemy {
	Coordinates coordinates;
}Target;

struct Missile {
	
	WarHead payload;
	Coordinates coordinates;

	Target target;

	bool armed;

	void arm()
	{
		if (armed)
			armed = false;
		else
			armed = true;
	}

	void update() {
		coordinates.x += 1;
		coordinates.y += 2;
	}
};
int main()
{
	std::srand(static_cast<unsigned>(time(NULL)));
	int codes[5] = { rand() % 10 , rand() % 10 , rand() % 10 , rand() % 10 , rand() % 10 };
	Missile rocket;
	int userInput;

	int xPos;
	int yPos;

	

	cout << "choose warhead" << "" << "  1. is for a Explosive rocket" << "" << " 2. is for a Nuclear rocket "<< endl;
	cin >> userInput;

	
	if (userInput == 1)
	{
		rocket.payload = WarHead::EXPLOSIVE;
	}
	if (userInput == 2)
	{
		rocket.payload = WarHead::NUCLEAR;
	}
	

	rocket.target.coordinates.x = rand() % 100;
	rocket.target.coordinates.y = rand() % 100;

	cout << "Rocket at target " << endl;
	rocket.target.coordinates.print();
	 
	for (int i = 0; i < 5; i++)
	{
		cout << codes[i] << "";
	}
	
	cout << "Please enter the codes shown" << endl;
	
	rocket.arm();

	while (true)
	{
		if (rocket.coordinates.x == rocket.target.coordinates.x)
		{
			if (rocket.coordinates.y == rocket.coordinates.y)
			{
				cout << "Target HIt" << endl;
			}
		}
	}

	system("pause");
}