#include <iostream>

char getcum();

int main(int argc, char *argv[])
{
    int cumcount {};

    char answ {};
    while(true)
    {
        answ = getcum();
        if(answ == 'y')
        {
            ++cumcount;
            std::cout << "you came\ncum count: " << cumcount << '\n';
        } else
        {
            std::cout << "you didnt cum\n";
            break;
        }
    }
    
    return 0;
}

char getcum()
{
    char yn { };
    while(yn != 'y' && yn != 'n')
    {
        std::cout << "wanna cum?[y/n]: ";
        std::cin >> yn;
    }

    return yn;
}
