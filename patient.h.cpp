#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Patient
{
private:
	string doc[5][8];
	string data[100][11];
	int roomNo;
	string read;
	int row;
	int column;
	string input;
	int num;
	char choice;
public:
	Patient()				//Constructor ----> Initialize all values with NULL
	{
		row = 0;
		column = 0;
		num = 1000;
		roomNo = 11;
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				data[i][j] = "-";
			}

		}

	}



	void addNewPatient()
	{
		system("cls");
		string str;
		int temp;
		int a;				// for age

		auto id = to_string(num);
		data[row][column] = id;
		cout << "\n\n\tThis Patient ID is : " << num << "\n";
		column++;

		cout << "\n\tEnter Patient Name : ";
		cin >> data[row][column];

		column++;


		cout << "\n\tEnter Phone Numeber : ";
		cin >> data[row][column];

		column++;

		do
		{
			cout << "\n\tEnter Age : ";
			cin >> data[row][column];
			a = stoi(data[row][column]);
			if (a < 0 || a>150)
			{
				cout << "\n\tWrong input....";
				cout << "\n\tEnter again : ";
			}
		} while (a < 0 || a>150);


		column++;

		cout << "\n\tEnter CNIC : ";
		cin >> data[row][column];

		column++;

		cout << "\n\tEnter Disease : ";
		cin >> data[row][column];

		column++;

		int count = 0;
		ifstream file;
		file.open("Doctor.txt");
		while (!file.eof())
		{
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					getline(file, read);
					doc[i][j] = read;
				}
			}
			break;
		}
		cout << "\n\t\tChoose Doctor. Available Doctors are\n";
		for (int i = 0; i < 5; i++)
		{
			if (doc[i][0] == "-")
			{
				break;
			}
			count++;
			cout << "\n\t\t" << i + 1 << ". " << doc[i][1] << "\t" << doc[i][6];

		}

		cout << "\n\n\t\tEnter your choice : ";
		int x;
		do
		{
			cin >> x;
			if (x > count || x <= 0)
			{
				cout << "\n\t\tWrong input\n";
				cout << "\t\tChoose again : ";
			}
		} while (x <= 0 || x > count);
		data[row][column] = doc[x - 1][1];
		column++;

		cout << "\n\tChoose Room Type";
		cout << "\n\t\t1. Ward Room\n\t\t2. Operation Theator\n\t\t3. ICU";
		cout << "\n\n\t\tEnter your choice : ";

		do
		{
			cin >> input;
			if (input != "1"&&input != "2" && input != "3")
			{
				cout << "\n\t\tWrong Input. Enter again : ";
			}
		} while (input != "1"&&input != "2" && input != "3");

		if (input == "1")
		{
			data[row][column] = "Ward Room";
			column++;
		}
		else if (input == "2")
		{
			data[row][column] = "Operation Theater";
			column++;
		}
		else
		{
			data[row][column] = "ICU";
			column++;
		}

		cout << "\n\n\tChoose care taker for patient";
		cout << "\n\t\t1. Ward Boy X\t\t2. Nurse U\n\t\t3. Ward Boy Y\t\t4. Nurse V\n\t\t5. Ward Boy Z\t\t6. Nurse W";
		cout << "\n\n\tChoose option : ";
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
			data[row][column] = "Ward Boy X";
			column++;
			break;
		case '2':
			data[row][column] = "Nurse U";
			column++;
			break;
		case '3':
			data[row][column] = "Ward Boy Y";
			column++;
			break;
		case '4':
			data[row][column] = "Nurse V";
			column++;
			break;
		case '5':
			data[row][column] = "Ward Boy Z";
			column++;
			break;
		case '6':
			data[row][column] = "Nurse W";
			column++;
			break;
		}

		auto room = to_string(roomNo);
		cout << "\n\nThe room number assigned to this patient is : " << roomNo;
		roomNo++;
		data[row][column] = room;
		column++;

		data[row][column] = "Admitted";					//Status

		row++;
		column = 0;
		num++;
		cout << "\n\n\t\t\tRecord Entered....!\n\n";
		system("pause");
	}


	void patientData()
	{
		string id;
		system("cls");
		cout << "\n\n\tEnter Patient ID : ";
		cin >> id;

		for (int i = 0; i < 100; i++)
		{
			if (id == data[i][0])
			{
				cout << "\n\n\tThis Patient ID is : " << data[i][0] << "\n";
				cout << "\tPatient Name : " << data[i][1] << "\n";
				cout << "\tPhone Numeber : " << data[i][2] << "\n";
				cout << "\tAge : " << data[i][3] << "\n";
				cout << "\tCNIC : " << data[i][4] << "\n";
				cout << "\tDisease : " << data[i][5] << "\n";
				cout << "\tDoctor Assigned : " << data[i][6] << "\n";
				cout << "\tRoom type : " << data[i][7] << "\n";
				cout << "\tCare taker : " << data[i][8] << "\n";
				cout << "\tRoom Number : " << data[i][9] << "\n";
				cout << "\tStatus : " << data[i][10] << "\n";
				cout << "\n";
				system("pause");
				return;
			}
		}
		cout << "\n\n\tEntry Not Found....!\n\n";
		system("pause");
		return;
	}

	void editRecord()
	{
		string id;
		system("cls");
		cout << "\n\n\tEnter Patient ID : ";
		cin >> id;

		for (int i = 0; i < 100; i++)
		{
			if (id == data[i][0] && data[i][10] == "Admitted")
			{
				cout << "\n\n\tThis Patient ID is : " << data[i][0] << "\n";
				cout << "\tPatient Name : " << data[i][1] << "\n";
				cout << "\tPhone Numeber : " << data[i][2] << "\n";
				cout << "\tAge : " << data[i][3] << "\n";
				cout << "\tCNIC : " << data[i][4] << "\n";
				cout << "\tDisease : " << data[i][5] << "\n";
				cout << "\tDoctor Assigned : " << data[i][6] << "\n";
				cout << "\tRoom type : " << data[i][7] << "\n";
				cout << "\tCare Taker : " << data[i][8] << "\n";
				cout << "\tRoom Number : " << data[i][9] << "\n";
				cout << "\tStatus : " << data[i][10] << "\n";
				cout << "\n";
				cout << "\t\tWhat you want to change\n\n";
				cout << "\t\t1. Name\t\t2. Phone\n\t\t3. Age\t\t4. CNIC\n\t\t5. Room type\t6. Room Number";

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
					cout << "\n\n\t\tEnter new Name : ";
					cin >> data[i][1];
					cout << "\n\n\t\tName has been changed....!\n";
					system("pause");
					break;
				case '2':
					cout << "\n\n\t\tEnter new Phone number : ";
					cin >> data[i][2];
					cout << "\n\n\t\tPhone number has been changed....!\n";
					system("pause");
					break;
				case '3':
					cout << "\n\n\t\tEnter new Age : ";
					cin >> data[i][3];
					cout << "\n\n\t\tAge has been changed....!\n";
					system("pause");
					break;
				case '4':
					cout << "\n\n\t\tEnter new CNIC : ";
					cin >> data[i][4];
					cout << "\n\n\t\tCNIC has been changed....!\n";
					system("pause");
					break;
				case '5':
					cout << "\n\n\t\tEnter new Room Type : ";
					cin >> data[i][7];
					cout << "\n\n\t\tRoom type has been changed....!\n";
					system("pause");
					break;
				case '6':
					cout << "\n\n\t\tEnter new Room Number : ";
					cin >> data[i][8];
					cout << "\n\n\t\tRoom Number has been changed....!\n";
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

	void viewAllPatient()
	{
		system("cls");
		int count = 0;
		cout << "\nID\tName\t\tDoctor Assign\t\tDisease\t\tStatus\n\n";
		for (int i = 0; i < 100; i++)
		{
			if (data[i][0] == "-")
			{
				break;
			}
			count++;
			cout << data[i][0] << "\t" << data[i][1] << "\t\t" << data[i][6] << "\t\t" << data[i][5] << "\t\t" << data[i][10] << endl << endl;
		}
		if (count == 0)
		{
			cout << "\n\n\tNo patient record....!\n\n";
		}
		system("pause");
	}

	void discharge()
	{
		string id;
		system("cls");
		cout << "\n\n\tEnter Patient ID : ";
		cin >> id;
		int days;
		int serviceTax = 300;
		int doctorFee;
		for (int i = 0; i < 100; i++)
		{
			if (id == data[i][0])
			{
				cout << "\n\n\tThis Patient ID is : " << data[i][0] << "\n";
				cout << "\tPatient Name : " << data[i][1] << "\n";
				cout << "\tPhone Numeber : " << data[i][2] << "\n";
				cout << "\tAge : " << data[i][3] << "\n";
				cout << "\tCNIC : " << data[i][4] << "\n";
				cout << "\tDisease : " << data[i][5] << "\n";
				cout << "\tDoctor Assigned : " << data[i][6] << "\n";
				cout << "\tRoom type : " << data[i][7] << "\n";
				cout << "\tCare taker : " << data[i][8] << "\n";
				cout << "\tRoom Number : " << data[i][9] << "\n";
				cout << "\tStatus : " << data[i][10] << "\n";
				cout << "\n";
				cout << "\n\t\tHow many days a patient stays in Hospital : ";
				cin >> days;
				if (data[i][6] == doc[0][1])
				{
					doctorFee = 5000;
				}
				else if (data[i][6] == doc[1][1])
				{
					doctorFee = 7000;
				}
				else if (data[i][6] == doc[1][1])
				{
					doctorFee = 3000;
				}
				else if (data[i][6] == doc[1][1])
				{
					doctorFee = 4000;
				}
				else
				{
					doctorFee = 2000;
				}

				cout << "\n\n\t\t\t==========================================================";
				cout << "\n\t\t\t\t\t\tHospital Bill\n";
				cout << "\t\t\t==========================================================";
				cout << "\n\n\t\t\tDays in Hospital (1 Day =500)\t\t\t" << days * 500;
				cout << "\n\t\t\tDoctor Fees\t\t\t\t\t" << doctorFee;
				cout << "\n\t\t\tService Tax\t\t\t\t\t" << serviceTax;
				cout << "\n\n\t\t\t==========================================================";
				cout << "\n\t\t\tTotal : \t\t\t\t\t" << (days * 500) + doctorFee + serviceTax;
				cout << "\n\t\t\t==========================================================";
				cout << "\n\n";
				data[i][10] = "Discharged";
				system("pause");
				return;
			}
		}
		cout << "\n\n\tEntry Not Found....!\n\n";
		system("pause");
		return;
	}
}; 
