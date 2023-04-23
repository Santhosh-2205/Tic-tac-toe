#include"ttt.hpp"

int main()
{
    std::cout<<"Do you play 1st move  or 2nd move : ";
    int x;
    std::cin>>x;
    if(x != 1 && x != 2)
    {
        std::cout<<"Do you play 1st move  or 2nd move\n";
        std::cout<<"Please enter 1 if you want to play 1st move, else enter 2 : ";
        std::cin>>x;
    }
    if(x != 1 && x != 2)
    {
        std::cout<<"Go to hell!!\n";
        return 0;
    }
    tic_tac_toe game(x);
    game.start_game();
}