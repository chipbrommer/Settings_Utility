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

    su.AddItem("test", 4);
    su.AddItem("test2", 5);
    su.AddItem("test3", "hello-world 100");

    su.PrintData();

    su.CloseFile();
}
