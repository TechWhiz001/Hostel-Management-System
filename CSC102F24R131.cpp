//--------------------------------------------------------------------------- Header files --------------------------------------------------------------------
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <windows.h>
#include <conio.h>

using namespace std;

//--------------------------------------------------------------------Functions ---------------------------------------------------------
void header();      // Display HMS
void admin();       // Display Administrator
void admin1();      // Display Manage record
void admin2();      // Display Accounts
void admin3();      // Display  lists
void applyHostel(); // Display  Apply hostel veiw
void userMenu();    // Display  hostelite

//--------------------Manage Records--> functions------
void addRecord(string AddSTname[], string AddStFatherName[], int AddSTMarks[], string AddSTCNIC[], string AddSTphoneNo[], bool addFlag[], int &addCounter, int &usersize, int apCounter);
void deleteRecord(string AddSTname[], string AddStFatherName[], int AddSTMarks[], string AddSTCNIC[], string AddSTphoneNo[], int assignRoom[], bool roomflag[], int &usersize, bool addFlag[], int removeRecord, int &addCounter, int &Rcounter, int &uCounter, bool uflag[], string username[], string password[]);
void updateRecord(string AddSTname[], string AddStFatherName[], int AddSTMarks[], string AddSTCNIC[], string AddSTphoneNo[], int assignRoom[], bool roomflag[], bool addFlag[], int addCounter, int editRecord, int Rcounter, int &usersize);
void RoomAssign(int assignRoom[], bool addFlag[], bool roomflag[], bool apFlag[], int addCounter, int &Rcounter, int &apCounter, int &usersize);
//-------------Accounts ---->Fumctions--------------
void CreatAccount(string username[], string password[], int assignRoom[], bool uflag[], int &uCounter, int addCounter, int &usersize, int Rcounter, int UpdateAccount);
void deleteAccount(string username[], string password[], int assignRoom[], bool roomflag[], bool uflag[], bool addFlag[], int &usersize, int removeAccount, int &uCounter, int addCounter, int Rcounter);
void updateAccount(string username[], string password[], int assignRoom[], bool uflag[], bool roomflag[], int UpdateAccount, int &uCounter, int addCounter, int &usersize, int Rcounter);
//--------------Lists ----->Functions-------------
void viewHosteliteApplications(string ApplySTname[], string ApplyStFatherName[], int ApplySTMarks[], string ApplySTCNIC[], string ApplySTphoneNo[], bool apFlag[], int apCounter, int &applysize);
void currentRecordList(int assignRoom[], string AddSTname[], string AddStFatherName[], int AddSTMarks[], string AddSTCNIC[], string AddSTphoneNo[], bool addFlag[], double HosteliteDues[], int addCounter, int usersize);
// Apply for hostel ---> functions-----------
void HostelInformation();
void applyHostelApplication(string ApplySTname[], string ApplyStFatherName[], int ApplySTMarks[], string ApplySTCNIC[], string ApplySTphoneNo[], bool apFlag[], int &apCounter, int &applysize);
// Hostelite------>Functions-----------
void veiwStatus(string username[], string password[], int assignRoom[], string AddSTname[], string AddStFatherName[], int AddSTMarks[], string AddSTCNIC[], string AddSTphoneNo[], double HosteliteDues[], bool uflag[], string pwd, string user, int addCounter, int &usersize);
void payDues(string username[], string password[], int assignRoom[], bool AssignDues[], bool uflag[], double payment, bool duesFlag[], string AddSTname[], double HosteliteDues[], string pwd, string user, int addCounter, int &usersize);
void saveCurrentRecordList(int assignRoom[], string AddSTname[], string AddStFatherName[], int AddSTMarks[], string AddSTCNIC[], string AddSTphoneNo[], bool addFlag[], double HosteliteDues[], int addCounter, int usersize);
void loadData(int assignRoom[], string AddSTname[], string AddStFatherName[], int AddSTMarks[], string AddSTCNIC[], string AddSTphoneNo[], bool addFlag[], bool roomflag[], int usersize, double HosteliteDues[], int &addCounter, int &Rcounter, bool AssignDues[]);
void applylistDataRecord(string ApplySTname[], string ApplyStFatherName[], int ApplySTMarks[], string ApplySTCNIC[], string ApplySTphoneNo[], bool apFlag[], int apCounter, int applysize);
void loadapplylistDataRecord(string ApplySTname[], string ApplyStFatherName[], int ApplySTMarks[], string ApplySTCNIC[], string ApplySTphoneNo[], bool apFlag[], int &apCounter, int applysize);
void loadAccountsRecord(string username[], string password[], string complain[], bool cmpFlag[], int usersize, int &uCounter, bool uflag[], int &cmpCounter);
void saveAccountsRecord(string username[], string password[], string complain[], bool cmpFlag[], int usersize, int uCounter, bool uflag[], int cmpCounter);

//-----------input validation for Student Name & Father Nmae------------
bool isAlphabet(string name)
{
    for (char c : name)
    {
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) && (c != ' ' || !((name[0] >= 'a' && name[0] <= 'z') || (name[0] >= 'A' && name[0] <= 'Z'))))
        { // allow alphabets and spaces and first character must be alphabet
            return false;
        }
    }
    return true;
}

//-----------input validation for Student Marks-----------
bool validMarks(int Marks)
{

    if (!(Marks >= 0 && Marks <= 400))
    { // allow alphabets and spaces
        return false;
    }

    return true;
}

//-----------input validation for Studrnt CNIC------------
bool checkValidCNIC(string Cnic)
{
    int digitCounter = 0;

    for (char c : Cnic)
    {
        if ((c >= '0' && c <= '9') && Cnic[0] == '3')
        {
            digitCounter++; // Count digits
        }
        else
        {
            return false; // Invalid character found
        }
    }

    // check the cnic contain  13 digits
    return digitCounter == 13;
}
//-----------input validation for Student Phone Number------------
bool checkValidContact(string phoneNo)
{
    int digitCounter = 0;

    for (char c : phoneNo)
    {
        if ((c >= '0' && c <= '9') && phoneNo[0] == '0' && phoneNo[1] == '3')
        {
            digitCounter++; // count digits
        }
        else
        {
            return false; // Invalid character found
        }
    }

    // check the phone no contain  11 digits
    return digitCounter == 11;
}
// This function is for colour the text on console
void setColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

