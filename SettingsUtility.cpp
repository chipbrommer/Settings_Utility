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

int SettingsUtility::SetFileType(const FILE_TYPE type)
{
	// File already open, cant set name. 
	if (mFile.is_open())
	{
		return -1;
	}

	// Set extension. 
	mSettingsFile.type = type;

	// If extensions are equal, success. 
	if (mSettingsFile.type == type)
	{
		return 1;
	}

	// Failed. 
	return 0;
}

int SettingsUtility::CreateOrVerifyDirectory(const std::string directory = "C:\\ProgramData")
{
	// Handler for the error return
	DWORD err;
	std::wstring stemp = std::wstring(directory.begin(), directory.end());
	LPCWSTR sw = stemp.c_str();

	// Utilizing the CreateDirectory, we check the series of return values.
	if (CreateDirectory(sw, NULL) == 0)
	{
		// Get the error
		err = GetLastError();

		// Directory already exists
		if (err == ERROR_ALREADY_EXISTS)
		{
			std::cout << "The path is valid!";
			return 0;
		}
	}
	else
	{
		// Path was created
		std::cout << "The path was created!";
		return 1;
	}

	// Failed
	return -1;
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