//Snake.hpp
#ifndef Snake_hpp
#define Snake_hpp
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <curses.h>
#include "owo.hpp"
#include <string.h>


class snake{
private:
    const char znak;        //z czego sklada sie waz
    int dodanie;            //o ile ma sie zwiekszyc waz w nastepnym kroku
public:
    std::string name;
    enum dir {up,down,left,right};  //cztery mozliwe kierunki drogi weza
    int points;                     //ile punktow zdobyl gracz
    static int ile;                 //ile jest obiektów typu snake
    dir kier;                       //w ktora jest obrocona jego paszcza
    std::vector<ve> tab;            //adresy poszczegolnych segmentow ciala

    snake(std::string str);             //konstruktor

    bool jest(int x,int y);          //czy na x y jest ten waz?

    bool go();                       //krok w przod

};
#endif