//----------------------! Main Function !------------
int main()
{
    // ---------------------------daclaration ----------------------
    system("cls");
    ofstream currentRlist;
    ifstream currentRlistIn;

    int usersize = 100;
    string username[usersize];
    string password[usersize];
    bool uflag[usersize];
    string complain[usersize];
    bool cmpFlag[usersize];
    int applysize = 100;

    string ApplySTname[applysize];
    string ApplyStFatherName[applysize];
    string ApplySTphoneNo[applysize];
    int ApplySTMarks[applysize];
    string ApplySTCNIC[applysize];
    bool apFlag[applysize];
    string AddSTname[usersize];
    string AddStFatherName[usersize];
    string AddSTphoneNo[usersize];
    int AddSTMarks[usersize];
    string AddSTCNIC[usersize];
    bool addFlag[usersize];
    int assignRoom[usersize];
    bool roomflag[usersize];
    double HosteliteDues[usersize];
    bool duesFlag[usersize];
    bool AssignDues[usersize];

    //------------ Initializing the  arrays-----
    for (int i = 0; i < usersize; i++)
    {
        username[i] = "nv";
        password[i] = "nv";
        uflag[i] = false;

        AddSTname[i] = "nv";
        AddStFatherName[i] = "nv";
        AddSTphoneNo[i] = "nv";
        AddSTMarks[i] = 0;
        AddSTCNIC[i] = "nv";
        addFlag[i] = false;

        assignRoom[i] = 0;
        roomflag[i] = false;

        HosteliteDues[i] = 0.0;
        duesFlag[i] = false;
        AssignDues[i] = false;

        complain[i] = "nv";
        cmpFlag[i] = false;
    }
    //------------ Initializing Arrays for apply Students-------------
    for (int i = 0; i < applysize; i++)
    {
        ApplySTname[i] = "nv";
        ApplyStFatherName[i] = "nv";
        ApplySTphoneNo[i] = "nv";
        ApplySTMarks[i] = 0;
        ApplySTCNIC[i] = "nv";
        apFlag[i] = false;
    }

    int option = 0; // for selecting the switches menu
    string user = " ";
    string pwd = " ";
    int editRecord = 0;
    int removeRecord = 0;
    int paymentRecord = 0;
    int removeAccount = 0;
    int UpdateAccount = 0;
    int loggedInUserType = -20; // 1 for seneior wardon , 2 for apply for hostel ,3 for user
    int apCounter = 0;          // apply student counter
    int addCounter = 0;         // add student counter
    int Rcounter = 0;           // Room assign counter
    int uCounter = 0;           // username counter
    int cmpCounter = 0;         // complain counter
    int sortingTemp = 0;        // sorting Data variable
    double payment = 0.0;       // pay hostel dues
    int complainLength = 60;    // complain submission length

    int hostelFee = 0; // hostel fee
    int extraCharges = 0;
    bool roomFound = false; // temporary flag for finding room
    bool ispresent = true;

    cout.unsetf(ios::left);
    cout.unsetf(ios::right);
    loadapplylistDataRecord(ApplySTname, ApplyStFatherName, ApplySTMarks, ApplySTCNIC, ApplySTphoneNo, apFlag, apCounter, applysize);
    loadData(assignRoom, AddSTname, AddStFatherName, AddSTMarks, AddSTCNIC, AddSTphoneNo, addFlag, roomflag, usersize, HosteliteDues, addCounter, Rcounter, AssignDues);
    loadAccountsRecord(username, password, complain, cmpFlag, usersize, uCounter, uflag, cmpCounter);

    do
    {
        system("cls");
        header();
        setColor(14);
        cout << endl;
        cout << left << setw(30) << "\t\t\t\t\t\tChoose the desired option\n";
        cout << endl;
        //----------------main menu of HMS---------
        cout << endl;
        cout << left << setw(5) << ""
             << setw(30) << "\t\t\t\t\t\t1. Administrator Login" << setw(30) << "2. Apply for Hostel" << endl
             << endl;
        cout << left << setw(5) << ""
             << setw(30) << "\t\t\t\t\t\t3. Hostelite  Login" << setw(30) << "0. Exit" << endl;
        cout << endl;
        cout << "\t\t\t\t\t\t---------------------------------------------------------------------------" << endl;
        cout << endl;

        cout.unsetf(ios::left);
        cout.unsetf(ios::right);

        cout << "\t\t\t\t\t\t\t\t" << "\tChoose an option (0-3): ";

        while (true)
        {
            cin >> option;

            // Check if the input is valid
            if (cin.fail())
            {
                cin.clear();           // Clear the error
                cin.ignore(255, '\n'); // remove invalid input
                cout << "\t\t\t\t\t\t\t\tInvalid input!! Please enter a number between 0 and 3.\n";
            }
            else if (option < 0 || option > 3)
            {
                cout << "\t\t\t\t\t\t\t\tOption out of range! Please enter a number between 0 and 3.\n";
            }
            else
            {
                // correct  input
                break;
            }
        }

        cout << endl;
        cout << endl;

        // this switch for username or password
        switch (option)
        {
            // for senior warden
        case 1:
            cout << "\t\t\t\t\t\t Enter the username : ";
            cin >> user;
            cout << "\t\t\t\t\t\t Enter the password : ";
            cin >> pwd;
            if (user == "Admin" && pwd == "123")
            {
                loggedInUserType = 1;
            }
            else
            {
                loggedInUserType = -20;
            }
            break;

        case 2:
            //----------- FOR hostel apply
            if (option == 2)
            {
                loggedInUserType = 2;
            }
            else
            {
                loggedInUserType = -20;
            }
            break;

        case 3:
            // -----------For hostelite
            cout << "\t\t\t\t\t\t Enter the username : ";
            cin >> user;
            cout << "\t\t\t\t\t\t Enter the password : ";
            cin >> pwd;
            for (int k = 0; k < usersize; k++)
            {
                if (username[k] == user && password[k] == pwd)
                {
                    uflag[k] = true;
                    if (uflag[k] == true)
                    {
                        loggedInUserType = 3;
                        ispresent = false;

                        break;
                    }
                }
            }
            if (ispresent)
            {
                loggedInUserType = -20;
            }
            break;

        case 0:
            loggedInUserType = -30;
            setColor(2);
            cout << "\t------------------------------- Thank you for choosing our system!---------------------------";
            break;
        default:
            setColor(4);
            cout << "\t\t\t\t\t Invalid option............ ";
            Sleep(300);
            break;
        }
        if (loggedInUserType == 1) // seneior warden access
        {
            do
            {
                cout << endl;
                system("cls");
                header();

                admin();
                cout << endl;

                cout << "\t\t\t\t\t\t\t\t" << "\tChoose an option (0-4): ";

                while (true)
                {
                    cin >> option;

                    // Check if the input is valid
                    if (cin.fail())
                    {
                        cin.clear();           // Clear the error
                        cin.ignore(255, '\n'); // remove invalid input
                        cout << "\t\t\t\t\t\t\t\tInvalid input!! Please enter a number between 0 and 4.\n";
                    }
                    else if (option < 0 || option > 4)
                    {
                        cout << "\t\t\t\t\t\t\t\tOption out of range! Please enter a number between 0 and 4.\n";
                    }
                    else
                    {
                        // correct  input
                        break;
                    }
                }

                cout.unsetf(ios::left);
                cout.unsetf(ios::right);

                switch (option)
                {
                case 1:
                    do
                    {
                        cout << endl; // Manage Records
                        system("cls");
                        header();

                        admin1();
                        cout << endl;
                        cout << "\t\t\t\t\t\t\t\t" << "\tChoose an option (0-4): ";

                        while (true)
                        {
                            cin >> option;

                            // Check if the input is valid
                            if (cin.fail())
                            {
                                cin.clear();           // Clear the error
                                cin.ignore(255, '\n'); // remove invalid input
                                cout << "\t\t\t\t\t\t\t\tInvalid input! Please enter a number between 0 and 4.\n";
                            }
                            else if (option < 0 || option > 4)
                            {
                                cout << "\t\t\t\t\t\t\t\tOption out of range! Please enter a number between 0 and 4.\n";
                            }
                            else
                            {
                                // correct  input
                                break;
                            }
                        }
                        cout.unsetf(ios::left);
                        cout.unsetf(ios::right);

                        switch (option)
                        {
                        case 1:
                            cout << endl;
                            // --------------Function call for adding record -----------
                            addRecord(AddSTname, AddStFatherName, AddSTMarks, AddSTCNIC, AddSTphoneNo, addFlag, addCounter, usersize, apCounter);

                            Sleep(1000);
                            system("cls");

                            break;
                        case 2:
                            cout << endl;
                            // --------------Function call for Assigning room servant and room -----------

                            RoomAssign(assignRoom, addFlag, roomflag, apFlag, addCounter, Rcounter, apCounter, usersize);

                            Sleep(1000);
                            system("cls");

                            break;
                        case 3:
                            cout << endl;
                            // --------------Function call for Updating record -----------
                            updateRecord(AddSTname, AddStFatherName, AddSTMarks, AddSTCNIC, AddSTphoneNo, assignRoom, roomflag, addFlag, addCounter, editRecord, Rcounter, usersize);
                            Sleep(1000);
                            system("cls");
                            break;
                        case 4:
                            //-------Function call for Deleting record -----------
                            cout << endl;
                            deleteRecord(AddSTname, AddStFatherName, AddSTMarks, AddSTCNIC, AddSTphoneNo, assignRoom, roomflag, usersize, addFlag, removeRecord, addCounter, Rcounter, uCounter, uflag, username, password);

                            Sleep(1000);
                            system("cls");
                            break;
                            cout << endl;

                        case 0:
                            cout << "\t\t\t\t\t------------------------->Administrator is exit in Manage record " << endl;
                            Sleep(1000);
                            system("cls");

                            break;

                        default:
                            cout << "\t\t\t\t\t\t\t\t\t-----------------> Invalid option ";
                            Sleep(1000);
                            system("cls");
                            break;
                        }
                    } while (option != 0);
                    option = -1; //----------! this statment is to make sure. that do not exit from outer loop !-----------

                    break;
                case 2:
                    do
                    {
                        // --------------------Accounts-----------------
                        system("cls");
                        header();
                        admin2();
                        cout << endl;
                        cout << "\t\t\t\t\t\t\t\t" << "\tChoose an option (0-3): ";

                        while (true)
                        {
                            cin >> option;

                            // Check if the input is valid
                            if (cin.fail())
                            {
                                cin.clear();           // Clear the error
                                cin.ignore(255, '\n'); // remove invalid input
                                cout << "\t\t\t\t\t\t\t\tInvalid input! Please enter a number between 0 and 3.\n";
                            }
                            else if (option < 0 || option > 3)
                            {
                                cout << "\t\t\t\t\t\t\t\tOption out of range! Please enter a number between 0 and 3.\n";
                            }
                            else
                            {
                                // correct  input
                                break;
                            }
                        }

                        cout.unsetf(ios::left);
                        cout.unsetf(ios::right);

                        switch (option)
                        {
                        case 1:
                            cout << endl;
                            // --------------Function call for Creating accounts -----------

                            CreatAccount(username, password, assignRoom, uflag, uCounter, addCounter, usersize, Rcounter, UpdateAccount);
                            Sleep(1000);
                            system("cls");
                            break;
                        case 2:
                            cout << endl;
                            // --------------Function call for Deleting accounts -----------
                            deleteAccount(username, password, assignRoom, roomflag, uflag, addFlag, usersize, removeAccount, uCounter, addCounter, Rcounter);
                            Sleep(1000);
                            system("cls");
                            break;
                        case 3:
                            cout << endl;
                            // --------------Function call for updating accounts -----------
                            updateAccount(username, password, assignRoom, uflag, roomflag, UpdateAccount, uCounter, addCounter, usersize, Rcounter);
                            Sleep(1000);
                            system("cls");
                            break;

                        case 0:
                            cout << "\t\t\t----------------------------->Administrator is exit in Accounts " << endl;
                            Sleep(1000);
                            system("cls");

                            break;

                        default:
                            cout << "\t\t\t\t\t\t\t\t\t-----------------> Invalid option ";
                            Sleep(1000);
                            system("cls");
                            break;
                        }
                    } while (option != 0);
                    option = -1; //----------! this statment is to make sure0. that do not exit from outer loop !-----------

                    break;
                case 3:
                    do
                    {
                        // --------------------Lists
                        system("cls");
                        header();
                        admin3();
                        cout << endl;
                        cout << "\t\t\t\t\t\t\t\t" << "\tChoose an option (0-3): ";

                        while (true)
                        {
                            cin >> option;

                            // Check if the input is valid
                            if (cin.fail())
                            {
                                cin.clear();           // Clear the error
                                cin.ignore(255, '\n'); // remove invalid input
                                cout << "\t\t\t\t\t\t\t\tInvalid input! Please enter a number between 0 and 3.\n";
                            }
                            else if (option < 0 || option > 3)
                            {
                                cout << "\t\t\t\t\t\t\t\tOption out of range! Please enter a number between 0 and 3.\n";
                            }
                            else
                            {
                                // correct  input
                                break;
                            }
                        }
                        cout.unsetf(ios::left);
                        cout.unsetf(ios::right);

                        switch (option)
                        {
                        case 1:
                            cout << endl;
                            // --------------Function call for view Hostelite Applications -----------
                            viewHosteliteApplications(ApplySTname, ApplyStFatherName, ApplySTMarks, ApplySTCNIC, ApplySTphoneNo, apFlag, apCounter, applysize);

                            break;
                        case 2:
                            cout << endl;
                            // --------------Function call for  current Record List -----------
                            currentRecordList(assignRoom, AddSTname, AddStFatherName, AddSTMarks, AddSTCNIC, AddSTphoneNo, addFlag, HosteliteDues, addCounter, usersize);

                            break;
                        case 3:
                            system("cls");
                            header();
                            admin3();
                            if (cmpCounter == 0)
                            {
                                cout << "\t\t\t\t\t\tNo Complain was submitted yet......" << endl;
                                break;
                            }
                            for (int i = 0; i < cmpCounter; i++)
                            {
                                if (cmpFlag[i])
                                {
                                    cout << "\t\t\t\t\t\t\t\t" << username[i] << "  CAN submit the complain:  " << complain[i] << endl;
                                }
                            }
                            cout << endl;
                            cout << "\t\t\t\t\t\t\t\t -------------> Hostelite " << endl;
                            cout << "\t\t\t\t\t\t\t\tKindly press any key...";
                            getch();
                            break;
                        case 0:
                            cout << "\t\t\t\t\t\t\t\t----------------------------->Administrator is exit in Lists.... " << endl;
                            Sleep(1000);
                            system("cls");

                            break;

                        default:
                            cout << "\t\t\t\t\t\t\t\t\t-----------------> Invalid option ";
                            Sleep(1000);
                            system("cls");
                            break;
                        }
                    } while (option != 0);
                    option = -1; //----------! this statment is to make sure0. that do not exit from outer loop !-----------

                    break;
                case 4:
                    // ----------------------------------Pay Dues---------------------
                    system("cls");
                    header();
                    cout << endl;
                    cout << endl;
                    cout << "\t\t\t\t\t\t\t\tEnter the Room no for student dues : ";
                    while (true)
                    {
                        cin >> paymentRecord;
                        if (cin.fail())
                        {
                            cin.clear();           // Clear the error
                            cin.ignore(255, '\n'); // remove invalid input
                            cout << "\t\t\t\t\t\t\t\tInvalid input!! Please enter a numeric value:";
                            continue;
                        }
                        if (paymentRecord >= 1 && paymentRecord < usersize) // enter room no in the given range
                        {
                            break;
                        }
                        else
                        {
                            cout << "\n\t\t\t\t\t\t\t\tInvalid room no . Enter the Room no again : ";
                        }
                    }

                    roomFound = false; // check the room was found  if it true then the desired room is ocuupied

                    for (int k = 0; k < usersize; k++)
                    {
                        if (assignRoom[k] == paymentRecord) // only the given room student  deposite the dues
                        {
                            roomFound = true;
                            if (roomflag[k])
                            {
                                cout << "\t\t\t\t\t\t\t\tKindly enter the dues according to the respective Room no : ";
                                while (true)
                                {
                                    cin >> hostelFee;
                                    if (cin.fail())
                                    {
                                        cin.clear();           // Clear the error
                                        cin.ignore(255, '\n'); // remove invalid input
                                        cout << "\t\t\t\t\t\t\t\tInvalid dues! Please Enter the dues again: \n";
                                    } // input the hostel fee
                                    if (hostelFee >= 6000 && hostelFee <= 15000) // enter the dues in the respective range
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        cout << "\t\t\t\t\t\t\t\tEnter the dues according to the range(6000 to 15000) : ";
                                    }
                                }
                                cout << "\t\t\t\t\t\t\t\tKindly enter the other charges : "; // enter the extra dues of the hostile
                                while (true)
                                {
                                    cin >> extraCharges;
                                    if (cin.fail())
                                    {
                                        cin.clear();           // Clear the error
                                        cin.ignore(255, '\n'); // remove invalid input
                                        cout << "\t\t\t\t\t\t\t\tInvalid dues! Please Enter the dues again: \n";
                                    }
                                    if (extraCharges >= 500 && extraCharges <= 5000) // validity for extra charges
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        cout << "\t\t\t\t\tEnter the extra charges according to the range(500 to 5000) : ";
                                    }
                                }

                                HosteliteDues[k] = hostelFee + extraCharges; //  total dues of the hostelite
                                AssignDues[k] = true;
                                break;
                            }
                            else
                            {
                                cout << "\t\t\t\t\t\t\t\tRoom was not occupied......." << endl;
                            }
                        }
                    }
                    if (!roomFound)
                    {
                        cout << "\t\t\t\t\t\t\t\tRoom number not found or not assigned yet." << endl;
                    }
                    Sleep(1000);

                    break;
                case 0:
                    cout << "\t\t\t\t\t\t------------------->Administrator is exit in dues phase " << endl;
                    Sleep(1000);
                    system("cls");

                    break;

                default:
                    cout << "\t\t\t\t\t\t\t\t\t-----------------> Invalid option ";
                    Sleep(1000);
                    system("cls");
                    break;
                }
            } while (option != 0);
            option = -1; //----------! this statment is to make sure0. that do not exit from outer loop !-----------
        }
        else if (loggedInUserType == 2) // Applicants can access the this block
        {
            do
            {
                system("cls");
                header();
                applyHostel(); // -----------Display Apply for Hostel----------
                cout << endl;
                cout << "\t\t\t\t\t\t\t\t" << "\tChoose an option (0-3): ";

                while (true)
                {
                    cin >> option;

                    // Check if the input is valid
                    if (cin.fail())
                    {
                        cin.clear();           // Clear the error
                        cin.ignore(255, '\n'); // remove invalid input
                        cout << "\t\t\t\t\t\t\t\tInvalid input! Please enter a number between 0 and 3.\n";
                    }
                    else if (option < 0 || option > 3)
                    {
                        cout << "\t\t\t\t\t\t\t\tOption out of range! Please enter a number between 0 and 3.\n";
                    }
                    else
                    {
                        // correct  input
                        break;
                    }
                }
                cout.unsetf(ios::left);
                cout.unsetf(ios::right);

                switch (option)
                {
                case 1:
                    cout << endl;
                    // --------------Function call for Veiw the Hostel information -----------

                    HostelInformation();
                    break;
                case 2:
                    cout << endl;
                    // --------------Function call for Applicants can apply for Hostel-----------

                    applyHostelApplication(ApplySTname, ApplyStFatherName, ApplySTMarks, ApplySTCNIC, ApplySTphoneNo, apFlag, apCounter, applysize);
                    Sleep(1000);
                    system("cls");
                    break;
                case 3:
                    // --------------Function call for view Hostelite Applications -----------

                    viewHosteliteApplications(ApplySTname, ApplyStFatherName, ApplySTMarks, ApplySTCNIC, ApplySTphoneNo, apFlag, apCounter, applysize);
                    Sleep(2000);

                    break;

                case 0:
                    cout << "\t\t\t\t\t----------------------> Applicants Exit the Apply body " << endl;
                    Sleep(1000);
                    system("cls");
                    break;

                default:
                    cout << "\t\t\t\t\t\t\t\t\t-----------------> Invalid option ";
                    Sleep(1000);
                    system("cls");
                    break;
                }

            } while (option != 0);
            option = -1; //----------! this statment is to make sure that do not exit from outer loop !-----------
        }
        else if (loggedInUserType == 3) // User access
        {
            do
            {
                system("cls");
                header();
                userMenu(); // Display the Hostelite on screen
                cout << "\t\t\t\t\t\t\t\t" << "\tChoose an option (0-3): ";

                while (true)
                {
                    cin >> option;

                    // Check if the input is valid
                    if (cin.fail())
                    {
                        cin.clear();           // Clear the error
                        cin.ignore(255, '\n'); // remove invalid input
                        cout << "\t\t\t\t\t\t\t\tInvalid input! Please enter a number between 0 and 3.\n";
                    }
                    else if (option < 0 || option > 3)
                    {
                        cout << "\t\t\t\t\t\t\t\tOption out of range! Please enter a number between 0 and 3.\n";
                    }
                    else
                    {
                        // correct  input
                        break;
                    }
                }

                cout.unsetf(ios::left);
                cout.unsetf(ios::right);

                switch (option)
                {
                case 1:
                    cout << endl;
                    // --------------Function call for Hostelilte can veiw status-----------
                    veiwStatus(username, password, assignRoom, AddSTname, AddStFatherName, AddSTMarks, AddSTCNIC, AddSTphoneNo, HosteliteDues, uflag, pwd, user, addCounter, usersize);

                    break;
                case 2:
                    for (int i = 0; i < usersize; i++)
                    {
                        if (username[i] == user && password[i] == pwd)
                        {

                            if (uflag[i] == true)
                            {
                                while (true)
                                {
                                    cout << "\t\t\t\t\tKindly enter your complain in more precise form : ";
                                    cin.ignore();
                                    getline(cin, complain[i]);
                                    if (complain[i].length() <= complainLength)
                                    {
                                        cmpFlag[i] = true;
                                        cmpCounter++;
                                        cout << "\t\t\t\t\t\t Your complain is submitted........" << endl;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    Sleep(1000);
                    break;
                case 3:
                    cout << endl;
                    // --------------Function call forHostelilte can pay their dues-----------
                    payDues(username, password, assignRoom, AssignDues, uflag, payment, duesFlag, AddSTname, HosteliteDues, pwd, user, addCounter, usersize);
                    Sleep(1000);
                    system("cls");
                    break;

                case 0:

                    cout << "\t\t\t\t\t\t----------------------> Hostelite is logged out" << endl;
                    Sleep(1000);
                    system("cls");
                    break;

                default:
                    cout << "\t\t\t\t\t\t\t\t\t-----------------> Invalid option ";
                    Sleep(1000);
                    system("cls");
                    break;
                }
            } while (option != 0);

            option = -1; //----------! this statment is to make sure that do not exit from outer loop !-----------
        }
        else if (loggedInUserType == -20) // invalid entry !!!!!!!
        {
            cout << "You have entered invalid Credentials!!!" << endl;
            Sleep(1000);
        }
    } while (option != 0);
    applylistDataRecord(ApplySTname, ApplyStFatherName, ApplySTMarks, ApplySTCNIC, ApplySTphoneNo, apFlag, apCounter, applysize);
    saveCurrentRecordList(assignRoom, AddSTname, AddStFatherName, AddSTMarks, AddSTCNIC, AddSTphoneNo, addFlag, HosteliteDues, addCounter, usersize);
    saveAccountsRecord(username, password, complain, cmpFlag, usersize, uCounter, uflag, cmpCounter);
    return 0;
}
//------------------------------------ End of main function----------------------<

// ----------------Display header menu ----------------------!
void header()

{
    setColor(11);
    cout << endl;
    cout << right << setw(70) << "\t\t\t\t\t\t\t /$$   /$$ /$$      /$$  /$$$$$$  \n";
    cout << right << setw(70) << "\t\t\t\t\t\t\t| $$  | $$| $$$    /$$$ /$$__  $$\n";
    cout << right << setw(70) << "\t\t\t\t\t\t\t| $$  | $$| $$$$  /$$$$| $$  \\__/ \n";
    cout << right << setw(70) << "\t\t\t\t\t\t\t| $$$$$$$$| $$ $$/$$ $$|  $$$$$$  \n";
    cout << right << setw(70) << "\t\t\t\t\t\t\t| $$__  $$| $$  $$$| $$ \\____  $$\n";
    cout << right << setw(70) << "\t\t\t\t\t\t\t| $$  | $$| $$\\  $ | $$ /$$  \\ $$\n";
    cout << right << setw(70) << "\t\t\t\t\t\t\t| $$  | $$| $$ \\/  | $$|  $$$$$$/\n";
    cout << right << setw(70) << "\t\t\t\t\t\t\t|__/  |__/|__/     |__/ \\______/ \n";
    cout << right << setw(70) << "\t\t\t\t\t\t                                 \n";
    cout << right << setw(70) << "\t\t\t\t\t\t ****************************************************************************************************\n";
    cout << right << setw(70) << "\t\t\t\t\t\t ***************************-----!```HOSTEL MANAGMENT SYSTEM```!-----********************************\n";
    cout << right << setw(70) << "\t\t\t\t\t\t ****************************************************************************************************\n";
    setColor(7);
}

// --------------------This Function is defined for Manage Record  Display on screen

void admin1()
{
    setColor(4);

    cout << "\t\t\t\t\t -------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t                                                    Manage Record                                          " << endl;
    cout << "\t\t\t\t\t -------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "\t\t\t\t\t\t\t\t"
            "---------! Pick the option that best suits your needs.---------!"
         << endl;
    cout << endl;
    cout << "\t\t\t\t\t\t\t\t"
            "\t Manage Record"
         << endl;
    cout << "\t\t\t\t\t\t\t\t------------------------------------------------------------" << endl;

    cout << "\t\t\t\t\t\t\t\t" << left << setw(30) << " 1. Add Record" << endl;
    cout << "\t\t\t\t\t\t\t\t" << left << setw(30) << " 2. RoomaAssign " << endl;
    cout << "\t\t\t\t\t\t\t\t" << left << setw(30) << " 3. Update Record" << endl;
    cout << "\t\t\t\t\t\t\t\t" << left << setw(30) << " 4. Delete Record" << endl;
    cout << "\t\t\t\t\t\t\t\t" << left << setw(30) << " 0.Exit" << endl;

    cout << "\t\t\t\t\t\t\t\t------------------------------------------------------------" << endl;
}

// --------------------This Function is defined for Administrator Display on screen

void admin()
{
    setColor(12);

    cout << "\t\t\t\t\t -------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t                                                    Administrator                                          " << endl;
    cout << "\t\t\t\t\t -------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "\t\t\t\t\t\t\t\t"
            "---------! Pick the option that best suits your needs.---------!"
         << endl;
    cout << endl;
    cout << "\t\t\t\t\t\t\t\t"
            "\tHostelite System - Information & Assignment Menu"
         << endl;
    cout << "\t\t\t\t\t\t\t\t------------------------------------------------------------" << endl;

    cout << "\t\t\t\t\t\t\t\t" << left << setw(30) << " 1. Manage Record..." << endl;
    cout << "\t\t\t\t\t\t\t\t" << left << setw(30) << " 2. Accounts... " << endl;
    cout << "\t\t\t\t\t\t\t\t" << left << setw(30) << " 3. Lists..." << endl;
    cout << "\t\t\t\t\t\t\t\t" << left << setw(30) << " 4. Payment info..." << endl;
    cout << "\t\t\t\t\t\t\t\t" << left << setw(30) << " 0.Logout..." << endl;

    cout << "\t\t\t\t\t\t\t\t------------------------------------------------------------" << endl;
}

// --------------------This Function is defined for  Accounts...  Display on screen

void admin2()
{
    setColor(3);

    cout << "\t\t\t\t\t -------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t                                                    Accounts...                                          " << endl;
    cout << "\t\t\t\t\t -------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "\t\t\t\t\t\t\t\t"
            "---------! Pick the option that best suits your needs.---------!"
         << endl;
    cout << endl;
    cout << "\t\t\t\t\t\t\t\t"
            "\t Accounts..."
         << endl;
    cout << "\t\t\t\t\t\t\t\t------------------------------------------------------------" << endl;

    cout << "\t\t\t\t\t\t\t\t" << left << setw(30) << " 1. Create Account" << endl;
    cout << "\t\t\t\t\t\t\t\t" << left << setw(30) << " 2. Delete Account" << endl;
    cout << "\t\t\t\t\t\t\t\t" << left << setw(30) << " 3. Update Account" << endl;
    cout << "\t\t\t\t\t\t\t\t" << left << setw(30) << " 0.Exit" << endl;

    cout << "\t\t\t\t\t\t\t\t------------------------------------------------------------" << endl;
}

// --------------------This Function is defined for Lists   Display on screen

void admin3()
{
    setColor(10);

    cout << "\t\t\t\t\t -------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t                                                    Lists...                                          " << endl;
    cout << "\t\t\t\t\t -------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "\t\t\t\t\t\t\t\t"
            "---------! Pick the option that best suits your needs.---------!"
         << endl;
    cout << endl;
    cout << "\t\t\t\t\t\t\t\t"
            "\tLists..."
         << endl;
    cout << "\t\t\t\t\t\t\t\t------------------------------------------------------------" << endl;

    cout << "\t\t\t\t\t\t\t\t" << left << setw(30) << " 1.Veiw Applicant list " << endl;
    cout << "\t\t\t\t\t\t\t\t" << left << setw(30) << " 2. Veiw Current list " << endl;
    cout << "\t\t\t\t\t\t\t\t" << left << setw(30) << " 3. Veiw General info.." << endl;
    cout << "\t\t\t\t\t\t\t\t" << left << setw(30) << " 0.Exit" << endl;

    cout << "\t\t\t\t\t\t\t\t------------------------------------------------------------" << endl;
}

// --------------------This Function is defined for  Apply for Hostel Display on screen

void applyHostel()
{

    cout << "\t\t\t\t\t -------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t                                                Apply for Hostel                                         " << endl;
    cout << "\t\t\t\t\t -------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "\t\t\t\t\t\t\t\t"
            "--------- Pick the option that best suits your needs.---------!"
         << endl;
    cout << endl;
    cout << "\t\t\t\t\t\t" << left << setw(30) << " 1.Veiw Hostel information . " << endl;
    cout << "\t\t\t\t\t\t" << left << setw(30) << " 2.Registration " << endl;
    cout << "\t\t\t\t\t\t" << left << setw(30) << " 3.Veiw Application " << endl;
    cout << "\t\t\t\t\t\t" << left << setw(30) << " 0.exit." << endl;
}

// --------------------This Function is defined for  Hostelite Display on screen

void userMenu()
{

    cout << "\t\t\t\t\t -------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t                                               Hostelite                                       " << endl;
    cout << "\t\t\t\t\t -------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "\t\t\t\t\t\t\t\t" << "---------! Pick the option that best suits your needs.---------!" << endl;
    cout << endl;
    cout << "\t\t\t\t\t\t\t\t" << left << setw(30) << " 1.View status . " << endl;
    cout << "\t\t\t\t\t\t\t\t" << left << setw(30) << " 2.Complaints . " << endl;
    cout << "\t\t\t\t\t\t\t\t" << left << setw(30) << " 3.Pay dues . " << endl;
    cout << "\t\t\t\t\t\t\t\t" << left << setw(30) << " 0.exit ." << endl;
}

// --------------------This Function is defined for  Add record in the system.....

void addRecord(string AddSTname[], string AddStFatherName[], int AddSTMarks[], string AddSTCNIC[], string AddSTphoneNo[], bool addFlag[], int &addCounter, int &usersize, int apCounter)
{
    bool isadded = false;
    if (apCounter == 0) // Check Applicants can apply for hostel
    {
        cout << "\t\t\t\t\t\t\t\tNo application is submit yet !! " << endl;
        return;
    }
    if (addCounter >= usersize) //  check if Applicants reaches the total size of apply counter
    {
        cout << "\t\t\t\t\t\t No more students are added ! Rooms are full." << endl;
        return;
    }
    cin.ignore(255, '\n');
    for (int i = 0; i < usersize; i++)
    {
        if (AddSTname[i] == "nv" && addFlag[i] == false)
        {
            cout << "\t\t\t\t\t\t\t Kindly enter your Name: ";
            while (true)
            {
                getline(cin, AddSTname[i]); // Get the full name input

                // Check if the input is valid
                if (isAlphabet(AddSTname[i]))
                {
                    break; // Input is valid, exit the loop
                }
                else
                {
                    cout << "\t\t\t\t\t\t Invalid name. Please enter alphabetic characters only in name: ";
                }
            }

            cout << "\t\t\t\t\t\t\t Kindly enter your Father Name: ";

            while (true)
            { // same validition as above
                getline(cin, AddStFatherName[i]);

                if (isAlphabet(AddStFatherName[i]))
                {
                    break;
                }
                else
                {
                    cout << "\t\t\t\t\t Invalid name. Please enter alphabetic characters only in name: ";
                }
            }

            cout << "\t\t\t\t\t\t\t Kindly enter your marks: ";

            while (true)
            {
                cin >> AddSTMarks[i];
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(255, '\n');
                    cout << "\t\t\t\t\t\t\tInvalid input!!.Kindly enter the numeric value:";
                    continue;
                }

                if (validMarks(AddSTMarks[i]))
                {
                    break;
                }
                else
                {
                    cout << "\t\t\t\t\t\t\tInvalid name. Please enter marks in the given range(0 to 400) : ";
                }
            }
            cin.ignore();

            cout << "\t\t\t\t\t\t\tKindly enter your CNIC : ";

            while (true)
            {
                getline(cin, AddSTCNIC[i]);

                if (checkValidCNIC(AddSTCNIC[i])) // valid check if the digit is 13
                {
                    break;
                }
                else
                {
                    cout << "\t\t\t\t\t\t\tInvalid CNIC! Please ensure it contains exactly 13 digits : ";
                }
            }

            cout << "\t\t\t\t\t\t\tKindly enter your phone number: ";

            while (true)
            {
                getline(cin, AddSTphoneNo[i]);

                if (checkValidContact(AddSTphoneNo[i])) // check if the digit is 11.
                {
                    break;
                }
                else
                {
                    cout << "\t\t\t\t\t\t\tInvalid phone no ! Please ensure it contains exactly 11 digits : ";
                }
            }
            addFlag[i] = true; // Administrator add the record
            isadded = true;
            cout << "\t\t\t\t\t\t\tStudent added successfully" << endl;
        }

        addCounter++;
        if (isadded)
        {
            break;
        }
    }
}

// --------------------This Function is defined for  Delete record in the system.....

void viewHosteliteApplications(string ApplySTname[], string ApplyStFatherName[], int ApplySTMarks[], string ApplySTCNIC[], string ApplySTphoneNo[], bool apFlag[], int apCounter, int &applysize)
{
    system("cls");
    header();
    int sortingTemp = 0;
    string tempName = "";
    string tempFatherName = "";
    string tempCNIC = "";
    string tempPhone = "";
    bool tempFlag = false;
    if (apCounter == 0)
    {

        cout << "\t\t\t\t\t\t\tNo applications submitted yet." << endl;
        return;
    }

    cout << "************************************************************************************************************************************************************************************************************" << endl;
    cout << left << setw(30) << "Name" << left << setw(30) << "Father Name" << left << setw(30) << "Marks (Ecat)" << left << setw(30) << "CNIC" << left << setw(30) << "Contact NO" << endl;
    cout << "************************************************************************************************************************************************************************************************************" << endl;
    for (int i = 0; i < apCounter - 1; i++) // sorting the data  in increasing order
    {
        for (int j = i + 1; j < apCounter; j++)
        {
            if (ApplySTname[i] != "nv")
            {
                if (ApplySTMarks[j] > ApplySTMarks[i])
                {
                    // swap  marks
                    sortingTemp = ApplySTMarks[j];
                    ApplySTMarks[j] = ApplySTMarks[i];
                    ApplySTMarks[i] = sortingTemp;

                    // swap  names
                    tempName = ApplySTname[j];
                    ApplySTname[j] = ApplySTname[i];
                    ApplySTname[i] = tempName;

                    // swap fathers  names
                    tempFatherName = ApplyStFatherName[j];
                    ApplyStFatherName[j] = ApplyStFatherName[i];
                    ApplyStFatherName[i] = tempFatherName;

                    // Swap  CNIc..
                    tempCNIC = ApplySTCNIC[j];
                    ApplySTCNIC[j] = ApplySTCNIC[i];
                    ApplySTCNIC[i] = tempCNIC;

                    // Swap  phone   numbers..
                    tempPhone = ApplySTphoneNo[j];
                    ApplySTphoneNo[j] = ApplySTphoneNo[i];
                    ApplySTphoneNo[i] = tempPhone;

                    // Swap  validity flags
                    tempFlag = apFlag[j];
                    apFlag[j] = apFlag[i];
                    apFlag[i] = tempFlag;
                }
            }
        }
    }

    for (int j = 0; j < applysize; j++)
    {
        if (apFlag[j] == true) // Display only valid   entries
        {
            cout << left << setw(30) << ApplySTname[j] << left << setw(30)
                 << ApplyStFatherName[j] << left << setw(30) << ApplySTMarks[j]
                 << left << setw(30) << ApplySTCNIC[j] << left << setw(30)
                 << ApplySTphoneNo[j] << endl;
        }
    }
    cout << "\t\t\t\t\t\t\t\tKindly press any key...";
    getch();
}

// --------------------This Function is defined for Applicants can view Hostel Information.....

void HostelInformation()
{
    system("cls");
    header();
    cout << endl;
    setColor(13);
    while (true)
    {

        int info = 1;
        cout << "\t\t\t\t\t\t\tHostel Setup for 50 Students:" << endl;
        cout << "\t\t\t\t\t\t\t--------------------------------------------------" << endl;
        cout << "\t\t\t\t\t\t\t1. Total of 50 rooms for 50 students." << endl;
        cout << "\t\t\t\t\t\t\t2. Each room servant is assigned to one room." << endl;
        cout << "\t\t\t\t\t\t\t3. Room Features:" << endl;
        cout << "\t\t\t\t\t\t\t   -> 1 fan and 2 bulbs for lighting." << endl;
        cout << "\t\t\t\t\t\t\t   -> Attached washroom shared between two rooms." << endl;
        cout << "\t\t\t\t\t\t\t   -> 1 cubet (small wardrobe) for storage." << endl;
        cout << "\t\t\t\t\t\t\t4. Common Amenities:" << endl;
        cout << "\t\t\t\t\t\t\t   -> Small playground for recreational activities." << endl;
        cout << "\t\t\t\t\t\t\t   -> TV room for entertainment and relaxation." << endl;
        cout << "\t\t\t\t\t\t\t5. Security:" << endl;
        cout << "\t\t\t\t\t\t\t   -> security guard for safety and surveillance." << endl;
        cout << "\t\t\t\t\t\t\t6. Each room is equipped with 1 bed for each student." << endl;
        cout << "\t\t\t\t\t\t\t7. Rooms are airy and well-ventilated for comfort." << endl;
        cout << "\t\t\t\t\t\t\t--------------------------------------------------" << endl;
        cout << "\t\t\t\t\t\t\tThe hostel provides a comfortable and engaging living space for all students." << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;

        while (true)
        {
            cout << "\t\t\t\t\t\t\tIf you read the information then " << endl;
            cout << "\t\t\t\t\t\t\t Enter 0 for exit : ";
            cin >> info;
            // Check if the input is valid
            if (cin.fail())
            {
                cin.clear();           // Clear the error
                cin.ignore(255, '\n'); // remove invalid input
                cout << "\t\t\t\t\t\tInvalid input! Please enter  0 for exit.\n";
            }
            else if (info < 0 || info > 0)
            {
                cout << "\t\t\t\t\t\tOption out of range! Please enter  0 for exit.\n";
            }
            else
            {
                // correct  input
                break;
            }
        }
        break; // break the outer loop...
    }
}

// --------------------This Function is defined for  applicants apply Hostel Application....

void applyHostelApplication(string ApplySTname[], string ApplyStFatherName[], int ApplySTMarks[], string ApplySTCNIC[], string ApplySTphoneNo[], bool apFlag[], int &apCounter, int &applysize)
{
    bool isApply = false;
    if (apCounter >= applysize)
    {
        cout << "\t\t\t\t\t\t\tNo more students can apply ! Applicants are full." << endl;
        return;
    }
    cin.ignore();

    // same validation as in adding phase
    for (int i = 0; i < applysize; i++)
    {
        if (ApplySTname[i] == "nv" && ApplyStFatherName[i] == "nv" && ApplySTMarks[i] == 0 && ApplySTCNIC[i] == "nv" && ApplySTphoneNo[i] == "nv")
        {
            cout << "\t\t\t\t\t\t\tKindly enter your Name: ";
            while (true)
            {
                getline(cin, ApplySTname[i]); // Get the full name input

                // Check if the input is valid
                if (isAlphabet(ApplySTname[i]))
                {
                    break; // Input is valid, exit the loop
                }
                else
                {
                    cout << "\t\t\t\t\t\t\tInvalid name. Please enter alphabetic characters only in name: ";
                }
            }

            cout << "\t\t\t\t\t\t\tKindly enter your Father Name: ";

            while (true)
            {
                getline(cin, ApplyStFatherName[i]);

                if (isAlphabet(ApplyStFatherName[i]))
                {
                    break;
                }
                else
                {
                    cout << "\t\t\t\t\t\tInvalid name. Please enter alphabetic characters only in name: ";
                }
            }

            cout << "\t\t\t\t\t\t\tKindly enter your marks: ";

            while (true)
            {
                cin >> ApplySTMarks[i];
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(255, '\n');
                    cout << "\t\t\t\t\t\t\tInvalid input!!.Kindly enter the numeric value(0 to 400):";
                    continue;
                }

                if (validMarks(ApplySTMarks[i]))
                {
                    break;
                }
                else
                {
                    cout << "\t\t\t\t\t\tInvalid name. Please enter marks in the given range(0 to 400) : ";
                }
            }
            cin.ignore();

            cout << "\t\t\t\t\t\t\tKindly enter your CNIC : ";

            while (true)
            {
                getline(cin, ApplySTCNIC[i]);

                if (checkValidCNIC(ApplySTCNIC[i]))
                {
                    break;
                }
                else
                {
                    cout << "\t\t\t\t\t\t\tInvalid CNIC! Please ensure it contains exactly 13 digits : ";
                }
            }

            cout << "\t\t\t\t\t\t\tKindly enter your phone number: ";

            while (true)
            {
                getline(cin, ApplySTphoneNo[i]);

                if (checkValidContact(ApplySTphoneNo[i]))
                {
                    break;
                }
                else
                {
                    cout << "\t\t\t\t\t\t\tInvalid phone no ! Please ensure it contains exactly 11 digits : ";
                }
            }
            apFlag[i] = true; // applicant can apply for hostel
            isApply = true;
            cout << "-\t\t\t\t\t\t\t------------->Application for hostel is submitted" << endl;
        }
        apCounter++;
        if (isApply)
        {
            break;
        }
    }
}

// --------------------This Function is defined for  Assigning the room & room servant....

void RoomAssign(int assignRoom[], bool addFlag[], bool roomflag[], bool apFlag[], int addCounter, int &Rcounter, int &apCounter, int &usersize)
{
    bool isRoomAssign = false;
    bool isOccured = true;
    if (Rcounter >= usersize)
    {
        cout << "\t\t\t\t\t\t\tNo more rooms available for assignment." << endl;
        return;
    }

    for (int j = 0; j < usersize; j++)
    {
        if (j == addCounter - 1 || roomflag[j] == false) // Process only desired records
        {
            cout << "\t\t\t\t\t\t\tAssign the room to Hostelite: ";

            while (true)
            {
                isOccured = true;
                cin >> assignRoom[j];
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(255, '\n');
                    cout << "\t\t\t\t\t\tInvalid Room no ##.kindly enter (1--100): ";
                }
                else if (assignRoom[j] < 1 || assignRoom[j] > usersize)
                {
                    cout << "\t\t\t\t\t\tInvalid Room no ##.kindly enter (1--100): ";
                }

                for (int i = 0; i < usersize; i++)
                {
                    if (assignRoom[i] == assignRoom[j] && i != j)
                    {
                        isOccured = false;
                        break;
                    }
                }
                if (isOccured)
                {
                    cout << "\t\t\t\t\t\tRoom assign successfully!!" << endl;
                    break;
                }
                else
                {
                    cout << "\t\t\t\t\t\t\tRoom already Assign!! kindly Assign other one: ";
                }
            }
            roomflag[j] = true;
            isRoomAssign = true;
            apFlag[j] = false; // Mark the record as processed
            apCounter--;
        }
        Rcounter++;
        if (isRoomAssign)
        {
            break;
        }
    }
}

