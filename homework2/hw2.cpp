#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;


int main(int argc, char** argv) {
    string filename;
    if (argc == 2) {

        // есть один агрумент
        // в argv[1] содержится строка с первым агрументом (имя файла)
        filename = argv[1];
    } else {
        // аргументов нет или их больше чем мы ожидаем
        filename = "in.txt";
    }


    ifstream F;
    string str;
    int delimiter;

    double x;
    double y;
    double h0;
    double vx;
    double vy;
    double dt = 0.01;
    double g = 9.1;
    int answer=0;

    F.open(filename); //Путь к файлику с данными
    int row_number;

    int i = 1;
    if (F) {
        while (!F.eof()) {
            getline(F, str);
            i = i + 1;
        }
    }
    F.close();
    F.open(filename);

    double xn[i-2];
    double hn[i-2];
    row_number = i-1;
    i=1;
    if (F) {
        while (!F.eof()) {
            if (i == 1) {
                getline(F, str);
                h0 = stod(str);
                i = i + 1;
            }
            if (i == 2) {
                getline(F, str);
                delimiter = str.find(" ");
                vx = stod(str.substr(0, delimiter));
                vy = stod(str.substr(delimiter + 1, str.length()));
                i = i + 1;
                }
            getline(F, str);
            i = i+1;

            delimiter = str.find(" ");
            xn[i-3] = stod(str.substr(0, delimiter));
            hn[i-3] = stod(str.substr(delimiter + 1, str.length()));
            }
            }

    //physics
    x =0;
    y = h0;
    double epsilon = dt*vx;
    int iter = 1;
    while(y>0){
        x = x+vx*dt;
        y = y+vy*dt;
        vy = vy-g*dt;
        for (int j = 1; j<=row_number-2; j++){
            if(x >xn[j]-epsilon && x <xn[j]+epsilon && y< hn[j]) {
              vx = -vx;


            }

        }
    iter = iter+1;

    }
    for (int j = 1; j<=row_number-1; j++){
        if(x >xn[j] && x <xn[j+1] ) {
            answer = j;
        }
        if(x >xn[row_number-2]){
            answer=  row_number-2;
        }


    }
    cout << answer << endl;
}

