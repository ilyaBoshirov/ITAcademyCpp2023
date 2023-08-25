#pragma once

#include <algorithm>
#include <functional>
#include <string>
#include <vector>


struct Contains : public std::binary_function<std::string, std::string, bool>
{
	bool operator()(std::string const& item, std::string const& pattern) const
	{
		std::string str{ item };
		std::transform(str.begin(), str.end(), str.begin(),
			[](unsigned char c) { return std::tolower(c); });
		return str.find(pattern) != std::string::npos;
	}
};


auto getNumberOfMatches{ [](std::vector<std::string> lines, std::string pattern) {
	return std::count_if(lines.begin(), lines.end(), std::bind2nd(Contains(), pattern));
	}
};
