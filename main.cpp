#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <curses.h>

#include "Snake.hpp"


using namespace std;



    void odn(bool pel=0);

    int menu (string * mozl, int wlk, bool spec=false);

    void rigs(int players,snake* sn,bool cz=false);

    int score();

    int addscores(string nick, int point);

    owoc owo;
    int snake::ile=0;
    bool koniec=false;

int main(){

    initscr();

    if(has_colors() == FALSE)
	{	endwin();
		printf("Your terminal does not support color\n");
		exit(1);
	}
	start_color();
	init_pair(1, COLOR_BLACK,COLOR_GREEN);


    curs_set(FALSE);
    raw();
    noecho();
    odn(true);
    const int men=3;// ile pozycji w menu
    string tabl[men]={
                    "Start",
      //              "Multiplayerr",
                    "Highscore",
          //          "Options",
                    "Exit"};
int wynik=0;
   while(wynik!=men){
    if(wynik==0)wynik=menu(tabl,men,1);
    if (wynik==1){
                odn();
                snake gracz[1];
                owo.znj(gracz[0].tab);
                gracz[0].owo=&owo;
                rigs(1,gracz,true);

                char klaw;
                do{
                    timeout(200);
                    klaw=getch();

                    if(klaw==119&&gracz[0].kier!=snake::down){
                        gracz[0].kier=snake::up;
                    }else if(klaw==115&&gracz[0].kier!=snake::up){
                        gracz[0].kier=snake::down;
                    }
                    else if(klaw==97&&gracz[0].kier!=snake::right){
                        gracz[0].kier=snake::left;
                    }else if(klaw==100&&gracz[0].kier!=snake::left){
                        gracz[0].kier=snake::right;
                    }
                    koniec=gracz[0].go();
                    rigs(1,gracz);


                    }while(koniec&&klaw!=9);

                        odn(1);
                        wynik=0;
                        if (!koniec){
                            int miej=addscores("player",gracz[0].points);



                            string tmp;
                            sprintf((char*)tmp.c_str(), "%d", gracz[0].points);

                            tmp=(string)tmp.c_str();

                            string tmp2;

                            sprintf((char*)tmp2.c_str(), "%d", miej);


                            string str1="Game Over";
                            string str2="You earned "+tmp+" points, You readched "+(string)tmp2.c_str()+" place in Highscore";
                            if (gracz[0].points==0||miej>19) str2="You earned "+tmp+" points";
                            string str3="Play Again? [Y/N]";
                            curs_set(true);

                            for(int y=0;y<str1.length();y++){
                                mvaddch(10,40-str1.length()/2+y,str1.at(y));
                                }//game over
                                for(int y=0;y<str2.length();y++){
                                mvaddch(11,40-str2.length()/2+y,str2.at(y));
                                }//You earned

                                 for(int y=0;y<str3.length();y++){
                                mvaddch(12,40-str3.length()/2+y,str3.at(y));
                                }//play again?


                                do{
                                klaw= getch();
                                }while(!(klaw==121||klaw==110));

                                if(klaw==121)  wynik=1;
                                else odn(1);
                                curs_set(FALSE);
                        }


    }
    if(wynik==2){
        odn(1);
        score();
        odn(1);
        wynik=0;
    }

   }


    clear();
    refresh();
    endwin();
    return 0;
}
