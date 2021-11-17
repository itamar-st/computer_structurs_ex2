// 207497769 Itamar Shachen tov



#include <stdio.h>
#include "ex2.h"

magnitude add(magnitude a, magnitude b) {
    magnitude aOnesComp = onesCompRep(a);
    magnitude bOnesComp = onesCompRep(b);

    magnitude carry = 0;
//    magnitude result = 0;
//    int size_of_byte = sizeof (char) * 8;
//    for (int i=0; i<size_of_byte; i++){
//        if(aOnesComp&mask ^ bOnesComp&mask) {
//            if(!carry){
//                result = result | mask;
//            }
//        }
//        if(aOnesComp&mask && bOnesComp&mask){
//            if(carry){
//                result = result | mask;
//            }
//            carry = 1;
//        } if(!(aOnesComp&mask || bOnesComp&mask)){
//            if (carry){
//                result = result | mask;
//                carry = 0;
//            }
//        }
//
//        mask<<=1;
//    }
    magnitude result = onesCompRep(aOnesComp+bOnesComp);

    if ((a<0 && b<0) && result > 0){
        return -1*result;
    }
    if ((a>0 && b>0) && result < 0){
        return -1*result;
    }
    else{
        return result;
    }
}
magnitude onesCompRep(magnitude num){
    if (num < 0){
        magnitude mask = 1;
        mask<<=31;
//        showBitRep(num);
        num*=(-1);
//        showBitRep(num);
        num = num ^ mask;
//        showBitRep(num);
    }
    return num;
}
int showBitRep(num){
    int mask = 1;
    for (int i = 0; i< sizeof(int)*8; i++){
        int tmp = num&mask;
        if (tmp){
            printf("%d",1);
        } else{
            printf("%d",0);
        }
        mask<<=1;
    }
    printf("\n");
}

magnitude multi(magnitude a, magnitude b) {
    magnitude aOnesComp = onesCompRep(a);
    magnitude bOnesComp = onesCompRep(b);
    magnitude result = onesCompRep(aOnesComp*bOnesComp);

    if ((a<0 && b<0) && result < 0){
        return -1*result;
    }
    if ((a>0 && b>0) && result < 0){
        return -1*result;
    }
    if (((a>0 && b<0)||(a<0 && b>0)) && result > 0){
        return -1*result;
    }
    else{
        return result;
    }}

magnitude sub(magnitude a, magnitude b) {
    magnitude aOnesComp = onesCompRep(a);
    magnitude bOnesComp = onesCompRep(b);
    magnitude result = onesCompRep(aOnesComp-bOnesComp);
    if ((a<0 && b>0) && result > 0){
        return -1*result;
    }
    if ((a>0 && b<0) && result < 0){
        return -1*result;
    }
    else{
        return result;
    }
}

int equal(magnitude a, magnitude b) {
    int mask = 1;
    for (int i = 0; i < sizeof(int)*8; i++) {
        mask<<=i;
        if ((a&mask) != (b&mask)){
            return 0;
        }
    }
    return 1;
}

int greater(magnitude a, magnitude b) {
    magnitude aOnesComp = onesCompRep(a);
    magnitude bOnesComp = onesCompRep(b);
    if(aOnesComp>bOnesComp ){
        return 1;
    }
    return 0;
}

