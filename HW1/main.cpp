#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;

int main() {
    string  str;
    int x;
    int y;
    int xn;
    int yn;
    int xmax_l=0;
    int ymax_l=0;
    float d_old_l=0;
    int xmax_r=0;
    int ymax_r=0;
    float d_old_r=0;
    float d_new=0;
    ifstream F;
    int delimiter;

    F.open("A:\\stydy\\results\\matmod\\in.txt"); //Путь к файлику с данными
    int i=1;
    if (F) {
        while (!F.eof()) {
            getline(F,str);
            delimiter = str.find(" ");
            x = stoi(str.substr(0, delimiter));
            y = stoi(str.substr(delimiter + 1, str.length()));
            if(i==1){
                xn = x;
                yn = y;
            }

            d_new = ((x*yn-xn*y) )/ (sqrt(yn*yn+xn*xn));

            if(d_new>d_old_r) {
                d_old_r = d_new;
                xmax_r=x;
                ymax_r=y;
            }
            if(d_new<d_old_l) {
                d_old_l = d_new;
                xmax_l=x;
                ymax_l=y;
            }
            i++;
        }
        cout<<"Leftmost: "<<xmax_l<<" "<<ymax_l<<endl;
        cout<<"Rightmost: "<<xmax_r<<" "<<ymax_r<<endl;

        F.close();
        return 0;
    }
}