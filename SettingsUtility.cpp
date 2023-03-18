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
#pragma once
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
	mSettingsFile = SettingsFile();
}

SettingsUtility::SettingsUtility(const std::string companyName, const std::string programName, const std::string fileName = "Settings")
{
	if (companyName.empty() || programName.empty())
	{
		return;
	}

	mTitle = "SettingsUtility";
	mSettingsFile = SettingsFile();
}

SettingsUtility::~SettingsUtility()
{
	if (mFile.is_open())
	{
		CloseFile();
	}
}

int SettingsUtility::SetCompanyName(const std::string company)
{
	// File already open, cant set company. 
	if (mFile.is_open())
	{
		return -1;
	}

	// Set name. 
	mSettingsFile.companyName = company;

	// If companyNames are equal, success. 
	if (mSettingsFile.companyName == company)
	{
		return 1;
	}

	// Failed. 
	return 0;
}

int SettingsUtility::SetProgramName(const std::string program)
{
	// File already open, cant set name. 
	if (mFile.is_open())
	{
		return -1;
	}

	// Set name. 
	mSettingsFile.programName = program;

	// If programNames are equal, success. 
	if (mSettingsFile.programName == program)
	{
		return 1;
	}

	// Failed. 
	return 0;
}

int SettingsUtility::SetFileName(const std::string filename)
{
	// File already open, cant set name. 
	if (mFile.is_open())
	{
		return -1;
	}

	// Set name. 
	mSettingsFile.fileName = filename;

	// If filenames are equal, success. 
	if (mSettingsFile.fileName == filename)
	{
		return 1;
	}

	// Failed. 
	return 0;
}

int SettingsUtility::SetExtension(const FILE_EXTENSION extension)
{
	// File already open, cant set name. 
	if (mFile.is_open())
	{
		return -1;
	}

	// Set extension. 
	mSettingsFile.extension = extension;

	// If extensions are equal, success. 
	if (mSettingsFile.extension == extension)
	{
		return 1;
	}

	// Failed. 
	return 0;
}

int SettingsUtility::OpenFile()
{
	if (!mSettingsFile.Valid())
	{
		return -2;
	}

	if (mFile.is_open())
	{
		return -1;
	}
	else
	{
		// TODO - Open file and return
	}

	// Failed. 
	return 0;
}

int SettingsUtility::CloseFile()
{
	if (!mFile.is_open())
	{
		return -1;
	}
	else
	{
		// TODO - Close file.

		return 1;
	}

	// Failed. 
	return 0;
}

int SettingsUtility::CreateSection(std::string section)
{
	// File not open, open it
	if (!mFile.is_open())
	{
		// TODO - open file
	}

	// TODO - add section to file

	// Failed. 
	return 0;
}