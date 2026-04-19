#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
using namespace std;

// DATA STRUCTURES (Entities)
// Using fixed-size char arrays is crucial for saving to binary .dat files
struct Student 
{
    int studentID;
    char name[50];
    int yearLevel;
    int stressLevel; // 1-10
};

struct Admin 
{
    char username[20];
    char password[20];
};


// FILE HANDLING & CREATION


// Function to check if a file exists, and create it if it doesn't
void initializeFiles() 
{
    const char* files[] = {"students.dat", "cases.dat", "counselors.dat", "admins.dat"};
    
    for (const char* file : files) {
        ifstream checkFile(file, ios::binary);
        if (!checkFile) {
            // File does not exist, create a blank one
            ofstream createFile(file, ios::binary);
            cout << "[SYSTEM] Created missing database file: " << file << endl;
            createFile.close();
            
            // If it's the admin file, create a default admin account
            if (strcmp(file, "admins.dat") == 0) {
                ofstream adminFile(file, ios::binary | ios::app);
                Admin defaultAdmin = {"admin", "password123"};
                adminFile.write(reinterpret_cast<char*>(&defaultAdmin), sizeof(Admin));
                adminFile.close();
                cout << "[SYSTEM] Default admin account created." << endl;
            }
        } else {
            checkFile.close();
        }
    }
    cout << "[SYSTEM] All database files are ready." << endl;
}

// LOGIN SYSTEM
bool adminLogin() 
{
    char inputUser[20];
    char inputPass[20];
    
    cout << "\n--- ADMIN LOGIN ---" << endl;
    cout << "Username: ";
    cin >> inputUser;
    cout << "Password: ";
    cin >> inputPass;
    
    ifstream adminFile("admins.dat", ios::binary);
    Admin tempAdmin;
    
    bool loginSuccess = false;
    // Read through the binary file to find a match
    while (adminFile.read(reinterpret_cast<char*>(&tempAdmin), sizeof(Admin))) {
        if (strcmp(tempAdmin.username, inputUser) == 0 && strcmp(tempAdmin.password, inputPass) == 0) {
            loginSuccess = true;
            break;
        }
    }
    
    adminFile.close();
    return loginSuccess;
}

void studentLogin() 
{
    int id;
    cout << "\n--- STUDENT PORTAL ---" << endl;
    cout << "Enter your Student ID (e.g., 2023001): ";
    cin >> id;
    
    // In a full system, you would search the BST or the students.dat file here to verify
    cout << "Welcome, Student " << id << ". Proceeding to wellness dashboard..." << endl;
    // Call student menu function
}

void loginMenu() 
{
    int choice;
    do {
        cout << "\n======================================" << endl;
        cout << "  CAMPUS WELLNESS & COUNSELING PORTAL " << endl;
        cout << "======================================" << endl;
        cout << "1. Admin / Counselor Login" << endl;
        cout << "2. Student Login (Walk-in / Dashboard)" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                if (adminLogin()) 
                {
                    cout << "\nLogin Successful! Accessing Main Menu...\n";
                    // Call mainAdminMenu()
                } else {
                    cout << "\n[ERROR] Invalid Credentials. Please try again.\n";
                }
                break;
            case 2:
                studentLogin();
                {
                    cout << "\nLogin Successful! Accessing Main Menu...\n";
                }
                break;
            case 3:
                cout << "Exiting system. Stay safe and well!" << endl;
                break;
            default:
                cout << "[ERROR] Invalid choice." << endl;
        }
    } while (choice != 3);
}

// MAIN FUNCTION
int main() 
{
    // 1. Ensure all .dat files exist before the program runs
    initializeFiles();
    
    // 2. Launch the login portal
    loginMenu();
    
    return 0;
}