#pragma once


int** creatArr(int size);

int mySize = 10;
bool chekingIgnore = false;

int** playerBoard = creatArr(mySize);
int** enemyBoard = creatArr(mySize);


void mysetcolor(int fg, int bg) {

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, fg | (bg << 4));
}


int** creatArr(int size) {

	int** arr = new int* [size + 1];

	for (size_t i = 0; i < size + 1; i++)
		arr[i] = new int[size + 1]{};

	return arr;
}


void fillArr(int** arr, PackageMan pack, Simvol s, int count, int data, int size) {

	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (i == 0 || j == 0 || i == size - 1 || j == size - 1)
				arr[i][j] = 9;

			else
				arr[i][j] = 0;
		}
	}
}


void showMyships(int** arr, int size) {

	cout << "  " << endl << endl << endl;

	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{

			if (arr[i][j] == 1) {

				mysetcolor(15, 0);
				cout << char(248) << "  ";
			}

			else if (arr[i][j] == 9) {

				cout << char(240) << "  ";
			}

			else if (arr[i][j] == 2) {

				mysetcolor(6, 0);
				cout << char(248) << "  ";
				mysetcolor(7, 0);
			}

			else if (arr[i][j] == 7) {
				mysetcolor(4, 0);
				cout << 'X' << "  ";
				mysetcolor(7, 0);
			}

			else if (arr[i][j] == 0) {

				mysetcolor(3, 0);
				cout << char(176) << "  ";
			}

			else if (arr[i][j] == 5) {

				mysetcolor(11, 0);
				cout << char(111) << "  ";
			}

		}
		cout << endl << endl;
	}
}


void showRivalShips(int** arr, int size) {

	cout << "  " << endl;

	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{

			if (arr[i][j] == 3) {

				mysetcolor(14, 0);
				cout << char(248) << "  ";
				//mysetcolor(7, 0);
			}

			else if (arr[i][j] == 0) {

				mysetcolor(3, 0);
				cout << char(176) << "  ";
			}

			else if (arr[i][j] == 7) {
				mysetcolor(4, 0);
				cout << char(248) << "  ";
				mysetcolor(7, 0);
			}

			else if (arr[i][j] == 2) {

				mysetcolor(13, 0);
				cout << char(248) << "  ";
				mysetcolor(7, 0);
			}

			else if (arr[i][j] == 6) {

				mysetcolor(6, 0);
				cout << char(219) << "  ";
			}

			else {
				mysetcolor(3, 0);
				cout << char(176) << "  ";
			}
		}
		cout << endl << endl;
	}
}


bool isEmptyPlace(int** arr, int y, int x) {

	if (y == mySize || x == mySize)
		return false;

	if (y == -1 || x == -1)
		return false;

	if (arr[y][x] == 6) return true;

	if (arr[y][x] != 0 || y < 0 || y >= mySize || x < 0 || x >= mySize)
		return false;

	return true;
}


bool fillShipManual(int** arr, int y, int x, Simvol s, int count) {

	bool hasSomething = false;
	int countCheck = 0;

	if (s == RIGHT) {

		for (size_t i = y; i < y + 1; i++)
		{
			for (size_t j = x; j < x + count; j++) {

				if (arr[i][j] != 0 || i < 0 || i >= mySize || j < 0 || j >= mySize || arr[i][j + 1] == 5
					|| arr[y + 1][x] == 5 || arr[y][x + 1] == 5 || arr[y][x - 1] == 5)
					countCheck++;

				if (y - 1 != -1) {

					if (arr[y - 1][x] == 5)
						++countCheck;
				}
			}
		}

		if (countCheck == 0) {

			for (size_t i = y; i < y + 1; i++)
			{
				for (size_t j = x; j < x + count; j++)
					arr[i][j] = 5;
			}

			hasSomething = false;
		}

		else
		{
			hasSomething = true;
			cout << "\a" << endl;
		}
	}

	else if (s == DOWN) {

		int i = 0, k = 0;

		for (i = y; i < y + count + 1; i++) {

			if (i > 10) {
				countCheck++;
				break;
			}

			for (k = x - 1; k < x + 2; k++) {

				if (k == -1) {
					k++;
				}
				if (arr[i][k] != 0 || k < 0 || k > mySize || i < 0 || i > mySize
					|| arr[y + 1][x] == 5 || arr[y][x + 1] == 5 || arr[y][x - 1] == 5)
					++countCheck;

			}

		}

		if (countCheck == 0) {

			for (size_t i = y; i < y + count; i++)
			{
				for (size_t j = x; j < x + 1; j++)
					arr[i][j] = 5;
			}

			hasSomething = false;
		}
		else
		{
			hasSomething = true;
			cout << "\a";
		}
	}
	return hasSomething;
}


