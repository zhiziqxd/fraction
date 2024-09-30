#ifndef fraction_H
#define fraction_H
#include <iostream>
#include <cmath>
#include <limits.h>
using namespace std;
struct fraction{
	int de,mol;
    void sim(){
        for(int i=min(de,mol);i>=2;i--){
            while(de%i==0&&mol%i==0){
                de/=i;
                mol/=i;
            }
        }
        return;
    }
    bool check(){
        if(de!=0&&de!=-1&&mol!=-1){
            return true;
        }
        return false;
    }
    void clear(){
        de=0;
        mol=0;
        return;
    }
};
fraction fra_count(fraction a,fraction b,short form){
	fraction ans={1,0};
	switch(form){
		case 1:
		if(a.de==b.de){
			ans.de=a.de;
			ans.mol=a.mol+b.mol;
		}
		else{
			ans.de=a.de*b.de;
			ans.mol=a.mol*b.de+b.mol*a.de;
		}
        break;
		case 2:
		if(a.de==b.de){
			if(a.mol>=b.mol){
				ans.de=a.de;
				ans.mol=a.mol-b.mol;
			}
			else{
                ans.de=-1;
                ans.mol=-1;
				cout<<"error:a is bigger than b";
			}
		}
		else{
			if(a.mol*b.de-b.mol*a.de<0){
				cout<<"error:a is bigger than b";
                ans.de=-1;
                ans.mol=-1;
			}
			else{
				ans.de=a.de*b.de;
				ans.mol=a.de*b.mol-b.de*a.mol;
			}
		}
        break;
		case 3:
		ans.de=a.de*b.de;
        ans.mol=a.mol*b.mol;
        break;
		case 4:
        ans.de=a.de*b.mol;
        ans.mol=a.mol*b.de;
        break;
	}
    return ans;
}
#endif