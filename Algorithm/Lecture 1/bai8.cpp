#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
   string S_string,T_string;
   cin >> S_string ;
   cin >> T_string;
   int cnt = 0, step = 0, cleared = 0;
   string tempS = S_string;
   string tempT = T_string;
   for (int i = 0; i < S_string.size(); i++)
   {
      if(S_string[i] == T_string[0]){
         tempS.replace(i,T_string.size(),T_string);
         if(tempS == S_string){
            cout << "automaton";
            return 0;
         }
       }
      for (size_t j = 0; j < tempT.size(); j++)
      {
         if(S_string[i] == tempT[j]){
            cnt++;
            tempT = tempT.erase(j,1);
            cout << tempT << endl;
         }
      }
   }
   if (cnt < T_string.size())
   {
      cout << "need tree";
   }
   else if(S_string.size() == T_string.size()){
      cout << "array";
   }
   else
   {
      cout << "both";
   }
   return 0;
}