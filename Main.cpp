#include <iostream>
#include "SettingsUtility.h"

int main()
{
    std::cout << "Hello World!\n";

    SettingsUtility su;
    su.SetCompanyName("ChipB");
    su.SetProgramName("TesterApp");
    su.SetFileName("Settings");
    su.SetFileType(FILE_TYPE::JSON);

    if (su.OpenFile() != 0)
    {
        std::cout << "Error Opening\n";
    }

    su.AddItem(NULL, NULL, "test", 1);
    su.AddItem(NULL, NULL, "test2", 1);

    su.PrintData();

    su.CloseFile();
}
