#include <iostream>
#include "SettingsUtility.h"

int main()
{
    SettingsUtility su;
    su.SetCompanyName("ChipB");
    su.SetProgramName("TesterApp");
    su.SetFileName("Settings");
    su.SetFileType(FILE_TYPE::JSON);

    if (su.OpenFile() != 0)
    {
        std::cout << "Error Opening\n";
    }

    su.AddItem("test", 1);
    su.AddItem("test2", 1);
    su.AddItem("test3", "hello");

    su.PrintData();

    su.CloseFile();
}
