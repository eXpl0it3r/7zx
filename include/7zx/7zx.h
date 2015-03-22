/* lib7z.h -- Library header for 7zx
2015-03-22 : Lukas Duerrenberger : Public domain */

#ifndef __LIB7ZX_H
#define __LIB7ZX_H

#ifdef __cplusplus
extern "C" {
#endif

#include <7zx/7zTypes.h>

////////////////////////////////////////////////////////////
/// \brief Extract an 7z archive
///
/// \param filename Filename of the 7z archive
/// \param fullPaths Should the archive be extracted with full paths i.e. in directories?
///
/// \return SZ_OK if successful
///
////////////////////////////////////////////////////////////
extern SRes SzxExtract(const char* filename, Bool fullPaths = 1);

////////////////////////////////////////////////////////////
/// \brief List the content of an 7z archive
///
/// \param filename Filename of the 7z archive
/// \param list Byte buffer to get the archive's list
/// \param size Size of the buffer
///
/// \return SZ_OK if successful
///
////////////////////////////////////////////////////////////
extern SRes SzxList(const char* filename, char* list, size_t* size);

////////////////////////////////////////////////////////////
/// \brief Test the integrity of an 7z archive
///
/// \param filename Filename of the 7z archive
///
/// \return SZ_OK if successful
///
////////////////////////////////////////////////////////////
extern SRes SzxTest(const char* filename);

#ifdef __cplusplus
}
#endif

#endif // __LIB7ZX_H

////////////////////////////////////////////////////////////
/// 7zx is a small C library to extract, test and list 7z / 7zip archives.
/// Supported formats are LZMA, LZMA2 and PPMD.
///
/// Usage example:
/// \code
/// char list[1024] = {};
/// size_t size = 1024;
/// SzxList("example.7z", list, &size); // List the archive's content
/// SzxTest("example.7z");              // Test the archive
/// SzxExtract("example.7z");           // Extract the archive with full paths
/// SzxExtract("example.7z", 0);        // Extract the archive flat
/// \endcode
///
////////////////////////////////////////////////////////////
