#include "ImageMasking.h"

struct Parameters {
	std::string imageFile;
	std::string maskFile;
	bool isCompressed;
};

Parameters parseArgs(int argc, char** argv) {
	Parameters params;
	params.imageFile = "";
	params.maskFile = "";
	params.isCompressed = false;

	for (auto i = 1; i < argc; ++i) {

		std::string paramValue{ argv[i] };

		if (paramValue == "-i") {
			params.imageFile = std::string{ argv[i + 1] };
			continue;
		}

		if (paramValue == "-m") {
			params.maskFile = std::string{ argv[i + 1] };
			continue;
		}

		if (paramValue == "-c") {
			params.isCompressed = true;
			continue;
		}
	}

	return params;
}

std::pair<size_t, size_t> prepareData(Parameters& args) {

	if (args.imageFile == "") {
		std::cout << "No image file. Generate file " << DEFAULT_IMAGE_FILE_NAME << "..." << std::endl;
		args.imageFile = DEFAULT_IMAGE_FILE_NAME;
		generateImageFile(args.imageFile, IMAGE_SIZE, IMAGE_SIZE);
	}
	else {
		if (!checkFile(args.imageFile)) {
			std::cout << "Can't open image file" << std::endl;
			exit(2);
		}
	}

	if (args.maskFile == "") {
		std::cout << "No mask file. Generate file " << DEFAULT_MASK_FILE_NAME << "..." << std::endl;
		args.maskFile = DEFAULT_MASK_FILE_NAME;
		generateMaskFile(args.maskFile, IMAGE_SIZE, IMAGE_SIZE, args.isCompressed);
	}
	else {
		if (!checkFile(args.maskFile)) {
			std::cout << "Can't open image file" << std::endl;
			exit(2);
		}
	}

	std::pair<size_t, size_t> imageFileSize = getFileSize(args.imageFile);
	std::pair<size_t, size_t> maskFileSize = getFileSize(args.maskFile);

	bool correctSizes = args.isCompressed ? (imageFileSize.second == maskFileSize.second) : (imageFileSize.first == maskFileSize.first) && (imageFileSize.second == maskFileSize.second);

	if (!correctSizes) {
		std::cout << "Image and mask files has different sizes." << std::endl;
		exit(2);
	}
	return imageFileSize;
}

void printHelpMessage() {
	std::cout << "This program created for masking images in text format." << std::endl;
	std::cout << "Flags:" << std::endl;
	std::cout << "-i\t[image_file] Image file name" << std::endl;
	std::cout << "-m\t[mask_file] Mask file name" << std::endl;
	std::cout << "-c\t\t Use compressed mask (in decemical format)" << std::endl;
}

int main(int argc, char** argv) {
	srand(time(NULL));
	Parameters args = parseArgs(argc, argv);
	auto imageFileSize = prepareData(args);

	std::cout << "INPUT IMAGE FILE" << std::endl;
	printFile(args.imageFile);
	std::cout << "INPUT MASK FILE" << std::endl;
	printFile(args.maskFile);

	maskImage(args.imageFile, args.maskFile, imageFileSize.first, imageFileSize.second, args.isCompressed);

	std::cout << "RESULT FILE" << std::endl;
	printFile(OUT_FILE_NAME);

	return 0;
}

