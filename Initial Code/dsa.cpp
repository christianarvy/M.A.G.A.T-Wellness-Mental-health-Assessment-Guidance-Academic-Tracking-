#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <chrono>
#include <thread>
#include <limits>  // Added for cin.ignore
#include <cstdlib> // Added for atoll
#include <string>  // Added for string operations
#include <sstream> // Added for stringstream
using namespace std;


// DATA STRUCTURES (Entities)
struct Student
{
    long long studentID; // long long yung crocodile haha
    char password[20];
    char name[50];
    int yearLevel;
    int stressLevel; // 1-10
    char assignedCounselor[20];
};


struct Admin
{
    char username[20];
    char password[20];
    char name[50]; // Added to store Admin's real name
};


struct Counselor
{
    char username[20];
    char password[20];
    char name[50];       // Added to store Counselor's real name
    char specialty[100]; // Added to store their specialty
    int assignedYear;
};


struct Case
{
    long long studentID;              // long long yung crocodile haha
    char clinicalObservations[500];   // [1] Clinical Observations
    char discussionSummary[500];      // [2] Discussion Summary
    char professionalAssessment[500]; // [3] Counselor's Assessment
    char actionPlan[500];             // [5] Action Plan (matches Concept)
    char date[20];                    // [DATE/TIME] from concept
};


struct Appointment
{
    char studentID[20]; // Change from char[20] to match Student struct
    char studentName[50];
    char reason[200];
    char preferredDate[20];
    char assignedCounselor[20];
    char type; // 'E' or 'B'
};




// HELPER FUNCTIONS
// Cross-platform screen clear (detects if you are on Windows or Mac/Linux mayabang kase tayo)
void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}


// Helper function to trim whitespace and special characters
string trimString(const string& str)
{
    string result = str;
    // Remove BOM if present
    if (!result.empty() && (unsigned char)result[0] == 0xEF) {
        result.erase(0, 3);
    }
    // Remove leading whitespace
    size_t start = result.find_first_not_of(" \t\r\n");
    if (start == string::npos) return "";
    result = result.substr(start);
    // Remove trailing whitespace
    size_t end = result.find_last_not_of(" \t\r\n");
    if (end != string::npos) result = result.substr(0, end + 1);
    return result;
}


// Simulated loading screen ni daddy Euken
void loadingTransition(const string &message, int seconds)
{
    cout << "\n[SYSTEM] " << message << "..." << endl;
    this_thread::sleep_for(chrono::seconds(seconds));
    clearScreen();
}






