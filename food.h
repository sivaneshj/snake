#ifndef FOOD_H
#define FOOD_H
#include<windows.h>

class food
{
	private:
		COORD foodpos;
	public:
		food();
		void genfood();
		COORD getfoodpos();
		
};

#endif
