#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int total_books = 0, free_time = 0, temp_sum = 0, erase_index = 0, sum = 0;
    cin >> total_books;
    int time_book[total_books];
    cin >> free_time;
    int time_remain = free_time;
    for (int i = 0; i < total_books; i++)
    {
        cin >> time_book[i];
    }
    for (int i = 0; i < total_books; i++)
    {
           
        if (time_book[i] >= free_time)
        {
                time_remain = free_time;
                erase_index = i + 1;
                temp_sum = 0;
        }
        else if(time_book[i] > time_remain){
            time_remain = free_time -(free_time - time_remain + time_book[i] - time_book[erase_index]);            
            erase_index++;
            temp_sum = sum;
        }
        else if(time_book[i] <= time_remain)
        {
            time_remain = time_remain - time_book[i];
            temp_sum++;
        }
        if (sum < temp_sum)
        {
            sum = temp_sum;
        }
    }
    cout << sum << endl;
    return 0;
}