#include "ImageMasking.h"

size_t getLineSize(std::string line)
{
	std::vector<std::string> bytes{};
	char ch = ' ';

	auto initialPos = 0;
	auto pos = line.find(ch, initialPos);

	// Decompose statement
	while (pos != std::string::npos) {
		bytes.push_back(line.substr(initialPos, pos - initialPos));
		initialPos = pos + 1;

		pos = line.find(ch, initialPos);
	}

	// Add the last one
	bytes.push_back(line.substr(initialPos, std::min(pos, line.size()) - initialPos + 1));

	return bytes.size();
}

bool checkFile(std::string fileName) {
	std::ifstream fin(fileName);
	auto isOpen = fin.is_open();
	fin.close();
	return isOpen;
}

std::pair<size_t, size_t> getFileSize(std::string fileName) {
	auto fileWidth{ 0 };
	auto fileHeight{ 0 };

	std::ifstream fin(fileName);
	if (!fin) {
		std::cout << "Can't open file " << fileName << std::endl;
		fin.close();
	}

	std::string line;
	std::string lastLine;

	while (!fin.eof()) {
		std::getline(fin, line);

		if (line.length() == 0) {
			break;
		}

		fileHeight += 1;
		lastLine = line;
	}
	fileWidth = getLineSize(lastLine);

	fin.close();

	return std::make_pair(fileWidth, fileHeight);
}

void printFile(std::string fileName) {
	std::ifstream fin(fileName);

	if (!fin) {
		std::cout << "Can't open file " << fileName << std::endl;
		fin.close();
	}

	std::string line;

	while (!fin.eof()) {
		std::getline(fin, line);
		std::cout << line << std::endl;
	}

	fin.close();
}

std::vector<uint32_t> getFileData(std::string fileName, uint32_t fileSize) {
	std::vector<uint32_t> fileData{};

	std::ifstream fin(fileName);
	if (!fin) {
		std::cout << "Can't open file " << fileName << std::endl;
		fin.close();
	}

	uint32_t element;

	for (auto i = 0; i < fileSize; ++i) {
		fin >> element;
		fileData.push_back(element);
	}

	fin.close();

	return fileData;
}

void maskImage(std::string imageFile, std::string maskFile, uint32_t width, uint32_t height, bool isCompressed) {
	std::vector<uint32_t> imageData = getFileData(imageFile, width * height);
	std::vector<uint32_t> maskData = getFileData(maskFile, isCompressed ? height : width * height);

	std::vector<uint32_t> resultImage{};

	if (!isCompressed) {
		for (auto i = 0; i < height; ++i) {
			for (auto j = 0; j < width; ++j) {
				resultImage.push_back(imageData[width * i + j] * maskData[width * i + j]);
			}
		}
	}
	else {
		for (auto i = 0; i < height; ++i) {
			for (auto j = 0; j < width; ++j) {
				resultImage.push_back(imageData[width * i + j] * ((maskData[i] >> (IMAGE_SIZE - j - 1)) & 0x1));
			}
		}
	}

	std::ofstream fout(OUT_FILE_NAME);
	if (!fout) {
		std::cout << "Can't create file " << OUT_FILE_NAME << std::endl;
	}
	for (auto i = 0; i < height; ++i) {
		for (auto j = 0; j < width; ++j) {
			fout << int(resultImage[width * i + j]) << " ";
		}
		fout << std::endl;
	}
}

void generateImageFile(std::string fileName, uint32_t width, uint32_t height) {
	std::ofstream fout(fileName);

	for (auto i = 0; i < width; ++i) {
		for (auto j = 0; j < height; ++j) {
			fout << rand() % 10;

			if (j < (IMAGE_SIZE - 1)) {
				fout << ' ';
			}
			else {
				fout << std::endl;
			}
		}
	}

	fout.close();
}

void generateMaskFile(std::string fileName, uint32_t width, uint32_t height, bool isCompressed) {
	std::ofstream fout(fileName);

	if (isCompressed) {
		for (auto j = 0; j < height; ++j) {
			fout << rand() % int(pow(2, IMAGE_SIZE)) << std::endl;
		}
	}
	else {
		for (auto i = 0; i < width; ++i) {
			for (auto j = 0; j < height; ++j) {
				fout << rand() % 2;

				if (j < (IMAGE_SIZE - 1)) {
					fout << ' ';
				}
				else {
					fout << std::endl;
				}
			}
		}
	}

	fout.close();
}