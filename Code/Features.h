/* 
 * File:   Features.h
 * Author: abdo
 *
 * Created on December 25, 2012, 6:44 AM
 */

#ifndef FEATURES_H
#define	FEATURES_H

#include "includes.h"

class Features {
public:
    Features();
    void SIFT_Feat(Mat& image, Mat& descriptor);
    void SIFT_Feat(Mat* images, Mat* descriptor, int size);
    void SURF_Feat(Mat& image, Mat& descriptor);
    void SURF_Feat(Mat* images, Mat* descriptor, int size);
    void ORB_Feat(Mat& image, Mat& descriptor);
    void ORB_Feat(Mat* images, Mat* descriptor, int size);
    void extractFeatures(Mat* images, Mat* descriptor, int size, EXTRACTOR TYPE);
    void extractFeatures(Mat& image, Mat& descriptor, EXTRACTOR TYPE);
};

#endif	/* FEATURES_H */

