#include <iostream>
#include <sys/time.h>

int getcum(int min, int max);
long long getMillisecond();

int main(int argc, char *argv[])
{
    std::cout << std::fixed;
    std::cout << "0: cum\n1: upgrade autocum\n2: dont cum\n3: exit game\n";

    long long prevTime { };
    long long currentTime { getMillisecond() };
    double deltaTime { };

    float cumcount {};
    int autocumCount {};
    float autoCost { 1 };

    int answ {};
    while(true)
    {
        prevTime = currentTime;
        currentTime = getMillisecond();
        deltaTime = currentTime - prevTime;

        cumcount += (autocumCount * deltaTime) / 10000;

        answ = getcum(0, 3);
        switch(answ)
        {
            case 0:
                std::cout << "you came\n";
                ++cumcount;
                std::cout << "cumcount: " << cumcount << '\n';
                break;
            case 1:
                if(cumcount >= autoCost)
                {
                    ++autocumCount;
                    cumcount -= autoCost;
                    std::cout << "autocum: " << autocumCount << '\n';
                } else
                    std::cout << "you are too poor\n";
                break;
            case 2:
                std::cout << "you didnt cum\n";
                break;
            case 3:
                std::cout << "you stopped playing :(\n";
                return 0;
            default:
                std::cout << "ERROR: answ " << answ << "is invalid\n";
                break;
        }

        std::cout << "cumcount: " << cumcount << '\n';
    }

    
    return 0;
}

int getcum(int min, int max)
{
    while(true)
    {
        int temp { };

        std::cout << "selection[" << min << "-" << max << "]: ";
        std::cin >> temp;
        if(temp <= max && temp >= min)
            return temp;
    }
}

long long getMillisecond()
{
    struct timeval te; 
    gettimeofday(&te, NULL); // get current time
    long long milliseconds = te.tv_sec*1000LL + te.tv_usec/1000; // calculate milliseconds

    return milliseconds;
}
