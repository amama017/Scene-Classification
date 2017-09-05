/* 
 * File:   includes.h
 * Author: abdo
 *
 * Created on December 23, 2012, 9:24 PM
 */

#ifndef INCLUDES_H
#define	INCLUDES_H

#include "opencv/cv.h"
#include "opencv/highgui.h"
#include <iostream>

using namespace std;
using namespace cv;

enum EXTRACTOR {
    SIFT_, SURF_,ORB_
};

static int k = 50;
static int numOfLevels = 1;
static int trainImgsSize = 1500;
static int testImgsSize = 2985;
static EXTRACTOR FeatureType = SURF_;

#endif	/* INCLUDES_H */

