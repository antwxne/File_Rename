//
// Created by antoine on 7/9/22.
//

#include <filesystem>
#include <iostream>
#include <unordered_map>
#include <sys/stat.h>
#include <time.h>
#include <cassert>

#include "RenameClass.hpp"

void RenameClass::renameFilesByDate(const std::string &folderPath)
{
    std::string newPath;
    std::string mimeType;
    std::string filePath;
    std::string fileDate;
    std::unordered_map<std::string, std::size_t> dateMap;
    for (const auto &entry: std::filesystem::directory_iterator(folderPath)) {
        filePath = entry.path().string();
        mimeType = entry.path().extension().string();
        fileDate = getFileDate(filePath);
        newPath =
            folderPath + "/" + fileDate + "_" + std::to_string(dateMap[fileDate]) +
                mimeType;
        dateMap[fileDate] += 1;
        std::cout << newPath << std::endl;
        std::rename(filePath.c_str(), newPath.c_str());
    }
}

std::string RenameClass::getMimeType(const std::string &path)
{
    return &path[path.find_last_of('.')];
}

std::string RenameClass::getFileDate(const std::string &filePath)
{
    #if _WIN32
    return "";
    #else
    struct stat t_stat;
    char buffer[11];
    stat(filePath.c_str(), &t_stat);
    struct tm *timeinfo = localtime(&t_stat.st_ctime);
    strftime(buffer, 11, "%d_%m_%Y", timeinfo);
    return buffer;
    #endif
}
