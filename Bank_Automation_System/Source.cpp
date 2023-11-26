#include<iostream>
#include<string>
using namespace std;
int c = 0;
int d = 0;
int f = 0;
int T = 0;
int size1;
class Bank
{
private:
	string CID;
	int TNO;
public:
	Bank()
	{
		TNO = T++;
	}
	void Enqueue()
	{
		if (c == d && f == 1)
		{
			cout << "Full" << endl;
		}
		else
		{
			cout << "Enter Customer ID" << endl;
			cin >> CID;
			c++;
			if (c == size1)
			{
				c = 0;
				f = 1;
			}
		}

	}
	void Dequeue(Bank* b)
	{
		if (c == 0 && d == 0 && f == 0)
		{
			cout << "Empty" << endl;
		}
		else
		{
			cout << b[d].TNO << "Is Deleted" << endl;
			cout << "Next is " << b[d + 1].TNO << endl;
			d++;
			if (d == size1)
			{
				f = 0;
				d = 0;
			}
		}
	}
	void Display(Bank* b)
	{
		if (c == 0 && f == 0)
		{
			cout << "Empty" << endl;
		}
		else if (f == 0)
		{
			for (int i = 0; i < c; i++)
			{
				cout << "Token No is " << b[i].TNO << endl;
				cout << "Customer ID is " << b[i].CID << endl;
			}
		}
		else
		{
			for (int t = d; t < size1; t++)
			{
				cout << "Token No is " << b[t].TNO << endl;
				cout << "Customer ID is " << b[t].CID << endl;
			}
			for (int f = 0; f < c; f++)
			{
				cout << "Token No is " << b[f].TNO << endl;
				cout << "Customer ID is " << b[f].CID << endl;
			}
		}

	}
};
void main()
{

	cout << "Enter Size" << endl;
	cin >> size1;
	Bank* bank = new Bank[size1];
	int in;

	do
	{
		cout << "1 for Enqueue\n2 for Dequeue\n3 for Display\n4 for Exit" << endl;
		cin >> in;
		switch (in)
		{
		case 1:
			int in2;
			cout << "1 for Withdraw\n2 for Deposite" << endl;
			cin >> in2;
			if (in2 == 1 || in2 == 2)
			{
				bank[c++].Enqueue();
			}
			break;
		case 2:
			bank[0].Dequeue(bank);
			break;
		case 3:
			bank[0].Display(bank);
			break;
		case 4:
			cout << "The End" << endl;
			break;
		}

	} while (in != 4);





	system("pause");
}