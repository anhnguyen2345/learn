#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int total_cards = 0;
    cin >> total_cards;
    int arr[total_cards];
    int cnt, sumSereja = 0, sumDima = 0;
    int left = 0, right = total_cards - 1, turnSereja = true;
    for (size_t i = 0; i < total_cards; i++)
    {
        cin >> arr[i];
    }
    while (total_cards)
    {
        if(turnSereja){
            if (arr[left] >= arr[right])
            {
                sumSereja = sumSereja + arr[left];
                left++;
            }
            else{
                sumSereja = sumSereja + arr[right];
                right--;
            }
            turnSereja = false;
        }
        else{
            if (arr[left] >= arr[right])
            {
                sumDima = sumDima + arr[left];
                left++;
            }
            else{
                sumDima = sumDima + arr[right];
                right--;
            }
            turnSereja = true;
        }
        total_cards--;

    }
    cout << sumSereja << " " <<  sumDima;
    return 0;
}