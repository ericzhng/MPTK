/******************************************************************************/
/*                                                                            */
/*                             anywave_table.h                                */
/*                                                                            */
/*                        Matching Pursuit Library                            */
/*                                                                            */
/* R�mi Gribonval                                                             */
/* Sacha Krstulovic                                                           */
/* Sylvain Lesage                                             Tue Nov 03 2005 */
/* -------------------------------------------------------------------------- */
/*                                                                            */
/*  Copyright (C) 2005 IRISA                                                  */
/*                                                                            */
/*  This program is free software; you can redistribute it and/or             */
/*  modify it under the terms of the GNU General Public License               */
/*  as published by the Free Software Foundation; either version 2            */
/*  of the License, or (at your option) any later version.                    */
/*                                                                            */
/*  This program is distributed in the hope that it will be useful,           */
/*  but WITHOUT ANY WARRANTY; without even the implied warranty of            */
/*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             */
/*  GNU General Public License for more details.                              */
/*                                                                            */
/*  You should have received a copy of the GNU General Public License         */
/*  along with this program; if not, write to the Free Software               */
/*  Foundation, Inc., 59 Temple Place - Suite 330,                            */
/*  Boston, MA  02111-1307, USA.                                              */
/*                                                                            */
/******************************************************************************/

/*****************************************/
/*                                       */
/* DEFINITION OF THE ANYWAVE TABLE CLASS */
/*                                       */
/*****************************************/
/*
 * CVS log:
 *
 * $Author: sacha $
 * $Date: 2007-07-04 15:41:07 +0200 (Wed, 04 Jul 2007) $
 * $Revision: 1086 $
 *
 */


#ifndef __anywave_table_h_
#define __anywave_table_h_

/***********************/
/* ANYWAVE TABLE CLASS */
/***********************/
/**
 * \brief A MP_Anywave_Table_c object is used to store waveforms,
 * corresponding to anywave atoms.
 *
 * In one MP_Anywave_Table_c, all the waveforms have the same length. To
 * use atoms with different sizes, you need several MP_Anywave_Table_c
 * instances.
**/
class MP_Anywave_Table_c 
{
	/********/
	/* DATA */
	/********/
	public:
		/** \brief Unique key string reprensenting either :
		 * 1) The path of the dictionary file for dictionaries of ancient format
		 * 2) The datas of the block dictionary for dictionaries of new format 
		 */
		char *szKeyTable;
		/** \brief Name of the file containing the waveform table (text file, extension .xml)
		 *
		 * To import the waveforms of the anywave atoms (e.g. generated with Matlab) in MPTK, you need to save them in two files as described below :
		 * - a xml file (text mode), describing all the parameters of the waveforms
		 * - a bin file (binary mode), containing the raw data
		 *
		 * The xml file, e.g. called "PATH/anywave.xml", must have the following syntax :
		 * - \<?xml version="1.0" encoding="ISO-8859-1"?\>
		 * - \<libVersion\>0.4beta\</libVersion\>
		 * - \<table\>
		 *   - \<par type = "numChans"\>2\</par\>
		 *   - \<par type = "filterLen"\>50\</par\>
		 *   - \<par type = "numFilters"\>10\</par\>
		 *   - \<par type = "data"\>PATH/anywave_data.bin\</par\>
		 * - \</table\>
		 *
		 * The associated binary file, called "PATH/anywave_data.bin", only
		 * contains the waveforms, in "double" format. The data is then \a
		 * numChans * \a numFilters * \a filterLen numbers in "double"
		 * format, in this example 1000 numbers, in the following order :
		 * - the first waveform, channel after channel
		 * - the second waveform, channel after channel 
		 * - so on ...
		 *
		 */
		char tableFileName[MP_MAX_STR_LEN];
		/** \brief Name of the file containing the data of the waveform table (binary file, extension .bin)
		 *
		 * To import the waveforms of the anywave atoms (e.g. generated with Matlab) in MPTK, you need to save them in two files as described below :
		 * - a xml file (text mode), describing all the parameters of the waveforms
		 * - a bin file (binary mode), containing the raw data
		 *
		 * The xml file, e.g. called "PATH/anywave.xml", must have the following syntax :
		 * - \<?xml version="1.0" encoding="ISO-8859-1"?\>
		 * - \<libVersion\>0.4beta\</libVersion\>
		 * - \<table\>
		 *   - \<par type = "numChans"\>2\</par\>
		 *   - \<par type = "filterLen"\>50\</par\>
		 *   - \<par type = "numFilters"\>10\</par\>
		 *   - \<par type = "data"\>PATH/anywave_data.bin\</par\>
		 * - \</table\>
		 *
		 * The associated binary file, called "PATH/anywave_data.bin", only
		 * contains the waveforms, in "double" format. The data is then \a
		 * numChans * \a numFilters * \a filterLen numbers in "double"
		 * format, in this example 1000 numbers, in the following order :
		 * - the first waveform, channel after channel
		 * - the second waveform, channel after channel 
		 * - so on ...
		 *
		 */
		char dataFileName[MP_MAX_STR_LEN];
		/** \brief Storage of the data. 
		 *
		 * The filters are stored one after the other, and for each filter,
		 * one channel after the other (as they are stored in the binary
		 * data file).
		 */
		MP_Real_t* storage;
		/** \brief Number of channels of the waveforms. 
		 * 
		 * It must be either 1, either the same number as in the signal to
		 * analyze.
		 */
		MP_Chan_t numChans;
		/** \brief Length of the waveforms */
		unsigned long int filterLen;
		/** \brief Number of waveforms */
		unsigned long int numFilters;
		/** \brief Flag indicating if the waveforms have been normalized
		 * 0 if not normalized
		 * 1 if normalized
		 * 2 if an error occured during the normalization.
		 */
		unsigned long int normalized;
		unsigned long int centeredAndDenyquisted;
		/** \brief Table of pointers to the waveforms
		 *
		 * The table is indexed by the number of the filter and the number
		 * of the channel. By example, wave[2][1] points to the second
		 * channel of the third waveform
		 */
		MP_Real_t*** wave;
	
