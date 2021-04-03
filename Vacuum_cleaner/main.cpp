#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
struct eveniment
{
    char* den;
};
struct stare
{
    char* nume;
};
typedef struct eveniment ev;
typedef struct stare st;
void populare_stari(st* stari)//am predefinit numele starilor pentru a facilita partea de afisare a mesajelor
{
    stari[0].nume=(char*)malloc(sizeof(char)*50);
    strcpy(stari[0].nume," starea initiala ");

    stari[1].nume=(char*)malloc(sizeof(char)*50);
    strcpy(stari[1].nume," curatare in mod automat ");

    stari[2].nume=(char*)malloc(sizeof(char)*50);
    strcpy(stari[2].nume," curatare manuala prin intermediul aplicatiei ");

    stari[3].nume=(char*)malloc(sizeof(char)*50);
    strcpy(stari[3].nume," scanare ");

    stari[4].nume=(char*)malloc(sizeof(char)*50);
    strcpy(stari[4].nume," pornire ultrasunete ");

    stari[5].nume=(char*)malloc(sizeof(char)*50);
    strcpy(stari[5].nume," ocolire ");

    stari[6].nume=(char*)malloc(sizeof(char)*50);
    strcpy(stari[6].nume," eliberare tub curatare ");

    stari[7].nume=(char*)malloc(sizeof(char)*50);
    strcpy(stari[7].nume," curatare colt ");

    stari[8].nume=(char*)malloc(sizeof(char)*50);
    strcpy(stari[8].nume," incheiere program de curatare ");

    stari[9].nume=(char*)malloc(sizeof(char)*50);
    strcpy(stari[9].nume," intoarcere la statia de incarcare ");

    stari[10].nume=(char*)malloc(sizeof(char)*50);
    strcpy(stari[10].nume," defect ");

    stari[11].nume=(char*)malloc(sizeof(char)*50);
    strcpy(stari[11].nume," necesitate schimbare sac ");

    stari[12].nume=(char*)malloc(sizeof(char)*50);
    strcpy(stari[12].nume," animal detectat a doua oara ");

    stari[13].nume=(char*)malloc(sizeof(char)*50);
    strcpy(stari[13].nume," avertizarea sonora a utilizatorului ");

    stari[14].nume=(char*)malloc(sizeof(char)*50);
    strcpy(stari[14].nume," intoarcere ");



}
void populare_ev(ev* evenimente)//s-au predefinit numele evenimentelor in scopul facilitarii afisarii mesajelor
{
    evenimente[0].den=(char*)malloc(sizeof(char)*100);
    strcpy(evenimente[0].den," Evenimentul nu este valid ");

    evenimente[1].den=(char*)malloc(sizeof(char)*100);
    strcpy(evenimente[1].den," pornire automata a procesului de curatare ");

    evenimente[2].den=(char*)malloc(sizeof(char)*100);
    strcpy(evenimente[2].den," controlarea procesului de catre utilizator ");

    evenimente[3].den=(char*)malloc(sizeof(char)*100);
    strcpy(evenimente[3].den," aparitie obstacol ");

    evenimente[4].den=(char*)malloc(sizeof(char)*100);
    strcpy(evenimente[4].den," detectare animal ");

    evenimente[5].den=(char*)malloc(sizeof(char)*100);
    strcpy(evenimente[5].den," detectare obiect ");

    evenimente[6].den=(char*)malloc(sizeof(char)*100);
    strcpy(evenimente[6].den," alungare animal ");

    evenimente[7].den=(char*)malloc(sizeof(char)*100);
    strcpy(evenimente[7].den," evitare obstacol ");

    evenimente[8].den=(char*)malloc(sizeof(char)*100);
    strcpy(evenimente[8].den," detectare colt ");

    evenimente[9].den=(char*)malloc(sizeof(char)*100);
    strcpy(evenimente[9].den," sistemul de actionare este functional ");

    evenimente[10].den=(char*)malloc(sizeof(char)*100);
    strcpy(evenimente[10].den," detectare baterie descarcata ");

    evenimente[11].den=(char*)malloc(sizeof(char)*100);
    strcpy(evenimente[11].den," defectiune ");

    evenimente[12].den=(char*)malloc(sizeof(char)*100);
    strcpy(evenimente[12].den," reset ");

    evenimente[13].den=(char*)malloc(sizeof(char)*100);
    strcpy(evenimente[13].den," reluare curatare ");

    evenimente[14].den=(char*)malloc(sizeof(char)*100);
    strcpy(evenimente[14].den," sac plin ");

    evenimente[15].den=(char*)malloc(sizeof(char)*100);
    strcpy(evenimente[15].den," terminare incarcare ");

    evenimente[16].den=(char*)malloc(sizeof(char)*100);
    strcpy(evenimente[16].den," terminare curatare colt ");

    evenimente[17].den=(char*)malloc(sizeof(char)*100);
    strcpy(evenimente[17].den," aparitie scari ");

    evenimente[18].den=(char*)malloc(sizeof(char)*100);
    strcpy(evenimente[18].den," scari evitate ");

    evenimente[19].den=(char*)malloc(sizeof(char)*100);
    strcpy(evenimente[19].den," terminare curatare ");

    evenimente[20].den=(char*)malloc(sizeof(char)*100);
    strcpy(evenimente[20].den," animalul nu se misca ");


}
void populare_delta(int** matr) //matricea reprezinta defapt functia de tranzitie
{
    matr[0][1]=1;
    matr[0][2]=2;
    matr[1][2]=2;
    matr[1][3]=3;
    matr[1][8]=6;
    matr[1][10]=9;
    matr[1][14]=11;
    matr[1][17]=14;
    matr[1][19]=8;

    matr[2][1]=1;
    matr[2][19]=8;

    matr[3][4]=4;
    matr[3][5]=5;

    matr[4][4]=12;
    matr[4][6]=1;

    matr[5][7]=1;

    matr[6][9]=7;
    matr[6][11]=10;

    matr[7][16]=1;

    matr[9][15]=1;
    matr[9][11]=10;

    matr[10][12]=15;

    matr[11][13]=1;

    matr[12][20]=13;

    matr[13][7]=1;

    matr[14][18]=1;
}
void populare_matrice(int** matr)
{
    for(int i=0;i<15;i++)
        for(int j=0;j<7;j++)
            matr[i][j]=0;
    matr[1][0]=1;
    matr[1][1]=1;
    matr[1][2]=1;
    matr[1][3]=1;
    matr[1][4]=1;
    matr[1][5]=1;
    matr[3][6]=1;
    matr[4][6]=1;
    matr[4][0]=1;
    matr[12][0]=1;
    matr[12][6]=1;
    matr[13][0]=1;
    matr[13][6]=1;
    matr[14][3]=1;
    matr[5][0]=1;
    matr[11][4]=1;
    matr[9][5]=1;

}
struct aspirator
{
    int dis_obst_stanga,dist_obst_dreapta,dist_obst_fata;//distantele returnate de cei 3 senzori
    int dis_sol;//distanta pana la sol returnata de senzorul amplasat in partea din fata jos
    int nivel_baterie;//nivelul bateriei
    int nivel_sac;//cat de plin este recipietul de colectare
    int nivel_termic;//valoarea termica in grade returnata de senzorul termic
    int stare;//starea in care se afla aspiratorul
};