// --------------------This Function is defined for veiw current Record List....

void currentRecordList(int assignRoom[], string AddSTname[], string AddStFatherName[], int AddSTMarks[], string AddSTCNIC[], string AddSTphoneNo[], bool addFlag[], double HosteliteDues[], int addCounter, int usersize)
{
    system("cls");
    header();
    if (addCounter == 0)
    {
        cout << "\t\t\t\t\t\t\tNo applications submitted yet." << endl;
        return;
    }

    cout << "************************************************************************************************************************************************************************************************************" << endl;
    cout << left << setw(10) << "Room no" << left << setw(30) << "Name" << left << setw(30) << "Father Name" << left << setw(30) << "Marks (Ecat)" << left << setw(30) << "CNIC" << left << setw(25) << "Contact NO" << left << setw(30) << " HosteliteDues" << endl;
    cout << "************************************************************************************************************************************************************************************************************" << endl;

    for (int j = 0; j < usersize; j++)
    {
        if (AddSTname[j] != "nv" && AddStFatherName[j] != "nv" && AddSTCNIC[j] != "nv" && AddSTphoneNo[j] != "nv" && AddSTMarks[j] != 0) // check if hosteelite rocord is added then display its record
        {
            cout << left << setw(10) << assignRoom[j] << left << setw(30) << AddSTname[j] << left << setw(30)
                 << AddStFatherName[j] << left << setw(30) << AddSTMarks[j]
                 << left << setw(30) << AddSTCNIC[j] << left << setw(30)
                 << AddSTphoneNo[j] << left << setw(30) << HosteliteDues[j] << endl;
        }
    }
    cout << "\t\t\t\t\t\t\t\tKindly press any key...";
    getch();
}
void loadData(int assignRoom[], string AddSTname[], string AddStFatherName[], int AddSTMarks[], string AddSTCNIC[], string AddSTphoneNo[], bool addFlag[], bool roomflag[], int usersize, double HosteliteDues[], int &addCounter, int &Rcounter, bool AssignDues[])
{
    ifstream currentRlistIn;
    currentRlistIn.open("CurrentRecord.txt");

    if (!currentRlistIn)
    {
        cout << "File does not exits!";
        return;
    }
    int i = 0;
    while (i < usersize && !currentRlistIn.eof())
    {
        currentRlistIn >> assignRoom[i];
        currentRlistIn.ignore();
        getline(currentRlistIn, AddSTname[i], ',');
        getline(currentRlistIn, AddStFatherName[i], ',');
        currentRlistIn >> AddSTMarks[i];
        currentRlistIn.ignore();
        getline(currentRlistIn, AddSTCNIC[i], ',');

        getline(currentRlistIn, AddSTphoneNo[i], ',');
        currentRlistIn >> HosteliteDues[i];

        roomflag[i] = true;
        addFlag[i] = true;
        AssignDues[i] = true;

        i++;
    }

    addCounter = i;
    Rcounter = i;
    currentRlistIn.close();
}
void saveCurrentRecordList(int assignRoom[], string AddSTname[], string AddStFatherName[], int AddSTMarks[], string AddSTCNIC[], string AddSTphoneNo[], bool addFlag[], double HosteliteDues[], int addCounter, int usersize)
{
    ofstream currentRlist;

    currentRlist.open("CurrentRecord.txt");
    int count = 0;
    if (!currentRlist)
    {
        cout << "\t\t\t\t\t\t\tFile does not exits!";
        return;
    }
    for (int j = 0; j < usersize; j++)
    {
        if (AddSTname[j] != "nv") // check if hosteelite rocord is added then display its record
        {
            if (count == addCounter - 1)
            {
                currentRlist << assignRoom[j] << "," << AddSTname[j] << ","
                             << AddStFatherName[j] << "," << AddSTMarks[j]
                             << "," << AddSTCNIC[j] << ","
                             << AddSTphoneNo[j] << "," << HosteliteDues[j];
            }
            else
            {
                currentRlist << assignRoom[j] << "," << AddSTname[j] << ","
                             << AddStFatherName[j] << "," << AddSTMarks[j]
                             << "," << AddSTCNIC[j] << ","
                             << AddSTphoneNo[j] << "," << HosteliteDues[j] << endl;
                count++;
            }
        }
    }
    currentRlist.close();
}

