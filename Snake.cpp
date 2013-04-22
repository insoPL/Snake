#include "Snake.hpp"
extern owoc owo;
 bool snake::go(){

        int x,y;
        if(dodanie==0){
        x=tab.back().x;
        y=tab.back().y;
        mvaddch(y,x,' ');
        tab.pop_back();
        }else dodanie--;



        if(kier==right){

        x=tab.front().x;
        y=tab.front().y;
        if(jest(x+1,y))  { attroff(COLOR_PAIR(1)); return false; }
        tab.insert(tab.begin(),ve(y,x+1));
        if(owo.x==x+1&&owo.y==y){owo.znj(tab); dodanie=dodanie+5; points+=10;}
            attron(COLOR_PAIR(1));
        mvaddch(y,x+1,'X');
        }
        else if(kier==left){

        x=tab.front().x;
        y=tab.front().y;
        if(jest(x-1,y)) { attroff(COLOR_PAIR(1));return false;}
        tab.insert(tab.begin(),ve(y,x-1));
        if(owo.x==x-1&&owo.y==y){owo.znj(tab); dodanie=dodanie+5; points+=10;}
           attron(COLOR_PAIR(1));
        mvaddch(y,x-1,'X');
        }
        else if(kier==up){
        x=tab.front().x;
        y=tab.front().y;
        if(jest(x,y-1)){  attroff(COLOR_PAIR(1)); return false;}
        tab.insert(tab.begin(),ve(y-1,x));
        if(owo.x==x&&owo.y==y-1){owo.znj(tab); dodanie=dodanie+5; points+=10;}
           attron(COLOR_PAIR(1));
        mvaddch(y-1,x,'X');
        }
        else if(kier==down){
        x=tab.front().x;
        y=tab.front().y;
        if(jest(x,y+1)) { attroff(COLOR_PAIR(1)); return false;}
        tab.insert(tab.begin(),ve(y+1,x));
        if(owo.x==x&&owo.y==y+1){owo.znj(tab); dodanie=dodanie+5; points+=10;}
           attron(COLOR_PAIR(1));
        mvaddch(y+1,x,'X');
        }

        attroff(COLOR_PAIR(1));
        refresh();

        return true;

    }

    snake::snake(std::string nam):znak(3){
        name=nam;
        points=0;
        ile++;
        dodanie=0;
        attron(COLOR_PAIR(1));
        tab.insert(tab.begin(),ve(13,38));
        mvaddch(13,38,'X');

        tab.insert(tab.begin(),ve(13,39));
        mvaddch(13,39,'X');

        tab.insert(tab.begin(),ve(13,40));
        mvaddch(13,40,'X');
        attroff(COLOR_PAIR(1));
        refresh();
       kier=right;
    }
        bool snake::jest(int x,int y){
        if(x==szer-1||x==0||y==0||y==24) return true;
        else {
            for(int z=0;z<tab.size();z++){
                if(tab.at(z).x==x&&tab.at(z).y==y) return true;
            }
        }

        return false;
    }

