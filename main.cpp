#include <iostream>
#include <ctime>
#include<conio.h>
#include<stdio.h>
#include<math.h>


using namespace std;

int main()
{

    void disparo_acertadoen_base_defensora();
    void disparo_acertadoen_base_atacante();
    void disparo_acertadoen_en_la_bala_atacante();
    int election=1;
    while (election!=0)
    {
        cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout <<"generar 3 disparos que den en el cañon defensivo=1\n"
             <<" generar 3 diaparos defensivos capaz de hacerle daño al cañon enemigo=2\n"
             <<"generar 3 disparos que intercepten la bala enemiga=3\n"
             <<"generar 3 disáros que le den a la bala enemiga pero que no le hagan daño a ninguno de los 2=4\n"
             <<"salir del programa=0\n"
             <<endl;
        cin >>election;
        if(election==1)
        {
            for (int x=0;x<3;x++)
            {
                disparo_acertadoen_base_defensora();
            }

        }
        else if (election==2)
        {
            for (int x=0;x<3;x++)
            {
                disparo_acertadoen_base_atacante();
            }
        }
        else if (election==3)
        {
            disparo_acertadoen_en_la_bala_atacante();
        }
        else
        {
            cout <<"eleccion invalida";
        }
    }

}


void disparo_acertadoen_base_defensora()
{
    //esta funion averiagua la velociad necesaria para que un disparo de en su objetivo (disparo atacante)
    // ninguna de las cariables puede pasar 3.4 x 10^38(6 dec) por que seria imposible para el programa entenderlas
    float d;
    float h;
    float h2;
    float ang;
    float a=9.81;
    cout <<"ingrese la distancia horizontal que hay entre ambos cañones(en metros)"<<endl;
    cin >> d;
    cout <<"ingrese la distancia vertical que hay el cañon atacante y el mar(en metros)"<<endl;
    cin >> h;
    cout <<"ingrese la distancia vertical que hay el cañon defensor y el mar(en metros)"<<endl;
    cin >>h2;
    h-=h2;
    cout <<"ingrese el angulo que se unsara en el cañon atacante(en radianes)"<<endl;
    cin >>ang;
    float t_lim =sqrt((d*tan(ang)+h)/(a/2));

    float VD=d/(cos(ang)*t_lim);
    cout << "ese disparo seria posible con la rapidez="<<VD<<endl;
}
void disparo_acertadoen_base_atacante()
{
    //esta funion averiagua la velociad necesaria para que un disparo de en su objetivo (disparo defensor)
    // ninguna de las cariables puede pasar 3.4 x 10^38(6 dec) por que seria imposible para el programa entenderlas
    float d;
    float h;
    float h2;
    float ang;
    float a=9.81;
    cout <<"ingrese la distancia horizontal que hay entre ambos cañones(en metros)"<<endl;
    cin >> d;
    cout <<"ingrese la distancia vertical que hay el cañon atacante y el mar(en metros)"<<endl;
    cin >> h;
    cout <<"ingrese la distancia vertical que hay el cañon defensor y el mar(en metros)"<<endl;
    cin >>h2;
    h-=h2;
    cout <<"ingrese el angulo que se unsara en el cañon defensor(en radianes)"<<endl;
    cin >>ang;
    float t_lim =sqrt((d*tan(ang)-h)/(a/2));
    float VD=d/(cos(ang)*t_lim);
    cout << "ese disparo seria posible con la rapidez="<<VD<<endl;
}
void disparo_acertadoen_en_la_bala_atacante()
{
    //esta funion averiagua la velociad necesaria para que un disparo de en su objetivo (disparo atacante)
    // ninguna de las cariables puede pasar 3.4 x 10^38(6 dec) por que seria imposible para el programa entenderlas
    float d;
    float h;
    float h2;
    float angD;
    float angO;
    float a=9.81;
    cout <<"ingrese la distancia horizontal que hay entre ambos cañones(en metros)"<<endl;
    cin >> d;
    cout <<"ingrese la distancia vertical que hay el cañon atacante y el mar(en metros)"<<endl;
    cin >> h;
    cout <<"ingrese la distancia vertical que hay el cañon defensor y el mar(en metros)"<<endl;
    cin >>h2;
    h-=h2;
    cout <<"ingrese el angulo que se unsara en el cañon defensor(en radianes)"<<endl;
    cin >>angD;
    cout <<"ingrese el angulo que se unsara en el cañon atacante(en radianes)"<<endl;
    cin >>angO;
    //se averigua la velocidad y el tiempo necesario para intervceptar el cañon defensor
    float t_lim =sqrt((d*tan(angO)+h)/(a/2));
    float VO=d/(cos(angO)*t_lim);
    t_lim -=2.5;

    if(t_lim>0)
    {
        //imprementacion de 2 for que por medio de busqueda
        //por fuerza bruta encuentran la velocidad necesaria para interceptar la bala


        float VD=0;
        for(char se_encontro='0';VD<10000;VD+=0.1)
        {
            for(float t=0;t<t_lim;t+=0.01)
            {
                float xD=VD*cos(angD)*t;
                float yD=VD*sin(angD)*t-4.905*pow(t,2);
                float xO=-VO*cos(angO)*(t+2.5)+d;
                float yO=VO*sin(angO)*(t+2.5)-4.905*pow(t+2.5,2)+h;
                if (sqrt(pow(xD-xO,2)+pow(yO-yD,2))<.025*d)
                {
                    cout <<"la rapidez necesaria para que el canhonaso defensor intersepte al canhonado ofensor es= " << VD <<endl;
                    se_encontro='1';
                    break;
                }

            }
            if(se_encontro=='1')
            {
                break;
            }
        }
    }
    else
    {
        cout <<"bala imposible de esquivar"<<endl;
    }


}



