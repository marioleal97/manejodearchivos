#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

//using namespace std;
//int tobin(int numero);
//int main()
//{
//    string texto;
//    int binario[1500]={},longitud=0,ascii;
//    cout<<"Ingrese un texto<<"<<endl;
//    getline(cin,texto);
//    longitud=texto.length();
//    for(int i=0;i<longitud;i++){
//        ascii=texto[i];
//        binario[i]=tobin(ascii);
//        cout<<binario[i]<<endl;
//    }


//    char nombre[12]={},texto[50]={};
//    cout <<"Ingrese texto a guardar "<<endl;
//    cin.get(texto,50);
//    cout<<"Ingrese nombre del archivo"<<endl;cin>>nombre;
//    ifstream fin;
//    ofstream fout;
//    fout.open(nombre);
//    fout<<texto;
//    fout.close();



//    return 0;
//}
int tobin(int numero){
    int residuo, base=1, binario = 0;
    while(numero > 0){
        residuo = numero%2;
        binario = binario + residuo*base;
        numero = numero/2;
        base = base*10;
    }
    return binario;
}
