#include "ImageMasking.h"

struct Parameters {
	std::string imageFile;
	std::string maskFile;
	bool isCompressed;
	bool testMode;
};

void printHelpMessage() {
	std::cout << "This program created for masking images in text format." << std::endl;
	std::cout << "Usage: HW2.exe -t ..." << std::endl;
	std::cout << "OR" << std::endl;
	std::cout << "Usage: HW2.exe -i <image_file_name> ..." << std::endl;
	std::cout << std::endl;
	std::cout << "Flags:" << std::endl;
	std::cout << "-i\t[image_file] Image file name" << std::endl;
	std::cout << "-m\t[mask_file] Mask file name" << std::endl;
	std::cout << "-c\tUse compressed mask (in decemical format)" << std::endl;
	std::cout << "-h\tShow this message" << std::endl;
	std::cout << "-t\tTest mode (Auto generate image and mask)" << std::endl;
	std::cout << "Required parameters: -t or -i" << std::endl;
}

Parameters parseArgs(int argc, char** argv) {
	Parameters params;
	params.imageFile = "";
	params.maskFile = "";
	params.isCompressed = false;
	params.testMode = false;

	for (auto i = 1; i < argc; ++i) {

		std::string paramValue{ argv[i] };

		if (paramValue == "-i") {
			if (i + 1 >= argc) {
				std::cout << "No image file" << std::endl;
				exit(2);
			}

			params.imageFile = std::string{ argv[i + 1] };
			continue;
		}

		if (paramValue == "-m") {
			if (i + 1 >= argc) {
				std::cout << "No mask file" << std::endl;
				exit(2);
			}

			params.maskFile = std::string{ argv[i + 1] };
			continue;
		}

		if (paramValue == "-c") {
			params.isCompressed = true;
			continue;
		}

		if (paramValue == "-t") {
			params.testMode = true;
			continue;
		}

		if (paramValue == "-h") {
			printHelpMessage();
			exit(0);
		}
	}

	if (params.imageFile == "" && params.testMode == false) {
		printHelpMessage();
		exit(0);
	}

	return params;
}

std::pair<size_t, size_t> prepareData(Parameters& args) {

	if (args.testMode) {
		args.imageFile = DEFAULT_IMAGE_FILE_NAME;
		generateImageFile(args.imageFile, IMAGE_SIZE, IMAGE_SIZE);

		args.maskFile = DEFAULT_MASK_FILE_NAME;
		generateMaskFile(args.maskFile, IMAGE_SIZE, IMAGE_SIZE, args.isCompressed);
		
		return std::make_pair(IMAGE_SIZE, IMAGE_SIZE);
	}

	if (!checkFile(args.imageFile)) {
		std::cout << "Can't open image file" << std::endl;
		exit(2);
	}

	if (args.maskFile == "") {
		std::cout << "No mask file. Generate mask file " << DEFAULT_MASK_FILE_NAME << "..." << std::endl;
		args.maskFile = DEFAULT_MASK_FILE_NAME;
		generateMaskFile(args.maskFile, IMAGE_SIZE, IMAGE_SIZE, args.isCompressed);
	}
	else {
		if (!checkFile(args.maskFile)) {
			std::cout << "Can't open image file" << std::endl;
			exit(2);
		}
	}

	auto imageFileSize = getFileSize(args.imageFile);
	auto maskFileSize = getFileSize(args.maskFile);

	bool correctSizes = args.isCompressed ? (imageFileSize.second == maskFileSize.second) : (imageFileSize.first == maskFileSize.first) && (imageFileSize.second == maskFileSize.second);

	if (!correctSizes) {
		std::cout << "Image and mask files has different sizes." << std::endl;
		exit(2);
	}
	return imageFileSize;
}

int main(int argc, char** argv) {
	srand(time(NULL));

	if (argc == 1) {
		printHelpMessage();
		return 0;
	}

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

