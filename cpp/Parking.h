#pragma once
#include <string>
#include <sstream>
#include <fstream>
#include <opencv2/opencv.hpp>

using namespace std;
//#define PARK_LAPLACIAN_TH 6.5  // Threshold value for the laplacian, to decide if the parking is occupied or not
#define PARK_LAPLACIAN_TH 2

class Parking
{	
private:
	int id;
	vector<vector<cv::Point>> contours_points;
	vector<cv::Point> polygon_points_in_bounding_rect;
	cv::Rect bounding_rect;  // pre-calculated bounding_rect, to cut the ROI
	bool occupied;
	cv::Mat mask;  // mask of polygon in bounding_rect coordinates
public:
	Parking();
	void setStatus(bool status);
	bool getStatus(void);
	void setId(int n);
	int getId(void);
	void setPoints(vector<cv::Point> points);
	vector<vector<cv::Point>> getContourPoints(void);
	void calcBoundingRect(void);
	cv::Rect getBoundingRect(void);	
	cv::Mat getMask(void);
	cv::Point getCenterPoint(void);
};

