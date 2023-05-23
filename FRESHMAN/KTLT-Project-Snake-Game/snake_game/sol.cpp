﻿#include "nkea.h"
// Cố định màn hình Console
void FixconsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

// Chỉnh màu chữ 
void setTextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Dịch chuyển
void GotoXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//Thay đổi font chữ
void fontsize(int a, int b) {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();
	lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);
	GetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
	lpConsoleCurrentFontEx->dwFontSize.X = a;
	lpConsoleCurrentFontEx->dwFontSize.Y = b;
	SetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
}

// hidecur
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConCurInf;

	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = CursorVisibility;
	SetConsoleCursorInfo(handle, &ConCurInf);
}

//Vẽ khung game
void DrawBoard(int x, int y, int width, int height, int curPosX, int curPosY) {
	GotoXY(x, y);
	setTextColor(9);
	for (int i = 0; i <= width; i++) cout << char(219);
	GotoXY(x, height + y);
	for (int i = 0; i <= width; i++) cout << char(219);
	for (int i = y + 1; i < height + y; i++) {
		GotoXY(x, i); cout << char(219);
		GotoXY(x + width, i); cout << char(219);
	}
	setTextColor(7);
	GotoXY(curPosX, curPosY);
}

//Vẽ chữ TEAM 14
void DrawTeam14() {
	GotoXY(22, 24);
	cout << " ____  ____   __   _  _     __   ___ ";
	GotoXY(22, 25);
	cout << "(_  _)(  __) / _\\ ( \\/ )   /  \\ / _ \\";
	GotoXY(24, 26);
	cout << ")(   ) _) /    \\/ \\/ \\  (_/ /(__  (";
	GotoXY(23, 27);
	cout << "(__) (____)\\_/\\_/\\_)(_/   (__)  (__/";
}

//Vẽ con rắn
void DrawSnake_Game() {
	GotoXY(93, 1);
	cout << "__";
	GotoXY(92, 2);
	cout << "{0O}";
	GotoXY(92, 3);
	cout << "\\__/";
	GotoXY(92, 4);
	cout << "/^/";
	GotoXY(91, 5);
	cout << "( (";
	GotoXY(91, 6);
	cout << "\\_\\_____";
	GotoXY(91, 7);
	cout << "(_______,)";
	GotoXY(90, 8);
	cout << "(_________()Oo";
}

//Vẽ chữ SNAKE
void DrawSnake_Text() {
	GotoXY(85, 10);
	cout << "___  __   ___  __ _ ____ ";
	GotoXY(85, 11);
	cout << "| _\\ | \\|\\|  \\ | V \\| __\\";
	GotoXY(85, 12);
	cout << "[__ \\|  \\|| . \\|  <_|  ]_";
	GotoXY(85, 13);
	cout << "|___/|/\\_/|/\\_/|/\\_/|___/";
}

//Vẽ chữ SNAKE GAME trong menu
void DrawSnakeGame_Menu(char Text, int x, int y) {
	if (Text == 83 || Text == 115) {
		GotoXY(x, y);
		cout << "____";
		GotoXY(x - 1, y + 1);
		cout << "(_ (_`";
		GotoXY(x - 2, y + 2);
		cout << ".__)__)";
	}
	else if (Text == 78 || Text == 110) {
		GotoXY(x, y);
		cout << "__  _";
		GotoXY(x - 1, y + 1);
		cout << "|  \\| |";
		GotoXY(x - 1, y + 2);
		cout << "|_|\\__|";
	}
	else if (Text == 65 || Text == 97) {
		GotoXY(x, y);
		cout << "____";
		GotoXY(x - 1, y + 1);
		cout << "/ () \\";
		GotoXY(x - 2, y + 2);
		cout << "/__/\\__\\";
	}
	else if (Text == 75 || Text == 107) {
		GotoXY(x, y);
		cout << "__  __";
		GotoXY(x - 1, y + 1);
		cout << "|  |/  /";
		GotoXY(x - 1, y + 2);
		cout << "|__|\\__\\";
	}
	else if (Text == 69 || Text == 101) {
		GotoXY(x, y);
		cout << "____";
		GotoXY(x - 1, y + 1);
		cout << "| ===|";
		GotoXY(x - 1, y + 2);
		cout << "|____| ";
	}
	else if (Text == 71 || Text == 103) {
		GotoXY(x, y);
		cout << "____";
		GotoXY(x - 1, y + 1);
		cout << "/ (_,`";
		GotoXY(x - 1, y + 2);
		cout << "\\____)";
	}
	else if (Text == 77 || Text == 109) {
		GotoXY(x, y);
		cout << "__  __";
		GotoXY(x - 1, y + 1);
		cout << "|  \\/  |";
		GotoXY(x - 1, y + 2);
		cout << "|_|\\/|_|";
	}
}

//Vẽ con rắn trong menu
void DrawSnake_Menu() {
	GotoXY(20, 1);
	cout << "____";
	GotoXY(4, 2);
	cout << "_______________/ O  \\___/";
	GotoXY(3, 3);
	cout << "<_O_O_O_O_O_O_O_O____/   \\";
}