void reversManual(int** arr, int y, int x, Simvol s, int count) {

	fillShipManual(arr, pack.y, pack.x, s, count);
}


void clearShip(int** arr, int y, int x, Simvol s, int count) {

	if (s == RIGHT) {

		for (size_t i = y; i < y + 1; i++)
		{
			for (size_t k = x; k < x + count + 1; k++)
				arr[i][k] = 0;
		}
	}

	else if (s == DOWN) {

		for (size_t i = y; i < y + count; i++)
		{
			if (i >= 10) break;
			for (size_t k = x; k < x + 1; k++)
				arr[i][k] = 0;
		}
	}
}


bool putShipWithCordinates(int** arr, int y, int x, Simvol direction, int count) {

	bool result = fillShipManual(arr, pack.y, pack.x, direction, count);
	char revers = ' ';

	do
	{
		system("cls");
		showMyships(arr, mySize);

		int revers = 0;
		revers = _getch();

		if (revers == REVERS) {

			if (direction == RIGHT) {

				direction = DOWN;
				clearShip(arr, pack.y, pack.x, RIGHT, count);
				reversManual(arr, pack.y, pack.x, DOWN, count);
			}

			else
			{
				direction = RIGHT;
				clearShip(arr, pack.y, pack.x, DOWN, count);
				reversManual(arr, pack.y, pack.x, RIGHT, count);
			}
			showMyships(arr, mySize);
		}

		if (revers == ENTER) {
			pack.y = 0;
			pack.x = 0;
			break;
		}

	} while (revers != ENTER);

	return result;
}


void putShipManual(int** arr) {

	int counters[10] = { 4,3,3,2,2,2,1,1,1,1 };
	int index = 0;

	while (true) {

		system("cls");
		showMyships(playerBoard, mySize);

		int direction = 0;
		direction = _getch();

		if (direction == 224) {

			direction = _getch();
			arr[pack.y][pack.x] = 0;

			if (direction == RIGHT) {

				if (isEmptyPlace(arr, pack.y, pack.x + 1))
					pack.x++;
			}

			else if (direction == LEFT) {

				if (isEmptyPlace(arr, pack.y, pack.x - 1))
					pack.x--;
			}

			else if (direction == UP) {

				if (isEmptyPlace(arr, pack.y - 1, pack.x))
					pack.y--;
			}

			else if (direction == DOWN) {

				if (isEmptyPlace(arr, pack.y + 1, pack.x))
					pack.y++;
			}

			arr[pack.y][pack.x] = 1;
		}

		else if (direction == ENTER) {

			arr[pack.y][pack.x] = 0;
			bool result = putShipWithCordinates(arr, pack.y, pack.x, RIGHT, counters[index]);

			if (result == false)
				++index;

			pack.y = 0;
			pack.y = 0;
			arr[pack.y][pack.x] = 1;

			if (index == 10) {
				break;
			}
		}
	}

}


