#include <iostream>
#include <string>     //header file for string (optional).
#include <algorithm>  //Header file for reverse fn.
using namespace std;
int main(){
string str = "Hello, How are you?"; //Eg String
reverse(str.begin(),str.end());     //In built fn.
cout<<"Reversed string is : "<<str<<endl; //Print
return 0;
}