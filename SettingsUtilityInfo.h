///////////////////////////////////////////////////////////////////////////////
//!
//! @file		SettingsUtilityInfo.h
//! 
//! @brief		A Settings file utility information file. 
//! 
//! @author		Chip Brommer
//! 
//! @date		< 3 / 17 / 2022 > Initial Start Date
//!
/*****************************************************************************/
#pragma once
///////////////////////////////////////////////////////////////////////////////
//
//  Include files:
//          name                        reason included
//          --------------------        ---------------------------------------
#include <string>                       // strings
#include <vector>                       // vectors
#include <map>                          // Map
//
//////////////////////////////////////////////////////////////////////////////

#define SETTINGS_UTILITY_VERSION_MAJOR 0
#define SETTINGS_UTILITY_VERSION_MINOR 0
#define SETTINGS_UTILITY_VERSION_REVISION 0
#define SETTINGS_UTILITY_VERSION_BUILD 1

//! @brief enum to hold the different file extensions
enum FILE_EXTENSION : uint8_t
{
    NOTSET,
    INI,
    JSON
};

//! @brief Map for enum to string sets
static std::map<FILE_EXTENSION, std::string> ExtensionMap = {
    {NOTSET, "Not Set"},
    {INI, "ini"},
    {JSON, "json"}
};

//! @brief Define Settings File Info Class
class SettingsFile
{
public:
    std::string		companyName;		// Company Name for folder name
    std::string		programName;		// Program Name for a sub folder name
    std::string		fileName;			// File Name of the settings file
    FILE_EXTENSION	extension;			// File Extension for the settings file

    // Constructor initializes everything
    SettingsFile(std::string companyName = "",
                std::string programName = "",
                std::string fileName = "",
                FILE_EXTENSION extension = NOTSET) :
                companyName(companyName), programName(programName), fileName(fileName),
                extension(extension)
    {}

    //! @brief Does struct have valid data ? 
    bool Valid(void) const
    {
        return  (!companyName.empty())                  && 
                (!programName.empty())                  && 
                (!fileName.empty())                     &&
                (extension != FILE_EXTENSION::NOTSET);
    }

    //! @brief Returns the complete folder path
    std::string GetFolderPath()
    {
        return companyName + '/' + programName + '/' + fileName + '.' + ExtensionMap[extension];
    }

    // Output Data to stream neatly.
    friend std::ostream& operator<<(std::ostream& os, const SettingsFile& sf)
    {
        os << "Settings File Info: " << "\n";
        sf.Valid() ? os << "\tValid:             Valid\n" : os << "\tValid:             Not Valid\n";
        os << "\tCompany Name:          " << sf.companyName             << "\n"
           << "\tProgram Name:          " << sf.programName             << "\n"
           << "\tFilename:              " << sf.fileName                << "\n"
           << "\tExtension:             " << ExtensionMap[sf.extension] << "\n"
           << "\n";

        return os;
    }
};