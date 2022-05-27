#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <fstream>
#include<stdlib.h>
#include <vector>

using namespace std;

void archivos();
void citas();
void listas();
void eliminar();
void modificar();
int cita, * a, * subtotal, * num, * iva, * total, * b,* dia, *mes ,* hora; // a=precio, b== cantidad
int opcion, codigo , salir;
string* nombre, * descripcion, * tratamiento, *correo;
int main()
{
	do {
		int op;
		cout << "-BIENVENIDO A DENTAL SONRISAS: DONDE CUIDAMOS TU SONRISA-" << endl << endl;
		cout << "Ingrese la opcion que desee: " << endl << endl;
		cout << "-----MENU-----" << endl << endl;
		cout << "1. AGENDAR CITA" << endl;
		cout << "2. MODIFICAR CITA" << endl;
		cout << "3. ELIMINAR CITA" << endl;
		cout << "4. LISTA DE CITAS VIGENTES" << endl;
		cout << "5. LIMPIAR PANTALLA" << endl;
		cout << "6. SALIR" << endl;
		cout << "7. GUARDAR ARCHIVO TXT." << endl << endl;
		cin >> op;
		cout << "------------------------" << endl;

		switch (op)
		{
		case 1: //registrar cita
			citas();
			return main();
			break;

		case 2: //modificar cita
			modificar();
			return main();
			break;

		case 3: //eliminar cita
			eliminar();
			return main();
			break;


		case 4: //mostrar lista de citas
			listas();
			return main();
			break;

		case 5: //limpiar pantalla
			system("cls"); //system("clear");
			return main();
			break;

		case 6: //cerrar el sistema 
			cout << "-----SALIR DEL SISTEMA-----" << endl << endl;
			cout << "Desea salir del sistema? (1) Si (2) No" << endl;
			cin >> salir;
			if (salir == 1) return 0; //cierra el programa
			else cout << "Regresando al sistema..." << endl << endl;
			break;

		case 7: // guardar archivo txt
			archivos();
			return main();
			break;


		default: cout << "Opcion no valida: Regresando al menu..." << endl << endl;
		}
		cout << "Presione 1 para regresar al menu o 2 para salir del sistema" << endl;
		cin >> opcion;

	} while (opcion == 1);

	return 0;
}


void citas()
{

	cout << "------AGENDAR CITA------" << endl << endl;
	cout << "Ingrese el numero de citas que desea hacer: " << endl;
	cin >> cita;
	nombre = new string[cita];
	b = new int[cita];
	total = new int[cita];
	a = new int[cita];
	hora = new int[cita];
	dia = new int[cita];
	mes = new int[cita];
	subtotal = new int[cita];
	descripcion = new string[cita];
	tratamiento = new string[cita];
	num = new int[cita];
	for (int i = 0; i < cita; i++)
	{
		cout << "Ingrese su numero de cita" << endl;
		cin >> num[i];
		while (getchar() != '\n');
		cout << "Ingrese su nombre completo" << endl;
		getline(cin, nombre[i]);
		cout << "Ingrese el horario (24 hrs) en que desee su cita " << endl;
		cin >> hora[i];
		cout << "Ingrese el dia en que desea su tratamiento" << endl;
		cin >> dia[i];
		cout << "Ingrese el mes en que desea su tratamiento" << endl;
		cin >> mes[i];
		cout << "Ingrese el nombre del tratamiento" << endl;
		getline(cin, tratamiento[i]);
		cout << "Ingrese la descripcion del tratamiento" << endl;
		getline(cin, descripcion[i]);
		cout << "Ingrese el precio del tratamiento" << endl;
		cin >> a[i];
		cout << "Ingrese la cantidad de tratamiento" << endl;
		cin >> b[i];
		cout << "Ingrese su correo" << endl;
		cin >> correo[i];
		subtotal[i] = b[i] * a[i];
		total[i] = subtotal[i] + (subtotal[i] * 0, 16);
		cout << "El total es de " << total[i] << endl;
	}
}

