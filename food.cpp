#include "food.h"
#include<ctime>
#include<stdlib.h>
#define width 50
#define height 30

food::food()
{
	srand(time(NULL));
    genfood();
}
void food::genfood()
{
	foodpos.X= rand()%width+1;
	foodpos.Y= rand()%height+1;
}
COORD food::getfoodpos()
{
	return foodpos;
}
