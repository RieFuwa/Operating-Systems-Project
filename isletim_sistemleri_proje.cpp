#include <iostream>
#include <time.h>    
#include <thread>
#include <pthread.h>
#include "schedule.h"
#include <math.h>
#include <chrono>
#include <ctime>
#include <fstream>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
using namespace std;

void surec_y(){
    pid_t tid=gettid();
    auto start = chrono::system_clock::now();
    ofstream file_;
    file_.open("tum_olaylar.txt",ios_base::app);   
    file_<<"Surec Y baslatiliyor. ||";
    sleep(1);
    auto end = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end-start;
    file_ <<" Thread id:"<<tid<<" || "<<" Surec Y bitiyor."<<" || "<<" Gecen sure : "<<elapsed_seconds.count()<<"s"<<"\n";
    file_.close();
}

void surec_x(){
    pid_t tid=gettid();
    auto start = chrono::system_clock::now();
    ofstream file_;
    file_.open("tum_olaylar.txt",ios_base::app);
    file_ <<"Surec X baslatiliyor. ||";
    sleep(2);
    auto end = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end-start;
    file_ <<" Thread id:"<<tid<<" || "<<" Surec X bitiyor."<<" || "<<" Gecen sure : "<<elapsed_seconds.count()<<"s"<<"\n";
    file_.close();
}

void surec_z(){
    pid_t tid=gettid();
    auto start = chrono::system_clock::now();
    ofstream file_;
    file_.open("tum_olaylar.txt",ios_base::app);  
    file_<<"Surec Z baslatiliyor. ||";
    sleep(4);
    auto end = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end-start;
    file_ <<" Thread id:"<<tid<<" || "<<" Surec Z bitiyor."<<" || "<<" Gecen sure : "<<elapsed_seconds.count()<<"s"<<"\n";
    file_.close();
}

void *olaylari_cagir(void *SECIM){
    switch(*((int*)SECIM)){
    case 0:
    surec_y();
    break; 
    case 1:
    surec_x();
    break;
    case 2:
    surec_z();
    break; 
    };
    return NULL;
}

int main(){  
    int OLAY_SURESI[OLAY_SAYISI];
    int OLAY_GELIS_ZAMANI[OLAY_SAYISI];
    int TOPLAM_ZAMAN = 0;
    ofstream file_;
    file_.open("tum_olaylar.txt");  
    srand (time(NULL));
    int OLAYLAR[OLAY_SAYISI];
    pthread_t t1,t2,t3;
    pthread_t THREADS[OLAY_SAYISI] = {t1,t2,t3};

    for(int i=0; i<OLAY_SAYISI; i++){
        OLAYLAR[i] = rand()%3;      
    }

    for(int i=0; i<OLAY_SAYISI; i++){
        OLAY_GELIS_ZAMANI[i] = TOPLAM_ZAMAN;
        auto start = chrono::system_clock::now();
        pthread_create(&THREADS[i],NULL,olaylari_cagir,&OLAYLAR[i]);
        pthread_join(THREADS[i],NULL);
        auto end = chrono::system_clock::now();
        chrono::duration<double> elapsed_seconds = end-start;
        OLAY_SURESI[i] = round(elapsed_seconds.count());
        TOPLAM_ZAMAN += elapsed_seconds.count();        
        cout<<"Olay id: "<<OLAYLAR[i]<<":"<<" || "<<"Gecen sure: "<<elapsed_seconds.count()<<endl;
    }
    olayortalamaSureBul(OLAYLAR, OLAY_SAYISI, OLAY_SURESI, OLAY_GELIS_ZAMANI);

}
