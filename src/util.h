/*
 * Copyright 2012 Moritz Hilscher
 *
 * This file is part of mapcrafter.
 *
 * mapcrafter is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * mapcrafter is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with mapcrafter.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef UTIL_H_
#define UTIL_H_

#include <iostream>
#include <sstream>
#include <string>
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)

namespace mapcrafter {

bool isBigEndian();

template<typename T>
std::string str(T value) {
	std::stringstream ss;
	ss << value;
	return ss.str();
}

bool copyFile(const fs::path& from, const fs::path& to);
bool copyDirectory(const fs::path& from, const fs::path& to);

void replaceAll(std::string& str, const std::string& from, const std::string& to);

/**
 * Shows a nice command line progress bar.
 */
class ProgressBar {
private:
	// the maximum value of the progress
	int max;
	// animated? if yes, it updates the progress bar and makes it "animated"
	// but not good if you pipe the output in a file, so you can disable it
	bool animated;

	// the time of the start of progress
	int start;
	// time of last update
	int last_update;
	// value of last update
	int last_value;
	// current percentage of last update
	int last_percent;
public:
	ProgressBar();
	ProgressBar(int max, bool animated);

	void setMax(int max);
	int getMax() const;

	void setAnimated(bool animated);
	bool isAnimated() const;

	void update(int value);
	void finish();
};

}

#endif /* UTIL_H_ */
