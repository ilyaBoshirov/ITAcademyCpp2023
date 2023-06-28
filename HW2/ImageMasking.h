#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <cmath>

#define DEFAULT_IMAGE_FILE_NAME "image.txt"
#define DEFAULT_MASK_FILE_NAME "mask.txt"
#define OUT_FILE_NAME "result.txt"
#define IMAGE_SIZE 8

std::pair<size_t, size_t> getFileSize(std::string fileName);

bool checkFile(std::string);

bool checkFileSizes(std::string imageFile, std::string maskFile, bool isCompressed);

void generateImageFile(std::string fileName, uint32_t width, uint32_t height);

void generateMaskFile(std::string fileName, uint32_t width, uint32_t height, bool isCompressed);

void maskImage(std::string imageFile, std::string maskFile, uint32_t width, uint32_t height, bool isCompressed);

void printFile(std::string fileName);
