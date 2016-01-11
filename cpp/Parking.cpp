#include "Parking.h"



Parking::Parking()
{
	id=-1;
	occupied = false;
}

void Parking::setStatus(bool status)
{
	occupied = status;
}

bool Parking::getStatus(void)
{
	return occupied;
}

void Parking::setId(int n)
{
	id = n;
}

int Parking::getId(void)
{
	return id;
}

void Parking::setPoints(vector<cv::Point> points)
{
	vector<vector<cv::Point>> contours;
	contours.push_back(points);
	contours_points = contours;
}

vector<vector<cv::Point>> Parking::getContourPoints(void)
{
	return contours_points;
}

void Parking::calcBoundingRect(void)
{
	if (!contours_points.empty())
	{
		bounding_rect =  cv::boundingRect(contours_points.at(0));
		// Create a mask for contour, to mask out that region from roi.
		mask = cv::Mat::zeros(bounding_rect.size(), CV_8UC1);
		for (cv::Point p : contours_points.at(0))
		{
			polygon_points_in_bounding_rect.push_back(cv::Point(p.x - bounding_rect.x, p.y - bounding_rect.y));
		}
		vector<vector<cv::Point>> contours;
		contours.push_back(polygon_points_in_bounding_rect);		
		cv::drawContours(mask, contours, -1, cv::Scalar(255), CV_FILLED);
	}
	else
	{
		throw logic_error("Cannot calculate boundingRect when polygon_points are empty");
	}
	
}

cv::Rect Parking::getBoundingRect(void)
{
	return bounding_rect;
}

cv::Mat Parking::getMask(void)
{
	return mask;
}

cv::Point Parking::getCenterPoint(void)
{
	cv::Point center = cv::Point((2 * bounding_rect.x + bounding_rect.width) / 2, (2 * bounding_rect.y + bounding_rect.height) / 2);
	return center;
}