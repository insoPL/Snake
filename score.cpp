using namespace std;
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <iostream>

    const int obsz=21;

    int menu (string * mozl, int wlk, bool spec=false);

    int which (string str[], int point);

    int ins (string str[], string strink, int point);

    int getPoints(string str);

    bool score(){

    string scorsy[obsz];
    fstream plik;
    plik.open( "highscore.dat", ios::in | std::ios::out );
    if( plik.good() )
    {
        string napis;
        int x=0;
        while( !(plik.eof()&&x!=obsz-2) ){
            string napis;
            getline( plik, napis );
            scorsy[x++]=napis;
        }
        x=x-1;
        while (x<obsz-2){
            scorsy[x++]="---";
        }

        scorsy[obsz-1]="Exit";
    } else return 0;
    plik.close();

    while(menu(scorsy,obsz)!=obsz);
    return true;
    }

int addscores(string nick, int point){
    int zwr;
    stringstream nc;

    nc<<nick<<" - "<<point;
    nick=nc.str();

    string scorsy[obsz];
    fstream plik;
     int x=0;
    plik.open( "highscore.dat", ios::in );
    if( plik.good() )
    {
        x=0;
        while( x!=obsz-2){//dopóki plik sieskonczy lub do 19 czyli koniec hiskori
            string napis;
            getline( plik, napis );
            if(plik.eof()) break;
            scorsy[x++]=napis;
        }
        zwr=ins(scorsy,nick, point);

    } else return 500;


    plik.close();

    plik.open( "highscore.dat", ios::out | ios::trunc);

    if( plik.good() )
    {
        int xx=0;
        while( plik&&scorsy[xx]!="" ){
            plik<<scorsy[xx++]<<endl;
        }

    } else return 500;
    plik.close();
    return zwr;
}

int getscores(string nick, int point){
    int zwr;

    string scorsy[obsz];
    ifstream plik;
     int x=0;
    plik.open( "highscore.dat", ios::in );
    if( plik.good() )
    {
        x=0;
        while( x!=obsz-2){//dopóki plik sieskonczy lub do 19 czyli koniec hiskori
            string napis;
            getline( plik, napis );
            if(plik.eof()) break;
            scorsy[x++]=napis;
        }
        zwr=which(scorsy, point);

    } else return 500;


    plik.close();


    return zwr;
}

int getPoints(string str){
    unsigned found = str.find_last_of("-");
    stringstream konwersja(str.substr(found+1));
    int liczba;
    konwersja>>liczba;
    return liczba;
}

int ins (string str[], string strink,int point){
    int zwr=50;
    bool tryb=false;
    string st;
    for(int y=0;y<obsz-2;y++){
        if(getPoints(str[y])<=point&&tryb==false){
                zwr=y;
                st=str[y];
                str[y]=strink;
                tryb=true;
        }
        else if(tryb){
            string he=st;
            st=str[y];
            str[y]=he;
        }
    }
    return zwr+1;
}
int which (string str[], int point){
    int zwr=50;
    string st;
    for(int y=0;y<obsz-2;y++){
        if(getPoints(str[y])<=point){
                return y+1;
        }
    }
    return zwr+1;
}
