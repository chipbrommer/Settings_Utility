///////////////////////////////////////////////////////////////////////////////
//!
//! @file		SettingsUtility.cpp
//! 
//! @brief		Implementation for the SettingsUtility class
//! 
//! @author		Chip Brommer
//! 
//! @date		< 3 / 17 / 2022 > Initial Start Date
//!
/*****************************************************************************/

///////////////////////////////////////////////////////////////////////////////
//
//  Include files:
//          name                        reason included
//          --------------------        ---------------------------------------
#include "SettingsUtility.h"			// Settings Utility header file
///////////////////////////////////////////////////////////////////////////////

SettingsUtility::SettingsUtility()
{
	mTitle = "SettingsUtility";
	mExtension = ".ini";
	mFileName = "Settings";
}

SettingsUtility::SettingsUtility(const std::string companyName, const std::string programName, const std::string fileName = "Settings")
{
	if (companyName.empty() || programName.empty())
	{
		return;
	}

	mTitle = "SettingsUtility";
	mExtension = ".ini";
	mCompanyName = companyName;
	mProgramName = programName;
	mFileName = fileName;
	mIsInitialized = true;
}

SettingsUtility::~SettingsUtility()
{
	// TODO
}

int SettingsUtility::SetFileName(const std::string filename)
{
	// File already open, cant set name. 
	if (mFile.is_open())
	{
		return -1;
	}

	// Set name. 
	dCSVFileInfo.filename = filename;

	// if filenames are equal, success. 
	if (dCSVFileInfo.filename == filename)
	{
		return 1;
	}
	// failed. 
	return 0;
}