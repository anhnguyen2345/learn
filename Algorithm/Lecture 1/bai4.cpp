#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    string S_string,T_string, output_string, temp;
    int cnt = 0;
    cin >> S_string;
    cin >> T_string;
    int len = S_string.size();
    for(int i = 0; i < S_string.size(); i++){
        if((T_string[i] - S_string[i]) >= 1){
            cnt++;
        }
        // else if((T_string[i] - S_string[i]) < 0){
        //     cout << "No such string";
        //     return 0;
        // }
    }
    if(cnt >= 1){
        if((T_string[len -1] - S_string[len - 1]) == 1 && cnt == 1){
           cout << "No such string"; 
        }
        else{
            temp = (char)(S_string[len-1]+1);
            output_string = S_string.replace(S_string.size()-1,1,temp);
            cout << output_string;            
        }         
    }
    else
    {
        cout << "No such string";
    }
    return 0;
}
