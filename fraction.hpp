#ifndef fraction_H
#define fraction_H
#include <iostream>
#include <cmath>
#include <limits.h>
using namespace std;
struct fraction{
	int de,mol;//分母，分子
    void sim(){//约分
        for(int i=min(de,mol);i>=2;i--){
            while(de%i==0&&mol%i==0){
                de/=i;
                mol/=i;
            }
        }
        return;
    }
    bool check(){//检查是否合法
        if(de!=0&&de!=-1&&mol!=-1){
            return true;
        }
        return false;
    }
    void clear(){//清空
        de=0;
        mol=0;
        return;
    }
};
//比较大小
bool fra_big(fraction a,fraction b){
	if(a.mol*b.de>b.mol*a.de){
		return true;
	}
	return false;
}
bool fra_small(fraction a,fraction b){
	if(a.mol*b.de<b.mol*a.de){
		return true;
	}
	return false;
}
bool fra_amount(fraction a,fraction b){
	if(a.mol*b.de==b.mol*a.de){
		return true;
	}
	return false;
}
fraction fra_count(fraction a,fraction b,short form){//计算
	fraction ans={1,0};
	switch(form){
		case 1://加法
		if(a.de==b.de){
			ans.de=a.de;
			ans.mol=a.mol+b.mol;
		}
		else{
			ans.de=a.de*b.de;
			ans.mol=a.mol*b.de+b.mol*a.de;
		}
        break;
		case 2://减法
		if(a.de==b.de){
			if(a.mol>=b.mol){
				ans.de=a.de;
				ans.mol=a.mol-b.mol;
			}
			else{//出现错误
                ans.de=-1;
                ans.mol=-1;
				cout<<"error:a is bigger than b";
			}
		}
		else{
			if(a.mol*b.de-b.mol*a.de<0){//出现错误
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
		case 3://乘法
		ans.de=a.de*b.de;
        ans.mol=a.mol*b.mol;
        break;
		case 4://除法
        ans.de=a.de*b.mol;
        ans.mol=a.mol*b.de;
        break;
	}
    return ans;//返回
}
#endif
