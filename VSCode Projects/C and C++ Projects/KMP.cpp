#include <iostream>
#include <string>
using namespace std;
void Getnext(int next[],string t)
{
   int j=0,k=-1;
   next[0]=-1;
   while(j<t.length()-1)
   {
      if(k == -1 || t[j] == t[k])
      {
         j++;k++;
         next[j] = k;
      }
      else k = next[k];//此语句是这段代码最反人类的地方，如果你一下子就能看懂，那么请允许我称呼你一声大神！
   }
}
int main(){
    string data = "abcabcmn";
    int next[data.length()];
    Getnext(next , data);
    for(int i = 0 ; i < data.length() ; i++){
        cout<<next[i] <<" ";
    }
}