// FILE HANDLING & CREATION
void initializeFiles()
{
    const char* files[] = {"students.dat", "cases.dat", "counselors.dat", "admins.dat"};
   
    for (const char* file : files)
    {
       
        ifstream checkFile(file);
        if (!checkFile)
        {
           
            ofstream createFile(file);
            cout << "[SYSTEM] Created missing database file: " << file << endl;
            createFile.close();
            
            // Seed Admin (Ma. Leonila V. Urrea)
            if (strcmp(file, "admins.csv") == 0)
            {
                ofstream adminFile(file, ios::binary | ios::app);
                // Updated Username and Password
                Admin defaultAdmin = {"leonila_urrea", "AdminPass123", "Ma. Leonila V. Urrea"};
                adminFile.write(reinterpret_cast<char*>(&defaultAdmin), sizeof(Admin));
                adminFile.close();
                cout << "[SYSTEM] Default admin account created." << endl;
            }
            
            // Seed Counselors based on specific list
            if (strcmp(file, "counselors.csv") == 0)
            {
                ofstream counselorFile(file, ios::binary | ios::app);
               
                // Updated Usernames based on real names and unique passwords
                Counselor defaultCounselors[5] = {
                    {"antonio_postrado", "Antonio@123", "Antonio C. Postrado Jr.", "Academic, Emotional, Career"},
                    {"jayson_parena", "Jayson@123", "Jayson S. Parena", "Academic, Emotional, Career"},
                    {"janine_bautista", "Janine@123", "Ma. Janine C. Bautista", "Academic, Emotional, Career"},
                    {"arnold_desilva", "Arnold@123", "Arnold A. de Silva", "Psychological Testing (Assessment)"},
                    {"jovine_delacruz", "Jovine@123", "Jovine Dimple L. Dela Cruz", "Administrative Support"}
                };











                for (int i = 0; i < 5; i++) {
                    // Writing as comma-separated values
                    counselorFile << defaultCounselors[i].username << ","
                                  << defaultCounselors[i].password << ","
                                  << defaultCounselors[i].name << ","
                                  << defaultCounselors[i].specialty << "\n";
                }
                
                counselorFile.close();
                cout << "[SYSTEM] Staff counselor accounts seeded." << endl;
            }
















            // Seed default Student
            if (strcmp(file, "students.dat") == 0)
            {
                ofstream studentFile(file, ios::binary | ios::app);
                // Updated assigned counselor to match Jayson's new username
               Student students[] = {








    // ===== FIRST YEAR =====
    {20131155389LL, "macal01", "Macalintal, Lev Ryan F.", 1, 1, "jayson_parena"},
    {20251104485LL, "gran02", "Grande, Clayton Kelsey P.", 1, 1, "jayson_parena"},
    {20231109721LL, "cana03", "Canaveral, Miguel R.", 1, 1, "jayson_parena"},
    {20231123345LL, "ramos04", "Ramos, Rhian Zyrene G.", 1, 1, "jayson_parena"},
    {20251120066LL, "chiu05", "Chiu, Nash Patrick G.", 1, 1, "jayson_parena"},
    {20251123963LL, "alca06", "Alcazar, Maxine Aliyah F.", 1, 1, "jayson_parena"},
    {20251130106LL, "cruz07", "Cruz, Sean Russel D.", 1, 1, "jayson_parena"},
    {20251121161LL, "javi08", "Javier, Zionah Rae M.", 1, 1, "jayson_parena"},
    {20251114564LL, "bern09", "Bernabe, Marx Aaron M.", 1, 1, "jayson_parena"},
    {20251108846LL, "dion10", "Dionisio, Jerich Andrew", 1, 1, "jayson_parena"},
    {20251105412LL, "acun11", "Acuna, Emmanuel Patrick R.", 1, 1, "jayson_parena"},
    {20251131278LL, "guna12", "Gunabe, Jophielle Briggz", 1, 1, "jayson_parena"},
    {20221141259LL, "says13", "Sayson, Ralph Jericho A.", 1, 1, "jayson_parena"},
    {20251123850LL, "lama14", "Lamamigo, Eros", 1, 1, "jayson_parena"},
    {20231137749LL, "igna15", "Ignacio, Axel Audrey D.", 1, 1, "jayson_parena"},
    {20251117643LL, "chua16", "Chua, Cyrus G.", 1, 1, "jayson_parena"},
    {20251108255LL, "isra17", "Israel, Quinn Mallory C.", 1, 1, "jayson_parena"},
    {20191132646LL, "marq18", "Marquez, Manuel Alexander", 1, 1, "jayson_parena"},
    {20251129609LL, "rata19", "Rata, Rean May", 1, 1, "jayson_parena"},
    {20231128975LL, "yamb20", "Yambao, Zuriel Ethan P.", 1, 1, "jayson_parena"},








    // ===== SECOND YEAR =====
    {20241113019LL, "ranc21", "Rance, Princess Nicole R.", 2, 1, "antonio_postrado"},
    {20241102346LL, "alde22", "Alde, Patrick P.", 2, 1, "antonio_postrado"},
    {20221105062LL, "baut23", "Bautista, Argelina Ryle P.", 2, 1, "antonio_postrado"},
    {20241123375LL, "alde24", "Aldeguer, Seun Gyrich I.", 2, 1, "antonio_postrado"},
    {20241120229LL, "gabi25", "Gabiano, Karl Sebastian B.", 2, 1, "antonio_postrado"},
    {20241120810LL, "gasp26", "Gaspi, Jay Lord F.", 2, 1, "antonio_postrado"},
    {20241117362LL, "jule27", "Jules, Roven", 2, 1, "antonio_postrado"},
    {20221112603LL, "bern28", "Bermardo, Tj", 2, 1, "antonio_postrado"},
    {20241120809LL, "timb29", "Timbol, Alexandria T.", 2, 1, "antonio_postrado"},
    {20241130029LL, "lope30", "Lopez, Gwen Angelynn", 2, 1, "antonio_postrado"},
    {20241116336LL, "roqu31", "Roque, Kayne Bernadette M.", 2, 1, "antonio_postrado"},
    {20241107313LL, "eyst32", "Eystaquio, Mariane", 2, 1, "antonio_postrado"},
    {20241141071LL, "dela33", "Dela Cruz, John Patrick", 2, 1, "antonio_postrado"},
    {20221124523LL, "jane34", "Janer, Jenny Rose M.", 2, 1, "antonio_postrado"},
    {20221104923LL, "nem35", "Nem, Hernan Jay", 2, 1, "antonio_postrado"},
    {20181114136LL, "park36", "Park, Chang Hyun A.", 2, 1, "antonio_postrado"},
    {20241126307LL, "tamp37", "Tampus, Jevric", 2, 1, "antonio_postrado"},
    {20241125746LL, "tole38", "Tolentino, Angela D.", 2, 1, "antonio_postrado"},
    {20241124674LL, "adam39", "Adame, Jennilie A.", 2, 1, "antonio_postrado"},
    {20221115635LL, "ogue40", "Oguez, John Meynaro R.", 2, 1, "antonio_postrado"},








    // ===== THIRD YEAR =====
    {20231110057LL, "coco41", "Coco, James H.", 3, 1, "janine_bautista"},
    {20131147803LL, "pine42", "Pineda, Franz Luis", 3, 1, "janine_bautista"},
    {20161137764LL, "ting43", "Ting, Aljiemer A.", 3, 1, "janine_bautista"},
    {20237144006LL, "goro44", "Gorospe, Rein Klyde T.", 3, 1, "janine_bautista"},
    {20211102453LL, "bonz45", "Bonzon, Aldrich", 3, 1, "janine_bautista"},
    {20231119974LL, "magr46", "Magrata, Renz", 3, 1, "janine_bautista"},
    {20211106739LL, "libr47", "Librada, Charles Bryan L.", 3, 1, "janine_bautista"},
    {20231143401LL, "bedi48", "Bedis, Ronwin Adlai B.", 3, 1, "janine_bautista"},
    {20111135659LL, "tiba49", "Tibay, Hyrile", 3, 1, "janine_bautista"},
    {20211114668LL, "rana50", "Rana, Adrian", 3, 1, "janine_bautista"},
    {20231128555LL, "vill51", "Villaflor, Kyle L.", 3, 1, "janine_bautista"},
    {20191151721LL, "cara52", "Carao, Johnleez", 3, 1, "janine_bautista"},
    {20231120140LL, "hale53", "Hale, Hannah Grace E.", 3, 1, "janine_bautista"},
    {20231150122LL, "gamb54", "Gambao, Rhamuel G.", 3, 1, "janine_bautista"},
    {20231123083LL, "yita55", "Yitalyu, Mark Andrew", 3, 1, "janine_bautista"},
    {20231125874LL, "baus56", "Bauson, John Carlo T.", 3, 1, "janine_bautista"},
    {20211115901LL, "rons57", "Ronsairo, Tordan P.", 3, 1, "janine_bautista"},
    {20211105452LL, "dial58", "Dialino, Rny Marc A.", 3, 1, "janine_bautista"},
    {20231135618LL, "bayo59", "Bayona, Ralph", 3, 1, "janine_bautista"},
    {20231114933LL, "simb60", "Simbulan, Anton Francis J.", 3, 1, "janine_bautista"},








    // ===== FOURTH YEAR =====
    {20221129620LL, "cruz61", "Cruz, Fyi James J.", 4, 1, "arnold_desilva"},
    {20171109323LL, "rock62", "Rock, Chester M.", 4, 1, "arnold_desilva"},
    {20161117744LL, "laca63", "Lacay, Tristan Russel M.", 4, 1, "arnold_desilva"},
    {20221132054LL, "go64", "Go, Hans Stephen", 4, 1, "arnold_desilva"},
    {20201129961LL, "buen65", "Buenaventura, Ai Francis", 4, 1, "arnold_desilva"},
    {20211106739LL, "libr66", "Librada, Charles", 4, 1, "arnold_desilva"},
    {20221131244LL, "nava67", "Navaro, Juanabel E.", 4, 1, "arnold_desilva"},
    {20221130354LL, "paja68", "Pajarillaga, Jasmine Rose R.", 4, 1, "arnold_desilva"},
    {20221133228LL, "bayl69", "Baylon, Trisha", 4, 1, "arnold_desilva"},
    {20221103288LL, "mark70", "Mark Geoffrey", 4, 1, "arnold_desilva"},
    {20221120509LL, "dona71", "Donayre, Willianne Lorraine M.", 4, 1, "arnold_desilva"},
    {20221119159LL, "conc72", "Conception, Liam Pyro P.", 4, 1, "arnold_desilva"},
    {20201107564LL, "vino73", "Vinoya, John Joneil", 4, 1, "arnold_desilva"},
    {20201107622LL, "dizo74", "Dizon, Marc", 4, 1, "arnold_desilva"},
    {20221100830LL, "anir75", "Anirion, Cristian F.", 4, 1, "arnold_desilva"},
    {20221100410LL, "bern76", "Bernardino, Bryan G.", 4, 1, "arnold_desilva"},
    {20221129880LL, "fran77", "Franco, Ivan B.", 4, 1, "arnold_desilva"},
    {2021135155LL, "agui78", "Aguire, Angelito B.", 4, 1, "arnold_desilva"},
    {20221105312LL, "marv79", "Marivic, John", 4, 1, "arnold_desilva"},
    {20221131038LL, "san80", "Santos, Maria", 4, 1, "arnold_desilva"}
};








int numStudents = sizeof(students) / sizeof(Student);
    for (int i = 0; i < numStudents; i++) {
    // This writes the student data to a single line, separated by spaces and a pipe
    studentFile << students[i].studentID << " "
                << students[i].password << " "
                << students[i].name << "|"
                << students[i].yearLevel << " "
                << students[i].stressLevel << " "
                << students[i].assignedCounselor << endl;
    }
                studentFile.close();
                cout << "[SYSTEM] Default student accounts seeded." << endl;
            }
        } else {
            checkFile.close();
        }
    }
    cout << "[SYSTEM] All database files are ready." << endl;
    this_thread::sleep_for(chrono::seconds(2));
    clearScreen();
}


