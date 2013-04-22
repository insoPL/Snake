#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <curses.h>
#include "Snake.hpp"

extern owoc owo;

using namespace std;



    void odn(bool pel=0);

    int menu (string * mozl, int wlk, bool spec=false);

    void rigs(int players,snake* sn,bool cz=false);

    int score();

    int addscores(string nick, int point);

    int getscores(string nick, int point);

    owoc owo;
    int snake::ile=0;
    bool koniec=false;
    bool smp_mod=true;

int main(){

    initscr();

    if(has_colors() == FALSE)
	{	endwin();
		printf("Your terminal does not support color\n");
		exit(1);
	}
	start_color();
	init_pair(1, COLOR_BLACK,2); //ciemne zielone
	init_pair(2, COLOR_BLACK,5); //ciemny fiolet
    init_pair(3, COLOR_BLACK,7); // jasne biale
	init_pair(4, COLOR_BLACK,11); //turkus
    init_pair(5, COLOR_BLACK,12); // czerwony
    init_pair(6, COLOR_BLACK,14); //zolty
    init_pair(7, COLOR_WHITE,COLOR_WHITE);
    init_pair(8, 20,20);

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
                snake gracz[1]={
                    snake("bolek")
                };
                owo.znj(gracz[0].tab);

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
                        int miej;
                        string str3;
                        if (!koniec){
                            miej=getscores(gracz[0].name,gracz[0].points);

                            string tmp;
                            sprintf((char*)tmp.c_str(), "%d", gracz[0].points);

                            tmp=(string)tmp.c_str();

                            string tmp2;

                            sprintf((char*)tmp2.c_str(), "%d", miej);


                            string str1="Game Over";
                            string str2="You earned "+tmp+" points, You readched "+(string)tmp2.c_str()+" place in Highscore";

                            if (gracz[0].points==0||miej>19) str2="You earned "+tmp+" points";
                            str3="Save Scores? [Y/N]";
                            if (gracz[0].points==0||miej>19) str3="Play Again? [Y/N]";
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


                                if(klaw==121){//yes
                                        if (gracz[0].points==0||miej>19) wynik=1;//nie ma miejsca
                                        else {
                                            odn();
                                            string str4="Podaj swoj nick";

                                            for(int y=0;y<str4.length();y++){
                                            mvaddch(10,40-str4.length()/2+y,str4.at(y));
                                            }
                                            move(11,40);

                                            curs_set(true);
                                            refresh();
                                            char nickname[20]="0000000000000000000";

                                            int s;
                                            timeout(-1);
                                            for(s=0;s<20;s++){
                                                do{nickname[s]=getch();}while(s>18&&!(nickname[s]==13||nickname[s]==8));

                                                if(nickname[s]==13)break;
                                                else if(nickname[s]==8){s=s-2;

                                                                        for(int x=0;x<20;x++) mvaddch(11,30+x,' ');


                                                                                             }

                                                for(int pies=0;pies<s+1;pies++){

                                                    mvaddch(11,(40-(s/2))+pies,nickname[pies]);
                                                }
                                                refresh();

                                            }
                                            string nic;
                                            for(int zre=0;zre<s;zre++){nic=nic+nickname[zre];}
                                            addscores(nic,gracz[0].points);

                                            curs_set(false);
                                        }//// TODO (£ukasz#1#): pobranie danych
                                }
                                else{//no
                                    if (gracz[0].points==0||miej>19){}//nie ma miejsca
                                    else{
                                        str3=" Play Again? [Y/N] ";
                                        for(int y=0;y<str3.length();y++){
                                            mvaddch(12,40-str3.length()/2+y,str3.at(y));}
                                             do{
                                                klaw= getch();
                                                }while(!(klaw==121||klaw==110));
                                            if(klaw==121) wynik=1;
                                        }
                                    }




                                odn(1);
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
