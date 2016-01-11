Automatic Parking Detection
===========================

This repository contains:

- C++ code
- Python prototype
- 1 video for testing

Running
-------

`DetectParking.exe <Video_Filename or Camera_Number> <ParkingData_Filename>`

Where:
- <Camera_Number> can be 0, 1, ... for webcam or usb camera.
- <ParkingData_Filename> should be simple txt file with lines of: id x1 y1 x2 y2 x3 y3 x4 y4.
  The x,y are the quadrilateral 4 points which mark the parking spot.
  `See \datasets\parkinglot_1.txt` for example.
  
Required Dlls from OpenCV: opencv_core300.dll, opencv_ffmpeg300.dll, opencv_highgui300.dll, opencv_imgcodecs300.dll, opencv_imgproc300.dll, opencv_videoio300.dll.

Parameters
----------

You can play with the threshold in `Parking.h`.

```c++
#define PARK_LAPLACIAN_TH 2
```

You can turn on/off the parking detection or saving output video in `main.cpp` by changing:

```c++
#define DETECT_PARKING true
#define SAVE_VIDEO false
```

Building
--------

**Linux:** I compiled it on Raspbian (Debian) with GCC 4.9 using the following command:

`TO ADD`

**Windows:** Add the files to a Visual Studio solution. Add the OpenCV header and libraries files and build.

Screenshots
-----------

[Video 1](https://youtu.be/bPeGC8-PQJg)

![Parking Lot 1](/docs/parking_lot_img1.jpg)

![Parking Lot 2](/docs/parking_lot_img2.jpg)