bool fillShipsRandomly(int** arr, int y, int x, Simvol s, int count, int data) {


	bool hasSomething = false;
	int counterchecker = 0;

	if (s == RIGHT) {

		int i = 0, k = 0;

		for (int i = y - 1; i < y + 2; i++) {

			for (int k = x - 1; k < x + count + 1; k++) {

				if (arr[i][k] != 0)
					++counterchecker;
			}
			if (counterchecker > 0)
				break;
		}

		if (counterchecker == 0) {

			for (int i = y; i < y + 1; i++) {

				for (int k = x; k < x + count; k++) {

					arr[i][k] = data;
				}
			}

			hasSomething = false;
		}

		else { hasSomething = true; }
	}

	else if (s == DOWN) {

		int i = 0, k = 0;

		for (i = y - 1; i < y + count + 1; i++) {

			if (i >= 10) {
				counterchecker++;
				break;
			}

			for (k = x - 1; k < x + 2; k++) {

				if (arr[i][k] != 0 || k < 0 || k > mySize || i < 0 || i > mySize || arr[x - 1][y + 1] == 5)
					++counterchecker;
			}
		}

		if (counterchecker == 0) {

			for (size_t i = y; i < y + count; i++)
			{
				for (size_t j = x; j < x + 1; j++)
					arr[i][j] = data;
			}

			hasSomething = false;
		}
		else
		{
			hasSomething = true;
			cout << "\a";
		}
	}
	return hasSomething;
}


void fillSpecialFunction(int** arr, int count, int data) {

	srand(time(nullptr));

	bool isNotOkay = false;

	do
	{
		int x = 2 + rand() % (11 - 2 + 1);
		int y = 1 + rand() % (9 - 1 + 1);

		isNotOkay = false;

		if (y % 2 == 0) {
			isNotOkay = fillShipsRandomly(arr, y, x, RIGHT, count, data);
		}
		else {
			isNotOkay = fillShipsRandomly(arr, y, x, DOWN, count, data);
		}

		if (isNotOkay == false)break;

	} while (isNotOkay == true); srand(81);
}


void fillSpecialFunctionEnemy(int** arr, int count, int data) {

	srand(time(nullptr));

	bool isNotOkay = false;

	do
	{
		int x = 1 + rand() % (11 - 1 + 1);
		int y = 1 + rand() % (8 - 1 + 1);

		isNotOkay = false;

		if (x % 2 == 0) {
			isNotOkay = fillShipsRandomly(arr, y, x, RIGHT, count, data);
		}
		else {
			isNotOkay = fillShipsRandomly(arr, y, x, DOWN, count, data);
		}

		if (isNotOkay == false)break;

	} while (isNotOkay == true); srand(43);
}


void putShipRandomly(int** arr, int data) {

	srand(200);

	const int size = 10;
	int counters[size] = { 4,3,3,2,2,2,1,1,1,1 };

	for (size_t i = 0; i < size; i++)
		fillSpecialFunction(arr, counters[i], data);
}


void putShipRandomlyEnemy(int** arr, int data) {

	srand(101);

	const int size = 10;
	int counters[size] = { 4,3,3,2,2,2,1,1,1,1 };

	for (size_t i = 0; i < size; i++)
		fillSpecialFunctionEnemy(arr, counters[i], data);
}


bool battle(int** arr) {

	int old_y = -1;
	int old_x = -1;
	int simvol = -1;

	if (chekingIgnore == false) {

		cin.ignore();
		cin.clear();
		chekingIgnore = true;
	}


	while (true) {


		system("cls");
		showMyships(playerBoard, mySize);
		showRivalShips(arr, mySize);

		int direction = 0;
		direction = _getch();

		if (direction == 224) {

			direction = _getch();
			old_y = pack.y;
			old_x = pack.x;

			if (arr[pack.y][pack.x] == 3 && simvol != -1)
				arr[old_y][old_x] = simvol;

			if (direction == RIGHT) {

				if (isEmptyPlace(arr, pack.y, pack.x + 1)) {
					simvol = arr[pack.y][pack.x + 1];
					pack.x++;
				}
			}

			else if (direction == LEFT) {

				if (isEmptyPlace(arr, pack.y, pack.x - 1)) {
					simvol = arr[pack.y][pack.x - 1];
					pack.x--;
				}
			}

			else if (direction == UP) {

				if (isEmptyPlace(arr, pack.y - 1, pack.x)) {
					simvol = arr[pack.y - 1][pack.x];
					pack.y--;
				}
			}

			else if (direction == DOWN) {

				if (isEmptyPlace(arr, pack.y + 1, pack.x)) {
					simvol = arr[pack.y + 1][pack.x];
					pack.y++;
				}
			}
			arr[pack.y][pack.x] = 3;
		}

		else if (direction == ENTER) {


			if (simvol == 6) {

				arr[pack.y][pack.x] = 7;
				simvol = -1;
				continue;
			}

			else if (simvol == 0) {

				arr[pack.y][pack.x] = 2;
				return false;
			}

			else
				arr[pack.y][pack.x] = 0;

			pack.y = 0;
			pack.x = 0;
			return false;
		}
	}
}