// --------------------This Function is defined for Updating record ....

void updateRecord(string AddSTname[], string AddStFatherName[], int AddSTMarks[], string AddSTCNIC[], string AddSTphoneNo[], int assignRoom[], bool roomflag[], bool addFlag[], int addCounter, int editRecord, int Rcounter, int &usersize)
{
    bool isUpdated = false;
    if (addCounter == 0)
    {
        cout << "\t\t\t\t\t\t\tKindly add the applicant record before Update Record!! " << endl;
        return;
    }
    if (Rcounter >= 0)
    {
        cout << "\t\t\t\t\t\t\tEnter the Room number to edit/update: ";

        while (true)
        {

            cin >> editRecord;
            if (cin.fail()) // input validation
            {
                cin.clear();
                cin.ignore(255, '\n');
                cout << "\t\t\t\t\t\t\tInvalid Room no ##.kindly enter (1--100): ";
            }
            else if (editRecord < 1 || editRecord > usersize)
            {
                cout << "\t\t\t\t\t\t\tInvalid Room no ##.kindly enter (1--100): ";
            }
            else
            {
                // valid input
                break;
            }
        }
    }

    for (int j = 0; j < usersize; j++)
    {
        if ((assignRoom[j] == editRecord)) // check if updating record occupied room
        {
            cin.ignore();

            cout << "\t\t\t\t\t\t\tKindly enter your Name: ";
            while (true)
            {
                getline(cin, AddSTname[j]); // Get the full name input

                // Check if the input is valid
                if (isAlphabet(AddSTname[j]))
                {
                    break; // Input is valid, exit the loop
                }
                else
                {
                    cout << "\t\t\t\t\t\t\tInvalid name. Please enter alphabetic characters only in name: ";
                }
            }

            cout << "\t\t\t\t\t\t\tKindly enter your Father Name: ";

            while (true)
            { // input validation
                getline(cin, AddStFatherName[j]);

                if (isAlphabet(AddStFatherName[j]))
                {
                    break;
                }
                else
                {
                    cout << "\t\t\t\t\t\t\tInvalid name. Please enter alphabetic characters only in name: ";
                }
            }

            cout << "\t\t\t\t\t\t\tKindly enter your marks: ";

            while (true)
            {
                cin >> AddSTMarks[j];
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(255, '\n');
                    cout << "\t\t\t\t\t\t\tInvalid input!!.Kindly enter the numeric value:";
                    continue;
                }

                if (validMarks(AddSTMarks[j]))
                {
                    break;
                }
                else
                {
                    cout << "\t\t\t\t\t\t\tInvalid name. Please enter marks in the given range(0 to 400) : ";
                }
            }
            cin.ignore();

            cout << "\t\t\t\t\t\t\tKindly enter your CNIC : ";

            while (true)
            {
                getline(cin, AddSTCNIC[j]);

                if (checkValidCNIC(AddSTCNIC[j]))
                {
                    break;
                }
                else
                {
                    cout << "\t\t\t\t\t\t\tInvalid CNIC! Please ensure it contains exactly 13 digits : ";
                }
            }

            cout << "\t\t\t\t\t\t\tKindly enter your phone number: ";

            while (true)
            {
                getline(cin, AddSTphoneNo[j]);

                if (checkValidContact(AddSTphoneNo[j]))
                {
                    break;
                }
                else
                {
                    cout << "\t\t\t\t\t\t\tInvalid phone no ! Please ensure it contains exactly 11 digits : ";
                }
            }
            isUpdated = true;
            cout << "\t\t\t\t\t....................User Update Successfully!" << endl;
            break;
        }
    }
    if (!isUpdated)
    {
        cout << "\t\t\t\t\t......................This Room no does not exist!!!" << endl;
    }
}

