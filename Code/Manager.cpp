#include "Manager.h"
#include <math.h>
#include "IO.h"
#include "Clusters.h"
#include "Features.h"
#include "Pyramid.h"

Manager::Manager() { 
//    trainImages[trainImgsSize];
//    trainLabels[trainImgsSize];
//
//    testImages[testImgsSize];
//    testLabels[testImgsSize];
//
//    descriptor[trainImgsSize];
    
    fout.open("results.out");
}

void Manager::readImages() {
    //Read random images and return by reference the images and labels arrays
    io.readTrainImages(trainImages, trainLabels);
    io.readTestImages(testImages, testLabels);
}

void Manager::clustering() {
    //Extract the descriptors from the training images and use it to get the k-means
    //centers of the descriptor clusters & its labels
    Clusters cluster;
    cluster.executeKmeans(descriptor, trainImages, centers, labels, trainImgsSize);
}

void Manager::train() {
    Mat trainSet; //Matrix to save the Training Set in it
    int TrainConfusion[15][15]; //Confusion Matrix for the Training Set
    Mat labelsSet = Mat(trainImgsSize, 1, DataType<int>::type, trainLabels); //Construct the training labels vector
       
    //Get the Training Set in the Histogram format from the Training images
    getDataSet(trainSet, trainImages, trainImgsSize, true);  
    
    float res = classifier.trainSVM(SVM, trainSet, labelsSet, TrainConfusion);
    cout << "Error at training set: " << res << "%" << endl;
    fout << "Error at training set: " << res << "%" << endl;
    io.printConfustionMat(TrainConfusion, fout);
}

void Manager::test() {
    Mat testSet; //Matrix to save the Training Set in it
    int TestConfusion[15][15]; //Confusion Matrix for the Test Set
    Mat labelsSet = Mat(testImgsSize, 1, DataType<int>::type, testLabels); //Construct the test labels vector
    
    //Get the Training Set in the Histogram format from the Test images
    getDataSet(testSet, testImages, testImgsSize, false);
    
    float res = classifier.predictSVM(SVM, testSet, labelsSet, TestConfusion);
    cout << "Error at test set: " << res << "%" << endl;
    fout << "Error at test set: " << res << "%" << endl;
    io.printConfustionMat(TestConfusion, fout);
}

void Manager::getDataSet(Mat& dataSet, Mat* images, int size, bool train) {
    int totalParts = 1, rowSize, count = 0;
    float mul;
    Features features;
    Pyramid pyramid;
    for (int i = 1; i < numOfLevels; i++) {
        //Get the total nuber of blocks being processed
        totalParts += pow(4, i);
    }
    //Get the number of rows in the final descriptor of the image to be used in the SVM
    rowSize = totalParts * k;
    for (int imgI = 0; imgI < size; imgI++) {
        //A vector to save the histogarms of each block in it per image.
        float rowVec[rowSize];
        for (int level = 0; level < numOfLevels; level++) {
            //Create vector of partitions to save the image blocks in it.
            vector<Mat> partitions;
            //Get the Image blocks in level "level"
            pyramid.spatialPyramid(images[imgI], pow(4, level), false, &partitions);
            //Create array of matrices of the number of blocks.
            Mat desc[(int) partitions.size()];
            for (unsigned int b = 0; b < partitions.size(); b++) {//for each block
                Mat histogram;
                //Set the weight according to level
                if (level == 0 || level == 1)
                    mul = 0.25;
                else {
                    mul = 0.25 * (level);
                }
                if (level != 0 || !train) { //if not level0
                    //Calculate the SIFT features of the block
                    //f.SIFT_Feat(partitions[b], desc[b]);
                    //Calculate the SURF features of the block
                    features.extractFeatures(partitions[b], desc[b], FeatureType);
                    //Get the Histogram of the blockdescriptor
                    pyramid.BOW(desc[b], centers, histogram);
                } else { //if level0 (the whole image) of the training set
                    pyramid.BOW(descriptor[imgI], centers, histogram);
                }
                for (int subI = 0; subI < histogram.cols; subI++) {
                    //Save the Histogram of the block with weight (1/4 * #level)
                    rowVec[count] = (histogram.at<int>(0, subI)) * mul;
                    count++;
                }
            }
        }
        //Save the final descriptor of the image "ImgI" in "dataSet" Matrix
        dataSet.push_back(Mat(1, rowSize, CV_32F, rowVec));
        count = 0;
    }
}