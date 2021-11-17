
#ifndef EX2_H
#define EX2_H

typedef int magnitude;


magnitude add(magnitude a, magnitude b); // a + b
magnitude sub(magnitude a, magnitude b); // a - b
magnitude multi(magnitude a, magnitude b); // a * b

// true = 1, false = 0
int equal(magnitude a, magnitude b); // a = b
int greater(magnitude a, magnitude b); // a > b
magnitude onesCompRep(magnitude num);
int showBitRep(magnitude num);



#endif //UNTITLED2_EX2_H