// ALGORITHMS
// 1. Helper function for Quick Sort (Swaps two Student records)
void swapStudents(Student &a, Student &b)
{
    Student temp = a;
    a = b;
    b = temp;
}


// 2. Partition function for Quick Sort
int partitionByID(vector<Student> &arr, int low, int high)
{
    long long pivot = arr[high].studentID; // Choosing the last element as the pivot
    int i = (low - 1);                     // Index of the smaller element


    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j].studentID < pivot)
        {
            i++;
            swapStudents(arr[i], arr[j]);
        }
    }
    swapStudents(arr[i + 1], arr[high]);
    return (i + 1);
}


// 3. The actual Quick Sort Function (Sort by Student ID)
void quickSortByID(vector<Student> &arr, int low, int high)
{
    if (low < high)
    {
        // pi is the partitioning index, arr[pi] is now at the right place
        int pi = partitionByID(arr, low, high);


        // Separately sort elements before and after partition
        quickSortByID(arr, low, pi - 1);
        quickSortByID(arr, pi + 1, high);
    }
}


// 4. Partition function for Quick Sort by Priority (Stress Level descending)
int partitionByPriority(Student arr[], int low, int high)
{
    int pivot = arr[high].stressLevel;
    int i = low - 1;


    for (int j = low; j < high; j++)
    {
        if (arr[j].stressLevel > pivot)
        {
            i++;
            swapStudents(arr[i], arr[j]);
        }
    }
    swapStudents(arr[i + 1], arr[high]);
    return i + 1;
}


// 5. Quick Sort by Priority
void quickSortPriority(Student arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partitionByPriority(arr, low, high);
        quickSortPriority(arr, low, pi - 1);
        quickSortPriority(arr, pi + 1, high);
    }
}


// Perfect for sorted, non-uniform data like real Student Numbers.
int binarySearch(const vector<Student> &arr, long long targetID)
{
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right)
    {
        // Calculate mid this way to prevent integer overflow on massive arrays
        int mid = left + (right - left) / 2;


        // 1. Target found!
        if (arr[mid].studentID == targetID)
        {
            return mid;
        }


        // 2. If target is greater, ignore the left half
        if (arr[mid].studentID < targetID)
        {
            left = mid + 1;
        }


        // 3. If target is smaller, ignore the right half
        else
        {
            right = mid - 1;
        }
    }


    // Target was not found in the array
    return -1;
}


// ADMIN FUNCTIONALITIES
void adminAddStudent()
{
    clearScreen();
    cout << "==================================================" << endl;
    cout << "               REGISTER NEW STUDENT               " << endl;
    cout << "==================================================" << endl;
   
    Student newStudent;
   
    cout << "Enter Student ID: ";
    cin >> newStudent.studentID;
   
    cout << "Enter Password: ";
    cin >> newStudent.password;
   
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
   
    cout << "Enter Full Name: ";
    cin.getline(newStudent.name, 50);
   
    cout << "Enter Year Level (1-4): ";
    cin >> newStudent.yearLevel;
   
    cout << "Enter Initial Stress Level (1-10): ";
    cin >> newStudent.stressLevel;
   
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
   
    cout << "Assign to Counselor (Enter Username): ";
    cin.getline(newStudent.assignedCounselor, 20);
   
    // Write strictly to CSV! (nalimutan iadd bobo)
    ofstream outFile("students.csv", ios::app);
    outFile << newStudent.studentID << ","
            << newStudent.password << ","
            << newStudent.name << ","
            << newStudent.yearLevel << ","
            << newStudent.stressLevel << ","
            << newStudent.assignedCounselor << "\n";
    outFile.close();
   
    cout << "\n[SYSTEM] Student successfully registered to the database!" << endl;
    this_thread::sleep_for(chrono::seconds(2));
}


