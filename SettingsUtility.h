///////////////////////////////////////////////////////////////////////////////
//!
//! @file		Settings_Utility.h
//! 
//! @brief		A Settings file utility class to parse and write settings files. 
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
#if defined _WIN32
#include	<windows.h>					// Windows necessary stuff
#include	<direct.h>					// Make Directory
#else
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<unistd.h>
#endif
//
#include <fstream>						// File Stream
#include <sstream>                      // Stream for parsing strings
#include <string>                       // Strings
#include <iostream>						// Standard IO
#include <mutex>						// Data protection
#include <filesystem>					// Checking for file extension
//
#include "SettingsUtilityInfo.h"		// Class information file. 
#include "nlohmann/json.hpp"			// Json functionality
// 
//	Defines:
//          name                        reason defined
//          --------------------        ---------------------------------------
#ifndef     SETTINGS_UTILITY			// Define the settings utility class. 
#define     SETTINGS_UTILITY
#endif
//
//	Global Constants:
//          name                        reason defined
//          --------------------        ---------------------------------------
// 
///////////////////////////////////////////////////////////////////////////////
class SettingsUtility
{
public:
	SettingsUtility();
	SettingsUtility(const std::string companyName, const std::string programName, const std::string fileName);
	~SettingsUtility();

	//! @brief Set the filename of the CSV file to be opened/created
	//! @param filename - [in] - filepath + name to be opened. 
	//! @return int: -1 if file is already open, 0 if failed, 1 if successful. 
	int SetCompanyName(const std::string filename);

	//! @brief Set the filename of the CSV file to be opened/created
	//! @param filename - [in] - filepath + name to be opened. 
	//! @return int: -1 if file is already open, 0 if failed, 1 if successful. 
	int SetProgramName(const std::string filename);

	//! @brief Set the filename of the CSV file to be opened/created
	//! @param filename - [in] - filepath + name to be opened. 
	//! @return int: -1 if file is already open, 0 if failed, 1 if successful. 
	int SetFileName(const std::string filename);

	//! @brief Set the extension of the settings file to be opened/created
	//! @param extension - [in] - extension of the settings file. 
	//! @return int: -1 if file is already open, 0 if failed, 1 if successful. 
	int SetExtension(const FILE_EXTENSION extension);

	int OpenFile();

	int CloseFile();

	//! @brief Create a section in the settings file. 
	//! @param section - [in] - name of the section for settings.
	//! @return int: -1 if already exists, 0 if failed, 1 if success. 
	int CreateSection(std::string section);

	//! @brief Create a settings item in the settings file. 
	//! @param section - [in] - name of the settings item.
	//! @return int: -1 if already exists, 0 if failed, 1 if success. 
	template<typename T> 
	int CreateItem(std::string section, std::string item, T value)
	{

	}

	int GetSectionItems();

	int GetItemValue(std::string value);

	int GetAllSettings();


protected:
private:
	std::string		mTitle;				// Title of the class for logging info
	SettingsFile	mSettingsFile;		// A class that holds typical things for the settings file. 
	std::fstream	mFile;				// File stream
};