// --------------------This Function is defined for Deleting record ....

void deleteRecord(string AddSTname[], string AddStFatherName[], int AddSTMarks[], string AddSTCNIC[], string AddSTphoneNo[], int assignRoom[], bool roomflag[], int &usersize, bool addFlag[], int removeRecord, int &addCounter, int &Rcounter, int &uCounter, bool uflag[], string username[], string password[])
{
    bool isDelete = false;

    if (addCounter == 0)
    {
        cout << "\t\t\t\t\t\tKindly add the applicant record before DeleteRecord!! " << endl;
        return;
    }
    while (true)
    {

        if (Rcounter > 0)
        {
            cout << "\t\t\t\t\t\t\tEnter the Room number to Delete: ";
        }
        else
        {
            cout << "Kindly add the applicant record before Deleting Record!! " << endl;
            return;
        }
        cin >> removeRecord;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(255, '\n');
            cout << "\t\t\t\t\t\t\tInvalid Room no ##.kindly enter (1--100): ";
        }
        else if (removeRecord < 1 || removeRecord > usersize)
        {
            cout << "\t\t\t\t\t\t\tInvalid Room no ##.kindly enter (1--100): ";
        }
        else
        {
            // valid room
            break;
        }
    }

    for (int i = 0; i < usersize; i++)
    {
        if ((assignRoom[i] == removeRecord))
        {
            // the desire slot epmty
            AddSTname[i] = "nv";
            AddStFatherName[i] = "nv";
            AddSTMarks[i] = 0;
            AddSTCNIC[i] = "nv";
            AddSTphoneNo[i] = "nv";
            addFlag[removeRecord - 1] = false;
            roomflag[removeRecord - 1] = false;
            username[removeRecord - 1] = "nv";
            password[removeRecord - 1] = "nv";
            uflag[removeRecord - 1] = false;
            uCounter--;
            Rcounter--;
            addCounter--;

            isDelete = true;
            cout << "\t\t\t\t\t\t\tRecord deleted successfully!" << endl;
            break;
        }
    }
    if (!isDelete)
    {
        cout << " \t\t\t\t\t\t\tThe record of this Room no does not Exist !!" << endl;
    }
}

