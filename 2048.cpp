#include <iostream>
#include <ctime>
#include <iomanip>



using namespace std;

void setConsoleColor(int textColor, int bgColor) 
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (textColor + (bgColor * 16)));
}


int main(){
	setConsoleColor(RED,BLUE);
}