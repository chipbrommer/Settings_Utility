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
	// Make sure all the info has been set 
	if (!mSettingsFile.Valid())
	{
		return -3;
	}

	// Check if we are already opened. 
	if (mFile.is_open())
	{
		return -2;
	}

	// Open
	mFile.open(mSettingsFile.GetFullPath(), std::ios::in | std::ios::out | std::ios::trunc);

	// Check if open was successful
	if (!mFile.is_open())
	{
#ifdef CPP_LOGGER
		log->AddEntry(LOG_LEVEL::LOG_ERROR, mTitle, "Failed to open the output file.");
#else
		printf_s("%s - Failed to open the output file.\n", mTitle.c_str());
#endif
		return -1;
	}

	// Re-assurance check that the file is good. 
	if (mFile.good())
	{
		// Success
#ifdef CPP_LOGGER
		log->AddEntry(LOG_LEVEL::LOG_INFO, mTitle, "File open successful: %s", mSettingsFile.GetFullPath().c_str());
#else
		printf_s("%s - File open successful: %s\n", mTitle.c_str(), mSettingsFile.GetFullPath().c_str());
#endif
		return 0;
	}
	else
	{
		CatchFailReason();
	}

	// Default Return
	return -1;
}

int SettingsUtility::CloseFile()
{
	// Verify the file is open.
	// if not open, return. 
	if (!mFile.is_open())
	{
		return -2;
	}
	else
	{
		// Close the file, clear the filename and reset the file flag
		mFile.close();

		// Verify file is closed and return appropriately. 
		if (mFile.is_open())
		{
			return -1;
		}

		return 0;
	}

	// Default Return. 
	return -1;
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

void SettingsUtility::CatchFailReason()
{
	if (mFile.eof())
	{
		printf("Eof bit set.\n");
	}
	else if (mFile.bad())
	{
		printf("Bad bit set.\n");
	}
	else if (mFile.fail())
	{
		printf("Fail bit set.\n");
	}
	else
	{
		printf("Unknown failure.\n");
	}
}