// --------------------This Function is defined for Creating account ....

void CreatAccount(string username[], string password[], int assignRoom[], bool uflag[], int &uCounter, int addCounter, int &usersize, int Rcounter, int UpdateAccount)
{
    bool isAccountCreate = false;
    if (addCounter == 0) // check creating account only added hostelite
    {
        cout << "\t\t\t\t\t\t\tKindly add the applicant record before creating Account!! " << endl;
        return;
    }

    cin.ignore();
    cout << "\t\t\t\t\t\t\tEnter the Room number to create account: ";

    while (true)
    {

        if (Rcounter > 0)
        {

            cin >> UpdateAccount;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(255, '\n');
                cout << "\t\t\t\t\t\t\tInvalid Room no ##.kindly enter (1--100): ";
            }
            else if (UpdateAccount < 1 || UpdateAccount > usersize)
            {
                cout << "\t\t\t\t\t\t\tInvalid Room no ##.kindly enter (1--100): ";
            }
            else
            {
                break;
            }
        }
        else
        {
            cout << "\t\t\t\t\t\t\tKindly assign the room  before create  Record!! " << endl;
            return;
        }
    }
    for (int i = 0; i < usersize; i++)
    {
        if (assignRoom[i] == UpdateAccount && username[i] == "nv")
        {
            cout << "\t\t\t\t\t\t\tEnter username: ";
            cin >> username[i];
            cout << "\t\t\t\t\t\t\tEnter Password: ";
            cin >> password[i];
            uflag[i] = true;
            isAccountCreate = true;
            

            cout << "\t\t\t\t\t\t\tHostelite account created Successfully!....." << endl;
            Sleep(1000);
        }
        uCounter++;
        if (isAccountCreate)
        {
            break;
        }
    }
}

