#include <iostream>
#include <string>

using namespace std;

int main() {
	//declarar las variables

	int opcion; // casos
	struct cita {

		string nombre, apellido, mes, tratamiento; // guardar nombres
		 //para poder acceder al menu
		int dia, hora, preciou, cantidad, preciotrat; //guardar numeros
	}datos[100];
	int num; //numero de citas
	int nuev; //confirmar nueva cita
	int salir;
	int menu=1;
	cout << "-BIENVENIDO A DENTAL SONRISAS: DONDE CUIDAMOS TU SONRISA-" << endl << endl;
	cout << "Ingrese la opcion que desee: " << endl << endl;

	while(menu==1) {
		cout << "-----MENU-----" << endl << endl;
		cout << "1. AGENDAR CITA" << endl; //opciones
		cout << "2. MODIFICAR CITA" << endl;
		cout << "3. ELIMINAR CITA" << endl;
		cout << "4. LISTA DE CITAS VIGENTES" << endl;
		cout << "5. LIMPIAR PANTALLA" << endl;
		cout << "6. SALIR" << endl << endl;
		cin >> opcion;
		cout << "------------------------" << endl;

		switch (opcion) {
		case 1:       //primer cita
			int menu;
			cout << "------AGENDAR CITA------" << endl << endl;
			cout << "Del 1 al 3 ingrese el numero de citas que desea hacer: " << endl;
			cin >> num;
			for (int i = 0; i < num; i++) {
				cout << "------CITA NUMERO " << i+1 << "------" << endl;
				cout << "\n-Ingrese su nombre : -" << endl;
				cin >> datos[i].nombre;
				cout << "-Ingrese su primer apellido : -" << endl;
				cin >> datos[i].apellido;
				cout << "\n-Ingrese el dia en que desee su cita: -" << endl;
				cin >> datos[i].dia;
				cout << "\n-Ingrese el nombre del mes en que desee su cita: -" << endl;
				cin >> datos[i].mes;
				cout << "\n-Ingrese el horario (24 hrs) en que desee su cita: -" << endl;
				cin >> datos[i].hora;
				cout << "\n-Ingrese su tratamiento: -" << endl;
				cin >> datos[i].tratamiento;
				cout << "\n-Ingrese el precio de su tratamiento: -" << endl;
				cin >> datos[i].preciotrat;
				cout << "\n-Ingrese la cantidad de su tratamiento: -" << endl;
				cin >> datos[i].cantidad;
			}
			break;

		case 2: //modificar cita
		case 3: //eliminar cita
		case 4: //lista de citas vigentes
			cout << "------LISTA DE CITAS VIGENTES------" << endl; 
			for (int i = 0; i < num; i++) {
				cout << "\n CITA #" << i + 1 << endl;
				cout << "\nNOMBRE:" << datos[i].nombre << " " << datos[i].apellido << endl;
				cout << "FECHA: " << datos[i].dia << " de " << datos[i].mes << endl;
				cout << "HORA:" << datos[i].hora << endl;
				cout << "TRATAMIENTO:" << datos[i].tratamiento << endl;
				cout << "PRECIO: $" << datos[i].preciotrat << endl;
				cout << "CANTIDAD: " << datos[i].cantidad << endl << endl;
				cout << "----------------" << endl;
			}
			break;
		case 5: // limpiar pantalla 
		case 6: //salir del sistema
			cout << "Desea salir del sistema? (1) Si (2) No" << endl;
			cin >> salir;
			if (salir == 1) return 0; //cierra el programa
			else cout << "Regresando al menu..." << endl << endl;
			break;
		default:
			cout << "Opcion no valida: regresando al menu..." << endl << endl;
		}
	}
	return 0;
}