void adminAddCounselor()
{
    clearScreen();
    cout << "==================================================" << endl;
    cout << "              REGISTER NEW COUNSELOR              " << endl;
    cout << "==================================================" << endl;
   
    Counselor newCounselor;
   
    cout << "Enter System Username: ";
    cin >> newCounselor.username;
   
    cout << "Enter Initial Password: ";
    cin >> newCounselor.password;
   
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
   
    cout << "Enter Full Name: ";
    cin.getline(newCounselor.name, 50);
   
    cout << "Enter Department/Specialty: ";
    cin.getline(newCounselor.specialty, 100);
   
    //Write strictly to CSV! (nabaliw ako dito slight)
    ofstream outFile("counselors.csv", ios::app);
    outFile << newCounselor.username << ","
            << newCounselor.password << ","
            << newCounselor.name << ","
            << newCounselor.specialty << "\n";
    outFile.close();
   
    cout << "\n[SYSTEM] Counselor successfully added to the system!" << endl;
    this_thread::sleep_for(chrono::seconds(2));
}




void adminViewCounselors()
{
    clearScreen();
    cout << "========================================================================================================================" << endl;
    cout << "                                              ACTIVE COUNSELOR STAFF                                                    " << endl;
    cout << "========================================================================================================================" << endl;


    cout << left
         << setw(10) << "ID"
         << setw(25) << "USERNAME"
         << setw(35) << "FULL NAME"
         << "SPECIALTY" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;


    ifstream file("counselors.csv");


    if (!file)
    {
        cout << "\n [ERROR] Counselor database not found." << endl;
    }
    else
    {
        string line;
        int count = 0;


        while (getline(file, line))
        {
            stringstream ss(line);
            string username, password, name, specialty;
            getline(ss, username, ',');
            getline(ss, password, ',');
            getline(ss, name, ',');
            getline(ss, specialty);


            Counselor temp;
            strcpy(temp.username, username.c_str());
            strcpy(temp.password, password.c_str());
            strcpy(temp.name, name.c_str());
            strcpy(temp.specialty, specialty.c_str());
            temp.assignedYear = 0;


            count++;


            // We use string(array) to ensure C++ handles the null terminator properly
            cout << left
                 << "[" << setw(7) << to_string(count) + "]"
                 << setw(25) << temp.username
                 << setw(35) << temp.name
                 << temp.specialty << endl;
        }


        if (count == 0)
            cout << " > No counselor staff currently registered." << endl;
        file.close();
    }


    cout << "========================================================================================================================" << endl;
    cout << "\nPress Enter to return...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}


// DASHBOARDS
void studentDashboard(Student currentStudent)
{
    int choice = 0;
    do
    {
        clearScreen();
        cout << "==================================================" << endl;
        cout << "            STUDENT WELLNESS DASHBOARD            " << endl;
        cout << "==================================================" << endl;
        cout << "Greetings, " << currentStudent.name << "! How can we support you today?\n"
             << endl;


        cout << " 1. View Student Profile & Schedules" << endl;
        cout << " 2. Assessment" << endl;
        cout << " 3. Emergency" << endl;
        cout << " 4. View Resource Recommendations" << endl;
        cout << " 5. Book Counseling Session" << endl;
        cout << " 6. Logout" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << "Enter choice: ";


        cin >> choice;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = -1;
        }


        switch (choice)
        {
        case 1:
            loadingTransition("Fetching student profile and schedules", 1);
            clearScreen();
            cout << "==================================================" << endl;
            cout << "                YOUR STUDENT PROFILE              " << endl;
            cout << "==================================================" << endl;
            cout << " Name               : " << currentStudent.name << endl;
            cout << " Student ID         : " << currentStudent.studentID << endl;
            cout << " Year Level         : " << currentStudent.yearLevel << endl;
            cout << " Stress Level       : " << currentStudent.stressLevel << " / 10" << endl;
            cout << " Assigned Counselor : " << currentStudent.assignedCounselor << endl;
            cout << "--------------------------------------------------" << endl;
            cout << "             UPCOMING COUNSELING SESSIONS         " << endl;
            cout << "--------------------------------------------------" << endl;
            cout << " > No appointments currently scheduled." << endl;
            cout << "==================================================" << endl;
            cout << "\nPress Enter to return to the dashboard...";


            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            break;


        case 2:
            loadingTransition("Opening assessment module", 1);
            break;
        case 3:
            loadingTransition("Connecting to emergency drop-in line", 1);
            break;
        case 4:
            loadingTransition("Loading wellness graph resources", 1);
            break;
       
        case 5:
        {
            loadingTransition("Opening counseling session scheduler", 1);
            clearScreen();
            cout << "==================================================" << endl;
            cout << "            BOOK COUNSELING SESSION               " << endl;
            cout << "==================================================" << endl;


            Appointment newAppt;
            strcpy(newAppt.studentID, to_string(currentStudent.studentID).c_str());
            strcpy(newAppt.studentName, currentStudent.name);
            strcpy(newAppt.assignedCounselor, currentStudent.assignedCounselor);  // Add this line


            cout << "Enter reason for session: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.getline(newAppt.reason, 200);


            cout << "Enter preferred date (MM/DD/YYYY): ";
            cin.getline(newAppt.preferredDate, 20);


            newAppt.type = 'B';


            ofstream outFile("appointments.csv", ios::app);
            outFile << newAppt.studentID << ",\"" << newAppt.studentName << "\"," << newAppt.reason << "," << newAppt.preferredDate << "," << newAppt.assignedCounselor << "," << newAppt.type << "\n";  // Updated with quoted name to handle commas
            outFile.close();


            cout << "\n[SYSTEM] Counseling session booked successfully!" << endl;
            this_thread::sleep_for(chrono::seconds(2));
            break;
        }
        case 6:
            loadingTransition("Logging out safely", 1);
            break;
        default:
            cout << "[ERROR] Invalid choice. Please try again." << endl;
            this_thread::sleep_for(chrono::seconds(1));
        }
    } while (choice != 6); // Updated to exit on choice 6 lmao
}