// --------------------This Function is defined for Deleting Account ....

void deleteAccount(string username[], string password[], int assignRoom[], bool roomflag[], bool uflag[], bool addFlag[], int &usersize, int removeAccount, int &uCounter, int addCounter, int Rcounter)
{
    bool isDelateAccount = false;

    while (true)
    { // input validation

        if (Rcounter == 0)
        {
            cout << "\t\t\t\t\t\t\tKindly assign the room  before Deleting  Account!! " << endl;
            return;
        }
        else
        {
            cout << "\t\t\t\t\t\t\tEnter the Room number to Delete account: ";
        }
        cin >> removeAccount;

        if (cin.fail())
        { // input validation
            cin.clear();
            cin.ignore(255, '\n');
            cout << "\t\t\t\t\t\t\tInvalid Room no ##.kindly enter (1--100): ";
        }
        else if (removeAccount < 1 || removeAccount > usersize)
        {
            cout << "\t\t\t\t\t\t\tInvalid Room no ##.kindly enter (1--100): ";
        }
        else
        {
            break;
        }
    }

    for (int i = 0; i < usersize; i++)
    {
        if (assignRoom[i] == removeAccount) // check if deleting accout occupied room
        {
            username[i] = "nv";
            password[i] = "nv";
            uflag[removeAccount - 1] = false;
            isDelateAccount = true;

            uCounter--; // decrease the value of counter
            cout << "\t\t\t\t\t\t\tAccount deleted successfully!........." << endl;
            break;
        }
    }

    if (!isDelateAccount)
    {
        cout << " The Account of this Room no is not Exist !!" << endl;
    }
    if (addCounter == 0)
    {
        cout << "Kindly add the applicant record before Deleting Account!! " << endl;
        return;
    }
    Sleep(1000);
}

