#include <iostream>
int angleCLock(int _h, int _m) {
    if (_h == 12) _h = 0;
    if (_m == 60) _m = 0;
    double hAngle = 0.5 * ((60 * _h) + _m);
    double mAngle = 6 * _m;
    double ret = abs(hAngle - mAngle);
    return std::min(360 - ret, ret);
}
int main()
{
    std::cout << angleCLock(3,30);
}

/*Afficher l'angle en fonction de l'heure et des minutes*/
/*Format heure/minute 1h<-60min 12+-> -12*/
/*Angle ->Heure/minute*/