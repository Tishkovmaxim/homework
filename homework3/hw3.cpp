#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <math.h>
#include <vector>
using namespace std;


class figure{
public:
    string fig_type;
    int n;
    vector<double> nodes;

};

bool ifintersec(figure fig1, figure fig2){

    if(fig1.fig_type=="CIRCLE" && fig2.fig_type=="CIRCLE"){
        if( sqrt( pow((fig1.nodes[1]-fig2.nodes[1]),2)+pow((fig1.nodes[2]-fig2.nodes[2]),2)) <fig1.nodes[0]+fig1.nodes[0] ){
              return true;
        }
    }

    if((fig1.fig_type=="CIRCLE" && fig2.fig_type=="POLYGON")||(fig1.fig_type=="CIRCLE" && fig2.fig_type=="RECTAGNLE")){

        for(int i =0; i<=fig2.nodes.size();i=i+2){

            if( sqrt( pow((fig1.nodes[1]-fig2.nodes[i]),2)+pow((fig1.nodes[2]-fig2.nodes[i+1]),2)) <fig1.nodes[0]){
                return true;
            }
        }
        for(int i =0; i<=fig2.nodes.size();i=i+2){

            int j = i+2;
            if(i+2>fig2.nodes.size()-1){
                j=0;
            }

            if( sqrt( pow(((fig2.nodes[i]-fig1.nodes[1]+fig2.nodes[j]-fig1.nodes[1]))/2,2)+pow(((fig2.nodes[i+1]-fig1.nodes[2]+fig2.nodes[j+1]-fig1.nodes[2]))/2,2)) <fig1.nodes[0]){
                return true;
            }
        }
    }

    if((fig2.fig_type=="CIRCLE" && fig1.fig_type=="POLYGON")||(fig2.fig_type=="CIRCLE" && fig1.fig_type=="RECTAGNLE")){

        for(int i =0; i<=fig1.nodes.size();i=i+2){



            if( sqrt( pow((fig2.nodes[1]-fig1.nodes[i]),2)+pow((fig2.nodes[2]-fig1.nodes[i+1]),2)) <fig2.nodes[0]){
                return true;
            }
        }
        for(int i =0; i<=fig1.nodes.size();i=i+2){

            int j = i+2;
            if(i+2>fig1.nodes.size()-1){
                j=0;
            }

            if( sqrt( pow(((fig1.nodes[i]-fig2.nodes[1]+fig1.nodes[j]-fig2.nodes[1]))/2,2)+pow(((fig1.nodes[i+1]-fig2.nodes[2]+fig1.nodes[j+1]-fig2.nodes[2]))/2,2)) <fig1.nodes[0]){
                return true;
            }
        }
    }





}





int main() {
    string str;
    ifstream F;
    F.open("in.txt");
    int number_of_figures=0;

    while (!F.eof()) {
        getline(F, str);

        if(str=="CIRCLE") {
            number_of_figures=number_of_figures+1;

        }
        if(str=="POLYGON") {
            number_of_figures=number_of_figures+1;
        }
        if(str=="RECTAGNLE") {
            number_of_figures=number_of_figures+1;
        }
        }
    F.close();

    figure fig_massive[number_of_figures];
    int row_of_figure[number_of_figures+1];

    F.open("in.txt");
    int i =0; //строка
    int j = -1; //фигура


    while (!F.eof()) {
        getline(F, str);

        if(str=="CIRCLE") {
            j = j+1;
            row_of_figure[j]=i;
        }
        if(str=="POLYGON") {
            j = j+1;
            row_of_figure[j]=i;
        }
        if(str=="RECTAGNLE") {
            j = j+1;
            row_of_figure[j]=i;
        }
        i=i+1;
    }

    row_of_figure[sizeof(row_of_figure)/sizeof(row_of_figure[0])-1]=i;
    F.close();


//    cout<<row_of_figure[sizeof(row_of_figure)]<<endl;




    F.open("in.txt");
    i =0; //строка
    j = -1; //фигура

    while (!F.eof()) {
        getline(F, str);

        if(str=="CIRCLE"){
            j=j+1;
            fig_massive[j].fig_type="CIRCLE";
            fig_massive[j].n=3;
            fig_massive[j].nodes.resize(fig_massive[j].n);
            i=i+1;
            continue;
        }

        if(str=="RECTAGNLE"){
            j=j+1;
            fig_massive[j].fig_type="RECTAGNLE";
            fig_massive[j].n=8;
            fig_massive[j].nodes.resize(fig_massive[j].n);
            i=i+1;
            continue;
        }

        if(str=="POLYGON"){
            j=j+1;
            fig_massive[j].fig_type="POLYGON";
            fig_massive[j].n=(row_of_figure[j+1]-1-row_of_figure[j])*2;
            fig_massive[j].nodes.resize(fig_massive[j].n);

            i=i+1;
            continue;
        }
//        cout<<j<<endl;
        if(fig_massive[j].fig_type=="CIRCLE" && i==row_of_figure[j]+1){
            fig_massive[j].nodes[0] = stod(str);
            i=i+1;
            continue;
        }

        int  delimiter;
        delimiter = str.find(" ");

        if(fig_massive[j].fig_type=="CIRCLE"){
            fig_massive[j].nodes[i-1-row_of_figure[j]] = stod(str.substr(0, delimiter));
            fig_massive[j].nodes[i-1-row_of_figure[j]+1] = stod(str.substr(delimiter + 1, str.length()));
            i=i+1;
            continue;
        }
        if(fig_massive[j].fig_type=="RECTAGNLE"){
            if(i-1-row_of_figure[j]==0) {
                fig_massive[j].nodes[0] = stod(str.substr(0, delimiter));
                fig_massive[j].nodes[1] = stod(str.substr(delimiter + 1, str.length()));
                i = i + 1;
                continue;
            }
            if(i-1-row_of_figure[j]==1) {
                fig_massive[j].nodes[4] = stod(str.substr(0, delimiter));
                fig_massive[j].nodes[5] = stod(str.substr(delimiter + 1, str.length()));

                fig_massive[j].nodes[2] = fig_massive[j].nodes[4];
                fig_massive[j].nodes[3] = fig_massive[j].nodes[1];

                fig_massive[j].nodes[6] = fig_massive[j].nodes[0];
                fig_massive[j].nodes[7] = fig_massive[j].nodes[5];


                i = i + 1;
                continue;
            }
        }



      fig_massive[j].nodes[(i - 1 - row_of_figure[j]) * 2] = stod(str.substr(0, delimiter));
            fig_massive[j].nodes[(i - 1 - row_of_figure[j]) * 2 + 1] = stod(str.substr(delimiter + 1, str.length()));


        i=i+1;
//        cout<<fig_massive[0].nodes[2]<<endl;
    }



//    cout<<ifintersec(fig_massive[1],fig_massive[2])<<endl;



    for(int l=0; l<=number_of_figures-1;l++){
        for(int m=0; m<=number_of_figures-1;m++){

            if(m>l){
//                cout<<l<<" "<<m<<endl;
                if(ifintersec(fig_massive[l],fig_massive[m])){
                    cout<<l<<" "<<m<<endl;
                }

            }
        }
    }


}
