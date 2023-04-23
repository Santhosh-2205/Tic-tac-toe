//JGD

#include<iostream>

class tic_tac_toe
{
    private:
        char board[3][3];
        int turn;
        char computer;
        char user;
        int win;
        int row_win(char c);
        int col_win(char c);
        int diag_win(char c);
        int nxt_row_win(char c);
        int nxt_col_win(char c);
        int nxt_diag_win(char c);
    public:
        tic_tac_toe(int use);
        int check_win(char c);
        void user_move();
        void computer_move();
        void print_board();
        void start_game();
};

tic_tac_toe::tic_tac_toe(int use)
{
    turn = 0;
    win = 0;

    if(use == 1)
    {
        user = 'X';
        computer = 'O';
    }
    else
    {
        user = 'O';
        computer = 'X';
    }

    for(int i = 0 ; i < 3 ; i++)
        for(int j = 0 ; j < 3 ; j++)
            board[i][j] = ' ';
}

void tic_tac_toe::user_move()
{
    if(check_win(computer))
    {
        std::cout<<"Computer win!"<<"\n";
        win = 1;
        return;
    }
    int x;
    std::cout<<"Enter the box number of your move: (1-9) ";
    std::cin>>x;
    x--;
    board[x/3][x%3] = user;
    turn++;
}

void tic_tac_toe::computer_move()
{
    if(check_win(user))
    {
        std::cout<<"You win!"<<"\n";
        win = 1;
        return;
    }
    if(board[1][1] == ' ')
    {
        board[1][1] = computer;
        turn++;
        return;
    }
    int x ;
    x = nxt_row_win(computer);
    if(x != -1)
    {
        board[x/3][x%3] = computer;
        turn++;
        return;
    }
    x = nxt_col_win(computer);
    if(x != -1)
    {
        board[x/3][x%3] = computer;
        turn++;
        return;
    }
    x = nxt_diag_win(computer);
    if(x != -1)
    {
        board[x/3][x%3] = computer;
        turn++;
        return;
    }
    x = nxt_row_win(user);
    if(x != -1)
    {
        board[x/3][x%3] = computer;
        turn++;
        return;
    }
    x = nxt_col_win(user);
    if(x != -1)
    {
        board[x/3][x%3] = computer;
        turn++;
        return;
    }
    x = nxt_diag_win(user);
    if(x != -1)
    {
        board[x/3][x%3] = computer;
        turn++;
        return;
    }
    if(board[0][0] == user && board[2][2] == user)
    {
        if(board[0][2] == ' ')
        {
            board[0][2] = computer;
            turn++;
            return;
        }
        if(board[2][0] == ' ')
        {
            board[2][0] = computer;
            turn++;
            return;
        }
    }
    if(board[0][2] == user && board[2][0] == user)
    {
        if(board[0][0] == ' ')
        {
            board[0][0] = computer;
            turn++;
            return;
        }
        if(board[2][2] == ' ')
        {
            board[2][2] = computer;
            turn++;
            return;
        }
    }
    for(int i = 0 ; i < 9 ; i++)
    {
        if(board[i/3][i%3] == ' ')
        {
            board[i/3][i%3] = computer;
            turn++;
            return;
        }
    }
    return;
}


void tic_tac_toe::print_board()
{
    system("clear");
    std::cout<<"_________________________"<<"\n";
    std::cout<<"|       |       |       |"<<"\n";
    std::cout<<"|   "<<board[0][0]<<"   |   "<<board[0][1]<<"   |   "<<board[0][2]<<"   |"<<"\n";
    std::cout<<"|_______|_______|_______|"<<"\n";
    std::cout<<"|       |       |       |"<<"\n";
    std::cout<<"|   "<<board[1][0]<<"   |   "<<board[1][1]<<"   |   "<<board[1][2]<<"   |"<<"\n";
    std::cout<<"|_______|_______|_______|"<<"\n";
    std::cout<<"|       |       |       |"<<"\n";
    std::cout<<"|   "<<board[2][0]<<"   |   "<<board[2][1]<<"   |   "<<board[2][2]<<"   |"<<"\n";
    std::cout<<"|_______|_______|_______|"<<"\n";
}


