#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct coordinate{
    int x;
    int y;
};
bool option_dec_x(coordinate a, coordinate b){
    return a.x > b.x;
}
bool option_dec_y(coordinate a, coordinate b){
    return a.y > b.y;
}
    vector<coordinate> coordinate(8);
    vector<int> fre_x(1000000);
    vector<int> fre_y(1000000);
int main(int argc, char const *argv[])
{   

    for (size_t i = 0; i < 8; i++)
    {
        cin >> coordinate[i].x;
        fre_x[coordinate[i].x]++;
        cin >> coordinate[i].y;
        fre_y[coordinate[i].y]++;
    }
    sort(coordinate.begin(),coordinate.end(),option_dec_x);
    //cout << endl;
    // for (size_t i = 0; i < 8; i++)
    // {
    //     cout << coordinate[i].x << "," << coordinate[i].y << endl; 
    // }
    //cout << endl << "this X " << fre_x[coordinate[0].x] << fre_x[coordinate[3].x] << fre_x[coordinate[5].x] << endl;
    if (fre_x[coordinate[0].x] != 3 || fre_x[coordinate[3].x] != 2 || fre_x[coordinate[5].x] != 3)
    {
        cout << "ugly";
        return 0;
    }
    sort(coordinate.begin(),coordinate.end(),option_dec_y);
    //cout << endl;
    //cout << endl << "this Y " << fre_y[coordinate[0].y] << fre_y[coordinate[3].y] << fre_y[coordinate[5].y] << endl;
    // for (size_t i = 0; i < 8; i++)
    // {
    //     cout << coordinate[i].x << "," << coordinate[i].y << endl; 
    // }
    if (fre_y[coordinate[0].y] != 3 || fre_y[coordinate[3].y] != 2 || fre_y[coordinate[5].y] !=3)
    {
        cout << "ugly";
        return 0;
    }
    cout << "respectable";
    
    return 0;
}