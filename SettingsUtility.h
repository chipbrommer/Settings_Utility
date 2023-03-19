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
#if defined CPP_LOGGER
#include "CPP_Logger.h"
#endif
//
#include <fstream>						// File Stream
#include <sstream>                      // Stream for parsing strings
#include <string>                       // Strings
#include <iostream>						// Standard IO
#include <mutex>						// Data protection
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
	int SetParentDirectory(const std::string parent = "C:\\ProgramData");

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

	//! @brief Set the type of the settings file to be opened/created
	//! @param type - [in] - extension of the settings file. 
	//! @return int: -1 if file is already open, 0 if failed, 1 if successful. 
	int SetFileType(const FILE_TYPE type);

	//! @brief Verifies the parent directory exists
	//! @param directory - [in] - parent directory for the settings file.  
	//! @return int: -1 if doesnt exist, 0 if exists, 1 if created.
	int CreateOrVerifyDirectory(const std::string directory);

	//! @brief Opens a file stream
	//! @return int: -3 if file settings not fulfilled, -2 if file already open, -1 on failure, 0 on success
	int OpenFile();

	//! @brief Closes a file if its open.
	//! @return int: -2 if no is file open, -1 on failure, 0 on success
	int CloseFile();

	//! @brief Create a section in the settings file. 
	//! @param section - [in] - name of the section for settings.
	//! @return int: -1 if already exists, 0 if failed, 1 if success. 
	int CreateSection(std::string section);

	//! @brief Create a settings item in the settings file. 
	//! @param section - [in] - name of the settings item.
	//! @return int: -1 if already exists, 0 if failed, 1 if success. 
	template<typename T> 
	int AddItem(std::string param, T value, std::string section = std::string(), std::string item = std::string())
	{
		if (!mSettingsFile.Valid())
		{
			return -1;
		}

		if (mSettingsFile.type == FILE_TYPE::JSON)
		{
			AddJsonItem(param, value, section, item);
		}
		else if (mSettingsFile.type == FILE_TYPE::INI)
		{
			AddIniItem(param, value, section, item);
		}
		else
		{
			return -1;
		}

		return 0;
	}

	int GetSectionItems();

	int GetItemValue(std::string value);

	int GetAllSettings();

	void PrintData();


protected:
private:
	//! @brief Create a section in the INI settings file. 
	//! @param section - [in] - name of the section for settings.
	//! @return int: -1 if already exists, 0 if failed, 1 if success.
	int AddIniSection(std::string section);

	//! @brief Create an item in the INI settings file. 
	//! @param section - [in] - name of the section for settings.
	//! @return int: -1 if already exists, 0 if failed, 1 if success.
	template<typename T> 
	int AddIniItem(std::string param, T value, std::string section = std::string(), std::string item = std::string())
	{
		int counter = 0;

		if (!section.empty())
		{
			// TODO - need to verify the section exists before adding. 
			/*
				if section doesnt exist, make it.
			*/
			counter += 1;
		}

		if (!item.empty())
		{
			// TODO - need to verify the item exists before adding. 
			/*
				if item doesnt exist, make it.
			*/

			counter += 2;
		}

		switch (counter)
		{
		default: break;
		}

		return 0;
	}

	//! @brief Create a section in the settings file. 
	//! @param section - [in] - name of the section for settings.
	//! @return int: -1 if already exists, 0 if failed, 1 if success.
	int ReadIniSection(std::string section);

	//! @brief Create a section in the settings file. 
	//! @param section - [in] - name of the section for settings.
	//! @return int: -1 if already exists, 0 if failed, 1 if success.
	int ReadIniItem(std::string item);
	
	//! @brief Create a section in the settings file. 
	//! @param section - [in] - name of the section for settings.
	//! @return int: -1 if already exists, 0 if failed, 1 if success.
	int AddJsonSection(std::string section);

	//! @brief Create a section in the settings file. 
	//! @param section - [in] - name of the section for settings.
	//! @return int: -1 if already exists, 0 if failed, 1 if success.
	template<typename T>
	int AddJsonItem(std::string param, T value, std::string section = std::string(), std::string item = std::string())
	{
		int counter = 0;

		if (!section.empty())
		{
			// TODO - need to verify the section exists before adding. 
			/*
				if section doesnt exist, make it. 
			*/
			counter += 1;
		}

		if (!item.empty())
		{
			// TODO - need to verify the item exists before adding. 
			/*
				if item doesnt exist, make it.
			*/

			counter += 2;
		}

		switch (counter)
		{
		case 0: mJsonData[param] = value; break;
		case 1: mJsonData[section][param] = value; break;
		default: break;
		}

		return 0;
	}

	//! @brief Create a section in the settings file. 
	//! @param section - [in] - name of the section for settings.
	//! @return int: -1 if already exists, 0 if failed, 1 if success.
	int ReadJsonSection(std::string section);

	//! @brief Create a section in the settings file. 
	//! @param section - [in] - name of the section for settings.
	//! @return int: -1 if already exists, 0 if failed, 1 if success.
	int ReadJsonItem(std::string item);

	//! @brief Catch a fail reason for the fstream file
	void CatchFailReason();

	std::string			mTitle;				// Title of the class for logging info
	SettingsFile		mSettingsFile;		// A class that holds typical things for the settings file. 
	std::fstream		mFile;				// File stream
	nlohmann::json		mJsonData;			// JSON data
};

