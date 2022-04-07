#include <iostream>
#include <time.h>    
using namespace std;


void sistem_cagrisi(){
    cout<< "Sistem cagrisi yapiliyor..." << endl;
}

void sureci_baslat(){
    cout<< "Surec basliyor..." << endl;
}

void sureci_bitir(){
    cout<< "Surec sonlaniyor..." << endl;
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
    const int OLAY_SAYISI = 7;
    int OLAYLAR[OLAY_SAYISI];

    for(int i=0; i<OLAY_SAYISI; i++){
        OLAYLAR[i] = rand()%3;
    }
    
    for(int i=0; i<OLAY_SAYISI; i++){
        cout<< "Olay : " << OLAYLAR[i] << endl;
        olaylari_cagir(OLAYLAR[i]);
    }

}
