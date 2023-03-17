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
//
//////////////////////////////////////////////////////////////////////////////

#define SETTINGS_UTILITY_VERSION_MAJOR 0
#define SETTINGS_UTILITY_VERSION_MINOR 0
#define SETTINGS_UTILITY_VERSION_REVISION 0
#define SETTINGS_UTILITY_VERSION_BUILD 1

//! @brief enum to hold the different file extensions
enum UTILITY_MODE
{
    NOTSET,
    INI,
    JSON
};


//! @brief Define Settings File Info Class
class SettingsFile
{
public:
    std::string		companyName;		// Company Name for folder name
    std::string		programName;		// Program Name for a sub folder name
    std::string		fileName;			// File Name of the settings file
    UTILITY_MODE	extension;			// File Extension for the settings file
    size_t          fileSize;			// Size of the file in bytes

    // constructor initializes everything
    SettingsFile(std::string companyName = "",
        std::string programName = "",
        std::string fileName = "",
        UTILITY_MODE extension = NOTSET) :
        companyName(companyName), programName(programName), fileName(fileName),
        extension(extension), fileSize(0)
    {}

    //! @brief Does struct have valid data ? 
    bool Valid(void) const
    {
        return (!companyName.empty()) && (!programName.empty()) && (!fileName.empty()) &&
            (extension != UTILITY_MODE::NOTSET) && (fileSize != 0);
    }

    // Output data to stream neatly.
    friend std::ostream& operator<<(std::ostream& os, const SettingsFile& sf)
    {
        os << "Settings File Info: " << "\n";
        sf.Valid() ? os << "\tValid:             Valid\n" : os << "\tValid:             Not Valid\n";
        os << "\tFilename:          " << sf.companyName << "\n"
           << "\tFilename:          " << sf.programName << "\n"
           << "\tFilename:          " << sf.fileName    << "\n"
           << "\tFilename:          " << sf.extension   << "\n"
           << "\tFile Size:         " << sf.fileSize    << "\n"
           << "\n";

        return os;
    }
};