void showMetods() {

	system("cls");
	showMyships(playerBoard, mySize);
	showRivalShips(enemyBoard, mySize);
}


bool isBoom(int** arr, int x, int y) {


	if (arr[y][x - 1] == 5 || arr[y][x + 1] == 5 || arr[y - 1][x] == 5 || arr[y + 1][x] == 5) {

		return false;
	}

	return true;
}

bool isEmptyArea(int** arr, int x, int y) {

	if (arr[y][x - 1] == 7 || arr[y][x + 1] == 7 || arr[y - 1][x] == 7 || arr[y + 1][x] == 7) {

		return false;
	}
	return true;
}


void ClearStrike(Striked& strike) {
	strike.dowm = false;
	strike.dowm_Access = false;
	strike.left = false;
	strike.left_Access = false;
	strike.right = false;
	strike.right_Access = false;
	strike.striked = false;
	strike.striked_x = -1;
	strike.striked_y = -1;
}


void battleRandom(int** arr)
{
	srand(time(0));

	bool isOkay = false;
	int x = 0;
	int y = 0;

	while (true) {

		do {

			x = rand() % 10;
			y = rand() % 10;
			Sleep(500);

		} while (arr[y][x] == 2 || arr[y][x] == 7);

		if (!strike.striked) {

			if (arr[y][x] == 5) {

				if (isBoom(arr, x, y)) {

					cout << "\a\a\a";
					ClearStrike(strike);
					continue;
				}

				arr[y][x] = 7;

				strike.striked = true;
				strike.striked_x = x;
				strike.striked_y = y;

				system("cls");
				showMyships(playerBoard, mySize);
				showRivalShips(enemyBoard, mySize);
				Sleep(500);
				continue;
			}
		}

		else {

			if (!strike.left_Access) {

				//strike.left_Access = true;
				if (strike.left == false) {

					x = strike.striked_x - 1;
					y = strike.striked_y;

					if (arr[y][x] == 2) {
						strike.left_Access = true;
						continue;
					}
					else if (y >= mySize || y<0 || x>mySize || x < 0) {
						strike.left_Access = true;
						continue;
					}

					if (isEmptyArea(arr, x, y)) {
						strike.left_Access = true;
						continue;
					}

					if (arr[y][x] == 5) {

						arr[y][x] = 7;
						strike.left = true;

						if (isBoom(arr, x, y)) {
							if (isBoom(arr, strike.striked_x, strike.striked_y)) {
								cout << "\a\a\a";
								ClearStrike(strike);
								continue;
							}
						}
					}

					else {
						arr[y][x] = 2;
						strike.left = false;
						strike.left_Access = true;
						Sleep(500);
						showMetods();
						break;
					}
				}

				if (strike.left == true) {

					x = strike.striked_x - 2;
					y = strike.striked_y;

					if (arr[y][x] == 2) {
						strike.left_Access = true;
						continue;
					}
					else if (y >= mySize || y<0 || x>mySize || x < 0) {
						strike.left_Access = true;
						continue;
					}
					if (arr[y][x] == 5) {
						arr[y][x] = 7;
						strike.left = true;
						if (isBoom(arr, x, y)) {
							if (isBoom(arr, strike.striked_x, strike.striked_y)) {
								cout << "\a\a\a";
								ClearStrike(strike);
								continue;
							}
						}
						Sleep(500);
						showMetods();
					}
					else {
						arr[y][x] = 2;
						strike.left = false;
						strike.left_Access = true;
						//strike.up_Access = true;
						//strike.dowm_Access = true;
						Sleep(500);
						showMetods();
						break;
					}
				}

				if (strike.left == true) {

					x = strike.striked_x - 3;
					y = strike.striked_y;

					if (arr[y][x] == 2) {
						strike.left_Access = true;
						continue;
					}
					else if (y >= mySize || y<0 || x>mySize || x < 0) {
						strike.left_Access = true;
						continue;
					}

					if (arr[y][x] == 5) {
						arr[y][x] = 7;
						strike.left = true;
						if (isBoom(arr, x, y)) {
							if (isBoom(arr, strike.striked_x, strike.striked_y)) {
								cout << "\a\a\a";
								ClearStrike(strike);
								continue;
							}
						}
						Sleep(500);
						showMetods();
					}
					else {
						arr[y][x] = 2;
						strike.left = false;
						strike.left_Access = true;
						//strike.dowm_Access = true;
						//strike.up_Access = true;
						Sleep(500);
						showMetods();
						break;
					}
				}
			}

			if (!strike.right_Access) {

				//strike.right Access = true;
				if (strike.right == false) {

					x = strike.striked_x + 1;
					y = strike.striked_y;

					if (arr[y][x] == 2) {
						strike.right_Access = true;
						continue;
					}
					else if (y >= mySize || y<0 || x>mySize || x < 0) {
						strike.right_Access = true;
						continue;
					}

					if (isEmptyArea(arr, x, y)) {
						strike.left_Access = true;
						continue;
					}

					if (arr[y][x] == 5) {
						arr[y][x] = 7;
						strike.right = true;
						if (isBoom(arr, x, y)) {
							if (isBoom(arr, strike.striked_x, strike.striked_y)) {
								cout << "\a\a\a";
								ClearStrike(strike);
								continue;
							}
						}
						Sleep(500);
						showMetods();
					}

					else {
						arr[y][x] = 2;
						strike.right = false;
						strike.right_Access = true;
						Sleep(500);
						showMetods();
						break;
					}
				}

				if (strike.right == true) {

					x = strike.striked_x + 2;
					y = strike.striked_y;

					if (arr[y][x] == 2) {
						strike.right_Access = true;
						continue;
					}
					else if (y >= mySize || y<0 || x>mySize || x < 0) {
						strike.right_Access = true;
						continue;
					}

					if (arr[y][x] == 5) {
						arr[y][x] = 7;
						strike.right = true;
						if (isBoom(arr, x, y)) {
							if (isBoom(arr, strike.striked_x, strike.striked_y)) {
								cout << "\a\a\a";
								ClearStrike(strike);
								continue;
							}
						}
						Sleep(500);
						showMetods();
					}
					else {
						arr[y][x] = 2;
						strike.right = false;
						strike.right_Access = true;
						//strike.up_Access = true;
						//strike.dowm_Access = true;
						Sleep(500);
						showMetods();
						break;
					}
				}

				if (strike.right == true) {

					x = strike.striked_x + 3;
					y = strike.striked_y;

					if (arr[y][x] == 2) {
						strike.right_Access = true;
						continue;
					}
					else if (y >= mySize || y<0 || x>mySize || x < 0) {
						strike.right_Access = true;
						continue;
					}

					if (arr[y][x] == 5) {
						arr[y][x] = 7;
						strike.right = true;
						if (isBoom(arr, x, y)) {
							if (isBoom(arr, strike.striked_x, strike.striked_y)) {
								cout << "\a\a\a";
								ClearStrike(strike);
								continue;
							}
						}
						Sleep(500);
						showMetods();
					}
					else {
						arr[y][x] = 2;
						strike.right = false;
						strike.right_Access = true;
						Sleep(500);
						showMetods();
						break;
					}
				}
			}

			if (!strike.dowm_Access) {

				//strike.down_Access = true;
				if (strike.dowm == false) {

					x = strike.striked_x;
					y = strike.striked_y + 1;

					if (arr[y][x] == 2) {
						strike.dowm_Access = true;
						continue;
					}
					else if (y >= mySize || y<0 || x>mySize || x < 0) {
						strike.dowm_Access = true;
						continue;
					}
					if (isEmptyArea(arr, x, y)) {
						strike.left_Access = true;
						continue;
					}

					if (arr[y][x] == 5) {
						arr[y][x] = 7;
						strike.dowm = true;
						if (isBoom(arr, x, y)) {
							if (isBoom(arr, strike.striked_x, strike.striked_y)) {
								cout << "\a\a\a";
								ClearStrike(strike);
								continue;
							}
						}
						Sleep(500);
						showMetods();
					}

					else {
						arr[y][x] = 2;
						strike.dowm = false;
						strike.dowm_Access = true;
						Sleep(500);
						showMetods();
						break;
					}
				}

				if (strike.dowm == true) {

					x = strike.striked_x;
					y = strike.striked_y + 2;

					if (arr[y][x] == 2) {
						strike.dowm_Access = true;
						continue;
					}
					else if (y >= mySize || y<0 || x>mySize || x < 0) {
						strike.dowm_Access = true;
						continue;
					}

					if (arr[y][x] == 5) {
						arr[y][x] = 7;
						strike.dowm = true;
						if (isBoom(arr, x, y)) {
							if (isBoom(arr, strike.striked_x, strike.striked_y)) {
								cout << "\a\a\a";
								ClearStrike(strike);
								continue;
							}
						}
						Sleep(500);
						showMetods();
					}
					else {
						arr[y][x] = 2;
						strike.dowm = false;
						strike.dowm_Access = true;
						Sleep(500);
						showMetods();
						break;
					}
				}

				if (strike.dowm == true) {

					x = strike.striked_x;
					y = strike.striked_y + 3;

					if (arr[y][x] == 2) {
						strike.dowm_Access = true;
						continue;
					}
					else if (y >= mySize || y<0 || x>mySize || x < 0) {
						strike.dowm_Access = true;
						continue;
					}

					if (arr[y][x] == 5) {
						arr[y][x] = 7;
						strike.dowm = true;
						if (isBoom(arr, x, y)) {
							if (isBoom(arr, strike.striked_x, strike.striked_y)) {
								cout << "\a\a\a";
								ClearStrike(strike);
								continue;
							}
						}
						Sleep(500);
						showMetods();
					}
					else {
						arr[y][x] = 2;
						strike.dowm = false;
						strike.dowm_Access = true;
						Sleep(500);
						showMetods();
						break;
					}
				}
			}

			if (!strike.up_Access) {

				//strike.up_Access = true;
				if (strike.up == false) {

					x = strike.striked_x;
					y = strike.striked_y - 1;

					if (arr[y][x] == 2) {
						strike.up_Access = true;
						continue;
					}
					else if (y >= mySize || y<0 || x>mySize || x < 0) {
						strike.up_Access = true;
						continue;
					}
					if (isEmptyArea(arr, x, y)) {
						strike.left_Access = true;
						continue;
					}

					if (arr[y][x] == 5) {
						arr[y][x] = 7;
						strike.up = true;
						if (isBoom(arr, x, y)) {
							if (isBoom(arr, strike.striked_x, strike.striked_y)) {
								cout << "\a\a\a";
								ClearStrike(strike);
								continue;
							}
						}
						Sleep(500);
						showMetods();
					}

					else {
						arr[y][x] = 2;
						strike.up = false;
						strike.up_Access = true;
						Sleep(500);
						showMetods();
						break;
					}
				}

				if (strike.up == true) {

					x = strike.striked_x;
					y = strike.striked_y - 2;

					if (arr[y][x] == 2) {
						strike.up_Access = true;
						continue;
					}
					else if (y >= mySize || y<0 || x>mySize || x < 0) {
						strike.up_Access = true;
						continue;
					}

					if (arr[y][x] == 5) {
						arr[y][x] = 7;
						strike.up = true;
						if (isBoom(arr, x, y)) {
							if (isBoom(arr, strike.striked_x, strike.striked_y)) {
								cout << "\a\a\a";
								ClearStrike(strike);
								continue;
							}
						}
						Sleep(500);
						showMetods();
					}
					else {
						arr[y][x] = 2;
						strike.up = false;
						strike.up_Access = true;
						Sleep(500);
						showMetods();
						break;
					}
				}

				if (strike.up == true) {

					x = strike.striked_x;
					y = strike.striked_y - 3;

					if (arr[y][x] == 2) {
						strike.up_Access = true;
						continue;
					}
					else if (y >= mySize || y<0 || x>mySize || x < 0) {
						strike.up_Access = true;
						continue;
					}

					if (arr[y][x] == 5) {
						arr[y][x] = 7;
						strike.up = true;
						if (isBoom(arr, x, y)) {
							if (isBoom(arr, strike.striked_x, strike.striked_y)) {
								cout << "\a\a\a";
								ClearStrike(strike);
								continue;
							}
						}
						Sleep(500);
						showMetods();
					}
					else {
						arr[y][x] = 2;
						strike.up = false;
						strike.up_Access = true;
						Sleep(500);
						showMetods();
						break;
					}
				}
			}
		}

		if (arr[y][x] == 0) {

			arr[y][x] = 2;
			break;
		}
	}
}


