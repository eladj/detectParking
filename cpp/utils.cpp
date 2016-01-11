#include "utils.h"

// *******************************************************
// * Parse the text file with the parking data
// * Each line in the text file should be in the format:
// *   id x1 y1 x2 y2 x3 y3 x4 y4
// *******************************************************
vector<Parking> parse_parking_file(string filename) {
	fstream infile(filename);
	string line;
	vector<Parking> parkings;

	while (getline(infile, line))
	{
		Parking park;
		vector<cv::Point> points;
		istringstream iss(line);
		int id, x1, y1, x2, y2, x3, y3, x4, y4;
		if (!(iss >> id >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4)) { break; } // error

																					 // Create current park object
		points.push_back(cv::Point(x1, y1));
		points.push_back(cv::Point(x2, y2));
		points.push_back(cv::Point(x3, y3));
		points.push_back(cv::Point(x4, y4));
		park.setId(id);
		park.setPoints(points);
		park.calcBoundingRect();
		// Add to the parkings vector
		parkings.push_back(park);
	}
	return parkings;
}
