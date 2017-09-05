#include "Classifiers.h"

Classifiers::Classifiers() { }

float Classifiers::trainSVM(CvSVM& SVM, Mat& dataSet, Mat& labels, int Confusion[15][15]) {
    // Set up SVM's parameters
    CvSVMParams params;
    params.svm_type = CvSVM::C_SVC;
    params.kernel_type = CvSVM::LINEAR;
    params.term_crit = cvTermCriteria(CV_TERMCRIT_ITER, 100, 1e-6);

    // Train the SVM
    //SVM.train(dataSet, labels, Mat(), Mat(), params);
    SVM.train_auto(dataSet, labels, Mat(), Mat(), params);

    return predictSVM(SVM, dataSet, labels, Confusion);
}

float Classifiers::predictSVM(CvSVM& SVM, Mat& dataSet, Mat& labels, int Confusion[15][15]) {
    //Initialize matrix to zeros
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            Confusion[i][j] = 0;
        }
    }
    float wrong = 0;
    //Predict the result
    for (int i = 0; i < dataSet.rows; i++) {
        float response = SVM.predict(dataSet.row(i));
        Confusion[(int) response][labels.at<int>(i, 0)] += 1;
        //Check if the prediction is correct or not
        if (response != labels.at<int>(i, 0)) {
            wrong++;
        }
    }
    //Retrun wrong percent
    return (wrong / labels.rows) * 100;
}
