/* 
 * File:   IO.h
 * Author: abdo
 *
 * Created on December 25, 2012, 8:14 AM
 */

#ifndef IO_H
#define	IO_H

#include "includes.h"
#include <set>

class IO {
private:
    std::set<int> trainimages[15];
public:
    IO();
    void readTrainImages(Mat images[1500], int labels[1500]);
    void readTestImages(Mat images[2985], int labels[2985]);
    void printToFile(Mat& centers, Mat& labels);
    void readFromFile(Mat& centers, Mat& labels);
    void printConfustionMat(int mat[15][15], ostream& fout);
};

#endif	/* IO_H */