	/***********/
	/* METHODS */
	/***********/

	/***************************/
	/* CONSTRUCTORS/DESTRUCTOR */
	/***************************/
	public:
		/** \brief Default constructor */
		MPTK_LIB_EXPORT MP_Anywave_Table_c( void );
		/** \brief Default destructor */
		MPTK_LIB_EXPORT virtual ~MP_Anywave_Table_c( void );

	/***************************/
	/* I/O METHODS             */
	/***************************/
	public:
		/** \brief Constructor using a filename
		 * \param fileName A string containing the name of the file that describes the anywave table
		 * \return true for success, false for failure
		 */
		MPTK_LIB_EXPORT bool AnywaveCreator( char* fileName );
		
		/** \brief Constructor using a filename
		 * \param paramMap A map of strings containing all the datas of the dictionary
		 * \return true for success, false for failure
		 */
		MPTK_LIB_EXPORT bool AnywaveCreator( map<string, string, mp_ltstring> *paramMap );
		
		/** \brief load the data contained in dataFileName, store it in storage and update the pointers in wave
		 * \return true for success, false for failure
		 **/
		MPTK_LIB_EXPORT bool load_data_anywave( void );

		/** \brief load the data contained in the szInputDatas, store it in storage and update the pointers in wave
		 * \return true for success, false for failure
		 **/
		MPTK_LIB_EXPORT bool load_data_anywave( char *szInputDatas );

		/** \brief creates a copy of this table (with all allocations needed)
		 * \return the copied anywave table
		 */
		MPTK_LIB_EXPORT MP_Anywave_Table_c* copy( void );

		/** \brief creates the dual table, named name, containing, for each filter, its hilbert transform
		 * \param szkeyTableName The hilbert keyname string
		 * \return The created (hilbert) anywave table
		 */
		MPTK_LIB_EXPORT MP_Anywave_Table_c* create_hilbert_dual( char* szkeyTableName );
	private:
		/** \brief Parse the xml file fName that describes the table
		 * \return true for success, false for failure
		 */
		bool parse_xml_file(const char* fName);

	/***************************/
	/* OTHER METHODS           */
	/***************************/
	public:
		/** \brief Test function, called by the test executable test_anywave
		 * \param filename The file to test in string
		 */
		MPTK_LIB_EXPORT static bool test( char* filename );
		
		/** \brief Re-initialize all the members */
		MPTK_LIB_EXPORT void reset( void );
		
		/** \brief Normalize the waveforms and update the flag \a normalize
		 * \returns 1 if succeed or 2 if an error occured
		 */
		MPTK_LIB_EXPORT unsigned long int normalize( void );
		
		/** \brief Sets the mean and the nyquist component of the waveforms to 0, and update the flag \a centeredAndDenyquisted
		 * \returns 1 if succeed or 2 if an error occured
		 */
		MPTK_LIB_EXPORT unsigned long int center_and_denyquist( void );
		
		/** \brief set the \a tableFileName member to  \a fileName
		 * \return pointer to the string \a tableFileName
		 */
		MPTK_LIB_EXPORT char* set_table_file_name( const char* fileName );
		
		/** \brief set the \a dataFileName member to \a fileName
		 * \return pointer to the string \a dataFileName
		*/
		MPTK_LIB_EXPORT char* set_data_file_name( const char* fileName );
		
		/** \brief set the \a szKeyTable member to \a szkeyTableName
		 * \return pointer to the string \a szKeyTable
		*/
		MPTK_LIB_EXPORT char* set_key_table( const char* szkeyTableName );

		/** \brief Encodes the input storage
		 * \return the encoded string
		*/
		MPTK_LIB_EXPORT string encodeBase64( char *szStorage, int iSizeToEncode );

	private:  
		/** \brief Allocate the pointers array \a wave, using the dimensions
		 * \a numFilters and \a numChans
		 * \return false if failed, true if succeed
		 **/
		bool alloc_wave( void );
		/** \brief Free the pointer array \a wave */
		void free_wave( void );
};
#endif /* __anywave_table_h_ */