// --------------------This Function is defined for Updating Account ....

void updateAccount(string username[], string password[], int assignRoom[], bool uflag[], bool roomflag[], int UpdateAccount, int &uCounter, int addCounter, int &usersize, int Rcounter)
{
    bool isUpadteAccount = true;

    if (addCounter == 0)
    {
        cout << "\t\t\t\t\t\t\tKindly add the applicant record before Update Account!! " << endl;
        return;
    }

    cout << "\t\t\t\t\t\t\tEnter the Room number to Update account: ";

    while (true)
    {

        if (Rcounter > 0)
        {

            cin >> UpdateAccount;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(255, '\n');
                cout << "\t\t\t\t\t\t\tInvalid Room no ##.kindly enter (1--100): ";
            }
            else if (UpdateAccount < 1 || UpdateAccount > usersize)
            {
                cout << "\t\t\t\t\t\t\tInvalid Room no ##.kindly enter (1--100): ";
            }
            else
            {
                break;
            }
        }
        else
        {
            cout << "\t\t\t\t\t\t\tKindly assign the room  before Update Record!! " << endl;
            return;
        }
    }

    for (int i = 0; i < usersize; i++)
    {
        if (assignRoom[i] == UpdateAccount) // check if updating accout occupied room
        {
            cout << "\t\t\t\t\t\t\tEnter new  username : ";
            cin >> username[i];
            cout << "\t\t\t\t\t\t\tEnter new Password : ";
            cin >> password[i];
            isUpadteAccount = false;
            break;
        }
    }
    if (isUpadteAccount)
    {
        cout << " The Account of this Room no is not Exist !!" << endl;
        return;
    }
    if (addCounter == 0)
    {
        cout << "Kindly add the applicant record before Update Account!! " << endl;
        return;
    }
}

// --------------------This Function is defined for hostelite can veiw Status ....

void veiwStatus(string username[], string password[], int assignRoom[], string AddSTname[], string AddStFatherName[], int AddSTMarks[], string AddSTCNIC[], string AddSTphoneNo[], double HosteliteDues[], bool uflag[], string pwd, string user, int addCounter, int &usersize)
{

    cout << "************************************************************************************************************************************************************************************************************" << endl;
    cout << left << setw(10) << "Room no" << left << setw(30) << "Name" << left << setw(30) << "Father Name" << left << setw(30) << "Marks (Ecat)" << left << setw(30) << "CNIC" << left << setw(25) << "Contact NO" << left << setw(30) << " HosteliteDues" << endl;

    cout << "************************************************************************************************************************************************************************************************************" << endl;
    for (int j = 0; j < usersize; j++)
    {
        if (username[j] == user && password[j] == pwd)
        {
            uflag[j] = true;
            if (uflag[j] == true) // check if the user login the account exist in the system

            {
                cout << left << setw(10) << assignRoom[j] << left << setw(30) << AddSTname[j] << left << setw(30)
                     << AddStFatherName[j] << left << setw(30) << AddSTMarks[j]
                     << left << setw(30) << AddSTCNIC[j] << left << setw(30)
                     << AddSTphoneNo[j] << left << setw(30) << HosteliteDues[j] << endl;
            }
        }
    }
    cout << "\t\t\t\t\t\t\t\tKindly press any key...";
    getch();
}

// --------------------This Function is defined for hostelite can pay their dues ....

void payDues(string username[], string password[], int assignRoom[], bool AssignDues[], bool uflag[], double payment, bool duesFlag[], string AddSTname[], double HosteliteDues[], string pwd, string user, int addCounter, int &usersize)
{
    bool submitt = false;

    for (int j = 0; j < usersize; j++)
    {
        if (username[j] == user && password[j] == pwd)
        {
            if (uflag[j] == true && AssignDues[j] == true)
            {
                cout << "\t\t\t\t\t\t\t\t\tName      : " << username[j] << endl
                     << "\t\t\t\t\t\t\t\t\tRoom no   : " << assignRoom[j] << endl
                     << "\t\t\t\t\t\t\t\t\tYour Dues : " << HosteliteDues[j] << endl;
                if (HosteliteDues[j] == 0)
                {
                    cout << "\t\t\t\t\t\t\tYou have no pending dues .Thank you!!!" << endl;
                    Sleep(1000);
                    return;
                }
                cout << "\t\t\t\t\t\t\t\tKindly enter your dues : ";

                while (true)
                {

                    cin >> payment;

                    // Check if the input is valid
                    if (cin.fail())
                    {
                        cin.clear();           // Clear the error
                        cin.ignore(255, '\n'); // remove invalid input
                        cout << "\t\t\t\t\t\t\t\tInvalid input! Please enter correct dues: ";
                    }
                    else if (payment != HosteliteDues[j])
                    {
                        cout << "\t\t\t\t\t\t\t\tOption out of range! Please enter correct dues: ";
                    }
                    else
                    {
                        // correct  input
                        break;
                    }
                }

                HosteliteDues[j] -= payment; // generating the remaining dues
                duesFlag[j] = true;
                submitt = true;

                cout << "\t\t\t\t\t\t\t\t\tPayment successful! You have paid " << payment << endl;
                cout << "\t\t\t\t\t\t\t\t\tRemaining dues: " << HosteliteDues[j] << endl;

                cout << "\n\t\t\t\t\t\t\t\t\tThank you for your payment!" << endl;
                break;
            }
        }
        if (submitt)
        {
            break;
        }
    }
}
//-----------------------------save the applicant data----------------------------
void applylistDataRecord(string ApplySTname[], string ApplyStFatherName[], int ApplySTMarks[], string ApplySTCNIC[], string ApplySTphoneNo[], bool apFlag[], int apCounter, int applysize)
{
    ofstream applyListData;
    applyListData.open("applylist.txt");
    if (!applyListData)
    {
        cout << "File does not exits!";
        return;
    }

    int saved = 0;
    for (int j = 0; j < applysize; j++)
    {
        if (ApplySTname[j] != "nv" && ApplyStFatherName[j] != "nv" && ApplySTMarks[j] != 0 && ApplySTCNIC[j] != "nv" && ApplySTphoneNo[j] != "nv") // Display only valid   entries
        {
            if (saved == apCounter - 1)
            {
                applyListData << ApplySTname[j] << "," << ApplyStFatherName[j] << "," << ApplySTMarks[j]
                              << "," << ApplySTCNIC[j] << "," << ApplySTphoneNo[j];
            }
            else
            {
                applyListData << ApplySTname[j] << "," << ApplyStFatherName[j] << "," << ApplySTMarks[j]
                              << "," << ApplySTCNIC[j] << "," << ApplySTphoneNo[j] << endl;
                saved++;
            }
        }
    }
    applyListData.close();
}
// --------------------------Load the applicant data----------------------------
void loadapplylistDataRecord(string ApplySTname[], string ApplyStFatherName[], int ApplySTMarks[], string ApplySTCNIC[], string ApplySTphoneNo[], bool apFlag[], int &apCounter, int applysize)
{
    ifstream applyListDataIn;
    applyListDataIn.open("applylist.txt");

    if (!applyListDataIn)
    {
        cout << "\t\t\t\t\t\t\tFile does not exits!";
        return;
    }
    int i = 0;
    while (i < applysize && !applyListDataIn.eof())
    {

        getline(applyListDataIn, ApplySTname[i], ',');
        getline(applyListDataIn, ApplyStFatherName[i], ',');

        applyListDataIn >> ApplySTMarks[i];

        applyListDataIn.ignore();
        getline(applyListDataIn, ApplySTCNIC[i], ',');

        getline(applyListDataIn, ApplySTphoneNo[i], '\n');

        apFlag[i] = true;
        i++;
    }
    apCounter = i; // no of applicants
    applyListDataIn.close();
}
//-----------------------------save the accounts and complain data----------------------------

void saveAccountsRecord(string username[], string password[], string complain[], bool cmpFlag[], int usersize, int uCounter, bool uflag[], int cmpCounter)
{
    ofstream accountsOut;
    accountsOut.open("account.txt");
    int temped = 0;
    if (!accountsOut)
    {
        cout << "\t\t\t\t\t\t\tFile does not exits!";
        return;
    }
    for (int i = 0; i < usersize; i++)
    {
        if (username[i] != "nv" && password[i] != "nv" && uflag[i] != false)
        {
            if (temped == uCounter - 1)
            {
                accountsOut << username[i] << "," << password[i] << "," << complain[i];
            }
            else
            {
                accountsOut << username[i] << "," << password[i] << "," << complain[i] << endl;
                temped++;
            }
        }
    }
    accountsOut.close();
}
//-----------------------------Load the  acounts and complains data----------------------------

void loadAccountsRecord(string username[], string password[], string complain[], bool cmpFlag[], int usersize, int &uCounter, bool uflag[], int &cmpCounter)
{
    ifstream accountsIn;
    accountsIn.open("account.txt");

    if (!accountsIn)
    {
        cout << "\t\t\t\t\t\t\tFile does not exits!";
        return;
    }
    int i = 0;
    while (i < usersize && !accountsIn.eof())
    {

        getline(accountsIn, username[i], ',');
        getline(accountsIn, password[i], ',');

        getline(accountsIn, complain[i], '\n');

        uflag[i] = true;
        cmpFlag[i] = true;
        i++;
    }
    uCounter = i;   // number of user accounts
    cmpCounter = i; // number of complain
    accountsIn.close();
}