typedef struct aspirator asp;
void afis_asp(asp robot)
{
    cout<<endl<<endl<<"Statusul actual al robotului este"<<endl;
    cout<<"Distanta obstacol stanga : "<<robot.dis_obst_stanga<<endl;
    cout<<"Distanta obstacol dreapta : "<<robot.dist_obst_dreapta<<endl;
    cout<<"Distanta obstacol fata : "<<robot.dist_obst_fata<<endl;
    cout<<"Distanta sol : "<<robot.dis_sol<<endl;
    cout<<"Nivel sac : "<<robot.nivel_sac<<endl;
    cout<<"Nivel baterie : "<<robot.nivel_baterie<<endl;
    cout<<"Nivel termic : "<<robot.nivel_termic<<endl<<endl;

}
void afis_posibilitati(ev* evenimente,int** matrice,int stare)
{
    for(int j=1;j<21;j++)
    {
        if(matrice[stare][j]!=0)
            cout<<j<<". -  "<<evenimente[j].den<<endl;
    }
}
char** init_variabile()//am creat
{
    char **Comb_variabile;
    Comb_variabile=(char**)malloc(sizeof(char*)*7);
    for(int i=0;i<7;i++)
        Comb_variabile[i]=(char*)malloc(sizeof(char)*50);
    strcpy(Comb_variabile[0],"Distanta fata ");
    strcpy(Comb_variabile[1],"Distanta fata si stanga ");
    strcpy(Comb_variabile[2],"Distanta fata si dreapta ");
    strcpy(Comb_variabile[3],"Distanta sol ");
    strcpy(Comb_variabile[4],"Nivel sac ");
    strcpy(Comb_variabile[5],"Nivel baterie ");
    strcpy(Comb_variabile[6],"Nivel termic ");
    return Comb_variabile;
}
int afis_variante(int ** matr,char** comb,int stare)//afiseaza variabile interna care pot fi modificate dintr o anumita stare
{
    int nr=0;
    for(int j=0;j<7;j++)
        if(matr[stare][j]  !=0 )
        {
            cout<<j<<".-"<<comb[j]<<endl;
            nr++;
        }
    return nr;

}
int returnare_eveniment(int** delta,int stare,int stare_noua)//afiseaza evenimentele posibile dintr-o stare
{
    for(int i=0;i<15;i++)
        for(int j=0;j<21;j++)
            if(delta[stare][j]==stare_noua)
                return j;
    return 0;
}
int main()
{
    //Initializari
    st* stari;
    ev* evenimente;
    int** delta,**matr_adiacenta;
    int evenim,var,var1,var2,verificare;//nr evenimentului citit de la tastatura
    char* raspuns,*mod,**Comb_var;



    raspuns=(char*)malloc(sizeof(char)*3);
    mod=(char*)malloc(sizeof(char)*20);
    delta=(int**)malloc(sizeof(int*)*15);



    for(int i=0;i<15;i++)
    {
        delta[i]=(int*)malloc(sizeof(int)*21);
    }

    for(int i=0;i<=14;i++)
        for(int j=0;j<=20;j++)
            delta[i][j]=0;

    populare_delta(delta);


    matr_adiacenta=(int**)malloc(sizeof(int*)*15);
    for(int i=0;i<15;i++)
    {
        matr_adiacenta[i]=(int*)malloc(sizeof(int)*7);
    }

    populare_matrice(matr_adiacenta);


    stari=(st*)malloc(sizeof(st)*15);
    populare_stari(stari);

    evenimente=(ev*)malloc(sizeof(ev)*20);
    populare_ev(evenimente);

    Comb_var=init_variabile();

    asp robot;
    robot.dist_obst_dreapta=100;//distanta in cm ,1 metru fiind distanta maxima la care senzorul poate vedea
    robot.dis_obst_stanga=100;
    robot.dist_obst_fata=100;
    robot.nivel_baterie=100;
    robot.dis_sol=4;
    robot.nivel_sac=0;
    robot.nivel_termic=10;//temperatura normala dintr-o camera;
    robot.stare=0;//Initializare cu starea initiala  automatului

    system("Color 70");
    cout<<" ||||||||       ||||||||       ||||||||||       |||||||||                              "<<endl;
    cout<<" ||     ||     ||      ||      ||       ||     ||       ||          ||                 ||"<<endl;
    cout<<" ||     ||     ||      ||      ||       ||     ||       ||          ||                 ||"<<endl;
    cout<<" ||||||||      ||      ||      ||||||||||      ||              ||||||||||||       ||||||||||||"<<endl;
    cout<<" ||||          ||      ||      ||       ||     ||                   ||                 ||"<<endl;
    cout<<" || ||         ||      ||      ||       ||     ||       ||          ||                 ||"<<endl;
    cout<<" ||  ||        ||      ||      ||       ||     ||       ||"<<endl;
    cout<<" ||   ||        ||||||||       ||||||||||       |||||||||"<<endl<<endl<<endl;
    cout<<" Bun venit ! \n\n Pentru incetarea simularii introduceti orice numar negativ ca eveniment.\n \n Te rugam sa selectezi un mod de curatare prin introducerea numarului corespunzator : \n "<<endl;
    afis_posibilitati(evenimente,delta,robot.stare);
    cin>>evenim;
    robot.stare=delta[robot.stare][evenim];
    afis_asp(robot);
    cout<<"\nVa rugam sa alegeti modul in care doriti sa treceti la o noua stare  : \n1.Evenimente\n2.Variabile \n3.Terminare (pentru a incheia simularea)\n";
    cin>>mod;
    while(strcmp(mod,"Terminare")!=0)
    {
        if(strcmp(mod,"Evenimente")==0)
        {
        cout<<"Evenimentele disponibile din aceasta stare sunt :"<<endl;
        afis_posibilitati(evenimente,delta,robot.stare);
        cout<<"Alegeti un eveniment : ";
        cin>>evenim;
        if(evenim<0) break;


        if(delta[robot.stare][evenim] != 0)
        {

            if(delta[robot.stare][evenim] == 1)//Se revine  la anumiti parametri normali pentru starea de curatare automata
            {
                robot.dist_obst_dreapta=100;
                robot.dis_obst_stanga=100;
                robot.dist_obst_fata=100;
                robot.nivel_sac=0;
                robot.nivel_termic=10;
                robot.nivel_baterie=100;
            }
            if(delta[robot.stare][evenim] == 3)//Detectarea unui obstacol duce la o distanta in fata de 2 sau sau mai mica de 2
            {
                robot.dist_obst_dreapta=100;
                robot.dis_obst_stanga=100;
                robot.dist_obst_fata=2;
                robot.nivel_sac=0;
                robot.nivel_termic=10;
            }
            if(delta[robot.stare][evenim] == 4)//Detectarea unui animal ar modifica valoarea returnata de senzorul termic mai mare ca fiind de 25
            {
                robot.dist_obst_dreapta=100;
                robot.dis_obst_stanga=100;
                robot.dist_obst_fata=2;
                robot.nivel_sac=0;
                robot.nivel_termic=35;
            }
            if(delta[robot.stare][evenim] == 6)//Detectarea unui colt modifica atat distanta fata  cat si una din dinstantele stanga sau dreapta . Am ales stanga.
            {
                robot.dist_obst_dreapta=100;
                robot.dis_obst_stanga=2;
                robot.dist_obst_fata=2;
                robot.nivel_sac=0;
                robot.nivel_termic=10;
            }
            if(delta[robot.stare][evenim] == 9)//Se considera ca bateria este descarcata cand nivelul ajunge la 10 sau mai putin de 10%
            {
                robot.dist_obst_dreapta=100;
                robot.dis_obst_stanga=100;
                robot.dist_obst_fata=100;
                robot.nivel_baterie=10;//se presupune ca robotul poate ajunge cu 10% baterie inapoi la statia de incarcare
                robot.nivel_sac=0;
                robot.nivel_termic=10;
            }
            if(delta[robot.stare][evenim] == 11)//Nivelul sacului ajunge la 100% cand
            {
                robot.dist_obst_dreapta=100;
                robot.dis_obst_stanga=100;
                robot.dist_obst_fata=100;
                robot.nivel_sac=100;
                robot.nivel_termic=10;
            }
            if(delta[robot.stare][evenim] == 14)//Distanta fata e sol devine mai mare de 4 atunci cand se detecteaza scarile
            {
                robot.dist_obst_dreapta=100;
                robot.dis_obst_stanga=100;
                robot.dist_obst_fata=100;
                robot.dis_sol=6;
                robot.nivel_sac=100;
                robot.nivel_termic=10;
            }
            if(delta[robot.stare][evenim] == 8)
            {
                cout<<" ||||||||       ||||||||       ||       ||      |||||||||"<<endl;
                cout<<" ||     ||     ||      ||      |||      ||     ||       || "<<endl;
                cout<<" ||     ||     ||      ||      || |     ||     ||       || "<<endl;
                cout<<" ||     ||     ||      ||      ||  |    ||     ||||||     "<<endl;
                cout<<" ||     ||     ||      ||      ||    |  ||     ||         "<<endl;
                cout<<" ||     ||     ||      ||      ||     | ||     ||       || "<<endl;
                cout<<" ||     ||     ||      ||      ||      |||     ||       ||"<<endl;
                cout<<" ||||||||       ||||||||       ||       ||      |||||||||"<<endl<<endl<<endl;
                break;

            }
            if(delta[robot.stare][evenim] == 15)
                robot.stare=0;
            else
                robot.stare=delta[robot.stare][evenim];
            cout<<"------------------------------------------------------------------";
            afis_asp(robot);

            cout<<endl<<"Starea in care se afla robotul este : "<<stari[robot.stare].nume<<endl<<endl;

            cout<<endl;
            cout<<"------------------------------------------------------------------"<<endl;
        }
        else
        {
            cout<<evenimente[0].den<<endl;
            cout<<"Daca doriti sa introduceti alt eveniment tastati DA in caz contrar NU :"<<endl;
            cin>>raspuns;
            if(strcmp(raspuns,"DA")==0)
            {
                cout<<"Introduceti un alt eveniment : "<<endl;
                cin>>evenim;
            }

        }

        }
        if(strcmp(mod,"Variabile")==0)
        {
            int copy_stare =robot.stare;
            cout<<"Din aceasta stare se pot schimba doar urmatoarele variabile"<<endl;
            int nr=afis_variante(matr_adiacenta,Comb_var,robot.stare);
            if(nr!=0)
            {
            cin>>var;
            cout<<"Introduceti ";
            cout<<Comb_var[var];

            if(var !=1 && var!=2)
                cin>>var1;
            else
                cin>>var1>>var2;
            if(var == 0) robot.dist_obst_fata=var1;
            if(var == 1)
            {
                robot.dis_obst_stanga=var2;
                robot.dist_obst_fata=var1;
            }
            if(var == 2)
            {
                robot.dist_obst_dreapta=var2;
                robot.dist_obst_fata=var1;
            }
            if(var == 3) robot.dis_sol=var1;
            if(var == 4) robot.nivel_sac=var1;
            if(var == 5) robot.nivel_baterie=var1;
            if(var == 6) robot.nivel_termic=var1;

            verificare=0;

            if(robot.stare == 1)
            {
                if(robot.dist_obst_fata <=2)
                {
                    if(robot.dist_obst_dreapta <=2 || robot.dis_obst_stanga <=2)
                    {
                        int stare_noua=6;
                        evenim=returnare_eveniment(delta,robot.stare,stare_noua);
                        cout<<"Se intampla evenimentul : "<<evenimente[evenim].den<<endl;
                        robot.stare=delta[robot.stare][evenim];
                        verificare=1;//Daca robotul a realizat deja o tranzitie dintr-o stare in alta sa nu se mai efecueze celelalte verificari
                    }
                    else
                    {
                        int stare_noua=3;
                        evenim=returnare_eveniment(delta,robot.stare,stare_noua);
                        cout<<"Se intampla evenimentul : "<<evenimente[evenim].den<<endl;
                        robot.stare=3;
                        verificare=1;

                    }

                }
                else
                {
                    if(robot.dis_sol > 4)
                    {
                        int stare_noua=14;
                        evenim=returnare_eveniment(delta,robot.stare,stare_noua);
                        cout<<"Se intampla evenimentul : "<<evenimente[evenim].den<<endl;
                        robot.stare=delta[robot.stare][evenim];
                        verificare=1;
                    }
                    else
                    {
                        if(robot.nivel_baterie <=10)
                        {
                            int stare_noua=9;
                            evenim=returnare_eveniment(delta,robot.stare,stare_noua);
                            cout<<"Se intampla evenimentul : "<<evenimente[evenim].den<<endl;
                            robot.stare=delta[robot.stare][evenim];
                            verificare=1;
                        }
                        else if(robot.nivel_sac >=90)
                        {
                            int stare_noua=11;
                            evenim=returnare_eveniment(delta,robot.stare,stare_noua);
                            cout<<"Se intampla evenimentul : "<<evenimente[evenim].den<<endl;
                            robot.stare=delta[robot.stare][evenim];
                            verificare=1;
                        }
                    }
                }

            }
            if(robot.stare==3 && verificare!=1)
            {
                if(robot.nivel_termic >= 25)
                {
                    int stare_noua=4;
                    evenim=returnare_eveniment(delta,robot.stare,stare_noua);
                    cout<<endl<<"Se intampla evenimentul : "<<evenimente[evenim].den<<endl;
                    robot.stare=4;
                    verificare=1;
                }
                else
                {
                    int stare_noua=5;
                    evenim=returnare_eveniment(delta,robot.stare,stare_noua);
                    cout<<endl<<"Se intampla evenimentul : "<<evenimente[evenim].den<<endl;
                    robot.stare=delta[robot.stare][evenim];
                    verificare=1;
                }

            }
            if(robot.stare==5 && verificare!=1)
            {
                if(robot.dist_obst_fata > 2)
                {
                    int stare_noua=4;
                    evenim=returnare_eveniment(delta,robot.stare,stare_noua);
                    cout<<endl<<"Se intampla evenimentul : "<<evenimente[evenim].den<<endl;
                    robot.stare=delta[robot.stare][evenim];
                    verificare=1;
                }
            }
            if(robot.stare==4 && verificare!=1)
            {
                if(robot.nivel_termic < 25)
                {
                    int stare_noua=1;
                    evenim=returnare_eveniment(delta,robot.stare,stare_noua);
                    cout<<endl<<"Se intampla evenimentul : "<<evenimente[evenim].den<<endl;
                    robot.stare=delta[robot.stare][evenim];
                    robot.dist_obst_fata=100;
                    verificare=1;
                }
                else
                {
                    int stare_noua=12;
                    evenim=returnare_eveniment(delta,robot.stare,stare_noua);
                    cout<<endl<<"Se intampla evenimentul : "<<evenimente[evenim].den<<endl;
                    robot.stare=delta[robot.stare][evenim];
                    verificare=1;
                }
            }
            if(robot.stare==12 && verificare!=1)
            {
                if(robot.nivel_termic < 25)
                {
                    int stare_noua=1;
                    evenim=returnare_eveniment(delta,robot.stare,stare_noua);
                    cout<<endl<<"Se intampla evenimentul : "<<evenimente[evenim].den<<endl;
                    robot.stare=delta[robot.stare][evenim];
                    robot.dist_obst_fata=100;
                    verificare=1;
                }
                else
                {
                    int stare_noua=13;
                    evenim=returnare_eveniment(delta,robot.stare,stare_noua);
                    cout<<endl<<"Se intampla evenimentul : "<<evenimente[evenim].den<<endl;
                    robot.stare=delta[robot.stare][evenim];
                    verificare=1;
                }
            }
            if(robot.stare==13 && verificare!=1 )
            {
                if(robot.dist_obst_fata > 2)
                {
                    int stare_noua=1;
                    evenim=returnare_eveniment(delta,robot.stare,stare_noua);
                    cout<<endl<<"Se intampla evenimentul : "<<evenimente[evenim].den<<endl;
                    robot.stare=delta[robot.stare][evenim];
                    verificare=1;
                }
            }
            if(robot.stare==11)
            {
                if(robot.nivel_sac == 0)
                {
                    int stare_noua=1;
                    evenim=returnare_eveniment(delta,robot.stare,stare_noua);
                    cout<<endl<<"Se intampla evenimentul : "<<evenimente[evenim].den<<endl;
                    robot.stare=delta[robot.stare][evenim];
                    verificare=1;
                }
            }
            if(robot.stare==9 && verificare!=1)
            {
                if(robot.nivel_baterie == 100)
                {
                    int stare_noua=1;
                    evenim=returnare_eveniment(delta,robot.stare,stare_noua);
                    cout<<endl<<"Se intampla evenimentul : "<<evenimente[evenim].den<<endl;
                    robot.stare=delta[robot.stare][evenim];
                    verificare=1;
                }
            }
            if(robot.stare==14 && verificare!=1)
            {
                if(robot.dis_sol <=4 )
                {
                    int stare_noua=1;
                    evenim=returnare_eveniment(delta,robot.stare,stare_noua);
                    cout<<endl<<"Se intampla evenimentul : "<<evenimente[evenim].den<<endl;
                    robot.stare=delta[robot.stare][evenim];
                    verificare=1;
                }
            }
            if(copy_stare == robot.stare)
            {
                cout<<"Robotul ramane in starea de "<<stari[robot.stare].nume;
            }
            else
            {
                cout<<"Noua stare a robtului este "<<stari[robot.stare].nume<<endl;
                afis_asp(robot);
            }
        }

        }
        cout<<"\nVa rugam sa alegeti modul in care doriti sa treceti la o noua stare  : \n1.Evenimente\n2.Variabile \n3.Termiare (pentru a incheia simularea)\n";
        cin>>mod;
    }
    return 0;
}
