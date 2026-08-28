// RollNo: MT26212
// Name: Nishtha Jaiswal

//int main() {
//   return 0;
//}
// RollNo: MT26212
// Name: Nishtha Jaiswal

#include "basicIO.h"

int main() {
    io.activateInput(); 

    char name[256];
    io.outputstring("Enter your name: ");
    io.inputstring(name, 256);

    io.outputstring("Enter your age: ");
    int age = io.inputint();

    // basic bounds check for age
    if (age <= 0 || age > 120) {
        io.errorstring("Invalid age entered.\n");
        io.terminate();
        return 1; 
    }

    char confirm[5];
    io.outputstring("Is this correct? (y/n): ");
    io.inputstring(confirm, 5);

    if (confirm[0] == 'y' || confirm[0] == 'Y') {
        io.outputstring("Information confirmed.\n");
    } else {
        io.outputstring("Information discarded.\n");
    }

    io.terminate();
    return 0;
}