void counselorDashboard(Counselor currentCounselor)
{
    int choice = 0;
    do
    {
        clearScreen();
        cout << "==================================================" << endl;
        cout << "               COUNSELOR DASHBOARD                " << endl;
        cout << "==================================================" << endl;
        // Updated to show their real name instead of username
        cout << "Welcome back, " << currentCounselor.name << ".\n";
        cout << "Specialty: " << currentCounselor.specialty << "\n"
             << endl;


        cout << " 1. View Assigned Cases" << endl;
        cout << " 2. Log New Counseling Case (BST)" << endl;
        cout << " 3. Search Case History by ID" << endl;
        cout << " 4. View Emergency Walk-in Queue" << endl;
        cout << " 5. Sort Students by Wellness Priority (Quick Sort)" << endl;
        cout << " 6. Logout" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << "Enter choice: ";


        cin >> choice;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = -1;
        }


        switch (choice)
        {
        case 1:
        {
            loadingTransition("Fetching assigned case files", 1);
            clearScreen();
            cout << "==================================================" << endl;
            cout << "               YOUR ASSIGNED CASES                " << endl;
            cout << "==================================================" << endl;


            ifstream studentFile("students.csv");
            string line;
            int caseCount = 0;


            while (getline(studentFile, line))
            {
                if (line.empty()) continue;
               
                stringstream ss(line);
                string idStr, password, name, yearStr, stressStr, counselor;
                getline(ss, idStr, ',');
                getline(ss, password, ',');
                getline(ss, name, ',');
                getline(ss, yearStr, ',');
                getline(ss, stressStr, ',');
                getline(ss, counselor);


                // Trim all strings
                idStr = trimString(idStr);
                yearStr = trimString(yearStr);
                stressStr = trimString(stressStr);
                counselor = trimString(counselor);
               
                if (idStr.empty() || yearStr.empty() || stressStr.empty()) continue;


                try {
                    Student tempStudent;
                    tempStudent.studentID = stoll(idStr);
                    strcpy(tempStudent.password, password.c_str());
                    strcpy(tempStudent.name, name.c_str());
                    tempStudent.yearLevel = stoi(yearStr);
                    tempStudent.stressLevel = stoi(stressStr);
                    strcpy(tempStudent.assignedCounselor, counselor.c_str());


                    //  ONLY shows students explicitly assigned to THIS counselor
                    if (strcmp(tempStudent.assignedCounselor, currentCounselor.username) == 0)
                    {
                        caseCount++;
                        cout << " [" << caseCount << "] ID: " << tempStudent.studentID
                             << " | Name: " << tempStudent.name << " | Stress Level: " << tempStudent.stressLevel << endl;
                    }
                } catch (...) { continue; }
            }
            studentFile.close();


            // Now display BOOKED APPOINTMENTS for assigned students
            cout << "\n--------------------------------------------------" << endl;
            cout << "        BOOKED COUNSELING SESSIONS                " << endl;
            cout << "--------------------------------------------------" << endl;
           
            ifstream apptFile("appointments.csv");
            int apptCount = 0;
           
            if (apptFile) {
                string apptLine;
                while (getline(apptFile, apptLine)) {
                    if (apptLine.empty()) continue;
                   
                    // Parse appointments with quoted names
                    stringstream ss(apptLine);
                    string sid, sname, reason, date, counselor;
                   
                    getline(ss, sid, ',');
                   
                    // Handle quoted name
                    if (ss.peek() == '\"') {
                        ss.ignore(); // skip opening quote
                        getline(ss, sname, '\"');
                        ss.ignore(); // skip comma after closing quote
                    } else {
                        getline(ss, sname, ',');
                    }
                   
                    getline(ss, reason, ',');
                    getline(ss, date, ',');
                    getline(ss, counselor, ',');
                   
                    // Trim strings
                    sid = trimString(sid);
                    sname = trimString(sname);
                    reason = trimString(reason);
                    date = trimString(date);
                    counselor = trimString(counselor);
                   
                    if (sid.empty()) continue;
                   
                    // Only show if assigned to this counselor
                    if (counselor == string(currentCounselor.username)) {
                        apptCount++;
                        cout << " [" << (caseCount + apptCount) << "] BOOKING - Student: " << sid << " (" << sname << ")" << endl;
                        cout << "    Date: " << date << " | Reason: " << reason << endl;
                    }
                }
                apptFile.close();
            }


            if (caseCount == 0 && apptCount == 0)
            {
                cout << " > No cases or bookings currently assigned to you." << endl;
            }


            cout << "==================================================" << endl;
            cout << "\nPress Enter to return to the dashboard...";


            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            break;
        }


        case 2: // Log New Counseling Case & Update Stress Level (Idea B ata to malay ko)
        {
            Case newCase;
            int professionalStressLevel;


            loadingTransition("Logging New Counseling Case", 1);
            clearScreen();
            cout << "==================================================" << endl;
            cout << "          NEW SESSION LOG: CLINICAL FINDINGS      " << endl;
            cout << "==================================================" << endl;


            cout << "Enter Target Student ID: ";
            cin >> newCase.studentID;
            cin.ignore(1000, '\n');


            cout << "\n[1] CLINICAL OBSERVATIONS:" << endl;
            cout << ">> Enter appearance/demeanor: ";
            cin.getline(newCase.clinicalObservations, 500);


            cout << "\n[2] DISCUSSION SUMMARY:" << endl;
            cout << ">> Brief notes on session topics: ";
            cin.getline(newCase.discussionSummary, 500);


            cout << "\n[3] COUNSELOR'S ASSESSMENT:" << endl;
            cout << ">> Your professional findings: ";
            cin.getline(newCase.professionalAssessment, 500);


            cout << "\n[4] ACTION PLAN:" << endl;
            cout << ">> Next steps for the student: ";
            cin.getline(newCase.actionPlan, 500);


            cout << "\n[5] DATE (MM/DD/YYYY): ";
            cin.getline(newCase.date, 20);


            // Append to cases.csv
            ofstream outFile("cases.csv", ios::app);
            if (outFile)
            {
                outFile << newCase.studentID << "," << newCase.clinicalObservations << "," << newCase.discussionSummary << "," << newCase.professionalAssessment << "," << newCase.actionPlan << "," << newCase.date << "\n";
                outFile.close();
                cout << "\n[SYSTEM] Saving findings to cases.csv... Success." << endl;
            }


            // --- IDEA B: PROFESSIONAL OVERRIDE ---
            cout << "\n--------------------------------------------------" << endl;
            cout << "[STRESS LEVEL RE-EVALUATION]" << endl;
            cout << ">> Enter new Professional Stress Level (1-10): ";
            cin >> professionalStressLevel;


            // Update students.csv
            vector<Student> students;
            ifstream inFile("students.csv");
            string csvline;
            bool studentFound = false;


            while (getline(inFile, csvline))
            {
                if (csvline.empty()) continue;
               
                stringstream ss(csvline);
                string idStr, password, name, yearStr, stressStr, counselor;
                getline(ss, idStr, ',');
                getline(ss, password, ',');
                getline(ss, name, ',');
                getline(ss, yearStr, ',');
                getline(ss, stressStr, ',');
                getline(ss, counselor);


                // Trim all strings
                idStr = trimString(idStr);
                yearStr = trimString(yearStr);
                stressStr = trimString(stressStr);
               
                if (idStr.empty() || yearStr.empty() || stressStr.empty()) continue;


                try {
                    Student tempStud;
                    tempStud.studentID = stoll(idStr);
                    strcpy(tempStud.password, password.c_str());
                    strcpy(tempStud.name, name.c_str());
                    tempStud.yearLevel = stoi(yearStr);
                    tempStud.stressLevel = stoi(stressStr);
                    strcpy(tempStud.assignedCounselor, counselor.c_str());


                    if (tempStud.studentID == newCase.studentID)
                    {
                        tempStud.stressLevel = professionalStressLevel;
                        studentFound = true;
                    }
                    students.push_back(tempStud);
                } catch (...) { continue; }
            }
            inFile.close();


            if (studentFound)
            {
                ofstream outFile2("students.csv");
                for (const auto& stud : students)
                {
                    outFile2 << stud.studentID << "," << stud.password << "," << stud.name << "," << stud.yearLevel << "," << stud.stressLevel << "," << stud.assignedCounselor << "\n";
                }
                outFile2.close();
                cout << "[SYSTEM] Student stressLevel updated to " << professionalStressLevel << " in students.csv." << endl;
            }
            else
            {
                cout << "[ERROR] Student ID not found in students.csv." << endl;
            }


            cout << "\nPress Enter to return to Dashboard...";
            cin.ignore(1000, '\n');
            cin.get();
            break;
        }


        case 3: // Search Case History by ID
        {
            char searchID[20];
            Case tempCase;
            bool found = false;


            loadingTransition("Searching case history", 1);
            clearScreen();
            cout << "==================================================" << endl;
            cout << "           Search Case History by ID              " << endl;
            cout << "==================================================" << endl;


            cout << "Enter Student ID (SN) to pull history: ";
            cin >> searchID;


            ifstream inFile("cases.csv");
            if (!inFile)
            {
                cout << "[SYSTEM] No history records found." << endl;
                break;
            }


            cout << "\nPulling past sessions for: " << searchID << endl;
            cout << "--------------------------------------------------" << endl;


            string line;
            while (getline(inFile, line))
            {
                stringstream ss(line);
                string idStr, obs, summary, assess, plan, date;
                getline(ss, idStr, ',');
                getline(ss, obs, ',');
                getline(ss, summary, ',');
                getline(ss, assess, ',');
                getline(ss, plan, ',');
                getline(ss, date);


                Case tempCase;
                tempCase.studentID = stoll(idStr);
                strcpy(tempCase.clinicalObservations, obs.c_str());
                strcpy(tempCase.discussionSummary, summary.c_str());
                strcpy(tempCase.professionalAssessment, assess.c_str());
                strcpy(tempCase.actionPlan, plan.c_str());
                strcpy(tempCase.date, date.c_str());


                if (tempCase.studentID == atoll(searchID))
                {
                    found = true;
                    cout << "\n[DATE]: " << tempCase.date << endl;
                    cout << "[OBSERVATIONS]: " << tempCase.clinicalObservations << endl;
                    cout << "[SUMMARY]:      " << tempCase.discussionSummary << endl;
                    cout << "[ASSESSMENT]:   " << tempCase.professionalAssessment << endl;
                    cout << "[ACTION PLAN]:  " << tempCase.actionPlan << endl;
                    cout << "--------------------------------------------------" << endl;
                }
            }


            if (!found)
                cout << "[SYSTEM] No past session history found." << endl;
            inFile.close();


            cout << "\nPress Enter to return to Dashboard...";
            cin.ignore(1000, '\n');
            cin.get();
            break;
        }


               case 4:
        {
            Appointment tempAppt;
            bool foundAny = false;


            loadingTransition("Syncing with appointments.csv", 1);
            clearScreen();
            cout << "==================================================" << endl;
            cout << "              ACTIVE SESSION QUEUE                " << endl;
            cout << "==================================================" << endl;


            ifstream inFile("appointments.csv");
            if (!inFile)
            {
                cout << "[System] No appointments or emergencies found." << endl;
                // No break here
            }
            else
            {
                vector<Appointment> appointments;
                string line;
                while (getline(inFile, line))
                {
                    stringstream ss(line);
                    string sid, sname, reason, date, counselor, typeStr;
                    getline(ss, sid, ',');
                    getline(ss, sname, ',');
                    getline(ss, reason, ',');
                    getline(ss, date, ',');
                    getline(ss, counselor, ',');  // Add this for assignedCounselor
                    getline(ss, typeStr);  // type is now the 6th field


                    Appointment tempAppt;
                    strcpy(tempAppt.studentID, sid.c_str());
                    strcpy(tempAppt.studentName, sname.c_str());
                    strcpy(tempAppt.reason, reason.c_str());
                    strcpy(tempAppt.preferredDate, date.c_str());
                    strcpy(tempAppt.assignedCounselor, counselor.c_str());  // Add this
                    tempAppt.type = typeStr[0];


                    appointments.push_back(tempAppt);
                }
                inFile.close();


                // PASS 1: Emergencies First (only for assigned students)
                cout << "\n[ !!! EMERGENCY ALERTS !!! ]" << endl;
                for (const auto& appt : appointments)
                {
                    if (appt.type == 'E' || appt.type == 'e')
                    {
                        if (strcmp(appt.assignedCounselor, currentCounselor.username) == 0)  // Add this filter
                        {
                            foundAny = true;
                            cout << "STUDENT: " << appt.studentID << " | " << appt.studentName << endl;
                            cout << "REASON:  " << appt.reason << endl;
                            cout << "--------------------------------------------------" << endl;
                        }
                    }
                }


                // PASS 2: Standard Bookings (only for assigned students)
                cout << "\n[ STANDARD BOOKINGS ]" << endl;
                for (const auto& appt : appointments)
                {
                    if (appt.type == 'B' || appt.type == 'b')
                    {
                        if (strcmp(appt.assignedCounselor, currentCounselor.username) == 0)  // Add this filter
                        {
                            foundAny = true;
                            cout << "DATE:    " << appt.preferredDate << endl;
                            cout << "STUDENT: " << appt.studentID << " | " << appt.studentName << endl;
                            cout << "REASON:  " << appt.reason << endl;
                            cout << "--------------------------------------------------" << endl;
                        }
                    }
                }
            }


            if (!foundAny && !(!inFile))
                cout << "Queue is currently empty." << endl;


            cout << "\nPress Enter to return to Dashboard...";
            cin.ignore(1000, '\n');
            cin.get();
            break;
        }


        case 5: // Wellness Priority List
        {
            vector<Student> students;
            ifstream countFile("students.csv");
            if (!countFile)
            {
                cout << "[ERROR] Student database not found." << endl;
                cout << "\nPress Enter to return...";
                cin.ignore(1000, '\n');
                cin.get();
                break;
            }


            string line;
            while (getline(countFile, line))
            {
                if (line.empty()) continue;
               
                stringstream ss(line);
                string idStr, password, name, yearStr, stressStr, counselor;
                getline(ss, idStr, ',');
                getline(ss, password, ',');
                getline(ss, name, ',');
                getline(ss, yearStr, ',');
                getline(ss, stressStr, ',');
                getline(ss, counselor);


                // Trim all strings
                idStr = trimString(idStr);
                yearStr = trimString(yearStr);
                stressStr = trimString(stressStr);
               
                if (idStr.empty() || yearStr.empty() || stressStr.empty()) continue;


                try {
                    Student temp;
                    temp.studentID = stoll(idStr);
                    strcpy(temp.password, password.c_str());
                    strcpy(temp.name, name.c_str());
                    temp.yearLevel = stoi(yearStr);
                    temp.stressLevel = stoi(stressStr);
                    strcpy(temp.assignedCounselor, counselor.c_str());


                    students.push_back(temp);
                } catch (...) { continue; }
            }
            countFile.close();


            if (students.empty())
            {
                cout << "[SYSTEM] No students registered yet." << endl;
                cout << "\nPress Enter to return...";
                cin.ignore(1000, '\n');
                cin.get();
                break;
            }


            quickSortPriority(students.data(), 0, students.size() - 1);


            //DISPLAY LOOP
            cout << "Rank | ID           | Name                 | Stress Level" << endl;
            cout << "----------------------------------------------------------------" << endl;


            int pRank = 1;        // Changed 'rank' to 'pRank' to fix std::rank error
            bool isFound = false; // Changed 'foundAssessed' to 'isFound' to be safe (uyy safe)


            for (size_t i = 0; i < students.size(); i++)
            {
                // Filter students with valid stress levels
                if (students[i].stressLevel > 1 && students[i].stressLevel <= 10)
                {
                    isFound = true;
                    cout << "  " << pRank << "  | "
                         << students[i].studentID << " | "
                         << students[i].name << " | "
                         << students[i].stressLevel << " / 10" << endl;
                    pRank++;
                }
            }


            if (!isFound)
            {
                cout << "\n > No priority cases found (All levels are 1 or 0)." << endl;
            }
            cout << "\nPress Enter to return to Dashboard...";
            cin.ignore(1000, '\n');
            cin.get();
            break;
        }


        case 6: // Logout
            cout << "Logging out... Returning to Main Menu." << endl;
            return;


        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 6);
}


