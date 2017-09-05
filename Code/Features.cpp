#include "Features.h"
#include <opencv2/nonfree/features2d.hpp>

Features::Features() {
}

void Features::SIFT_Feat(Mat& image, Mat& descriptor) {
    SiftDescriptorExtractor extractor;
    SiftFeatureDetector detector;
    vector<KeyPoint> keypoints;

    detector.detect(image, keypoints);
    extractor.compute(image, keypoints, descriptor);
}

void Features::SURF_Feat(Mat& image, Mat& descriptor) {

    //setting the threshold value.high value will result low number of keypoints.
    int hessian = 100;
    //initializing the surf keypoint detector
    SurfFeatureDetector detector(hessian);

    //creating vector to store detected keypoints
    vector<KeyPoint> keypoints;
    //detect keypoints
    detector.detect(image, keypoints);

    /*extract descriptor vectors/feature vectors from each and every keypoints */
    SurfDescriptorExtractor extractor;
    //extracting descriptors/features
    extractor.compute(image, keypoints, descriptor);
}

void Features::ORB_Feat(Mat& image, Mat& descriptor) {
    OrbDescriptorExtractor extractor;
    OrbFeatureDetector detector;
    vector<KeyPoint> keypoints;
    Mat mask;
    detector.detect(image, keypoints, mask);
    extractor.compute(image, keypoints, descriptor);
    descriptor.convertTo(descriptor, CV_32F);
}

void Features::SIFT_Feat(Mat* images, Mat* descriptor, int size) {
    for (int i = 0; i < size; i++) {
        SIFT_Feat(images[i], descriptor[i]);
    }

}

void Features::SURF_Feat(Mat* images, Mat* descriptor, int size) {
    for (int i = 0; i < size; i++) {
        SURF_Feat(images[i], descriptor[i]);
    }

}

void Features::ORB_Feat(Mat* images, Mat* descriptor, int size) {
    for (int i = 0; i < size; i++) {
        ORB_Feat(images[i], descriptor[i]);
    }

}

void Features::extractFeatures(Mat* images, Mat* descriptor, int size, EXTRACTOR TYPE) {
    switch (TYPE) {
        case SIFT_:
            SIFT_Feat(images, descriptor, size);
            break;
        case SURF_:
            SURF_Feat(images, descriptor, size);
            break;
        case ORB_:
            ORB_Feat(images, descriptor, size);
            break;
    }
}

void Features::extractFeatures(Mat& image, Mat& descriptor, EXTRACTOR TYPE) {
    switch (TYPE) {
        case SIFT_:
            SIFT_Feat(image, descriptor);
            break;
        case SURF_:
            SURF_Feat(image, descriptor);
            break;
        case ORB_:
            ORB_Feat(image, descriptor);
            break;
    }
}