void archivos()
{
	ofstream archivo;
	string nombrearchivo;
	int texto;
	string texto2;

	nombrearchivo = "altascita";

	archivo.open(nombrearchivo.c_str(), ios::out);

	if (archivo.fail())
	{
		cout << "ERROR NO SE PUDO CREAR EL ARCHIVO";
		exit(1);
	}

	archivo << "Nombre" << "\t";
	archivo << "Medicamento" << "\t";
	archivo << "Descripcion" << "\t";
	archivo << "Precio" << "\t";
	archivo << "Cantidad" << "\t";
	archivo << "Subtotal" << "\t";
	archivo << "Total" << "\n";

	for (int i = 0; i < cita; i++)
	{
		if (b[i] == 0)
		{

		}
		else
		{
			texto2 = nombre[i];
			archivo << texto2 << "\t" << "\t";
			texto2 = tratamiento[i];
			archivo << texto2 << "\t" << "\t";
			texto2 = descripcion[i];
			archivo << texto2 << "\t " << "\t";

			texto = a[i];
			archivo << texto << "\t " << "\t";
			texto = b[i];
			archivo << texto << "\t " << "\t";
			archivo << texto << " ";
			texto = total[i];
			archivo << texto << " ";
		}
	}


	archivo.close();
}


void listas()
{
	cout << "------LISTA DE CITAS VIGENTES------" << endl;
	for (int i = 0; i < cita; i++)
	{
		if (b[i] == 0)
		{
			cout << "REGISTRO ELIMINADO" << i + 1 << endl;
		}
		else
		{
			cout << "CITA # " << i + 1 << endl;
			cout << "NOMBRE: " << nombre[i] << endl;
			cout << "HORA: " << hora[i] << endl;
			cout << "FECHA:" << dia[i] << "de" << mes[i] << endl;
			cout << "TRATAMIENTO:" << tratamiento[i] << endl;
			cout << "DESCRIPCION:" << descripcion[i] << endl;
			cout << "SUBTOTAL:" << subtotal[i] << endl;
			cout << "TOTAL:" <<total[i] << endl;
			cout << "--------------------------" << endl;
		}
	}
}


void eliminar()
{
	cout << "------LISTA DE CITAS VIGENTES------" << endl;
	int j;
	cout << "Ingrese la cita que desee eliminar";
	cin >> j;
	j = j - 1;
	for (int i = j; i == j; i++)
	{
		cout << "Eliminando cita #" << j + 1 << endl;

		nombre[i] = " ";
		hora[i] = 0;
		tratamiento[i] = " ";
		descripcion[i] = " ";
		a[i] = 0;
		b[i] = 0;
		total[i] = 0;
	}
}

void modificar()
{
	cout << "------MODIFICAR CITA------" << endl;
	int i;
	int j, opcion;
	cout << "Ingrese el numero de citas que establecio al principio " << endl;
	cin >> i;

	cout << "Ingrese el numero de la cita que desee modificar";
	cin >> j;
	j = j - 1;
	cout << "Selecione la opcion que desea modificar:" << endl;
	cout << "1.NOMBRE" << endl;
	cout << "2.HORA" << endl;
	cout << "3.TRATAMIENTO" << endl;
	cout << "4.DESCRIPCION" << endl;
	cout << "5.PRECIO DE TRATAMIENTO" << endl;
	cout << "6.CANTIDAD DE TRATAMIENTO" << endl;
	cin >> opcion;

	switch (opcion)
	{
	case 1:
		for (i = j; i == j; i++)
		{
			while (getchar() != '\n');
			cout << "Ingrese el nuevo nombre" << endl;
			getline(cin, nombre[i]);
			break;

	case 2:
		for (int i = j; i == j; i++)
		{
			cout << "Ingrese el nuevo horario." << endl;
			cin >> hora[i];
		}
		break;

	case 3:
		for (i = j; i == j; i++)
		{
			while (getchar() != '\n');
			cout << "Ingrese el nuevo tratamiento" << endl;
			getline(cin, tratamiento[i]);
		}
		break;

	case 4:
		for (i = j; i == j; i++)
		{
			while (getchar() != '\n');
			cout << "Ingrese la nueva descripcion del tratamiento" << endl;
			getline(cin, descripcion[i]);
		}

	case 5:
		for (int i = j; i == j; i++)
		{
			cout << "Ingrese el nuevo precio del tratamiento" << endl;
			cin >> a[i];
		}
		break;

	case 6:
		for (int i = j; i == j; i++)
		{
			cout << "Ingrese la nueva cantidad del tratamiento" << endl;
			cin >> b[i];
		}
		break;

	default:
		cout << "Opcion no valida" << endl;
		}


	}

}