//Snake.hpp
#ifndef Snake_hpp
#define Snake_hpp
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <curses.h>
#include "owo.hpp"


class snake{
private:
    const char znak;        //z czego sklada sie waz
    int dodanie;            //o ile ma sie zwiekszyc waz w nastepnym kroku
public:
    enum dir {up,down,left,right};  //cztery mozliwe kierunki drogi weza
    owoc* owo;                      //adres obiektu owocu znajdujacego sie na mapie !!zmienic na static!!
    int points;                     //ile punktow zdobyl gracz
    static int ile;                 //ile jest obiektów typu snake
    dir kier;                       //w ktora jest obrocona jego paszcza
    std::vector<ve> tab;            //adresy poszczegolnych segmentow ciala

    snake(char zn='X');             //konstruktor

    bool jest(int x,int y);

    bool go();

};
#endif
