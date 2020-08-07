#include <iostream>

using namespace std;
bool Solve(int Number)
{
	bool Status = false;
	int LuckyNumbers[50];
	int Count = 0, Digit = 0, Case = 0, Temp = 0;
	for (int i = 1; i < 1000; i++)
	{
		Temp = i;
		Case = 0; Digit = 0;
		while (Temp != 0)
		{
			if (Temp % 10 == 4 || Temp % 10 == 7)
			{
				Case++;
			}
			Temp = Temp / 10;
			Digit++;
		}
		if (Case == Digit)
		{
			LuckyNumbers[Count] = i;
			Count++;
		}
	}
	for (int i = 0; i < Count; i++)
	{
		if (Number % LuckyNumbers[i] == 0)
		{
			Status = true;
		}
	}
	return Status;
}
int main(){
	int Num;
	cin >> Num;
	if (Solve(Num))
	{
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;
	return 0;
}
