#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
using namespace std;

class Doctor
{
private:
	string record[5][8];

	int row;
	int column;
	string input;
	int num;
	char choice;
public:
	Doctor()				//Constructor ----> Initialize all values with NULL
	{
		row = 5;
		column = 0;
		num = 1006;
		ifstream outfile("Doctor.txt");
		string temp;
		while (!outfile.eof())
		{
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					getline(outfile, temp);

					record[i][j] = temp;
				}
			}
			break;
		}
	}

	void DoctorRecord()
	{
		string id;
		system("cls");
		cout << "\n\n\tEnter Doctor's ID : ";
		cin >> id;

		ifstream file("Doctor.txt");
		while (!file.eof())
		{
			string temp;
			getline(file, temp);
			if (temp == id)
			{
				cout << "\n\n\tThis Doctors ID is : " << temp << "\n";
				getline(file, temp);
				cout << "\tDoctor's Name : " << temp << "\n";
				getline(file, temp);
				cout << "\tPhone Numeber : " << temp << "\n";
				getline(file, temp);
				cout << "\tAge : " << temp << "\n";
				getline(file, temp);
				cout << "\tCNIC : " << temp << "\n";
				getline(file, temp);
				cout << "\tQualification : " << temp << "\n";
				getline(file, temp);
				cout << "\tSpeciality : " << temp << "\n";
				getline(file, temp);
				cout << "\tDoctor's Fee : " << temp << "\n";

				cout << "\n";
				system("pause");
				return;
			}
		}
	}

	void editDetail()
	{
		string id;
		system("cls");
		cout << "\n\n\tEnter Doctor ID : ";
		cin >> id;

		for (int i = 0; i < 5; i++)
		{
			if (id == record[i][0])
			{
				cout << "\n\n\tThis Patient ID is : " << record[i][0] << "\n";
				cout << "\tDoctor Name : " << record[i][1] << "\n";
				cout << "\tPhone Numeber : " << record[i][2] << "\n";
				cout << "\tAge : " << record[i][3] << "\n";
				cout << "\tCNIC : " << record[i][4] << "\n";
				cout << "\tQualification : " << record[i][5] << "\n";
				cout << "\tSpeciality : " << record[i][6] << "\n";
				cout << "\tDoctor Fee : " << record[i][7] << "\n";

				cout << "\n";
				cout << "\t\tWhat you want to change\n\n";
				cout << "\t\t1. Phone\t2. Age\n\t\t3. CNIC\t\t4. Qualification\n\t\t5. Speciality\t6. Doctor Fee";

				cout << "\n\n\t\tEnter your choice: ";

				do
				{
					choice = _getch();
					if (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6' && choice)
					{
						cout << "\n\tWrong Input....!\n\tEnter again : ";
					}
				} while (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6' && choice);

				switch (choice)
				{
				case '1':
					cout << "\n\n\t\tEnter new Phone : ";
					cin >> record[i][2];
					cout << "\n\n\t\tPhone number has been changed....!\n";
					system("pause");
					break;
				case '2':
					cout << "\n\n\t\tEnter new Age : ";
					cin >> record[i][3];
					cout << "\n\n\t\tAge has been changed....!\n";
					system("pause");
					break;
				case '3':
					cout << "\n\n\t\tEnter new CNIC : ";
					cin >> record[i][4];
					cout << "\n\n\t\tCNIC has been changed....!\n";
					system("pause");
					break;
				case '4':
					cout << "\n\n\t\tEnter new Qualification : ";
					cin >> record[i][5];
					cout << "\n\n\t\tQualification has been changed....!\n";
					system("pause");
					break;
				case '5':
					cout << "\n\n\t\tEnter new Speciality : ";
					cin >> record[i][6];
					cout << "\n\n\t\tSpeciality has been changed....!\n";
					system("pause");
					break;
				case '6':
					cout << "\n\n\t\tEnter new Doctor Fee : ";
					cin >> record[i][7];
					cout << "\n\n\t\tDoctor Fee has been changed....!\n";
					system("pause");
					break;
				}
				return;
			}
			
		}
		cout << "\n\n\tEntry Not Found....!\n\n";
		system("pause");
		return;
	}

	
};

