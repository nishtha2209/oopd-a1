// RollNo: MT26212
// Name: Nishtha Jaiswal

//int main() {
//   return 0;
//}
// RollNo: MT26212
// Name: Nishtha Jaiswal

// RollNo: MT26212
// Name: Nishtha Jaiswal

#include "basicIO.h"

// --- Question 3: Object-Oriented User Profile ---
class UserProfile {
private:
    char name[256];
    int age;
    char confirm[5];

public:
    bool collectAndValidate() {
        io.outputstring("Enter your name: ");
        io.inputstring(name, 256);

        io.outputstring("Enter your age (must be a number): ");
        age = io.inputint();

        // Validity check (Compulsory)
        if (age <= 0 || age > 120) {
            io.errorstring("Invalid input! Age must be a valid positive number.\n");
            return false; 
        }

        io.outputstring("Is this correct? (y/n): ");
        io.inputstring(confirm, 5);

        if (confirm[0] == 'y' || confirm[0] == 'Y') {
            io.outputstring("Success: Information confirmed.\n\n");
        } else {
            io.outputstring("Notice: Information discarded.\n\n");
        }
        return true;
    }
};

// --- Question 4 & 5: Object-Oriented Name Allocation ---
class NameManager {
private:
    // Statically allocate a maximum safe boundary to prevent overflow
    static const int MAX_NAMES = 50; 
    static const int MAX_NAME_LEN = 256;
    char filenames[MAX_NAMES][MAX_NAME_LEN];
    int count;

public:
    NameManager(int n) {
        if (n <= 0) count = 0;
        else if (n > MAX_NAMES) count = MAX_NAMES; // Overflow prevention
        else count = n;
    }

    void collectNames() {
        if (count == 0) return;
        for (int i = 0; i < count; ++i) {
            io.outputstring("Enter filename ");
            io.outputint(i + 1);
            io.outputstring(": ");
            io.inputstring(filenames[i], MAX_NAME_LEN);
        }
        io.outputstring("Successfully stored ");
        io.outputint(count);
        io.outputstring(" filenames.\n");
    }
};


int main() {
    io.activateInput(); 

    // 1. Execute Question 3 via Object
    UserProfile user;
    if (!user.collectAndValidate()) {
        io.terminate();
        return 1; // Exit if validation fails
    }

    // 2. Execute Question 4 & 5 via Object
    bool keepGoing = true;
    char choice[5];

    while (keepGoing) {
        io.outputstring("How many filenames do you need to add? (Max 50): ");
        int numNames = io.inputint();

        if (numNames > 0 && numNames <= 50) {
            NameManager manager(numNames); // Object instantiation
            manager.collectNames();
        } else {
            io.errorstring("Invalid number. Must be between 1 and 50 to prevent overflow.\n");
        }

        // Question 5 loop check
        io.outputstring("\nDo you want to change the number of filenames and start over? (y/n): ");
        io.inputstring(choice, 5);
        if (choice[0] == 'n' || choice[0] == 'N') {
            keepGoing = false;
        }
    }

    io.terminate();
    return 0;
}