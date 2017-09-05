/* 
 * File:   Manager.h
 * Author: abdo
 *
 * Created on December 25, 2012, 7:27 AM
 */

#ifndef MANAGER_H
#define	MANAGER_H

#include "includes.h"
#include "Classifiers.h"
#include "IO.h"
#include <fstream>

class Manager {
private:
    //Arrays and matrices for storing images pixels and labels
    Mat trainImages[1500];
    int trainLabels[1500];

    Mat testImages[2985];
    int testLabels[2985];
    
    //Array of descriptors for SIFT features with the size of the input images
    Mat descriptor[1500];
    
    //The centers and labels returned by the clustering algorithm
    Mat centers, labels;
    
    //Classifier for learning and predict a dataSet
    Classifiers classifier;
    
    //Create an Instance of the SVM Classifier
    CvSVM SVM;
    
    //For writing to file results.out
    IO io;
    
    //Saving results in results.out file
    ofstream fout;
public:
    Manager();
    void getDataSet(Mat& dataSet, Mat* images, int size, bool train);
    void readImages();
    void clustering();
    void train();
    void test();
    void printConfustionMat(int mat[15][15]);
};

#endif	/* MANAGER_H */

