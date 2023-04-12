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
#include "nlohmann/json.hpp"			// Json functionality
//
//////////////////////////////////////////////////////////////////////////////

#define SETTINGS_UTILITY_VERSION_MAJOR 0
#define SETTINGS_UTILITY_VERSION_MINOR 0
#define SETTINGS_UTILITY_VERSION_REVISION 0
#define SETTINGS_UTILITY_VERSION_BUILD 1

//! @brief enum to hold the different file extensions
enum class FILE_TYPE : uint8_t
{
    NOTSET,
    INI,
    JSON
};

//! @brief Map for enum to string sets
static std::map<FILE_TYPE, std::string> TypeMap
{
    {FILE_TYPE::NOTSET, "Not Set"},
    {FILE_TYPE::INI, "ini"},
    {FILE_TYPE::JSON, "json"}
};

//! @brief Define Settings File Info Class
class SettingsFile
{
public:
    std::string		parentDirectory;	// Parent Directory for the folder structure
    std::string		companyName;		// Company Name for folder name
    std::string		programName;		// Program Name for a sub folder name
    std::string		fileName;			// File Name of the settings file
    FILE_TYPE	    type;			    // File Extension for the settings file

    // Constructor initializes everything
    SettingsFile(std::string parentDirectory = "",
                std::string companyName = "",
                std::string programName = "",
                std::string fileName = "",
                FILE_TYPE type = FILE_TYPE::NOTSET) :
                parentDirectory(parentDirectory), companyName(companyName), programName(programName), 
                fileName(fileName), type(type)
    {}

    //! @brief Does struct have valid data ? 
    bool Valid(void) const
    {
        return  (!parentDirectory.empty())          &&
                (!companyName.empty())              && 
                (!programName.empty())              && 
                (!fileName.empty())                 &&
                (type != FILE_TYPE::NOTSET);
    }

    //! @brief Returns the complete folder path
    std::string GetFullPath()
    {
        return parentDirectory + '\\' + companyName + '\\' + programName + '\\' + fileName + '.' + TypeMap[type];
    }

    void ToJson(nlohmann::json& json)
    {
        json = nlohmann::json{
            { "parentDirectory",this->parentDirectory },
            { "companyName",    this->companyName },
            { "programName",    this->programName },
            { "fileName",       this->fileName },
            { "type",           this->type }
        };
    }

    void FromJson(const nlohmann::json& json)
    {
        json.at("parentDirectory").get_to(  this->parentDirectory);
        json.at("companyName").get_to(      this->companyName);
        json.at("programName").get_to(      this->programName);
        json.at("fileName").get_to(         this->fileName);
        json.at("type").get_to(             this->type);
    }

    // Output Data to stream neatly.
    friend std::ostream& operator<<(std::ostream& os, const SettingsFile& sf)
    {
        os << "Settings File Info: " << "\n";
        sf.Valid() ? os << "\tValid:             Valid\n" : os << "\tValid:             Not Valid\n";
        os << "\tParent Directory:      " << sf.parentDirectory         << "\n"
           << "\tCompany Name:          " << sf.companyName             << "\n"
           << "\tProgram Name:          " << sf.programName             << "\n"
           << "\tFilename:              " << sf.fileName                << "\n"
           << "\tType:                  " << TypeMap[sf.type]           << "\n"
           << "\n";

        return os;
    }
};