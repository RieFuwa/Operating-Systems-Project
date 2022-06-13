
#include<iostream>
#define OLAY_SAYISI 3

using namespace std;
 
void olaybeklemeSuresiBul(int OLAYLAR[], int n, int OLAY_SURESI[],
                                   int OLAY_BEKLEME_SURESI[], int OLAY_GELIS_ZAMANI[])
{
    int OLAY_BASLAMA_ZAMANI[OLAY_SAYISI];
    OLAY_BASLAMA_ZAMANI[0] = OLAY_GELIS_ZAMANI[0];
    OLAY_BEKLEME_SURESI[0] = 0;

    for (int i = 1; i < n ; i++)
    {
        OLAY_BASLAMA_ZAMANI[i] = OLAY_BASLAMA_ZAMANI[i-1] + OLAY_SURESI[i-1];
        OLAY_BEKLEME_SURESI[i] = OLAY_BASLAMA_ZAMANI[i] - OLAY_GELIS_ZAMANI[i];
    }
}

void olaygeridonusSuresiBul(int OLAYLAR[], int n, int OLAY_SURESI[],
                                      int OLAY_BEKLEME_SURESI[], int OLAY_GERI_DONUS_SURESI[])
{
    for (int i = 0; i < n ; i++)
        OLAY_GERI_DONUS_SURESI[i] = OLAY_SURESI[i] + OLAY_BEKLEME_SURESI[i];
}
 
void olayortalamaSureBul(int OLAYLAR[], int n, int OLAY_SURESI[], int OLAY_GELIS_ZAMANI[])
{
    int OLAY_BEKLEME_SURESI[OLAY_SAYISI], OLAY_GERI_DONUS_SURESI[OLAY_SAYISI];
    olaybeklemeSuresiBul(OLAYLAR, n, OLAY_SURESI, OLAY_BEKLEME_SURESI, OLAY_GELIS_ZAMANI);
    olaygeridonusSuresiBul(OLAYLAR, n, OLAY_SURESI, OLAY_BEKLEME_SURESI, OLAY_GERI_DONUS_SURESI);

    cout << "===Olaylar=== " << " ===Olay Suresi=== " << " ===Olay Gelis Zamani=== "
         << " ===Olay Bekleme Suresi=== " << " ===Olay Donme Suresi=== "
         << " ===Toplam Sure=== \n";
         
    int TOPLAM_BEKLEME_SURESI = 0, TOPLAM_GERI_DONUS_SURESI = 0;
    for (int i = 0 ; i < n ; i++)
    {
        TOPLAM_BEKLEME_SURESI = TOPLAM_BEKLEME_SURESI + OLAY_BEKLEME_SURESI[i];
        TOPLAM_GERI_DONUS_SURESI = TOPLAM_GERI_DONUS_SURESI + OLAY_GERI_DONUS_SURESI[i];
        int TOPLAM_SURE = OLAY_GERI_DONUS_SURESI[i] + OLAY_GELIS_ZAMANI[i];
        cout << " " << i+1 << "\t\t" << OLAY_SURESI[i] << "\t\t\t"
             << OLAY_GELIS_ZAMANI[i] << "\t\t\t" << OLAY_BEKLEME_SURESI[i] << "\t\t\t "
             << OLAY_GERI_DONUS_SURESI[i]  <<  "\t\t\t " << TOPLAM_SURE << endl;
    }
 
 cout << "\nOrtalama Donme Suresi = "
         << (float)TOPLAM_GERI_DONUS_SURESI / (float)n<<endl;
    cout << "Ortalama Bekleme Suresi = "
         << (float)TOPLAM_BEKLEME_SURESI / (float)n;
    
}