void welcomeScreen() {
	mysetcolor(9, 0); cout << "\n";

	cout << "      			 ________________________________________________________________\n";
	cout << "      			|*****   ****  ****** ****** **     ******  ***** **  ** ** *****|\n";
	cout << "      			|**  *  **  **   **     **   **     **     **     **  ** ** **  *|\n";
	cout << "      			|*****  **  **   **     **   **     ****    ****  ****** ** *****|\n";
	cout << "      			|**  *  ******   **     **   **     **         ** **  ** ** **   |\n";
	cout << "      			|*****  **  **   **     **   ****** ****** *****  **  ** ** **   |\n";
	cout << "      			|________________________________________________________________|\n";
	cout << "      			\n";
}


void ShowMenu() {

	int select = 0;
	int e = 0;

	cout << "\n\n\t\t\t\t\t\t  ";
	while (e < 15) { cout << (char)196; ++e; }
	cout << endl << " \t\t\t\t\t         " << (char)179 << "NEW GAME -> 1  " << (char)179 << endl;
	cout << "         \t\t\t\t\t " << (char)179 << "EXIT -> 0      " << (char)179 << endl;
	cout << "         \t\t\t\t\t  ";

	int e1 = 0; while (e1 < 15) { cout << (char)196; ++e1; }
	cout << "\n\t\t\t\t\t\t   Select ->";
	cin >> select;
	system("cls");

	while (true) {

		if (select == 1) {

			cout << "\t\t\t\t\tRandom[0] or Manual[1]";
			cin >> select;

			if (select == 0) {

				putShipRandomly(playerBoard, 5);

				system("cls");
				showMyships(playerBoard, mySize);

				putShipRandomlyEnemy(enemyBoard, 6);
				showRivalShips(enemyBoard, mySize);

				while (true) {
					cout << endl << endl << endl;
					system("cls");
					battle(enemyBoard);
					battleRandom(playerBoard);
				}
			}
			else if (select == 1) {

				playerBoard[pack.y][pack.x] = 1;

				putShipManual(playerBoard);
				putShipRandomly(enemyBoard, 6);

				while (true) {
					Sleep(1000);
					system("cls");
					battle(enemyBoard);
					battleRandom(playerBoard);
				}
			}
			//Fight Place
		}
	}
}
