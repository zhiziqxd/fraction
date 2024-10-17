#include "fraction.hpp"
using namespace std;
int main(){
    fraction a;
    a.de=2;
    a.mol=1;
    cout<<a.check()<<endl;
    fraction b;
    b.de=4;
    b.mol=1;
    a=fra_count(a,b,1);
    cout<<a.de<<" "<<a.mol<<endl;
    a.sim();
    cout<<a.de<<" "<<a.mol<<endl;
    return 0;
}
