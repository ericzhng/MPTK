## NOTE
Only option here is to use Win32 build.
When compiling using Cmake, remember to deselect use shared library, otherwise can't build mptk4matlab

## Intro
The Matching Pursuit Tool Kit (MPTK) provides a fast implementation of the Matching Pursuit algorithm for the sparse decomposition of multichannel audio signals. It comprises a library, standalone utilities and wrappers for Matlab and Python enabling you to use MPTK directly and plot its results.

    * FAST: e.g., extract 1.5 million atoms from a 1 hour long, 16kHz audio signal (15dB extracted) in 0.25x real time on a Pentium IV@2.4GHz, out of a dictionary of 178M Gabor atoms. Such incredible speed makes it possible to process "real world" signals.
    * FLEXIBLE: multi-channel, various signal input formats, flexible syntax to describe the dictionaries => reproducible results, cleaner experiments.
    * OPEN: modular architecture => add your own atoms ! Free distribution under the GPL.

## Required

To build MPTK yo will need some packages:
	-Libsndfile: at least version 1.0.11 
	-fftw: at least version 3.0.1 
	-Qt(OpenSource): at least version 4.3.1

For further informations see Build MPTK for Linux and OSX or Build MPTK for Windows (Win 32) in pdf. Available on the INRIA GFORGE MPTK project (https://gforge.inria.fr/projects/mptk/) under Docs/Misc.


## Fix bugs

BUGS:
1 Add const to size_t in FILES: dict.in.cpp book.cpp
2 Modify PTHREAD_INCLUDE_DIR, FFTW3_INCLUDE_DIR, SNDFILE_INCLUDE_DIR in CMakeLists.txt in /src/utils Folder
3 Add SET(MATLAB_ROOT "C:/Program Files/MATLAB/R2017a") to FindMatlab.cmake in CMake Folder
4 Delete GP_ATOM and POSITION items from CMakeGenerateMPTKHeader.cmake file in CMake Folder
5 Modify hFile type to in dll_win32.cpp
6
7
8
9
10
11
12
13

2. modify mpd cmakefile

4. modify path.xml
IF(UNIX)
	SET(MPTK_TMP_PATH /tmp)
ELSE(UNIX)
	IF(WIN32)
		SET(MPTK_TMP_PATH C:/Temp)
	ENDIF(WIN32)
ENDIF(UNIX)

6. modify CMakeLists main
make sure select x64 in CMAKE.

MODIFICATIONS
Delete msg function in libmptk4matlab.cpp
getinfomptk.cpp, comment out free lines
Modify CMakeLists every time on a new computer, CMAKE_INSTALL_PREFIX, MPTK_TMP_PATH

Improvements
