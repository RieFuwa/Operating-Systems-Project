#include <iostream>
#include <time.h>    
#include <thread>
#include "schedule.h"
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
using namespace std;


void sistem_cagrisi(){
    cout<< "Sistem cagrisi yapiliyor..." << endl;
    Sleep(1000);
    cout<< "Sistem cagrisi yapiliyor.../bitti" << endl;
}

void sureci_baslat(){
    cout<< "Surec basliyor..." << endl;
    Sleep(1000);
    cout<< "Surec basliyor... /bitti" << endl;
}

void sureci_bitir(){
    cout<< "Surec sonlaniyor..." << endl;
    Sleep(1000);
    cout<< "Surec sonlaniyor.../bitti" << endl;
}

void olaylari_cagir(int SECIM){
    switch(SECIM){
    case 0:
    sureci_baslat();
    break; 
    case 1:
    sureci_bitir();
    break;
    case 2:
    sistem_cagrisi();
    break; 
    };
}

int main(){
    srand (time(NULL));
    int OLAYLAR[OLAY_SAYISI];
    thread THREADS[OLAY_SAYISI];

    for(int i=0; i<OLAY_SAYISI; i++){
        OLAYLAR[i] = rand()%3;
    }

    for(int i=0; i<OLAY_SAYISI; i++){
        THREADS[i] = thread(olaylari_cagir,OLAYLAR[i]);
        THREADS[i].join();
    }

    

    int OLAY_SURESI[] = {5, 9, 6, 8, 12, 4, 3};
 
    int OLAY_GELIS_ZAMANI[] = {0, 3, 6, 7, 10, 11, 13};
 
    olayortalamaSureBul(OLAYLAR, OLAY_SAYISI, OLAY_SURESI, OLAY_GELIS_ZAMANI);

}
