//
// Created by antoine on 7/9/22.
//

#ifndef CHANGER_LES_NOMS_DES_FICHIERS_PAR_DATE_RENAMECLASS_HPP
#define CHANGER_LES_NOMS_DES_FICHIERS_PAR_DATE_RENAMECLASS_HPP

#include <string>

class RenameClass {

public:
    static void renameFilesByDate(const std::string &folderPath);
    static std::string getMimeType(const std::string &path);
    static std::string getFileDate(const std::string &filePath);
};

#endif //CHANGER_LES_NOMS_DES_FICHIERS_PAR_DATE_RENAMECLASS_HPP
