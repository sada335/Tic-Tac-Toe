#include<iostream>
using namespace std;

char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn='X';
int i,j,row,col,choice;
bool draw=false;

void display_board()
{
    system("cls");

    cout<<" T.I.C...T.A.C...T.O.E...G.A.M.E.\n";
    cout<<"  Player1 : [X]\n  Player2 : [0]\n";

    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |   "<<board[0][2]<<" \n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |   "<<board[1][2]<<" \n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
     cout<<"\t\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |   "<<board[2][2]<<" \n";
    cout<<"\t\t     |     |     \n";
    cout<<"\n";

}

void player_turn()
{
    if(turn=='X') {cout<<"Player1 [X] turn: ";}
    else         {cout<<"Player2 [0] turn: ";}

    cin>>choice;

    switch(choice)
    {
        case 1: row=0; col=0;   break;
        case 2: row=0; col=1;   break;
        case 3: row=0; col=2;   break;
        case 4: row=1; col=0;   break;
        case 5: row=1; col=1;   break;
        case 6: row=1; col=2;   break;
        case 7: row=2; col=0;   break;
        case 8: row=2; col=1;   break;
        case 9: row=2; col=2;   break;

    }

    if(turn=='X' && board[row][col]!='X' && board[row][col]!='0' )
    {
        board[row][col]='X';
        turn='0';
    }
    else if (turn=='0' && board[row][col]!='X' && board[row][col]!='0')
    {
        board[row][col]='0';
        turn='X';
    }
    else
    {
        cout<<"\t\t BOX alreday filled !\n\t\t  Please try again!!!\n\n";
        player_turn();
    }

     display_board();
}

bool gameover()
{
    //Win
    for(i=0;i<3;i++)
    {
        if((board[i][0]==board[i][1] && board[i][0]==board[i][2] ) || (board[0][i]==board[1][i] && board[0][i]==board[2][i]))
            return false;
    }
    if((board[0][0]==board[1][1] && board[0][0]==board[2][2]) || (board[0][2]==board[1][1] && board[0][2]==board[2][0]))
           return false;

    //playing game

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(board[i][j] !='X' && board[i][j]!='0')
                return true;
        }
    }

    //draw
    draw=true;
    return false;
}

int main()
{
    while(gameover())
    {
        display_board();
        player_turn();
        gameover();
    }

    if(turn=='X' && draw==false)
        cout<<" Player2 [0] WINS !!! Congratulation!\n\n";
    else if(turn=='0' && draw==false)
         cout<<" Player1 [X] WINS !!! Congratulation!\n\n";
    else
        cout<<" GAME DRAW !!!\n\n";


    return 0;
}
