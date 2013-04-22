#include "snake.hpp"

using namespace std;

extern bool smp_mod;

   void odn(bool pel=0){
    clear();
    int sze=szer;
    if(pel)sze=80;
    for(int y=0; y<25; y++){
            for(int x=0; x<sze; x++){
                    if(x==sze-1||x==0||y==0||y==24){ attron(COLOR_PAIR(7)); mvaddch(y,x,'#'); attron(COLOR_PAIR(8));}
            }}
            refresh();
            }









    int menu (string * mozl, int wlk, bool spec=false){
        if (wlk==0) return 0;//jesli tak naprawde gowno podaleœ no zwróc 0
        if (spec){//jesli spec to true to wypisz:
      const char napis[8][31]={ " ###  #   #   ##   #   # #####",
                                "#   # ##  #  #  #  #  #  #    ",
                                "#   # ##  # #    # # #   #    ",
                                " ##   # # # #    # ##    #### ",
                                "   #  # # # ###### ##    #    ",
                                "#   # #  ## #    # # #   #    ",
                                "#   # #  ## #    # #  #  #    ",
                                " ###  #   # #    # #   # #####"};
            for(int x=0;x<8;x++){
                for(int y=0;y<30;y++){
                        if(napis[x][y]==' '){attron(COLOR_PAIR(8)); mvaddch(2+x,25+y,napis[x][y]);}
                        else if(napis[x][y]=='#'){attron(COLOR_PAIR(7)); mvaddch(2+x,25+y,napis[x][y]);}
                }
                    attron(COLOR_PAIR(8));
            }}

            int najw=0;//najwiekszy z mozl sluzy za punkt odniesienia przy tworzenia nawiasow >tekst<
        for (int x=0;x< wlk; x++){
            if ((int)mozl[x].length()>najw) najw=mozl[x].length();
        }

            int lin=2;// pomijamy pierwsze 2 linijki
            if(spec) lin=12;//jesli napis snake to 13
            for(int x=0;x<wlk;x++){//wypisanie
                        //x to linijki
                        //y to litera w stringu
                    for(int y=0;y<mozl[x].length();y++){
                   //     if(mozl[x].at(y)=='$') y=y;
                        mvaddch(x+lin,40-mozl[x].length()/2+y,mozl[x].at(y));
                    }

            }

            int aktual=1;
            char wybor=0;
          while (wybor==0){//skasowanie szczalek punkt wyzej lub nizej i wstawienie nowych w dwoch wersjach parzystej i nieparzystej

                    if(najw%2==0){
                        mvaddch(aktual-1+lin,40+najw/2-1,'<');
                        mvaddch(aktual-1+lin,40-najw/2-1,'>');

                        mvaddch(aktual+lin,40+najw/2-1,' ');
                        mvaddch(aktual+lin,40-najw/2-1,' ');

                        mvaddch(aktual-2+lin,40+najw/2-1,' ');
                        mvaddch(aktual-2+lin,40-najw/2-1,' ');
                }
                else{
                    mvaddch(aktual-1+lin,40+najw/2+2,'<');
                    mvaddch(aktual-1+lin,40-najw/2-2,'>');

                    mvaddch(aktual+lin,40+najw/2+2,' ');
                    mvaddch(aktual+lin,40-najw/2-2,' ');

                    mvaddch(aktual-2+lin,40+najw/2+2,' ');
                    mvaddch(aktual-2+lin,40-najw/2-2,' ');
                }
                refresh();

            unsigned char klaw;
                 bool koniec=true;

                do{//pobranie klawisza dopóki nie poda opowiedniego w albo s
                    klaw= getch();

                            if(klaw==115&&aktual<wlk) {aktual++; koniec=false;}
                            if(klaw==119&&aktual>1) {aktual--; koniec=false;}

                    if(klaw==13){wybor=aktual; koniec=false;}
                    }while(koniec);
                }

                if(najw%2==0){//skasowanie szczalek na aktualu w razie przejscia dalej niz o 1 w gore lub dol
                        mvaddch(aktual-1+lin,40-najw/2-1,' ');
                        mvaddch(aktual-1+lin,40+najw/2-1,' ');}
                 else{
                    mvaddch(aktual-1+lin,40+najw/2+2,' ');
                    mvaddch(aktual-1+lin,40-najw/2-2,' ');}


               return wybor;
    }







    void rigs(int players,snake* sn,bool cz=false){
        if(smp_mod){
                int line=0;
            for(int x=1;x-1<players;x++){

            int i = 42;

                string tmp;
                sprintf((char*)tmp.c_str(), "%d", x);

            string pl="Score :";


            for(int y=0;y<pl.length();y++){
                    mvaddch(1+line*2,66+y,pl.at(y));
                }
        line++;
        }}
        else if(cz){
            int line=0;
            for(int x=1;x-1<players;x++){

            int i = 42;

                string tmp;
                sprintf((char*)tmp.c_str(), "%d", x);

            string pl="Player "+(string)tmp.c_str()+":";


            for(int y=0;y<pl.length();y++){
                    mvaddch(1+line*2,66+y,pl.at(y));
                }
        line++;

         }
        }


        for(int y=0;y<players;y++){

            string tmp="";
            sprintf((char*)tmp.c_str(), "%d", sn[y].points);
            string tek=(string)tmp.c_str();

            reverse(tek.begin(), tek.end());

            for(int x=0;x<tek.length();x++){
            mvaddch(2,78-x,tek.at(x));
            refresh();
        }
    }}
