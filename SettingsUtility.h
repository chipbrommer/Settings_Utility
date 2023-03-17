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


protected:
private:
	std::string		mTitle;				// Title of the class for logging info
	std::string		mCompanyName;		// Company Name for folder name
	std::string		mProgramName;		// Program Name for a sub folder name
	std::string		mFileName;			// File Name of the settings file
	std::string		mExtension;			// File Extension for the settings file
	bool			mIsInitialized;		// Flag for initialization
	std::fstream	mFile;				// File stream
};

