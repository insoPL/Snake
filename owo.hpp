#ifndef owo_hpp
#define owo_hpp
#include <vector>

const int szer=65;


class ve{
public:
    int x,y;
    ve(int yy, int xx):x(xx),y(yy){};
};


class owoc{

public:
    int x,y;
    owoc(){
        x=1;
        y=1;
        }


        bool znj(const std::vector<ve>& gr){
            attroff(COLOR_PAIR(1));
        mvaddch(y,x,' ');
        bool czy=true;
         while(czy){
            x=rand()% (szer-2)+1;
            y=rand()% 23+1;

            for(int xx=0;xx<gr.size();xx++){
                if(czy=gr.at(xx).x==x && gr.at(xx).y==y) break;
            }
        }

        mvaddch(y,x,'O');

        refresh();
        }


};
#endif
