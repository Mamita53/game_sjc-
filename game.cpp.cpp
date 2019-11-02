#include<iostream>
using namespace std;

int count = 0;
char pos[9];
void display(int arr[][3],string player1, string player2)
{
    cout<<endl<<endl<<"\t\t\t\t\t....."<<player1<<" V/S "<<player2<<endl;
    cout<<endl;
    cout<<"\t\t\t\t "<<player1<<" your symbol is P and "<<player2<<" your symbol is X"<<endl<<endl;
    cout<<"\t\t\t\t\t\t ___ ___ ___"<<endl;
    for(int i = 0; i < 3; i++)
    {
        cout<<"\t\t\t\t\t\t|";
        for(int j = 0; j < 3; j++)
        {
            if(arr[i][j] == 80 || arr[i][j] == 88)
                cout<<" "<<char(arr[i][j])<<" |";
            else
                cout<<" "<<arr[i][j]<<" |";
        }
        cout<<endl<<"\t\t\t\t\t\t|___|___|___|"<<endl;
    }
}
void choose_position(int arr[][3], string name,char ch)
{
    int num;
    while(1)
    {
        int flag = 0;
        cout<<"\n\n\t\t\t\t"<<name<<" player turn:  ";
        cin>>num;
        for(int i = 0 ; i < 9; i++)
            if(pos[i] == num){
                flag = 1;
                break;
            }
        if(num<1 || num>9)
            cout<<"\n\t\t\t\tThis position is out of given range. Try again:"<<endl;
        else if(flag)
        {
            cout<<"\n\t\t\t\t This position is already reserve please choose another position...."<<endl;
        }
        else{
            for(int i = 0; i < 3; i++)
                for(int j = 0; j < 3; j++)
                    if(arr[i][j] == num)
                        arr[i][j] = int(ch);
            break;
        }
    }
    pos[count++] = num;
}
void annoucement(int num,string player1,string player2)
{
	if(char(num) == 'P')
				cout<<"\n\n\t\t\t\t"<<player1<<" congratulation you are winner....."<<endl;
			else
				cout<<"\n\n\t\t\t\t"<<player2<<" congratulation you are winner....."<<endl;
}
int determine(int x, int y, int z){
	if( (x==y) && (x == z))
		return x;
	else
		return 0;

}
int check(int arr[][3],string player1, string player2){
	/*int first_row[3], first_col[3];
	int second_row[3], second_col[3];*/
	int test;
	int flag = 0;
	int count_row1 =0, count_row2 = 0;
	for(int i = 0; i < 3; i++){
		test = determine(arr[i][0],arr[i][1],arr[i][2]);//for row check
		if(test){
			annoucement(test, player1, player2);
			flag = 1;
			break;
		}
		test = determine(arr[0][i],arr[1][i],arr[2][i]);//for row check
		if(test){
			annoucement(test, player1, player2);
			flag = 1;
			break;
		}
	}
	if(flag)
		cout<<"\n\t\t\t\tThank for playing this game."<<endl;
	else{
		test = determine(arr[0][0],arr[1][1],arr[2][2]);//for row check
		if(test){
			annoucement(test, player1, player2);
			flag = 1;
		}
		else
		{
			test = determine(arr[0][2],arr[1][1],arr[2][0]);
			if(test){
				annoucement(test,player1,player2);
				flag = 1;
			}
		}
	}
	return flag;
}

int main()
{
    int arr[3][3] = {1,2,3,4,5,6,7,8,9};
    int n = 9;
    int flag = 1, test = 1;
    string player1, player2;
    cout<<endl<<endl<<"\t\t\t\t**************  Tik Tac Toe Game.   ***********"<<endl<<endl;
    cout<<"\n\n\t\t\t\t Enter first player name:  ";
    cin>>player1;
    cout<<"\n\t\t\t\t Enter second player name:   ";
    cin>>player2;
    while(n)
    {
        display(arr,player1, player2);
        if(n <= 4){
        	if(check(arr,player1,player2))
        	{
        		test = 0;
        		break;
        	}
        }
        cout<<"\n\t\t\t\tEnter given number in given range 0 to 9"<<endl;
        if(flag){
            choose_position(arr, player1, 'P');
            flag = 0;
        }
        else{
            choose_position(arr, player2, 'X');
            flag = 1;
        }
        system("cls");
        n--;
    }
    display(arr,player1, player2);
    if(test)
    	cout<<"\n\n\t\t\t\tGame over.."<<endl;
    return 0;
}

