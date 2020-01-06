#include <iostream>


#include<fstream>
using namespace std;

int menu();
void agregar();
void contacto();

int main()
{
	int a;
	int opcion=menu();
	
	while(opcion!=0){
		
		switch(opcion){
			
			case 1:{
				agregar();
					
				break;
			}
			
			case 2:{
				contacto();
						
				break;
			}
		}
				opcion = menu();

	}
    return 0;
}

int menu(){
	
	int op = -2;
	while ((op < 0) || (op > 2)) {
		cout << "1 - Agregar Contacto" << endl;
		cout << "2 - Ver lista de contactos" << endl;
		cout << "0 - Salir" << endl;
		cout << "Opcion: " << endl;
		cin >> op;
		if ((op < 0) || (op > 2)) {
			cout << "¡ Opcion no valida!" << endl;
		}
	}
	return op;
	
}

void agregar(){
	string nombre;
    string apellido;
    int edad;
    char r;
    ofstream archivoprueba;
    string nombrearchivo;
    cout << "Ingrese nombre del archivo: ";
    getline(cin,nombrearchivo);

    archivoprueba.open(nombrearchivo.c_str(),ios::out);
    do
    {
        cout << "\tIngrese el nombre ";
        getline(cin, nombre,'\n');
        cout << "\tIngrese el apellido ";
        getline(cin, apellido,'\n');
        cout << "\tIngrese la edad ";
        cin>> edad;
        archivoprueba<<nombre<<" "<< apellido << " "<< edad<< "\n";
        cout << "Desea ingresar otro contacto s/n: ";
        cin >> r;
        cin.ignore();
    }
    while(r=='s');

    archivoprueba.close();
	
}

void contacto(){
	
	
	string nombre;
    string apellido;
    int edad;
    char r;
	
	ifstream archivolectura("contactos.txt");
    string texto;

    while(!archivolectura.eof())
    {

            archivolectura>> nombre>> apellido>> edad;


            if(!archivolectura.eof()){

            cout <<"Nombre: " << nombre << "\n";
            cout <<"Apellido: " << apellido << "\n";
            cout <<"Edad: "<< edad << "\n";

            }
            getline(archivolectura,texto);



    }
    archivolectura.close();
}


