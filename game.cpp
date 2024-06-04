#include<iostream>
#include<fstream>
#include<conio.h>
#include"yourgraphics.h"
using namespace std;
void RotateLeft(int arr[])
{
	int temp = arr[0];
	for (int i = 0; i < 2; i++)                   //moves elements (colours) of arrays around
	{
		arr[i] = arr[i + 1];
	}
	arr[2] = temp;
}
int main()
{
	int w = 0, h = 0;
	getWindowDimensions(w, h);
	showConsoleCursor(false);
	cout << endl;
	cout << "                                                      *******************     " << endl;
	cout << "                                                      * BRICK           *     " << endl;
	cout << "                                                      *       BREAKER   *     " << endl;
	cout << "                                                      *******************     " << endl;
	cout << endl;
	cout << "Instructions :" << endl;
	cout << endl;
	cout << " 1) Press 'W' for Up " << endl;
	cout << " 2) Press 'A' for Left " << endl;
	cout << " 3) Press 'S' for Down " << endl;
	cout << " 4) Press 'D' for Right " << endl;
	cout << " 5) Press 'P' for Pause " << endl;
	cout << " 6) Press 'U' for Unpause " << endl;
	cout << " 7) Press 'K' for Save " << endl;
	cout << " 8) Press 'L' for Load " << endl;
	cout << " 9) Press 'Q' for Quit " << endl;
	cout << " 10) Press 'E' for Special Power (Elongation) " << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << endl;
	}
	cout << " Group Members :   " << endl;
	cout << endl;
	cout << "    HUSNAIN ALI   (22L-6562)" << endl;
	cout << "    HASNAIN KHURRAM   (22L-6564)" << endl;
	int getch();
	char n;
	while (1)
	{
		n = getch();
		if (n == 13)
		{                                                        //waiting for enter to get pressed
			break;
		}
	}
	cls(); gotoxy(0, 0);
	for (int i = 0; i < 5; i++)
	{
		cout << endl;
	}
	int choice;
	cout << endl;
	cout << "                                                      **************     " << endl;
	cout << "                                                      * New Game   *     " << endl;
	cout << "                                                      **************   " << endl;
	cout << endl;
	cout << "                                                      **************    " << endl;
	cout << "                                                      * Saved Game *     " << endl;
	cout << "                                                      **************  " << endl;
	cout << endl;
	cout << "                                                      **************    " << endl;
	cout << "                                                      * Quit Game  *     " << endl;
	cout << "                                                      **************  " << endl;
	cout << endl;
	cout << endl;
	int highscore[6] = { 0,0,0,0,0 }; int score = 0;
	int count[10] = { 0,0,0,0,0,0,0,0,0,0 };
	bool black[5][10];                                             //initializing arrays
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			black[i][j] = false;
		}
	}
	cout << "Choice : ";
	cin >> choice;
	while (choice < 1 || choice >3)
	{
		cout << "Choice : ";
		cin >> choice;
	}
	if (choice == 1 || choice == 2)
	{
		cls(); int bar1 = 475, bar2 = 675, life = 3, f = 0; bool flag = false;
		int e[4] = { 573,586,363,376 }, t[4] = { 0,0,6,6 }; int limit[10] = { 225,225,225,225,225,225,225,225,225,225 };
		gotoxy(100, 0); int a = 565, b = 570;
		int x = 0, y = 30; char p; int k; int l = 0, time = 0;
		int colour[3], brush[3];
		for (int m = 0; m < 10; m++)
		{
			y = 25; colour[0] = 255, colour[1] = 0, colour[2] = 0; brush[0] = 100, brush[1] = 0, brush[2] = 0;
			for (int j = 0; j < 5; j++)
			{
				x = 0;
				for (int i = 0; i < 10; i++)
				{
					drawRectangle(x, y, (x + 105), (y + 40), colour[0], colour[1], colour[2], brush[0], brush[1], brush[2]);
					x = x + 105;
					RotateLeft(colour);
					RotateLeft(brush);                        //printing coloured bricks
				}
				y = y + 40;
				RotateLeft(colour);
				RotateLeft(brush);
			}
		}
		if (choice == 2)
		{
			drawEllipse(e[0], e[2], e[1], e[3], 0, 0, 0, 0, 0, 0);
			drawRectangle(bar1, a, bar2, b, 0, 0, 0, 0, 0, 0);
			ifstream myfile;
			myfile.open("Saved_Game.txt");                //reading data from Saved_Game file
			myfile >> life;
			myfile >> score;
			myfile >> e[0] >> e[2] >> e[1] >> e[3];
			myfile >> bar1 >> bar2;
			myfile >> a >> b;
			myfile >> t[0] >> t[2] >> t[1] >> t[3];
			myfile >> time;
			myfile >> l;
			for (int i = 0; i < 10; i++)
			{
				myfile >> limit[i];
			}
			for (int i = 0; i < 10; i++)
			{
				myfile >> count[i];
			}
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					myfile >> black[i][j];
				}
			}
		}
	jump:
		y = 25;
		for (int i = 0; i < 5; i++)
		{
			x = 0;
			for (int j = 0; j < 10; j++)
			{
				if (black[i][j])
				{
					drawRectangle(x, y, (x + 105), (y + 40), 0, 0, 0, 0, 0, 0);
				}
				x = x + 105;                                // printing black bricks
			}
			y = y + 40;
		}
		while (1)
		{
			if (flag == true)
			{
				time++;
			}
			if (time == 500)
			{
				flag = false;
				drawRectangle(bar1, a, bar2, b, 0, 0, 0, 0, 0, 0);
				bar1 = bar1 + 25; bar2 = bar2 - 25;
				drawRectangle(bar1, a, bar2, b, 255, 255, 255, 255, 255, 255);
				time++;
			}
			gotoxy(0, 0); cout << " LIFE : " << life;
			gotoxy(100, 0); cout << " SCORE : " << score;
			char c = getKey();
			if (c == 'p' || c == 'P')                    // pause and unpause
			{
				gotoxy(50, 0);
				cout << "Game Paused. Press 'U' to unpause.";
				while (1)
				{
					p = getch();
					if (p == 'u' || p == 'U')
					{
						gotoxy(50, 0);
						cout << "                                           ";
						break;
					}
				}
			}
			if (c == 'a' || c == 'A')                          // leftward movement of bar
			{
				if (bar1 > 0)
				{
					drawRectangle(bar1, a, bar2, b, 0, 0, 0, 0, 0, 0);
					bar1 = bar1 - 25; bar2 = bar2 - 25;
				}
			}
			if (c == 'd' || c == 'D')                          // rightward movement of bar
			{
				if (bar2 < 1050)
				{
					drawRectangle(bar1, a, bar2, b, 0, 0, 0, 0, 0, 0);
					bar2 = bar2 + 25; bar1 = bar1 + 25;
				}
			}
			if (c == 'w' || c == 'W')                          // upward movement of bar
			{
				drawRectangle(bar1, a, bar2, b, 0, 0, 0, 0, 0, 0);
				if (a > 250)
				{
					a = a - 5;
					b = b - 5;
				}
			}
			if (c == 's' || c == 'S')                       // downward movement of bar
			{
				drawRectangle(bar1, a, bar2, b, 0, 0, 0, 0, 0, 0);
				if (b < 570)
				{
					a = a + 5;
					b = b + 5;
				}
			}
			if (c == 'k' || c == 'K')                        // saving game 
			{
				gotoxy(50, 0);
				cout << "Game Saved";
				delay(1000);
				gotoxy(50, 0);
				cout << "                                           ";
				ofstream myfile;
				myfile.open("Saved_Game.txt");
				myfile << life << endl;
				myfile << score << endl;
				myfile << e[0] << endl;
				myfile << e[2] << endl;
				myfile << e[1] << endl;
				myfile << e[3] << endl;
				myfile << bar1 << endl;
				myfile << bar2 << endl;
				myfile << a << endl;
				myfile << b << endl;
				myfile << t[0] << endl;
				myfile << t[2] << endl;
				myfile << t[1] << endl;
				myfile << t[3] << endl;
				myfile << time << endl;
				myfile << l << endl;
				for (int i = 0; i < 10; i++)
				{
					myfile << limit[i] << endl;
				}
				for (int i = 0; i < 10; i++)
				{
					myfile << count[i] << endl;
				}
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 10; j++)
					{
						myfile << black[i][j] << endl;
					}
				}
				cls();
				break;
			}
			if (c == 'l' || c == 'L')                //reading data if game loaded during new game
			{
				gotoxy(50, 0);
				cout << "Game Loaded";
				delay(1000);
				gotoxy(50, 0);
				cout << "                                           ";
				drawEllipse(e[0], e[2], e[1], e[3], 0, 0, 0, 0, 0, 0);
				drawRectangle(bar1, a, bar2, b, 0, 0, 0, 0, 0, 0);
				ifstream myfile;
				myfile.open("Saved_Game.txt");
				myfile >> life;
				myfile >> score;
				myfile >> e[0] >> e[2] >> e[1] >> e[3];
				myfile >> bar1 >> bar2;
				myfile >> a >> b;
				myfile >> t[0] >> t[2] >> t[1] >> t[3];
				myfile >> time;
				myfile >> l;
				for (int i = 0; i < 10; i++)
				{
					myfile >> limit[i];
				}
				for (int i = 0; i < 10; i++)
				{
					myfile >> count[i];
				}
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 10; j++)
					{
						myfile >> black[i][j];
					}
				}
				goto jump;
			}
			if (c == 'q' || c == 'Q')             //quit game
			{
				cls();
				break;
			}
			if (c == 'e' || c == 'E')             // Bar Elongation
			{
				if (l >= 0) 
				{
					{
						delay(50);
						flag = true;
						time = 0;
						bar1 = bar1 - 25; bar2 = bar2 + 25;
						l--;
					}
				}
			}
			if (flag == true) 
			{
				drawRectangle(bar1, a, bar2, b, 255,0,0,255, 0, 0);
			}
			else 
			{
				drawRectangle(bar1, a, bar2, b, 15, 148, 255, 15, 148, 255);
			}
			delay(15);
			drawEllipse(e[0], e[2], e[1], e[3], 0, 0, 0, 0, 0, 0);

			for (int i = 0; i < 4; i++)                          //movement of ball
			{
				e[i] = e[i] + t[i];
			}
			drawEllipse(e[0], e[2], e[1], e[3], 15, 148, 255, 15, 148, 255);

			if (e[1] >= 1050)                                    //condition when hits right wall
			{
				t[1] = t[1] * -1;
				t[0] = t[0] * -1;
			}
			if (e[0] <= 0)                                        //condition when hits left wall
			{
				t[0] = t[0] * -1; t[1] = t[1] * -1;
			}
			if (score == 5300)                                     //condition when to end game
			{
				cls(); gotoxy(0, 0);
				for (int i = 0; i < 4; i++)
				{
					cout << endl;
				}
				cout << "Congratulation you win" << endl; cout << endl;
				break;
			}
			if (e[2] <= limit[0] && e[0] < 105)                   //next 10 conditions are for when ball hits the break from bottom
			{
				count[0]++;
				if (e[1] == 104)
				{
					t[0] = t[0] * -1; t[1] = t[1] * -1;
					k = ((e[2] + 10) / 40) - 1;
					if (k < 0)
					{
						k = k + 1;
					}
					black[k][1] = true;
					drawRectangle(105, (k * 40) + 25, 210, (k * 40) + 65, 0, 0, 0, 0, 0, 0);
					score = score + 50;
				}
				t[2] = t[2] * -1;
				t[3] = t[3] * -1;
				k = e[0] / 105;
				if (count[0] == 1)
				{
					drawLine(k * 105, limit[0] - 40, ((k * 105) + 105), limit[0], 0, 0, 0);
				}
				else if (count[0] >= 2)
				{
					black[(limit[0] / 40) - 1][k] = true;
					drawRectangle(k * 105, limit[0] - 40, ((k * 105) + 105), limit[0], 0, 0, 0, 0, 0, 0);
					if (limit[0] > 25)
					{
						limit[0] = limit[0] - 40;
						score = score + 100;
					}
				}
			}
			if (e[2] <= limit[1] && e[0] >= 105 && e[0] < 210)
			{
				count[1]++;
				if (e[0] == 105)
				{
					t[0] = t[0] * -1; t[1] = t[1] * -1;
					k = ((e[2] + 10) / 40) - 1;
					if (k < 0)
					{
						k = k + 1;
					}
					black[k][0] = true;
					drawRectangle(0, (k * 40) + 25, 105, (k * 40) + 65, 0, 0, 0, 0, 0, 0);
					score = score + 50;
				}
				if (e[1] == 209)
				{
					t[0] = t[0] * -1; t[1] = t[1] * -1;
					k = ((e[2] + 10) / 40) - 1;
					if (k < 0)
					{
						k = k + 1;
					}
					black[k][2] = true;
					drawRectangle(210, (k * 40) + 25, 315, (k * 40) + 65, 0, 0, 0, 0, 0, 0);
					score = score + 50;
				}
				t[2] = t[2] * -1;
				t[3] = t[3] * -1;
				k = e[0] / 105;
				if (count[1] == 1)
				{
					drawLine(k * 105, limit[1] - 40, ((k * 105) + 105), limit[1], 0, 0, 0);
				}
				else if (count[1] >= 2)
				{
					black[(limit[1] / 40) - 1][k] = true;
					drawRectangle(k * 105, limit[1] - 40, ((k * 105) + 105), limit[1], 0, 0, 0, 0, 0, 0);
					if (limit[1] > 25)
					{
						limit[1] = limit[1] - 40; score = score + 100;
					}
				}
			}
			if (e[2] <= limit[2] && e[0] >= 210 && e[0] < 315)
			{
				count[2]++;
				if (e[0] == 210)
				{
					t[0] = t[0] * -1; t[1] = t[1] * -1;
					k = ((e[2] + 10) / 40) - 1;
					if (k < 0)
					{
						k = k + 1;
					}
					{
						black[k][1] = true;
						drawRectangle(105, (k * 40) + 25, 210, (k * 40) + 65, 0, 0, 0, 0, 0, 0);
						score = score + 50;
					}
				}
				if (e[1] == 314)
				{
					t[0] = t[0] * -1; t[1] = t[1] * -1;
					k = ((e[2] + 10) / 40) - 1;
					if (k < 0)
					{
						k = k + 1;
					}
					{
						black[k][3] = true;
						drawRectangle(315, (k * 40) + 25, 420, (k * 40) + 65, 0, 0, 0, 0, 0, 0);
						score = score + 50;
					}
				}
				t[2] = t[2] * -1;
				t[3] = t[3] * -1;
				k = e[0] / 105;
				if (count[2] == 1)
				{
					drawLine(k * 105, limit[2] - 40, ((k * 105) + 105), limit[2], 0, 0, 0);
				}
				else if (count[2] >= 2)
				{
					black[(limit[2] / 40) - 1][k] = true;
					drawRectangle(k * 105, limit[2] - 40, ((k * 105) + 105), limit[2], 0, 0, 0, 0, 0, 0);
					if (limit[2] > 25)
					{
						limit[2] = limit[2] - 40; score = score + 100;
					}
				}
			}
			if (e[2] <= limit[3] && e[0] >= 315 && e[0] < 420)
			{
				count[3]++;
				if (e[0] == 315)
				{
					t[0] = t[0] * -1; t[1] = t[1] * -1;
					k = ((e[2] + 10) / 40) - 1;
					if (k < 0)
					{
						k = k + 1;
					}
					black[k][2] = true;
					drawRectangle(210, (k * 40) + 25, 315, (k * 40) + 65, 0, 0, 0, 0, 0, 0);
					score = score + 50;
				}
				if (e[1] == 419)
				{
					t[0] = t[0] * -1; t[1] = t[1] * -1;
					k = ((e[2] + 10) / 40) - 1;
					if (k < 0)
					{
						k = k + 1;
					}
					{
						black[k][4] = true; 
						drawRectangle(420, (k * 40) + 25, 525, (k * 40) + 65, 0, 0, 0, 0, 0, 0);
						score = score + 50;
					}
				}
				t[2] = t[2] * -1;
				t[3] = t[3] * -1;
				k = e[0] / 105;
				if (count[3] == 1)
				{
					drawLine(k * 105, limit[3] - 40, ((k * 105) + 105), limit[3], 0, 0, 0);
				}
				else if (count[3] >= 2)
				{
					black[(limit[3] / 40) - 1][k] = true;
					drawRectangle(k * 105, limit[3] - 40, ((k * 105) + 105), limit[3], 0, 0, 0, 0, 0, 0);
					if (limit[3] > 25)
					{
						limit[3] = limit[3] - 40; score = score + 100;
					}
				}
			}
			if (e[2] <= limit[4] && e[0] >= 420 && e[0] < 525)
			{
				count[4]++;
				if (e[0] == 420)
				{
					t[0] = t[0] * -1; t[1] = t[1] * -1;
					k = ((e[2] + 10) / 40) - 1;
					if (k < 0)
					{
						k = k + 1;
					}
					{
						black[k][3] = true;
						drawRectangle(315, (k * 40) + 25, 420, (k * 40) + 65, 0, 0, 0, 0, 0, 0);
						score = score + 50;
					}
				}
				if (e[1] == 524)
				{
					t[0] = t[0] * -1; t[1] = t[1] * -1;
					k = ((e[2] + 10) / 40) - 1;
					if (k < 0)
					{
						k = k + 1;
					}
					{
						black[k][5] = true;
						drawRectangle(525, (k * 40) + 25, 630, (k * 40) + 65, 0, 0, 0, 0, 0, 0);
						score = score + 50;
					}
				}
				t[2] = t[2] * -1;
				t[3] = t[3] * -1;
				k = e[0] / 105;
				if (count[4] == 1)
				{
					drawLine(k * 105, limit[4] - 40, ((k * 105) + 105), limit[4], 0, 0, 0);
				}
				else if (count[4] >= 2)
				{
					black[(limit[4] / 40) - 1][k] = true;
					drawRectangle(k * 105, limit[4] - 40, ((k * 105) + 105), limit[4], 0, 0, 0, 0, 0, 0);

					if (limit[4] > 25)
					{
						limit[4] = limit[4] - 40; score = score + 100;
					}
				}
			}
			if (e[2] <= limit[5] && e[0] >= 525 && e[0] < 630)
			{
				count[5]++;
				if (e[0] == 525)
				{
					t[0] = t[0] * -1; t[1] = t[1] * -1;
					k = ((e[2] + 10) / 40) - 1;
					if (k < 0)
					{
						k = k + 1;
					}
					{
						black[k][4] = true;
						drawRectangle(420, (k * 40) + 25, 525, (k * 40) + 65, 0, 0, 0, 0, 0, 0);
						score = score + 50;
					}
				}
				if (e[1] == 629)
				{
					t[0] = t[0] * -1; t[1] = t[1] * -1;
					k = ((e[2] + 10) / 40) - 1;
					if (k < 0)
					{
						k = k + 1;
					}
					{
						black[k][6] = true;
						drawRectangle(630, (k * 40) + 25, 735, (k * 40) + 65, 0, 0, 0, 0, 0, 0);
						score = score + 50;
					}
				}
				t[2] = t[2] * -1;
				t[3] = t[3] * -1;
				k = e[0] / 105;
				if (count[5] == 1)
				{
					drawLine(k * 105, limit[5] - 40, ((k * 105) + 105), limit[5], 0, 0, 0);
				}
				else if (count[5] >= 2)
				{
					black[(limit[5] / 40) - 1][k] = true;
					drawRectangle(k * 105, limit[5] - 40, ((k * 105) + 105), limit[5], 0, 0, 0, 0, 0, 0);

					if (limit[5] > 25)
					{
						limit[5] = limit[5] - 40; score = score + 100;
					}
				}
			}
			if (e[2] <= limit[6] && e[0] >= 630 && e[0] < 735)
			{
				count[6]++;
				if (e[0] == 630)
				{
					t[0] = t[0] * -1; t[1] = t[1] * -1;
					k = ((e[2] + 10) / 40) - 1;
					if (k < 0)
					{
						k = k + 1;
					}
					{
						black[k][5] = true;
						drawRectangle(525, (k * 40) + 25, 630, (k * 40) + 65, 0, 0, 0, 0, 0, 0);
						score = score + 50;
					}
				}
				if (e[1] == 734)
				{
					t[0] = t[0] * -1; t[1] = t[1] * -1;
					k = ((e[2] + 10) / 40) - 1;
					if (k < 0)
					{
						k = k + 1;
					}
					{
						black[k][7] = true;
						drawRectangle(735, (k * 40) + 25, 840, (k * 40) + 65, 0, 0, 0, 0, 0, 0);
						score = score + 50;
					}
				}
				t[2] = t[2] * -1;
				t[3] = t[3] * -1;
				k = e[0] / 105;
				if (count[6] == 1)
				{
					drawLine(k * 105, limit[6] - 40, ((k * 105) + 105), limit[6], 0, 0, 0);
				}
				else if (count[6] >= 2)
				{
					black[(limit[6] / 40) - 1][k] = true;
					drawRectangle(k * 105, limit[6] - 40, ((k * 105) + 105), limit[6], 0, 0, 0, 0, 0, 0);

					if (limit[6] > 25)
					{
						limit[6] = limit[6] - 40; score = score + 100;
					}
				}
			}
			if (e[2] <= limit[7] && e[0] >= 735 && e[0] < 840)
			{
				count[7]++;
				if (e[0] == 735)
				{
					t[0] = t[0] * -1; t[1] = t[1] * -1;
					k = ((e[2] + 10) / 40) - 1;
					if (k < 0)
					{
						k = k + 1;
					}
					{
						black[k][6] = true;
						drawRectangle(630, (k * 40) + 25, 735, (k * 40) + 65, 0, 0, 0, 0, 0, 0);
						score = score + 50;
					}
				}
				if (e[1] == 839)
				{
					t[0] = t[0] * -1; t[1] = t[1] * -1;
					k = ((e[2] + 10) / 40) - 1;
					if (k < 0)
					{
						k = k + 1;
					}
					{
						black[k][8] = true;
						drawRectangle(840, (k * 40) + 25, 945, (k * 40) + 65, 0, 0, 0, 0, 0, 0);
						score = score + 50;
					}
				}
				t[2] = t[2] * -1;
				t[3] = t[3] * -1;
				k = e[0] / 105;
				if (count[7] == 1)
				{
					drawLine(k * 105, limit[7] - 40, ((k * 105) + 105), limit[7], 0, 0, 0);
				}
				else if (count[7] >= 2)
				{
					black[(limit[7] / 40) - 1][k] = true;
					drawRectangle(k * 105, limit[7] - 40, ((k * 105) + 105), limit[7], 0, 0, 0, 0, 0, 0);

					if (limit[7] > 25)
					{
						limit[7] = limit[7] - 40; score = score + 100;
					}
				}
			}
			if (e[2] <= limit[8] && e[0] >= 840 && e[0] < 945)
			{
				count[8]++;
				if (e[0] == 840)
				{
					t[0] = t[0] * -1; t[1] = t[1] * -1;
					k = ((e[2] + 10) / 40) - 1;
					if (k < 0)
					{
						k = k + 1;
					}
					{
						black[k][7] = true;
						drawRectangle(735, (k * 40) + 25, 840, (k * 40) + 65, 0, 0, 0, 0, 0, 0);
						score = score + 50;
					}
				}
				if (e[1] == 944)
				{
					t[0] = t[0] * -1; t[1] = t[1] * -1;
					k = ((e[2] + 10) / 40) - 1;
					if (k < 0)
					{
						k = k + 1;
					}
					{
						black[k][9] = true;
						drawRectangle(945, (k * 40) + 25, 1050, (k * 40) + 65, 0, 0, 0, 0, 0, 0);
						score = score + 50;
					}
				}
				t[2] = t[2] * -1;
				t[3] = t[3] * -1;
				k = e[0] / 105;
				if (count[8] == 1)
				{
					drawLine(k * 105, limit[8] - 40, ((k * 105) + 105), limit[8], 0, 0, 0);
				}
				else if (count[8] >= 2)
				{
					black[(limit[8] / 40) - 1][k] = true;
					drawRectangle(k * 105, limit[8] - 40, ((k * 105) + 105), limit[8], 0, 0, 0, 0, 0, 0);

					if (limit[8] > 25)
					{
						limit[8] = limit[8] - 40; score = score + 100;
					}
				}
			}
			if (e[2] <= limit[9] && e[0] >= 945 && e[0] < 1050)
			{
				count[9]++;
				if (e[0] == 945)
				{
					t[0] = t[0] * -1; t[1] = t[1] * -1;
					k = ((e[2] + 10) / 40) - 1;
					if (k < 0)
					{
						k = k + 1;
					}
					{
						black[k][8] = true;
						drawRectangle(840, (k * 40) + 25, 945, (k * 40) + 65, 0, 0, 0, 0, 0, 0);
						score = score + 50;
					}
				}
				t[2] = t[2] * -1;
				t[3] = t[3] * -1;
				k = e[0] / 105;
				if (count[9] == 1)
				{
					drawLine(k * 105, limit[9] - 40, ((k * 105) + 105), limit[9], 0, 0, 0);
				}
				else if (count[9] >= 2)
				{
					black[(limit[9] / 40) - 1][k] = true;
					drawRectangle(k * 105, limit[9] - 40, ((k * 105) + 105), limit[9], 0, 0, 0, 0, 0, 0);

					if (limit[9] > 25)
					{
						limit[9] = limit[9] - 40; score = score + 100;
					}
				}
			}
			if (e[3] >= a)               //when ball reaches the bat level
			{
				if (e[1] >= bar1 && e[0] <= bar2)
				{
					t[2] = t[2] * -1;                     //checking if ball lands on bat
					t[3] = t[3] * -1;
					if (e[0] > (bar1 + 80) && e[1] < (bar2 - 80))
					{
						t[0] = 0; t[1] = 0;                           
					}
					else if (e[1] > (bar2 - 80))
					{
						if (t[0] == 0)
						{
							t[0] = 2.5, t[1] = 2.5;
						}
						if (t[0] < 0)
						{
							t[0] = t[0] * -1; t[1] = t[1] * -1;
						}
					}
					else if (e[0] < (bar1 + 80))
					{
						if (t[0] == 0)
						{
							t[0] = 2.5, t[1] = 2.5;
						}
						if (t[0] > 0)
						{
							t[0] = t[0] * -1; t[1] = t[1] * -1;
						}
					}
				}
				else
				{
					life--;
					if (life > 0)                          //when ball does not hit bat and goes down than one life gone 
					{
						drawRectangle(bar1, a, bar2, b, 0, 0, 0, 0, 0, 0);
						drawEllipse(e[0], e[2], e[1], e[3], 0, 0, 0, 0, 0, 0); a = 565, b = 570;
						drawRectangle(bar1, a, bar2, b, 0, 0, 0, 0, 0, 0);
						bar1 = 475, bar2 = 675;
						delay(1500);
						t[0] = 0; t[1] = 0; t[2] = 6; t[3] = 6;
						e[0] = 573; e[1] = 585; e[2] = 363; e[3] = 376;
					}
					else
					{
						cls();
						break;
					}
				}
			}
		}
	}
	if (choice == 3) {
		cls();
	}
	cout << endl;
	cout << "                                                      ***************     " << endl;
	cout << "                                                      * Game        *     " << endl;
	cout << "                                                      *       Over  *     " << endl;
	cout << "                                                      ***************     " << endl; cout << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << endl;
	}
	cout << " Total Score  =  " << score;
	for (int i = 0; i < 5; i++)
	{
		cout << endl;
	}
	ifstream myfile("highscore.txt");                           //reading previous highscores
	int temp; highscore[5]; int t1;
	for (int i = 0; i < 5; i++)
	{
		myfile >> highscore[i];
	}
	if (myfile)
	{
		for (int i = 0; i < 5; i++)
		{
			if (score > highscore[i])
			{
				temp = highscore[i];
				highscore[i] = score;
				break;
			}
		}
		for (int i = 0; i < 5 - 1; i++)
		{
			for (int j = 0; j < 5 - 1 - i; j++)
			{
				if (highscore[j] < highscore[j + 1])         //sorting previous highscores and current score
				{
					t1 = highscore[j];
					highscore[j] = highscore[j + 1];
					highscore[j + 1] = t1;
				}
			}
		}
		for (int i = 0; i < 5; i++)
		{
			myfile >> highscore[i];
		}
		ofstream myfile("highscore.txt");
		for (int i = 0; i < 5; i++)
		{
			myfile << highscore[i] << endl;                    //writing highscore in file
		}
		cout << " Highscore : ";
		for (int i = 0; i < 5; i++)
		{
			cout << highscore[i] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < 5; i++)
	{
		cout << endl;
	}
	cout << endl;
	cout << "                                                      ***************     " << endl;
	cout << "                                                      * Thank       *     " << endl;
	cout << "                                                      *       You   *     " << endl;
	cout << "                                                      ***************     " << endl; cout << endl;
	system("pause");
	return 0;
	// End of Game
	// THank you
}