/* 
 * File:   SVM_Classifier.h
 * Author: abdo
 *
 * Created on December 25, 2012, 6:54 AM
 */

#ifndef CLASSIFIERS_H
#define	CLASSIFIERS_H

#include "includes.h"
#include "modules/ml/include/opencv2/ml/ml.hpp"

class Classifiers {
public:
    Classifiers();
    float trainSVM(CvSVM& SVM, Mat& dataSet, Mat& labels, int Confusion[15][15]);
    float predictSVM(CvSVM& SVM, Mat& dataSet, Mat& labels, int Confusion[15][15]);
};

#endif	/* SVM_CLASSIFIER_H */

