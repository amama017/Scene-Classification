/* 
 * File:   Clusters.h
 * Author: abdo
 *
 * Created on December 25, 2012, 7:00 AM
 */

#ifndef CLUSTERS_H
#define	CLUSTERS_H

#include "includes.h"

class Clusters {
public:
    Clusters();
    void executeKmeans(Mat* descriptor, Mat* trainImages, 
        Mat& centers, Mat& labels, int size, int clusterCount = k);
};


#endif	/* CLUSTERS_H */

