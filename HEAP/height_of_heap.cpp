//Height of heap is log2(N) where N is the no of nodes and 2 is log base
#include <iostream>
using namespace std;

int height(int N){
    int h = -1;
    while(N > 0){
        h++;
        N/=2; //half the valuef node after every height reached.
    }
    return h;
}
int main(){
    int N;
    cout<<"Enter the no of nodes in the heap : ";
    cin>>N;
    cout<<"height of heap is "<<height(N)<<endl;
    return 0;
}