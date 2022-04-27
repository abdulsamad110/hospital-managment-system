#include <iostream>
#include <conio.h>
#include <string>
#include "Patient.h"
#include "Doctor.h"

using namespace std;

void main()
{
	Patient object1;
	Doctor object2;
	char choice;
	while (1)
	{
		system("cls");
		cout << "\t\t\tHospital Management System\n\n\n";
		cout << "\t1. Add Patient\n";
		cout << "\t2. View Patient Data\n";
		cout << "\t3. Edit Patient Record\n";
		cout << "\t4. View All Patient\n";
		cout << "\t5. View Doctor Details\n";
		cout << "\t6. Edit Doctor Record\n";
		cout << "\t7. Discharge patient\n";
		cout << "\t8. Exit\n";
		cout << "\n\n\tEnter your choice: ";

		do
		{
			choice = _getch();
			if (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6' && choice != '7' && choice != '8')
			{
				cout << "\n\tWrong Input....!\n\tEnter again : ";
			}
		} while (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6' && choice != '7' && choice != '8');

		switch (choice)
		{
		case '1':
			object1.addNewPatient();
			break;
		case '2':
			object1.patientData();
			break;
		case '3':
			object1.editRecord();
			break;
		case '4':
			object1.viewAllPatient();
			break;
		case '5':
			object2.DoctorRecord();
			break;
		case '6':
			object2.editDetail();
			break;
		case '7':
			object1.discharge();
			break;
		case '8':
			exit(0);
			break;
		}
	}

	_getch();
}