void adminDashboard(Admin currentAdmin)
{
    int choice = 0;
    do
    {
        clearScreen();
        cout << "==================================================" << endl;
        cout << "                 ADMIN DASHBOARD                  " << endl;
        cout << "==================================================" << endl;
        cout << "System Administrator: " << currentAdmin.name << ".\n"
             << endl;


        cout << " 1. Add New Student" << endl;
        cout << " 2. Add New Counselor Staff" << endl;
        cout << " 3. View Active Counselor Staff" << endl;
        cout << " 4. Logout" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << "Enter choice: ";


        cin >> choice;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = -1;
        }


        switch (choice)
        {
        case 1:
            loadingTransition("Opening student registration form", 1);
            adminAddStudent();
            break;
        case 2:
            loadingTransition("Opening counselor registration form", 1);
            adminAddCounselor();
            break;
        case 3:
            loadingTransition("Retrieving counselor staff list", 1);
            adminViewCounselors();
            break;
        case 4:
            loadingTransition("Logging out securely", 1);
            return; // Exit the dashboard immediately on logout
        default:
            cout << "[ERROR] Invalid choice. Please try again." << endl;
            this_thread::sleep_for(chrono::seconds(1));
        }
    } while (choice != 4);
}


// LOGIN SYSTEMS
bool adminLogin(Admin &loggedInAdmin)
{
    char inputUser[20]; char inputPass[20]; bool loginSuccess = false;


    while (!loginSuccess) {
        cout << "\n--- ADMIN LOGIN ---" << endl;
        cout << "Username (or type 'exit' to cancel): "; cin >> inputUser;
        if (strcmp(inputUser, "exit") == 0) return false;


        cout << "Password: "; cin >> inputPass;


        // Look in CSV!
        ifstream adminFile("admins.csv");
        string line;


        while (getline(adminFile, line)) {
            if (line.empty()) continue;
           
            stringstream ss(line);
            string user, pass, name;
            getline(ss, user, ','); getline(ss, pass, ','); getline(ss, name, ',');


            // Cleanup invisible formatting (taena nasisira nung una pag inopen mo yung csv file)
            user = trimString(user);
            pass = trimString(pass);
            name = trimString(name);
           
            if (user.empty() || pass.empty()) continue;


            if (user == string(inputUser) && pass == string(inputPass)) {
                loginSuccess = true;
                strcpy(loggedInAdmin.username, user.c_str());
                strcpy(loggedInAdmin.password, pass.c_str());
                strcpy(loggedInAdmin.name, name.c_str());
                break;
            }
        }
        adminFile.close();


        if (!loginSuccess) {
            cout << "\n[ERROR] Invalid credentials. Please try again.\n";
            this_thread::sleep_for(chrono::seconds(2)); clearScreen();
        }
    }
    return loginSuccess;
}


