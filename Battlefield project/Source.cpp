#include <conio.h>
#include <iomanip>
#include <iostream>
#include<fcntl.h>
#include<stdio.h>
#include<Windows.h>
#include<time.h>

using namespace std;

#include"struct.h"
#include"function.h"


void main() {

	srand(time(0));

	welcomeScreen();
	ShowMenu();

}