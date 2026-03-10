#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

// Fungsi untuk membersihkan layar (cross-platform)
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void showHeader() {
    cout << "======================================================" << endl;
    cout << "       DATABASE MANAGEMENT CONTROL CENTER v1.0        " << endl;
    cout << "======================================================" << endl;
}

int main() {
    int choice;
    bool running = true;

    // Mengubah warna teks terminal (0=Black, A=Light Green)
    system("color 0A");

    while (running) {
        clearScreen();
        showHeader();
        cout << " [1] Run Automated Database Backup (ERP Production)" << endl;
        cout << " [2] Refresh Mirror Database (for Data Analysts)" << endl;
        cout << " [3] Run Both (Full Sync)" << endl;
        cout << " [4] Exit Program" << endl;
        cout << "------------------------------------------------------" << endl;
        cout << " Select Option [1-4]: ";
        
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        cout << endl;

        switch (choice) {
            case 1:
                cout << ">>> Executing Backup Process..." << endl;
                system("python backup_db.py");
                break;
            case 2:
                cout << ">>> Executing Mirroring Refresh..." << endl;
                system("python mirror_db.py");
                break;
            case 3:
                cout << ">>> Running Full Sync (Backup -> Mirror)..." << endl;
                system("python backup_db.py && python mirror_db.py");
                break;
            case 4:
                cout << "Closing system. Safety first!" << endl;
                running = false;
                break;
            default:
                cout << "Invalid option! Please try again." << endl;
        }

        if (running) {
            cout << "\nPress ENTER to return to menu...";
            cin.ignore();
            cin.get();
        }
    }

    return 0;
}