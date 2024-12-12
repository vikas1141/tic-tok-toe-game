#include<iostream>
using namespace std;

char num[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
string  n1;
string  n2;
int digit ;
int t='X';
int row ;
int column;
bool tie=false;


void func1()

{
	
	cout <<"\n  "<<num[0][0]<<"  |  "<<num[0][1]<<"  |  "<<num[0][2]<<endl;
	cout <<"_____|_____|_____"<<endl;
	cout << "  "<<num[1][0]<<"  |  "<<num[1][1]<<"  |  "<<num[1][2]<<endl;
	cout <<"_____|_____|_____"<<endl;
	cout << "  "<<num[2][0]<<"  |  "<<num[2][1]<<"  |  "<<num[2][2]<<endl;
	

}
void func2()
{
	if(t=='X')
	{
		cout <<n1<< " Please enter ";
		cin >> digit;
	}
	else if(t=='O')
	{
		cout <<n2<< " Please enter ";
		cin >> digit;
	}
	switch(digit)
	{
		case 1: row=0,column=0;
		break;
		case 2: row=0,column=1;
		break;
		case 3: row=0,column=2;
		break;
		case 4: row=1,column=0;
		break;
		case 5: row=1,column=1;
		break;
		case 6: row=1,column=2;
		break;
		case 7: row=2,column=0;
		break;
		case 8: row=2,column=1;
		break;
		case 9: row=2,column=2;
		break;
		default: 
		cout << "invalid!!!\n";
		func2();
		break;
		
	}
	if(t =='X'&& num[row][column]!='X'&& num[row][column]!='O')	
	{
		num[row][column]='X';
		t='O';
	}
	if(t =='O'&& num[row][column]!='X'&& num[row][column]!='O')	
	{
		num[row][column]='O';
		t='X';
	}
}
bool func3()
{
	for(int i=0;i<3;i++)
	{
		if(num[i][0]==num[i][1]&&num[i][0]==num[i][2])
		{
			return true ;
		}
	}
	if (num[0][0]==num[1][1]&&num[0][0]==num[2][2])
	{
		return true;
	}
	if (num[0][2]==num[1][1]&&num[0][2]==num[2][0])
	{
		return true;
	}
	for(int i=0;i<3;i++)
	{
		for (int j=0;j<3;j++)
		{
			if(num[i][j] !='X'&&num[i][j]!='O')
			{
				return false;
			}
			
		}
	}
	
	tie = true ;
	return true;
	
}
int main()
{
	cout <<"enter the name of first player\n";
	getline(cin , n1);
	cout<< "enter the name of second player\n";
	getline(cin , n2);
	
	cout <<n1 <<" will play as first player symbol is X\n";
	cout <<n2 <<" will play as second player symbol is O\n";
	while(!func3())
	{
		func1();
		func2();
		func3();
	};
	
	if(t=='O'&&tie == false)
	{
		cout<< n1<<" is winner";
	}
	if(t=='X'&&tie == false)
	{
		cout<< n2<<" is winner";
	}
	if(tie == true )
	{
		cout << "It's a  draw ";
	}
	
	
}