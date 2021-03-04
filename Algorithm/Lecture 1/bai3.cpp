#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int min_old = 0;
    int interesting_times = 0;
    int get_min = 0;
    int total_min = 0;
    cin >> interesting_times;
    for (int i = 0; i < interesting_times; i++)
    {
        cin >> get_min;
        if((get_min-min_old) > 15){
            total_min = min_old + 15;
            break;
        }
        else{
            total_min = get_min + 15;
        }
        min_old = get_min;
    }
    if(total_min >= 90){
        total_min = 90;
    }
    cout << total_min;
    return 0;
}
