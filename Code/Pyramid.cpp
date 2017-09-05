#include "Pyramid.h"

Pyramid::Pyramid() { }

int Pyramid::spatialPyramid(Mat image, int noofparts, bool bound, vector<Mat>* partitions) {
    if (noofparts == 1) {
        partitions->push_back(image);
        return 0;
    } else {
        int rows = image.rows;
        int cols = image.cols;
        if (bound == false) {
            cv::Mat subImg1 = image(cv::Range(0, rows), cv::Range(0, cols / 2));
            spatialPyramid(subImg1, noofparts / 2, true, partitions);
            cv::Mat subImg2 = image(cv::Range(0, rows), cv::Range((cols / 2) + 1, cols));
            spatialPyramid(subImg2, noofparts / 2, true, partitions);
        } else {
            cv::Mat subImg1 = image(cv::Range(0, rows / 2), cv::Range(0, cols));
            spatialPyramid(subImg1, noofparts / 2, false, partitions);
            cv::Mat subImg2 = image(cv::Range((rows / 2) + 1, rows), cv::Range(0, cols));
            spatialPyramid(subImg2, noofparts / 2, false, partitions);
        }
    }
    return 0;
}

void Pyramid::BOW(Mat& features, Mat& centers, Mat& histogram) {
    if (features.cols == 0) {
        // Create the historgram
        float arr[centers.rows];
        for (int i = 0; i < centers.rows; i++) {
            arr[i] = 0;
        }
        histogram = Mat(1, centers.rows, CV_32F, arr);
        return;
    }
    // KdTree with 5 random trees
    cv::flann::KDTreeIndexParams indexParams(5);

    // Create the Index
    cv::flann::Index kdtree(centers, indexParams);

    // Batch: Call knnSearch
    Mat indices; //(numQueries, k, CV_32S);
    Mat dists; //(numQueries, k, CV_32F);

    // Invoke the function
    kdtree.knnSearch(features, indices, dists, 1, cv::flann::SearchParams(64));

    // Create the historgram
    float arr[centers.rows];
    for (int i = 0; i < centers.rows; i++) {
        arr[i] = 0;
    }

    for (int i = 0; i < indices.rows; i++) {
        arr[indices.at<int>(i, 0)]++;
    }
    histogram = Mat(1, centers.rows, CV_32F, arr);
}
