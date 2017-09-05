/* 
 * File:   Pyramid.h
 * Author: abdo
 *
 * Created on December 25, 2012, 7:11 AM
 */

#ifndef PYRAMID_H
#define	PYRAMID_H

#include "includes.h"

class Pyramid {
public:
    Pyramid();
    int spatialPyramid(Mat image, int noofparts, bool bound, vector<Mat>* partitions);
    void BOW(Mat& features, Mat& centers, Mat& histogram);
};

#endif	/* PYRAMID_H */

