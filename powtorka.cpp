// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

double mediana(int tab[], int n){
    for(int i = 0; i<n-1; i++){
        for(int j = 0; j<n-i-1; j++){
            if(tab[j] > tab[j+1]){
                int temp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = temp;
            }
        }
    }
    
    if(n % 2 == 0){
        return (tab[n/2-1] + tab[n/2])/2.0;
    }
    else{
        return (tab[n/2]);
    }
};

void losowanieLiczb(int tablicaLosowych[], int l){
    srand(time(NULL));
    for(int i = 0; i<l; i++){
        tablicaLosowych[i] = rand()%100+1;
    }
    
    for(int i = 0; i<l; i++){
        cout<<tablicaLosowych[i]<<" | ";
    }
};

int dominanta(int liczby[], int dlugosc){
    int najwLicznik = 0;
    int dominujaca = -1;
    
    for(int i = 0; i<dlugosc; i++){
        int licznik = 0;
        for(int j = 0; j<dlugosc; j++){
            if(liczby[j] == liczby[i]){
                licznik++;
            }
        }
        if(licznik > najwLicznik){
            najwLicznik = licznik;
            dominujaca = liczby[i];
        }
        else if(licznik == najwLicznik && dominujaca != liczby[i]){
            dominujaca = -1;
        }
        
    }
    if(najwLicznik == 1){
        return -1;
    }
    
    return dominujaca;
    
};

void sortowaniePrzezWstawianie(int tablicaDanych[], int dl){
    for(int i = 1; i<dl; i++){
        int a = tablicaDanych[i];
        int j = i - 1;
        while(j >= 0 && tablicaDanych[j] > a){
            tablicaDanych[j+1] = tablicaDanych[j];
            j--;
        }
        tablicaDanych[j+1] = a;
    }
    for(int i = 0; i<dl; i++){
        cout<<tablicaDanych[i]<<endl;
    }
};

int wyszukiwanieBinarne(int liczbyTab[], int szukana, int n){
    int poczatek = 0;
    int koniec = n-1;
    
    while(poczatek <= koniec){
        int srodek = poczatek + (koniec - poczatek)/2;
        if(liczbyTab[srodek] == szukana){
            return srodek;
        }
        if(liczbyTab[srodek] < szukana){
            poczatek = srodek+1;
        }
        else{
            koniec = srodek-1;
        }
    }
    return -1;
};

void sortowaniePrzezWybor(int daneTablica[], int dlugoscTab){
    for(int i = 0; i<dlugoscTab-1; i++){
        int najmIndeks = i;
        for(int j = i+1; j<dlugoscTab; j++){
            if(daneTablica[j] < daneTablica[najmIndeks]){
                najmIndeks = j;
            }
        }
        if(najmIndeks != i){
            int temp = daneTablica[najmIndeks];
            daneTablica[najmIndeks] = daneTablica[i];
            daneTablica[i] = temp;
        }
    }
    for(int i = 0; i<dlugoscTab; i++){
        cout<<daneTablica[i]<<endl;
    }
};

int main() {
    int n = 0;
    int* tablicaLiczb;
    int* tab;
    int tabulator[] = {3,8,9,1,6,20,23};
    
    cout<<"Wprowadź ilość liczb w tablicy: ";
    cin>>n;
    
    tablicaLiczb = new int[n];
    tab = new int[n];
    losowanieLiczb(tablicaLiczb, n);
    //losowanieLiczb(tab, n);
    
    cout<<"\n";
    cout<<"Mediana tego zbioru liczb losowych: "<<mediana(tablicaLiczb, n)<<"\n";
    
    cout<<"\n Dominanta tych liczb: "<<dominanta(tablicaLiczb, n)<<endl;
    
    //sortowaniePrzezWstawianie(tab, n);
    
    cout<<"\n Wyszukana liczba binarnie została znaleziona na indeksie: "<<wyszukiwanieBinarne(tabulator, 20, sizeof(tabulator)/sizeof(tabulator[0]))<<endl;
    
    //sortowaniePrzezWybor(tabulator, 7);
    
    

    return 0;
}
