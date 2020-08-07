#include <iostream>
#include <time.h>

using namespace std;
class Game
{
public:

	void MainFunction(char Choice)
	{
		CreateGameBoard();
		if (Choice != 'x' && Choice != 'X')
		{
			srand(time(NULL));
			Human = 'O';
			Computer = 'X';
			cout << "Oyun basladi.Ilk sira bilgisayarin." << endl;
			cout << "Bilgisayarin sirari." << endl;
			Intelligence();
			for (int i = 0; i < 4; i++)
			{		
				Designation();
				if (CheckWinStatus() == 1)
				{
					cout << "Yarisma bitti ! Kazanan oyuncu :" << Winner << endl;
					break;
				}
				cout << "Bilgisayarin sirari." << endl;
				Intelligence();
				if (CheckWinStatus() == 1)
				{
					cout << "Yarisma bitti ! Kazanan oyuncu :" << Winner << endl;
					break;
				}
			}
			if (CheckWinStatus() == 0)
			{
				cout << "Yarisma bitti ! Kazanan yok." << endl;
			}
		}
		else
		{
			Human = 'X';
			Computer = 'O';
			cout << "Oyun basladi.Ilk sira senin." << endl;
			for (int i = 0; i < 5; i++)
			{
				Designation();
				if (CheckWinStatus() == 1)
				{
					cout << "Yarisma bitti ! Kazanan oyuncu :" << Winner << endl;
					break;
				}
				cout << "Bilgisayarin sirari." << endl;
				Intelligence();
				if (CheckWinStatus() == 1)
				{
					cout << "Yarisma bitti ! Kazanan oyuncu :" << Winner << endl;
					break;
				}
			}
			if (CheckWinStatus() == 0)
			{
				cout << "Yarisma bitti ! Kazanan yok." << endl;
			}
		}
	}
private:
	char Board[3][3] = { '.','.', '.', '.', '.', '.', '.', '.', '.' };
	char Human;
	char Computer;
	char Winner;
	void Updater()
	{
		cout << "============================" << endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << " " << Board[i][j];
			}
			cout << endl;
		}
		cout << "============================" << endl;
	}
	void Intelligence()
	{
		//Önce kazanabileceği bir kombinasyon olup olmadığını kontrol ediyor
		if (Probabilitys(Computer, Computer) == 1)
		{
			Updater();
		}
		else
		{
			//Kazanabileceği bir kombinasyon yoksa bu sefer diğer oyuncununun kombinasyonlarını engellemeye çalışıyor.
			if (Probabilitys(Human, Computer) == 1)
			{
				Updater();
			}
			else
			{
				if (Moves() == 1)
				{
					Updater();
				}
				else
				{
					int a = 0;
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							if (Board[i][j] == '.')
							{
								Board[i][j] = Computer; a++;
								break;
							}
						}
						if (a == 1) break;
					}
					Updater();
				}
			}
		}
	}
	int Moves()
	{
		if (Board[0][0] == Human || Board[0][2] == Human || Board[2][0] == Human || Board[2][2] == Human)
		{
			if (Board[1][1] == '.')
			{
				Board[1][1] = Computer;
				return 1;
			}
		}
		else if (Board[0][0] == '.')
		{
			Board[0][0] = Computer;
			return 1;
		}
		else if (Board[0][2] == '.')
		{
			Board[0][2] = Computer;
			return 1;
		}
		else if (Board[2][0] == '.')
		{
			Board[2][0] = Computer;
			return 1;
		}
		else if (Board[2][2] == '.')
		{
			Board[2][2] = Computer;
			return 1;
		}
		else return 0;
	}
	int Probabilitys(char Player, char x)
	{
		//1
		if (Board[0][0] == Board[0][1] && Board[0][2] == '.' && Board[0][0] == Player)
		{
			Board[0][2] = x;
			return 1;
		}
		else if (Board[0][0] == Board[0][2] && Board[0][1] == '.' && Board[0][0] == Player)
		{
			Board[0][1] = x;
			return 1;
		}
		else if (Board[0][0] == Board[1][0] && Board[2][0] == '.' && Board[0][0] == Player)
		{
			Board[2][0] = x;
			return 1;
		}
		else if (Board[0][0] == Board[2][0] && Board[1][0] == '.' && Board[0][0] == Player)
		{
			Board[1][0] = x;
			return 1;
		}
		else if (Board[0][0] == Board[1][1] && Board[2][2] == '.' && Board[0][0] == Player)
		{
			Board[2][2] = x;
			return 1;
		}
		else if (Board[0][0] == Board[2][2] && Board[1][1] == '.' && Board[0][0] == Player)
		{
			Board[1][1] = x;
			return 1;
		}
		//2
		else if (Board[0][1] == Board[0][0] && Board[0][2] == '.' && Board[0][1] == Player)
		{
			Board[0][2] = x;
			return 1;
		}
		else if (Board[0][1] == Board[0][2] && Board[0][0] == '.' && Board[0][1] == Player)
		{
			Board[0][0] = x;
			return 1;
		}
		else if (Board[0][1] == Board[1][1] && Board[2][1] == '.' && Board[0][1] == Player)
		{
			Board[2][1] = x;
			return 1;
		}
		else if (Board[0][1] == Board[2][1] && Board[1][1] == '.' && Board[0][1] == Player)
		{
			Board[1][1] = x;
			return 1;
		}
		//3
		else if (Board[0][2] == Board[0][0] && Board[0][1] == '.' && Board[0][2] == Player)
		{
			Board[0][1] = x;
			return 1;
		}
		else if (Board[0][2] == Board[0][1] && Board[0][0] == '.' && Board[0][2] == Player)
		{
			Board[0][0] = x;
			return 1;
		}
		else if (Board[0][2] == Board[1][2] && Board[2][2] == '.' && Board[0][2] == Player)
		{
			Board[2][2] = x;
			return 1;
		}
		else if (Board[0][2] == Board[2][2] && Board[1][2] == '.' && Board[0][2] == Player)
		{
			Board[1][2] = x;
			return 1;
		}
		else if (Board[0][2] == Board[1][1] && Board[2][0] == '.' && Board[0][2] == Player)
		{
			Board[2][0] = x;
			return 1;
		}
		else if (Board[0][2] == Board[2][0] && Board[1][1] == '.' && Board[0][2] == Player)
		{
			Board[1][1] = x;
			return 1;
		}
		//4
		else if (Board[1][0] == Board[0][0] && Board[2][0] == '.' && Board[1][0] == Player)
		{
			Board[2][0] = x;
			return 1;
		}
		else if (Board[1][0] == Board[2][0] && Board[0][0] == '.' && Board[1][0] == Player)
		{
			Board[0][0] = x;
			return 1;
		}
		else if (Board[1][0] == Board[1][1] && Board[1][2] == '.' && Board[1][0] == Player)
		{
			Board[1][2] = x;
			return 1;
		}
		else if (Board[1][0] == Board[1][2] && Board[1][1] == '.' && Board[1][0] == Player)
		{
			Board[1][1] = x;
			return 1;
		}
		//5
		else if (Board[1][1] == Board[0][1] && Board[2][1] == '.' && Board[1][1] == Player)
		{
			Board[2][1] = x;
			return 1;
		}
		else if (Board[1][1] == Board[2][1] && Board[0][1] == '.' && Board[1][1] == Player)
		{
			Board[0][1] = x;
			return 1;
		}
		else if (Board[1][1] == Board[1][0] && Board[1][2] == '.' && Board[1][1] == Player)
		{
			Board[1][2] = x;
			return 1;
		}
		else if (Board[1][1] == Board[1][2] && Board[1][0] == '.' && Board[1][1] == Player)
		{
			Board[1][0] = x;
			return 1;
		}
		else if (Board[1][1] == Board[0][2] && Board[2][0] == '.' && Board[1][1] == Player)
		{
			Board[2][0] = x;
			return 1;
		}
		else if (Board[1][1] == Board[2][0] && Board[0][2] == '.' && Board[1][1] == Player)
		{
			Board[0][2] = x;
			return 1;
		}
		//6
		else if (Board[1][2] == Board[0][2] && Board[2][2] == '.' && Board[1][2] == Player)
		{
			Board[2][2] = x;
			return 1;
		}
		else if (Board[1][2] == Board[2][2] && Board[0][2] == '.' && Board[1][2] == Player)
		{
			Board[0][2] = x;
			return 1;
		}
		else if (Board[1][2] == Board[1][0] && Board[1][1] == '.' && Board[1][2] == Player)
		{
			Board[1][1] = x;
			return 1;
		}
		else if (Board[1][2] == Board[1][1] && Board[1][0] == '.' && Board[1][2] == Player)
		{
			Board[1][0] = x;
			return 1;
		}
		//7
		else if (Board[2][0] == Board[0][0] && Board[1][0] == '.' && Board[2][0] == Player)
		{
			Board[1][0] = x;
			return 1;
		}
		else if (Board[2][0] == Board[1][0] && Board[0][0] == '.' && Board[2][0] == Player)
		{
			Board[0][0] = x;
			return 1;
		}
		else if (Board[2][0] == Board[2][1] && Board[2][2] == '.' && Board[2][0] == Player)
		{
			Board[2][2] = x;
			return 1;
		}
		else if (Board[2][0] == Board[2][2] && Board[2][1] == '.' && Board[2][0] == Player)
		{
			Board[2][1] = x;
			return 1;
		}
		else if (Board[2][0] == Board[1][1] && Board[0][2] == '.' && Board[2][0] == Player)
		{
			Board[0][2] = x;
			return 1;
		}
		else if (Board[2][0] == Board[0][2] && Board[1][1] == '.' && Board[2][0] == Player)
		{
			Board[1][1] = x;
			return 1;
		}
		//8
		else if (Board[2][1] == Board[0][1] && Board[1][1] == '.' && Board[2][1] == Player)
		{
			Board[1][1] = x;
			return 1;
		}
		else if (Board[2][1] == Board[1][1] && Board[0][1] == '.' && Board[2][1] == Player)
		{
			Board[0][1] = x;
			return 1;
		}
		else if (Board[2][1] == Board[2][0] && Board[2][2] == '.' && Board[2][1] == Player)
		{
			Board[2][2] = x;
			return 1;
		}
		else if (Board[2][1] == Board[2][2] && Board[2][0] == '.' && Board[2][1] == Player)
		{
			Board[2][0] = x;
			return 1;
		}
		//9
		else if (Board[2][2] == Board[0][2] && Board[1][2] == '.' && Board[2][2] == Player)
		{
			Board[1][2] = x;
			return 1;
		}
		else if (Board[2][2] == Board[1][2] && Board[0][2] == '.' && Board[2][2] == Player)
		{
			Board[0][2] = x;
			return 1;
		}
		else if (Board[2][2] == Board[2][0] && Board[2][1] == '.' && Board[2][2] == Player)
		{
			Board[2][1] = x;
			return 1;
		}
		else if (Board[2][2] == Board[2][1] && Board[2][0] == '.' && Board[2][2] == Player)
		{
			Board[2][0] = x;
			return 1;
		}
		else if (Board[2][2] == Board[1][1] && Board[0][0] == '.' && Board[2][2] == Player)
		{
			Board[0][0] = x;
			return 1;
		}
		else if (Board[2][2] == Board[0][0] && Board[1][1] == '.' && Board[2][2] == Player)
		{
			Board[1][1] = x;
			return 1;
		}
		else return 0;
	}
	int CheckWinStatus()
	{
		if (Board[0][0] == Board[1][0] && Board[1][0] == Board[2][0] && Board[0][0] != '.')
		{
			Winner = Board[0][0];
			return 1;
		}
		else if (Board[0][1] == Board[1][1] && Board[1][1] == Board[2][1] && Board[0][1] != '.')
		{
			Winner = Board[0][1];
			return 1;
		}
		else if (Board[0][2] == Board[1][2] && Board[1][2] == Board[2][2] && Board[0][2] != '.')
		{
			Winner = Board[0][2];
			return 1;
		}
		else if (Board[0][0] == Board[0][1] && Board[0][1] == Board[0][2] && Board[0][0] != '.')
		{
			Winner = Board[0][0];
			return 1;
		}
		else if (Board[1][0] == Board[1][1] && Board[1][1] == Board[1][2] && Board[1][0] != '.')
		{
			Winner = Board[1][0];
			return 1;
		}
		else if (Board[2][0] == Board[2][1] && Board[2][1] == Board[2][2] && Board[2][0] != '.')
		{
			Winner = Board[2][0];
			return 1;
		}
		else if (Board[0][0] == Board[1][1] && Board[1][1] == Board[2][2] && Board[0][0] != '.')
		{
			Winner = Board[0][0];
			return 1;
		}
		else if (Board[0][2] == Board[1][1] && Board[1][1] == Board[2][0] && Board[0][2] != '.')
		{
			Winner = Board[0][2];
			return 1;
		}
		else return 0;
	}
	void Designation()
	{
		char loc1;
		int loc2, loc3;
		cout << "Sira sende !" << endl;
	str:

		cout << "Konum giriniz (Örnek : b2):";
		cin >> loc1 >> loc2;
		if (loc1 == 'A' || loc1 == 'a' || loc1 == 'B' || loc1 == 'b' || loc1 == 'C' || loc1 == 'c')
		{
			if (loc2 == 1 || loc2 == 2 || loc2 == 3)
			{
				if (loc1 == 'A' || loc1 == 'a')
				{
					loc3 = 1;
				}
				else if (loc1 == 'B' || loc1 == 'b')
				{
					loc3 = 2;
				}
				else
				{
					loc3 = 3;
				}
				if (Board[loc3 - 1][loc2 - 1] == '.')
				{
					Board[loc3 - 1][loc2 - 1] = Human;
					Updater();
				}
				else
				{
					cout << "Seçilen konum dolu." << endl;
					goto str;
				}

			}
			else
			{
				cout << "Geçersiz konum." << endl;
				goto str;
			}
		}
		else
		{
			cout << "Geçersiz konum." << endl;
			goto str;
		}
	}
	void CreateGameBoard()
	{
		bool Status;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << " " << Board[i][j];
			}
			cout << endl;
		}
		cout << "Seçim formati :" << endl;
		cout << "# 1 2 3" << endl;
		cout << "A\nB\nC" << endl;
	}
};
int main()
{
	setlocale(LC_ALL, "Turkish");
	Game g;
	char ch;
	cout << "---Tic Tac Toe---" << endl;
gt1:
	cout << "Karakter seçiniz (X veya O):";
	cin >> ch;
	if (ch == 'X' || ch == 'x' || ch == 'O' || ch == 'o')
	{
		g.MainFunction(ch);
	}
	else
	{
		cout << "Hatali secim yaptiniz." << endl;
		goto gt1;
	}
	return 0;
}
