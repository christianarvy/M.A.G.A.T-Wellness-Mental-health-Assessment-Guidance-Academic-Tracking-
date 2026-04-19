#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <chrono>
#include <thread>
#include <limits>    // Added for cin.ignore
#include <cstdlib>   // Added for atoll


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

struct Case {
    char studentID[20];                
    char clinicalObservations[500];     // [1] Clinical Observations
    char discussionSummary[500];        // [2] Discussion Summary
    char professionalAssessment[500];   // [3] Counselor's Assessment
    char actionPlan[500];               // [5] Action Plan (matches Concept)
    char date[20];                      // [DATE/TIME] from concept
};

struct Appointment {
    char studentID[20];
    char studentName[50];
    char reason[200];
    char preferredDate[20]; // For Bookings; can store "ASAP" for Emergencies
    char type;              // 'E' for Emergency, 'B' for Booking
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








// Simulated loading screen ni daddy Euken
void loadingTransition(const string& message, int seconds)
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
        ifstream checkFile(file, ios::binary);
        if (!checkFile)
        {
            ofstream createFile(file, ios::binary);
            cout << "[SYSTEM] Created missing database file: " << file << endl;
            createFile.close();
           
            // Seed Admin (Ma. Leonila V. Urrea)
            if (strcmp(file, "admins.dat") == 0)
            {
                ofstream adminFile(file, ios::binary | ios::app);
                // Updated Username and Password
                Admin defaultAdmin = {"leonila_urrea", "AdminPass123", "Ma. Leonila V. Urrea"};
                adminFile.write(reinterpret_cast<char*>(&defaultAdmin), sizeof(Admin));
                adminFile.close();
                cout << "[SYSTEM] Default admin account created." << endl;
            }
           
            // Seed Counselors based on specific list
            if (strcmp(file, "counselors.dat") == 0)
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
                    counselorFile.write(reinterpret_cast<char*>(&defaultCounselors[i]), sizeof(Counselor));
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
                cout << "[SYSTEM] Default student account created." << endl;
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
void swapStudents(Student& a, Student& b)
{
    Student temp = a;
    a = b;
    b = temp;
}


// 2. Partition function for Quick Sort
int partitionByID(vector<Student>& arr, int low, int high)
{
    long long pivot = arr[high].studentID; // Choosing the last element as the pivot
    int i = (low - 1); // Index of the smaller element


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
void quickSortByID(vector<Student>& arr, int low, int high)
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
int binarySearch(const vector<Student>& arr, long long targetID)
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
   
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear buffer for getline
   
    cout << "Enter Full Name: ";
    cin.getline(newStudent.name, 50);
   
    cout << "Enter Year Level (1-4): ";
    cin >> newStudent.yearLevel;
   
    cout << "Enter Initial Stress Level (1-10): ";
    cin >> newStudent.stressLevel;
   
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear buffer for getline
   
    cout << "Assign to Counselor (Enter Username): ";
    cin.getline(newStudent.assignedCounselor, 20);
   
    ofstream outFile("students.dat", ios::binary | ios::app);
    outFile.write(reinterpret_cast<char*>(&newStudent), sizeof(Student));
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
   
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear buffer for getline
   
    cout << "Enter Full Name: ";
    cin.getline(newCounselor.name, 50);
   
    cout << "Enter Department/Specialty: ";
    cin.getline(newCounselor.specialty, 100);
   
    ofstream outFile("counselors.dat", ios::binary | ios::app);
    outFile.write(reinterpret_cast<char*>(&newCounselor), sizeof(Counselor));
    outFile.close();
   
    cout << "\n[SYSTEM] Counselor successfully added to the system!" << endl;
    this_thread::sleep_for(chrono::seconds(2));
}




void adminViewCounselors() {
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


    ifstream file("counselors.dat", ios::binary | ios::in);
   
    if (!file) {
        cout << "\n [ERROR] Counselor database not found." << endl;
    } else {
        Counselor temp;
        int count = 0;


        // Ensure we are reading exactly the size of the class
        while (file.read(reinterpret_cast<char*>(&temp), sizeof(Counselor))) {
            count++;
           
            // We use string(array) to ensure C++ handles the null terminator properly
            cout << left
                 << "[" << setw(7) << to_string(count) + "]"
                 << setw(25) << temp.username
                 << setw(35) << temp.name
                 << temp.specialty << endl;
        }


        if (count == 0) cout << " > No counselor staff currently registered." << endl;
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
        cout << "Greetings, " << currentStudent.name << "! How can we support you today?\n" << endl;
       
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
                loadingTransition("Opening counseling session scheduler", 1);
                break;
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
    do {
        clearScreen();
        cout << "==================================================" << endl;
        cout << "               COUNSELOR DASHBOARD                " << endl;
        cout << "==================================================" << endl;
        // Updated to show their real name instead of username
        cout << "Welcome back, " << currentCounselor.name << ".\n";
        cout << "Specialty: " << currentCounselor.specialty << "\n" << endl;
       
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
               
                ifstream studentFile("students.dat", ios::binary);
                Student tempStudent;
                int caseCount = 0;
               
                while (studentFile.read(reinterpret_cast<char*>(&tempStudent), sizeof(Student)))
                {
                    // Now it ONLY shows students explicitly assigned to THIS counselor
                    if (strcmp(tempStudent.assignedCounselor, currentCounselor.username) == 0) {
                        caseCount++;
                        cout << " [" << caseCount << "] ID: " << tempStudent.studentID
                             << " | Name: " << tempStudent.name << " | Stress Level: " << tempStudent.stressLevel << endl;
                    }
                }
                studentFile.close();
               
                if (caseCount == 0) {
                    cout << " > No cases currently assigned to you." << endl;
                }
               
                cout << "==================================================" << endl;
                cout << "\nPress Enter to return to the dashboard...";
               
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
                break;
            }
            
           case 2: // Log New Counseling Case & Update Stress Level (Idea B)
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

        // Append to cases.dat
        ofstream outFile("cases.dat", ios::binary | ios::app);
        if (outFile) {
            outFile.write(reinterpret_cast<char*>(&newCase), sizeof(Case));
            outFile.close();
            cout << "\n[SYSTEM] Saving findings to cases.dat... Success." << endl;
        }

        // --- IDEA B: PROFESSIONAL OVERRIDE ---
        cout << "\n--------------------------------------------------" << endl;
        cout << "[STRESS LEVEL RE-EVALUATION]" << endl;
        cout << ">> Enter new Professional Stress Level (1-10): ";
        cin >> professionalStressLevel;
        
        // In-place Binary File Update for students.dat
        fstream studentFile("students.dat", ios::in | ios::out | ios::binary);
        Student tempStud;
        bool studentFound = false;

        if (studentFile) {
            while(studentFile.read(reinterpret_cast<char*>(&tempStud), sizeof(Student))) {
                if(tempStud.studentID == atoll(newCase.studentID)) {
                    tempStud.stressLevel = professionalStressLevel; // Update struct
                    
                    // Move the put pointer back by one struct size to overwrite
                    int pos = -1 * static_cast<int>(sizeof(Student));
                    studentFile.seekp(pos, ios::cur);
                    studentFile.write(reinterpret_cast<char*>(&tempStud), sizeof(Student));
                    
                    studentFound = true;
                    break;
                }
            }
            studentFile.close();
        }

        if(studentFound) {
            cout << "[SYSTEM] Student stressLevel updated to " << professionalStressLevel << " in students.dat." << endl;
        } else {
            cout << "[ERROR] Student ID not found in students.dat." << endl;
        }

        cout << "\nPress Enter to return to Dashboard...";
        cin.ignore(1000, '\n'); cin.get();
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

        ifstream inFile("cases.dat", ios::binary);
        if (!inFile) {
            cout << "[SYSTEM] No history records found." << endl;
            break;
        }

        cout << "\nPulling past sessions for: " << searchID << endl;
        cout << "--------------------------------------------------" << endl;

        while (inFile.read(reinterpret_cast<char*>(&tempCase), sizeof(Case))) {
            if (strcmp(tempCase.studentID, searchID) == 0) {
                found = true;
                cout << "\n[DATE]: " << tempCase.date << endl;
                cout << "[OBSERVATIONS]: " << tempCase.clinicalObservations << endl;
                cout << "[SUMMARY]:      " << tempCase.discussionSummary << endl;
                cout << "[ASSESSMENT]:   " << tempCase.professionalAssessment << endl;
                cout << "[ACTION PLAN]:  " << tempCase.actionPlan << endl;
                cout << "--------------------------------------------------" << endl;
            }
        }

        if (!found) cout << "[SYSTEM] No past session history found." << endl;
        inFile.close();

        cout << "\nPress Enter to return to Dashboard...";
        cin.ignore(1000, '\n'); cin.get();
        break;
    }

    case 4: // View Session Queue (Emergency First, Then Bookings)
    {
        Appointment tempAppt;
        bool foundAny = false;
        
        loadingTransition("Loading Session Queue", 1);
        clearScreen();
        cout << "==================================================" << endl;
        cout << "              ACTIVE SESSION QUEUE                " << endl;
        cout << "==================================================" << endl;

        ifstream inFile("appointments.dat", ios::binary);
        if (!inFile) {
            cout << "[System] No appointments or emergencies found." << endl;
            break;
        }

        // PASS 1: Emergencies First
        cout << "\n[ !!! EMERGENCY ALERTS !!! ]" << endl;
        while (inFile.read(reinterpret_cast<char*>(&tempAppt), sizeof(Appointment))) {
            if (tempAppt.type == 'E') {
                foundAny = true;
                cout << "STUDENT: " << tempAppt.studentID << " | " << tempAppt.studentName << endl;
                cout << "REASON:  " << tempAppt.reason << endl;
                cout << "--------------------------------------------------" << endl;
            }
        }

        inFile.clear();            // Clear EOF flag
        inFile.seekg(0, ios::beg); // Rewind back to start of file

        // PASS 2: Standard Bookings
        cout << "\n[ STANDARD BOOKINGS ]" << endl;
        while (inFile.read(reinterpret_cast<char*>(&tempAppt), sizeof(Appointment))) {
            if (tempAppt.type == 'B') {
                foundAny = true;
                cout << "DATE:    " << tempAppt.preferredDate << endl;
                cout << "STUDENT: " << tempAppt.studentID << " | " << tempAppt.studentName << endl;
                cout << "REASON:  " << tempAppt.reason << endl;
                cout << "--------------------------------------------------" << endl;
            }
        }
        
        if (!foundAny) cout << "Queue is currently empty." << endl;
        inFile.close();
        
        cout << "\nPress Enter to return to Dashboard...";
        cin.ignore(1000, '\n'); cin.get();
        break;
    }

    case 5: // Sort Students by Wellness Priority (Quick Sort)
    {
        loadingTransition("Sorting Data", 1);
        clearScreen();
        cout << "==================================================" << endl;
        cout << "     WELLNESS PRIORITY LIST (QUICK SORT ALGO)     " << endl;
        cout << "==================================================" << endl;

        // Count how many students exist
        ifstream countFile("students.dat", ios::binary);
        if (!countFile) {
            cout << "[Error] No student data found." << endl;
            break;
        }
        countFile.seekg(0, ios::end);
        int studentCount = countFile.tellg() / sizeof(Student);
        countFile.seekg(0, ios::beg);

        if (studentCount == 0) {
            cout << "No students registered yet." << endl;
            break;
        }

        // Load into dynamic array
        Student* students = new Student[studentCount];
        for (int i = 0; i < studentCount; i++) {
            countFile.read(reinterpret_cast<char*>(&students[i]), sizeof(Student));
        }
        countFile.close();

        // Perform the Quick Sort
        quickSortPriority(students, 0, studentCount - 1);

        // Display Data
        cout << "Priority | ID           | Name                 | Stress Level" << endl;
        cout << "--------------------------------------------------------------" << endl;
        for (int i = 0; i < studentCount; i++) {
            // Only display students who have actually taken the assessment (Level > 1)
            if (students[i].stressLevel > 1) {
                cout << "   " << i + 1 << "     | " 
                     << students[i].studentID << " | " 
                     << students[i].name << " | " 
                     << students[i].stressLevel << " / 10" << endl;
            }
        }

        delete[] students; // Free memory
        cout << "\nPress Enter to return to Dashboard...";
        cin.ignore(1000, '\n'); cin.get();
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
    do {
        clearScreen();
        cout << "==================================================" << endl;
        cout << "                 ADMIN DASHBOARD                  " << endl;
        cout << "==================================================" << endl;
        cout << "System Administrator: " << currentAdmin.name << ".\n" << endl;
       
        cout << " 1. Add New Student" << endl;
        cout << " 2. Add New Counselor Staff" << endl;
        cout << " 3. View Active Counselor Staff" << endl;
        cout << " 4. Logout" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << "Enter choice: ";
       
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = -1;
        }
       
        switch (choice) {
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
bool adminLogin(Admin& loggedInAdmin)
{
    char inputUser[20];
    char inputPass[20];
    bool loginSuccess = false;
   
    while (!loginSuccess) {
        cout << "\n--- ADMIN LOGIN ---" << endl;
        cout << "Username (or type 'exit' to cancel): ";
        cin >> inputUser;
       
        if (strcmp(inputUser, "exit") == 0) return false;




        cout << "Password: ";
        cin >> inputPass;
       
        ifstream adminFile("admins.dat", ios::binary);
        Admin tempAdmin;
       
        while (adminFile.read(reinterpret_cast<char*>(&tempAdmin), sizeof(Admin))) {
            if (strcmp(tempAdmin.username, inputUser) == 0 && strcmp(tempAdmin.password, inputPass) == 0)
            {
                loginSuccess = true;
                loggedInAdmin = tempAdmin;
                break;
            }
        }
        adminFile.close();
       
        if (!loginSuccess)
        {
            cout << "\n[ERROR] Invalid credentials. Please try again.\n";
            this_thread::sleep_for(chrono::seconds(2));
            clearScreen();
        }
    }
    return loginSuccess;
}




bool counselorLogin(Counselor& loggedInCounselor)
{
    char inputUser[20];
    char inputPass[20];
    bool loginSuccess = false;
   
    while (!loginSuccess)
    {
        cout << "\n--- COUNSELOR LOGIN ---" << endl;
        cout << "Username (or type 'exit' to cancel): ";
        cin >> inputUser;
       
        if (strcmp(inputUser, "exit") == 0) return false;










        cout << "Password: ";
        cin >> inputPass;
       
        ifstream counselorFile("counselors.dat", ios::binary);
        Counselor tempCounselor;
       
        while (counselorFile.read(reinterpret_cast<char*>(&tempCounselor), sizeof(Counselor)))
        {
            if (strcmp(tempCounselor.username, inputUser) == 0 && strcmp(tempCounselor.password, inputPass) == 0)
            {
                loginSuccess = true;
                loggedInCounselor = tempCounselor;
                break;
            }
        }
        counselorFile.close();
       
        if (!loginSuccess)
        {
            cout << "\n[ERROR] Invalid credentials. Please try again.\n";
            this_thread::sleep_for(chrono::seconds(2));
            clearScreen();
        }
    }
    return loginSuccess;
}








void studentLogin()
{
    long long id;
    char inputPass[20];
    bool loginSuccess = false;
   
    while (!loginSuccess)
    {
        cout << "\n--- STUDENT PORTAL ---" << endl;
        cout << "Enter your Student ID (or 0 to cancel): ";
       
        cin >> id;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n[ERROR] Invalid input. Please enter numbers only.\n";
            this_thread::sleep_for(chrono::seconds(2));
            clearScreen();
            continue;
        }
       
        if (id == 0)
        {
            cout << "Returning to Main Menu..." << endl;
            this_thread::sleep_for(chrono::seconds(1));
            return;
        }








        cout << "Password: ";
        cin >> inputPass;
       
        ifstream studentFile("students.dat", ios::binary);
        vector<Student> students;
        Student tempStudent;
       
        while (studentFile.read(reinterpret_cast<char*>(&tempStudent), sizeof(Student)))
        {
            students.push_back(tempStudent);
        }
        studentFile.close();
       
        if (!students.empty())
        {
            quickSortByID(students, 0, students.size() - 1);
        }
       
        int index = -1;
        if (!students.empty() && id != -1)
        {
            index = binarySearch(students, id);
        }
       
        if (index != -1 && strcmp(students[index].password, inputPass) == 0)
        {
            loginSuccess = true;
            loadingTransition("Verifying credentials", 1);
            studentDashboard(students[index]);
        } else
        {
            cout << "\n[ERROR] Invalid credentials. Student ID or password incorrect." << endl;
            cout << "Please try again..." << endl;
            this_thread::sleep_for(chrono::seconds(2));
            clearScreen();
        }
    }
}






void loginMenu()
{
    int choice = 0;
    do {
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