//Vẽ chữ GAME OVER
void DrawGameOver() {
	int WIDTH_CONSOLE = 20;
	int HEIGH_CONSOLE = 20;
	GotoXY(WIDTH_CONSOLE / 2 + 8, HEIGH_CONSOLE / 2 - 3);
	cout << " (  (     )    )     (         )     (  (    ";
	GotoXY(WIDTH_CONSOLE / 2 + 8, HEIGH_CONSOLE / 2 - 2);
	cout << " )\\))( ( /(   (     ))\\    (  /((   ))\\ )(   ";
	GotoXY(WIDTH_CONSOLE / 2 + 8, HEIGH_CONSOLE / 2 - 1);
	cout << "((_))\\ )(_))  )\\  '/((_)   )\\(_))\\ /((_|()\\  ";
	GotoXY(WIDTH_CONSOLE / 2 + 8, HEIGH_CONSOLE / 2);
	cout << " (()(_|(_)_ _((_))(_))    ((_))((_|_))  ((_) ";
	GotoXY(WIDTH_CONSOLE / 2 + 8, HEIGH_CONSOLE / 2 + 1);
	cout << "/ _` |/ _` | '  \\() -_)  / _ \\ V // -_)| '_| ";
	GotoXY(WIDTH_CONSOLE / 2 + 8, HEIGH_CONSOLE / 2 + 2);
	cout << "\\__, |\\__,_|_|_|_|\\___|  \\___/\\_/ \\___||_|   ";
	GotoXY(WIDTH_CONSOLE / 2 + 8, HEIGH_CONSOLE / 2 + 3);
	cout << "|___/                                        ";
}

//Vẽ hướng dẫn chơi
void DrawHowToPlay() {
	GotoXY(93, 23);
	cout << "HOW TO PLAY";
	GotoXY(88, 25);
	cout << "MOVE SNAKE: A, W, S, D";
	GotoXY(88, 26);
	cout << "PAUSE GAME: P";
	GotoXY(88, 27);
	cout << "SAVE GAME: L";
	GotoXY(88, 28);
	cout << "BACK TO MENU: M";
}

//Tính toán vị trí in menu_list
int pos_calc(string s) {
	return (s.length() / 2 + 1);
}

//Drawboard cho menu
void Draw_Board(int x, int y, int width, int height, int curPosX, int curPosY) {
	setTextColor(9);
	GotoXY(x, y);
	cout << char(201);
	for (int i = 1; i < width / 2; i++) {
		cout << char(205) << char(205);
		Sleep(1);
	}
	if (width + 1 > width / 2 * 2) cout << char(205);
	cout << char(187);
	GotoXY(x, height + y); cout << char(200);
	for (int i = 1; i < width / 2; i++) {
		cout << char(205) << char(205);
		Sleep(1);
	}
	if (width + 1 > width / 2 * 2) cout << char(205);
	cout << char(188);
	for (int i = y + 1; i < height + y; i++) {
		GotoXY(x, i); cout << char(186);
		GotoXY(x + width, i); cout << char(186);
		Sleep(1);
	}
	GotoXY(curPosX, curPosY);

	// Vẽ chữ SNAKE GAME
	setTextColor(6);
	DrawSnakeGame_Menu('S', 34, 1);
	DrawSnakeGame_Menu('N', 40, 1);
	DrawSnakeGame_Menu('A', 48, 1);
	DrawSnakeGame_Menu('K', 55, 1);
	DrawSnakeGame_Menu('E', 63, 1);
	DrawSnakeGame_Menu('G', 72, 1);
	DrawSnakeGame_Menu('A', 79, 1);
	DrawSnakeGame_Menu('M', 86, 1);
	DrawSnakeGame_Menu('E', 94, 1);

	// Vẽ hình con rắn
	setTextColor(2);
	DrawSnake_Menu();
}

//Vẽ bảng menu save game load setiing..
void Draw_menu_board() {
	setTextColor(9);
	int x_menu = 2, y_menu = 5;
	string top[3] = { R"(         /\        )",
								  R"( _       \/       _)",
						 R"((______/\/\/\______))" };
	string mid[20] = { " |                | ",
					  " (                ( ",
					  "  )                )",
					  " (                ( ",
					  " |                | ",
					  " (                ( ",
					  "  )                )",
					  " (                ( ",
					  " |                | ",
					  " (                ( ",
					  "  )                )",
					  " (                ( ",
					  " |                | ",
					  " (                ( ",
					  "  )                )",
					  " (                ( ",
					  " |                | ",
					  " (                ( ",
					  "  )                )",
					  " (                ( " };
	string bot[2] = { " |________________| ",
			R"( (_____/\/\/\_____))" };
	for (int i = 16; i > 5; i--) {
		for (int j = i + 1; j < 33 - i; j++)
		{
			GotoXY(x_menu, j);
			cout << mid[j - 7];
		}
		for (int j = 0; j < 3; j++) {
			GotoXY(x_menu, i - j);
			cout << top[2 - j];
		}
		for (int j = 0; j < 2; j++) {
			GotoXY(x_menu, 33 - i + j);
			cout << bot[j];
		}
		Sleep((i - 4) * 10);
	}
}
