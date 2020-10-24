#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <stdalign.h>

using namespace std;

int main()
{//todo lo que necesito para el cajero
    ifstream leer;
    ofstream guardar,temp;
    int clave,opcion,bclave,Nclave,sueldo;
    char nombre[30];
    guardar.open("Fichero.txt",ios::app);
    while (true){
        cout<<"1.Guardar Registro\n2.Leer Registro\n3.Buscar Registro\n4.Eliminar Registro\n5.Modificar Registro"<<endl;
        cout<<"ingrese opcion: ";cin>>opcion;
        switch (opcion) {
        case 1:{
            cout<<"Ingrese un nombre: "<<endl;cin.getline(nombre,30);
            cout<<"Ingrese la Claves: "<<endl;cin>>clave;
            cout<<"Ingrese el sueldo: "<<endl;cin>>sueldo;
            guardar<<nombre<<","<<clave<<","<<sueldo<<endl;
            system("pause");
            system("CLS");
            break;
        }
        case 2:{
            leer.open("Fichero.txt");
            char linea[100];
            leer.getline(linea,sizeof(linea));
            while(!leer.eof()){
                for(int i=0;i<3;i++){
                    char *puntero;
                    if(i==0){
                        puntero=strtok(linea,",");
                        strcpy(nombre,puntero);
                    }
                    if(i==1){
                        puntero=strtok(NULL,",");
                        clave=atoi(puntero);
                    }
                    if(i==2){
                        puntero=strtok(NULL,",");
                        sueldo=atoi(puntero);
                    }
                }
                cout<<"Nombre: "<<nombre<<endl;
                cout<<"Clave: "<<clave<<endl;
                cout<<"Sueldo: "<<sueldo<<endl;
                cout<<endl;
                leer.getline(linea,sizeof(linea));

            }
            leer.close();
            system("pause");
            system("CLS");
            break;
        }
        case 3:{
            bool encontrado=false;
            leer.open("Fichero.txt");
            leer>>nombre;
            cout<<"ingrese clave a buscar: "<<endl;cin>>bclave;
            while(!leer.eof()){
                leer>>clave>>sueldo;
                if(bclave==clave){
                    encontrado=true;
                    cout<<"Nombre: "<<nombre<<endl;
                    cout<<"Clave: "<<clave<<endl;
                    cout<<"Sueldo: "<<sueldo<<endl;
                    cout<<endl;
                }
                leer>>nombre;
            }
            if(!encontrado) cout<<"El registro no existe."<<endl;
            leer.close();
            system("pause");
            system("CLS");
            break;
        }
        case 4:{
            bool encontrado=false;
            leer.open("Fichero.txt");
            temp.open("Temp.txt");
            leer>>nombre;
            cout<<"ingrese clave a eliminar: "<<endl;cin>>bclave;
            while(!leer.eof()){
                leer>>clave>>sueldo;
                if(bclave==clave){
                    encontrado=true;
                    cout<<"Nombre: "<<nombre<<endl;
                    cout<<"Clave: "<<clave<<endl;
                    cout<<"Sueldo: "<<sueldo<<endl;
                    cout<<endl;
                    cout<<"Eliminado"<<endl;
                }
                else temp<<nombre<<" "<<clave<<" "<<sueldo<<endl;
                leer>>nombre;
            }
            if(!encontrado) cout<<"El registro no existe."<<endl;
            leer.close();
            temp.close();
            guardar.close();
            remove("Fichero.txt");
            rename("Temp.txt","Fichero.txt");
            guardar.open("Fichero.txt",ios::app);
            system("pause");
            system("CLS");

            break;
        }
        case 5:{
            bool encontrado=false;
            leer.open("Fichero.txt");
            temp.open("Temp.txt");
            leer>>nombre;
            cout<<"ingrese clave de registro a modificar: "<<endl;cin>>bclave;
            while(!leer.eof()){
                leer>>clave>>sueldo;
                if(clave==bclave){
                    encontrado=true;
                    cout<<"Nombre: "<<nombre<<endl;
                    cout<<"Clave: "<<clave<<endl;
                    cout<<"Sueldo: "<<sueldo<<endl;
                    cout<<endl;
                    cout<<"Ingrese nueva clave: "<<endl;cin>>Nclave;
                    temp<<nombre<<" "<<Nclave<<" "<<sueldo<<endl;
                    cout<<"MODIFICADO"<<endl;
                }
                else temp<<nombre<<" "<<clave<<" "<<sueldo<<endl;
                leer>>nombre;
            }
            if(!encontrado) cout<<"El registro no existe."<<endl;
            leer.close();
            temp.close();
            guardar.close();
            remove("Fichero.txt");
            rename("Temp.txt","Fichero.txt");
            guardar.open("Fichero.txt",ios::app);
            system("pause");
            system("CLS");
            break;
        }

        }
    }
    return 0;
}

