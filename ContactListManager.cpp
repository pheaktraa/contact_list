#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;
kkkkkkkkkkkkkkkkkkkkkk

void CreateStudentData()
{
    ofstream Myfile("contactList.csv");
    
    int n;
    cout << "Enter N student : "; cin >> n;
    cout << endl;
    cout << "Enter the detail of " << n << " students : " << endl;

    string id;
    char gender;
    string name, email, phone_number;  

    //read input
    for ( int i = 0; i < n; i++)
    {
        // cin >> id >> name >> gender >> email >> phone_number;
        cout << "ID : "; cin >> id;
        cout << "Name : ";
        cin.ignore(); 
        getline(cin,name);
        cout << "Gender : "; cin >> gender;
        cout << "Email : "; cin >> email;
        cout << "Phone Number : "; cin >> phone_number;

        //insert data to file
        Myfile << id << "," << name << "," << gender << "," << email << "," << phone_number << endl;
    }
}

void SearchStudent()
{
    ifstream Myfile;
    Myfile.open("studentd_data.csv");

    //get id student to display
    int idNum, roll2, count = 0;
    cout << "Enter ID of the students to display :"; cin >> idNum;

    //read data form file as string vector
    vector<string> row;
    string line, word;
    // bool found = false;

    //first loop
    while (getline(Myfile, line))
    {
        row.clear();

        //use stringstream to split line by comma
        stringstream s(line);
        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        //check if the idnum match
        // roll2 = stoi(row[0]);
        stringstream ss(row[0]);
        ss >> roll2;

            if (roll2 == idNum)
            {
                count = 1;
                //print data
                cout << "ID : " << row[0] << endl;
                cout << "Name : " << row[1] << endl;
                cout << "Gender : " << row[2] << endl;
                cout << "Email : " << row[3] << endl;
                cout << "Phone-Number : " << row[4] << endl;
                break;
            } 
    }
    if (count == 0)
    {
        cout << "Data not found" << endl;
    }
    Myfile.close();
}

void UpdateStudentData()
{
        // fstream ok;

    ifstream ok("studentd_data.csv");

    //new file
    ofstream newfile ("reportcardnew.csv");

    int rollnum, roll1, count = 0, i;
    // char new_gender;
    // string new_name, new_email, new_phone_number;
    int index;
    string new_data;

    string line, word;
    vector<string> row;

    cout << "Enter roll number to update : ";
    cin >> rollnum;

    char choice;
    cout << "Enter Choice You want to Update (N/G/E/P) : "; 
    cin >> choice;

    if (choice == 'n' || choice == 'N')
    {
        index = 1;
    }
    else if (choice == 'g' || choice == 'G')
    {
        index = 2;
    }
    else if (choice == 'e' || choice == 'E')
    {
        index = 3;
    }
    else if (choice == 'p' || choice == 'P')
    {
        index = 4;
    }
    else 
    {
        cout << "wrong input." << endl;
    }

    cout << "Enter New Data : "; 
    cin.ignore(); 
    getline(cin, new_data);
    //update data
    // cout << "Enter new Name : "; 
    // cin >> new_name;
    // cout << "Enter Gender : ";
    // cin >> new_gender;
    // cout << "Enter new Email : ";
    // cin >> new_email;
    // cout << "Enter new Phone-Number : ";
    // cin >> new_phone_number;

    //update loop 
    while (getline(ok, line))
    {
        row.clear();
        stringstream s(line);

        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        stringstream ss(row[0]);
        ss >> roll1;
        int row_size = row.size();

        if (roll1 == rollnum)
        {
            // count = 1;
            // // row[1] = to_string(new_name);
            // // row[2] = to_string(new_email);
            // // row[3] = to_string(new_phone_number);
            // row[1] = new_name;
            // row[2] = new_gender;
            // row[3] = new_email;
            // row[4] = new_phone_number;
            count = 1; 
            row[index] = new_data;  // Update the specific field with new data
        }

        //
        for (i = 0; i < row_size - 1; i++)
        {
            newfile << row[i] << ",";
        }

        newfile << row[row_size - 1] << "\n";
    }

    if (count == 0)
    {
        cout << "Record not found\n";
    }

    ok.close();
    newfile.close();

    //
    remove("studentd_data.csv");
    rename("reportcardnew.csv", "studentd_data.csv");
}

void DeleteStudentData()
{
        // 
    fstream fin;

    //open existing file
    fin.open("studentd_data.csv");

    //create new file to store non-delete data
    ofstream new_file("reportcardnew.csv");

    int rollnum, roll1, count = 0;
    string line, word;
    vector<string> row;

    //
    cout << "Enter roll num to delete : ";
    cin >> rollnum;

    //
    while (getline(fin, line))
    {
        row.clear();   
        stringstream s(line);

        // string word;
        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        stringstream ss(row[0]);
        ss >> roll1;
        int row_size = row.size();

        //
        if (roll1 != rollnum)
        {
            for (size_t i = 0; i < row.size() - 1; i++)
            {
                new_file << row[i] << ", ";
            }
            new_file << row.back() << "\n";
        }
        else 
        {
            count = 1;
        }
    }

    if (count == 1)
    {
        cout << "Record deleted successfully.\n";
    }
    else 
    {
        cout << "Record not found.\n";
    }

    //
    fin.close();
    new_file.close();

    //
    remove("studentd_data.csv");

    //
    rename("reportcardnew.csv", "studentd_data.csv");
}

int main()
{
    bool condition = true;
    while (condition)
    {
        cout << "\n========================================" << endl;
        cout << "Student System Menu" << endl;
        cout << "1. Create Student Data : " << endl;
        cout << "2. Search Student by Id : " << endl;
        cout << "3. Update Student Data : " << endl;
        cout << "4. Delete Student Data : " << endl;
        cout << "5. Exit" << endl;
        cout << "========================================" << endl;

        int choice;
        cout << "Please Enter Your Choice : "; cin >> choice;

        switch (choice)
        {
        case 1:
            CreateStudentData();
            break;
        case 2:
            SearchStudent();
            break;
        case 3:
            UpdateStudentData();
            break;
        case 4:
            DeleteStudentData();
            break;
        case 5:
            condition = false;
            cout << "Exit Menu.\n";
            break;
        default:
            cout << "Invalid Input.\n";
            break;
        }
    }
}