bool counselorLogin(Counselor &loggedInCounselor)
{
    char inputUser[20]; char inputPass[20]; bool loginSuccess = false;


    while (!loginSuccess) {
        cout << "\n--- COUNSELOR LOGIN ---" << endl;
        cout << "Username (or type 'exit' to cancel): "; cin >> inputUser;
        if (strcmp(inputUser, "exit") == 0) return false;


        cout << "Password: "; cin >> inputPass;


       
        ifstream counselorFile("counselors.csv");
        string line;


        while (getline(counselorFile, line)) {
            if (line.empty()) continue;
           
            stringstream ss(line);
            string user, pass, name, spec;
            getline(ss, user, ','); getline(ss, pass, ','); getline(ss, name, ','); getline(ss, spec, ',');


            // Cleanup invisible formatting
            user = trimString(user);
            pass = trimString(pass);
            name = trimString(name);
            spec = trimString(spec);
           
            if (user.empty() || pass.empty()) continue;


            if (user == string(inputUser) && pass == string(inputPass)) {
                loginSuccess = true;
                strcpy(loggedInCounselor.username, user.c_str());
                strcpy(loggedInCounselor.password, pass.c_str());
                strcpy(loggedInCounselor.name, name.c_str());
                strcpy(loggedInCounselor.specialty, spec.c_str());
                break;
            }
        }
        counselorFile.close();


        if (!loginSuccess) {
            cout << "\n[ERROR] Invalid credentials. Please try again.\n";
            this_thread::sleep_for(chrono::seconds(2)); clearScreen();
        }
    }
    return loginSuccess;
}