int  tic_tac_toe::row_win(char c)
{
    if(board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] != ' ') 
    {
        if(board[0][0] == c)
            return 1;
    }
    if(board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] != ' ') 
    {
        if(board[1][0] == c)
            return 1;
    }
    if(board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] != ' ') 
    {
        if(board[2][0] == 'c')
            return 1;
    }
    return 0;
}

int tic_tac_toe::col_win(char c)
{
    if(board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] != ' ') 
    {
        if(board[0][0] == c)
            return 1;
    }
    if(board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] != ' ') 
    {
        if(board[0][1] == c)
            return 1;
    }
    if(board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] != ' ') 
    {
        if(board[0][2] == c)
            return 1;
    }
    return 0;
}

int tic_tac_toe::diag_win(char c)
{
   if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') 
    {
        if(board[0][0] == c)
            return 1;
    } 
    if(board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != ' ') 
    {
        if(board[0][0] == 'X')
            return 1;
    }
    return 0;
}

int tic_tac_toe::check_win(char c)
{
    return row_win(c) || col_win(c) || diag_win(c);
}

int tic_tac_toe::nxt_row_win(char c)
{
    if(board[0][0] + board[0][1] + board[0][2] == 2*c + ' ')
    {
        if(board[0][0] == ' ')
            return 0;
        if(board[0][1] == ' ')
            return 1;
        if(board[0][2] == ' ')
            return 2;
    }
    if(board[1][0] + board[1][1] + board[1][2] == 2*c + ' ')
    {
        if(board[1][0] == ' ')
            return 3;
        if(board[1][1] == ' ')
            return 4;
        if(board[1][2] == ' ')
            return 5;
    }
    if(board[2][0] + board[2][1] + board[2][2] == 2*c )
    {
        if(board[2][0] == ' ')
            return 6;
        if(board[2][1] == ' ')
            return 7;
        if(board[2][2] == ' ')
            return 8;
    }
    return -1;
}

int tic_tac_toe::nxt_col_win(char c)
{
    if(board[0][0] + board[1][0] + board[2][0] == 2*c + ' ' )
    {
        if(board[0][0] == ' ')
            return 0;
        if(board[1][0] == ' ')
            return 3;
        if(board[2][0] == ' ')
            return 6;
    }
    if(board[0][1] + board[1][1] + board[2][1] == 2*c + ' ')
    {
        if(board[0][1] == ' ')
            return 1;
        if(board[1][1] == ' ')
            return 4;
        if(board[2][1] == ' ')
            return 7;
    }
    if(board[0][2] + board[1][2] + board[2][2] == 2*c + ' ')
    {
        if(board[0][2] == ' ')
            return 2;
        if(board[1][2] == ' ')
            return 5;
        if(board[2][2] == ' ')
            return 8;
    }
    return -1;
}

int tic_tac_toe::nxt_diag_win(char c)
{
    if(board[0][0] + board[1][1] + board[2][2] == 2*c + ' ')
    {
        if(board[0][0] == ' ')
            return 0;
        if(board[1][1] == ' ')
            return 4;
        if(board[2][2] == ' ')
            return 8;
    }
    if(board[2][0] + board[1][1] + board[0][2] == 2*c + ' ')
    {
        if(board[2][0] == ' ')
            return 6;
        if(board[1][1] == ' ')
            return 4;
        if(board[0][2] == ' ')
            return 2;
    }
    return -1;
}

void tic_tac_toe::start_game()
{
    if(user == 'O')
        computer_move();
    while(turn < 9 && win == 0)
    {
        print_board();
        user_move();
        if(win == 1)
            break;
        print_board();
        computer_move();
    }
    if(win == 0)
        std::cout<<"Draw!"<<"\n";
}



