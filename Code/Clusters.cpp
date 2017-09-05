#include "Clusters.h"
#include "Features.h"
#include "IO.h"

Clusters::Clusters() { }

void Clusters::executeKmeans(Mat* descriptor, Mat* trainImages, 
        Mat& centers, Mat& labels, int size, int clusterCount) {
    //============== SIFT ============================================
    Features f;
    //f.SIFT_Feat(trainImages, descriptor, trainImgsSize);
    //============== SURF ============================================
    f.extractFeatures(trainImages, descriptor, size, FeatureType);

    //============== K-Means =========================================
    IO write; 
    write.printToFile(centers, labels);
    //readFromFile(centers, labels);
    
    // Combine matrices
    Mat desc = Mat(0, 128, CV_32F);
    for (int i = 0; i < size; i++) {
        Mat temp = descriptor[i];
        for (int q = 0; q < temp.rows; q++)
            desc.push_back(temp.row(q));
    }

    // Execute algorithm
    kmeans(desc, clusterCount, labels, TermCriteria(CV_TERMCRIT_EPS + CV_TERMCRIT_ITER, 100, 1.0), 3, KMEANS_PP_CENTERS, centers);
}