void studentLogin()
{
    long long id; char inputPass[20]; bool loginSuccess = false;


    while (!loginSuccess) {
        cout << "\n--- STUDENT PORTAL ---" << endl;
        cout << "Enter your Student ID (or 0 to cancel): ";
        cin >> id;
        if (cin.fail()) {
            cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n[ERROR] Invalid input. Please enter numbers only.\n";
            this_thread::sleep_for(chrono::seconds(2)); clearScreen(); continue;
        }
        if (id == 0) return;


        cout << "Password: "; cin >> inputPass;


       
        ifstream studentFile("students.csv");
        vector<Student> students; string line;


        while (getline(studentFile, line)) {
            if (line.empty()) continue;
           
            // Parse from the end backwards because name contains commas
            // Format: ID,password,name,yearLevel,stressLevel,counselor
            vector<string> fields;
            size_t pos = 0;
           
            // Get counselor (last field)
            size_t lastComma = line.rfind(',');
            if (lastComma == string::npos) continue;
            string couns = line.substr(lastComma + 1);
           
            // Get stressLevel (second to last)
            size_t secondLastComma = line.rfind(',', lastComma - 1);
            if (secondLastComma == string::npos) continue;
            string stressStr = line.substr(secondLastComma + 1, lastComma - secondLastComma - 1);
           
            // Get yearLevel (third to last)
            size_t thirdLastComma = line.rfind(',', secondLastComma - 1);
            if (thirdLastComma == string::npos) continue;
            string yrStr = line.substr(thirdLastComma + 1, secondLastComma - thirdLastComma - 1);
           
            // Get password and ID (first two fields, separated by comma)
            stringstream ss(line.substr(0, thirdLastComma));
            string idStr, pass;
            getline(ss, idStr, ',');
            getline(ss, pass, ',');
           
            // Everything after password and before year is the name
            string name = line.substr(idStr.length() + pass.length() + 2, thirdLastComma - idStr.length() - pass.length() - 2);


            // Cleanup invisible formatting
            idStr = trimString(idStr);
            pass = trimString(pass);
            name = trimString(name);
            yrStr = trimString(yrStr);
            stressStr = trimString(stressStr);
            couns = trimString(couns);
           
            if (idStr.empty() || pass.empty()) continue;


            try {
                Student tempStudent;
                tempStudent.studentID = stoll(idStr);
                strcpy(tempStudent.password, pass.c_str());
                strcpy(tempStudent.name, name.c_str());
                tempStudent.yearLevel = stoi(yrStr);
                tempStudent.stressLevel = stoi(stressStr);
                strcpy(tempStudent.assignedCounselor, couns.c_str());
                students.push_back(tempStudent);
            } catch (...) { continue; }
        }
        studentFile.close();


        if (!students.empty()) quickSortByID(students, 0, students.size() - 1);
        int index = -1;
        if (!students.empty() && id != -1) index = binarySearch(students, id);


        if (index != -1 && string(students[index].password) == string(inputPass)) {
            loginSuccess = true;
            loadingTransition("Verifying credentials", 1);
            studentDashboard(students[index]);
        } else {
            cout << "\n[ERROR] Invalid credentials. Student ID or password incorrect." << endl;
            cout << "Please try again..." << endl;
            this_thread::sleep_for(chrono::seconds(2)); clearScreen();
        }
    }
}


void loginMenu()
{
    int choice = 0;
    do
    {
        clearScreen();
        cout << "==================================================" << endl;
        cout << "       M.A.G.A.T WELLNESS & COUNSELING PORTAL     " << endl;
        cout << "==================================================" << endl;
        cout << " 1. Admin Login" << endl;
        cout << " 2. Counselor Login" << endl;
        cout << " 3. Student Login (Walk-in / Dashboard)" << endl;
        cout << " 4. Exit" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << "Enter choice: ";


        cin >> choice;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = -1;
        }


        switch (choice)
        {
        case 1:
        {
            Admin currentAdmin;
            if (adminLogin(currentAdmin))
            {
                loadingTransition("Authenticating Admin", 1);
                adminDashboard(currentAdmin);
            }
            break;
        }
        case 2:
        {
            Counselor currentCounselor;
            if (counselorLogin(currentCounselor))
            {
                loadingTransition("Authenticating Counselor", 1);
                counselorDashboard(currentCounselor);
            }
            break;
        }
        case 3:
            clearScreen();
            studentLogin();
            break;
        case 4:
            loadingTransition("Shutting down M.A.G.A.T Wellness System. Stay safe", 2);
            break;
        default:
            cout << "[ERROR] Invalid choice. Please try again." << endl;
            this_thread::sleep_for(chrono::seconds(1));
        }
    } while (choice != 4);
}


// MAIN FUNCTION
int main()
{
    initializeFiles();
    loginMenu();
    return 0;
}

