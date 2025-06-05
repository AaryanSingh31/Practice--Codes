#include <iostream>
#include <string>
using namespace std;
string removeOccurence(string s, string part){

 //find() -> Inbuilt c++ fn to find the starting index of part inside the s string.
while(s.length()>0 && s.find(part)<s.length()){  
    

 //erase() ->Inbuilt c++ fn to erase the elements |from| starting index of part (inside s string) |till| length of part string.
    s.erase(s.find(part), part.length());        
   }
 // Return the remaining string s.
    return s;
}

int main(){
string s = "daabcbaabcbc";
cout<<"Original String : "<<s<<endl;
string part = "abc";
cout<<"Part to be removed : "<<part<<endl;
cout<<"Remaining string : ";
cout<<removeOccurence(s,part); // output -> dab

    return 0;
}
// Dry run:-
// daabcbaabcbc -> dabaabcbc -> dababc -> dab