#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

// File names
const string DONORS_FILE = "donors.csv";
const string PROJECTS_FILE = "projects.csv";
const string VOLUNTEERS_FILE = "volunteers.csv";
const string FUNDS_FILE = "funds.csv";
const string USERS_FILE = "users.csv";

// Secure login credentials
struct User {
    string username;
    string password;
};

// Function to load users from file
vector<User> loadUsers() {
    vector<User> users;
    ifstream file(USERS_FILE);
    string line, username, password;
    
    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, username, ',');
        getline(ss, password, ',');
        users.push_back({username, password});
    }
    
    file.close();
    return users;
}

// Function to register new user
void registerUser() {
    ofstream file(USERS_FILE, ios::app);
    string username, password;

    cout << "Enter new username: ";
    cin >> username;
    cout << "Enter new password: ";
    cin >> password;

    file << username << "," << password << "\n";
    file.close();
    cout << "You are registered! Logging in...\n";
}

// Function to check login
bool login() {
    vector<User> users ={{"zainab","zainab123"},{"ali","ali123"},{"sara","sara123"},{"maryam","maryam123"}};
    vector<User> fileUsers=loadUsers();
    
    users.insert(users.end(), fileUsers.begin(),fileUsers.end());
	string username, password;
    
    cout << "\nEnter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;
    
    for (User u : users) {
        if (u.username == username && u.password == password) {
            cout << "Login Successful!\n";
            return true;
        }
    }
    cout << "Invalid credentials! Try again.\n";
    return login();
}

// Function to add donor
void addDonor() {
    ofstream file(DONORS_FILE, ios::app);
    string name;
    float amount;
    string date, purpose;

    cout << "Enter Donor Name: ";
    cin >> name;
    cout << "Enter Donation Amount: ";
    cin >> amount;
    cout << "Enter Date (YYYY-MM-DD): ";
    cin >> date;
    cout << "Enter Purpose: ";
    cin >> purpose;

    file << name << "," << amount << "," << date << "," << purpose << "\n";
    file.close();
    cout << "Donor added successfully!\n";
}

// Function to view donors
void viewDonors() {
    ifstream file(DONORS_FILE);
    string line;
    
    cout << "\n--- Donor List ---\n";
    cout<<"\n fahad \n 2000000 \n 20-6-2015 \n for education  \n";
    cout<<"\n raan \n 70000 \n 31-7-2020 \n for clean water initiated";
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

// Function to add project
void addProject() {
    ofstream file(PROJECTS_FILE, ios::app);
    string name, status;
    
    cout << "Enter Project Name: ";
    cin >> name;
    cout << "Enter Status (Ongoing/Completed): ";
    cin >> status;
    file << name << "," << status << "\n";
    file.close();
    cout << "Project added successfully!\n";
}

// Function to view projects (with initial data)
void viewProjects() {
    ofstream file(PROJECTS_FILE, ios::app);
    file.close();
    
    ifstream inFile(PROJECTS_FILE);
    string line;
    
    cout << "\n--- Project List ---\n";
    cout<<"Education for All,Ongoing\n";
    cout<<"Clean Water Initiative,Complete\n";
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();
}

// Function to add volunteer
void addVolunteer() {
    ofstream file(VOLUNTEERS_FILE, ios::app);
    string name, project;
    
    cout << "Enter Volunteer Name: ";
    cin >> name;
    cout << "Enter Assigned Project: ";
    cin >> project;

    file << name << "," << project << "\n";
    file.close();
    cout << "Volunteer registered successfully!\n";
}

// Function to view volunteers (with initial data)
void viewVolunteers() {
    ofstream file(VOLUNTEERS_FILE, ios::app);
    file.close();
    
    ifstream inFile(VOLUNTEERS_FILE);
    string line;
    
    cout << "\n--- Volunteer List ---\n";
    cout<<"Baber Azam,Education for All\n";
    cout<<"virat koli,Clean Water Initiative\n";
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();
}
                   
// Function to record funds
void recordFunds() {
    ofstream file(FUNDS_FILE, ios::app);
    float amount;
    string purpose;
    
    cout << "Enter Fund Amount: ";
    cin >> amount;
    cout << "Enter Purpose: ";
    cin >> purpose;

    file << amount << "," << purpose << "\n";
    file.close();
    cout << "Funds recorded successfully!\n";
}

// Function to view funds (with initial data)
void viewFunds() {
    ofstream file(FUNDS_FILE, ios::app);
    file.close();
    
    ifstream inFile(FUNDS_FILE);
    string line;
    
    cout << "\n--- Fund Records ---\n";
    cout<<"50000,School Renovation\n";
    cout<<"25000,Water Purification";
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();
}

// Function to display menu
void menu() {
    int choice;
    do {
        cout << "\n===== NGO Management System =====\n";
        cout << "1. Add Donor\n2. View Donors\n3. Add Project\n4. View Projects\n5. Add Volunteer\n";
        cout << "6. View Volunteers\n7. Record Funds\n8. View Funds\n9. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addDonor(); break;
            case 2: viewDonors(); break;
            case 3: addProject(); break;
            case 4: viewProjects(); break;
            case 5: addVolunteer(); break;
            case 6: viewVolunteers(); break;
            case 7: recordFunds(); break;
            case 8: viewFunds(); break;
            case 9: cout << "Exiting Program...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 9);
}

// Main function
int main() {
    int choice;
    cout << "=========================== Welcome to NGO Management System =============================\n";
    cout << "1. Register\n2. Login\nChoose an option: ";
    cin >> choice;

    if (choice == 1) {
        registerUser();
    }

    if (login()) {
        menu();
    }

    return 0;
}