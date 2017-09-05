#include "IO.h"
#include <string.h>
#include <fstream>

IO::IO() { }

void IO::readTrainImages(Mat images[], int labels[]) {
    //Using OpenCV Random Generator
    cv::theRNG() = cv::RNG(time(0));
    //////////////////////Reading Images//////////////////////////////////////
    int imagesid[15] = {216, 241, 311, 210, 289, 360, 328, 260, 308, 374, 410, 292, 356, 215, 315}; // images count in files
    //names of files of images
    int count = 0;
    string classesname[15] = {"bedroom", "CALsuburb", "industrial", "kitchen", "livingroom", "MITcoast", "MITforest", "MIThighway",
        "MITinsidecity", "MITmountain", "MITopencountry", "MITstreet", "MITtallbuilding", "PARoffice", "store"};
    for (int i = 0; i < 15; i++) {
        std::set<int> myset;
        std::set<int>::iterator it;
        for (int j = 0; j < 100; j++) {
            bool check = true;
            int ran;
            while (check) {
                //ran = 1 + rand() % imagesid[i];
                //Using OpenCV Random Generator //Ayman
                Mat_<int> random(1, 1);
                randu(random, Scalar(1), Scalar(imagesid[i]));
                ran = random.at<int>();
                if (myset.find(ran) == myset.end()) {
                    myset.insert(ran);
                    check = false;
                }
            }
            string num;
            if (ran < 10)
                num = "00";
            else if (ran < 100)
                num = "0";
            string path = "scene_categories//";
            stringstream ss;
            ss << ran;
            string str = ss.str();
            path = path.append(classesname[i]).append("//image_0").append(num).append(str).append(".jpg");
            Mat image;
            image = imread(path, CV_LOAD_IMAGE_COLOR); // Read the file
            images[count] = image;
            labels[count] = i;
            count++;
        }
        trainimages[i] = myset;
    }
}

void IO::readTestImages(Mat images[], int labels[]) {
    //////////////////////Reading Images//////////////////////////////////////
    int imagesid[15] = {216, 241, 311, 210, 289, 360, 328, 260, 308, 374, 410, 292, 356, 215, 315}; // images count in files
    //names of files of images 
    int count = 0;
    string classesname[15] = {"bedroom", "CALsuburb", "industrial", "kitchen", "livingroom", "MITcoast", "MITforest", "MIThighway",
        "MITinsidecity", "MITmountain", "MITopencountry", "MITstreet", "MITtallbuilding", "PARoffice", "store"};
    for (int i = 0; i < 15; i++) {
        for (int j = 1; j <= imagesid[i]; j++) {
            if (trainimages[i].find(j) == trainimages[i].end()) {
                string num;
                if (j < 10)
                    num = "00";
                else if (j < 100)
                    num = "0";
                string path = "scene_categories//";
                stringstream ss;
                ss << j;
                string str = ss.str();
                path = path.append(classesname[i]).append("//image_0").append(num).append(str).append(".jpg");
                Mat image;
                image = imread(path, CV_LOAD_IMAGE_COLOR); // Read the file
                images[count] = image;
                labels[count] = i;
                count++;
            }
        }
    }
}

void IO::printToFile(Mat& centers, Mat& labels) {
    ofstream fout1("centers.out");
    ofstream fout2("labels.out");
    ofstream fout3("sizes.out");

    fout3 << centers.rows << " " << centers.cols << endl;
    fout3 << labels.rows << " " << labels.cols << endl;

    for (int i = 0; i < centers.rows; i++) {
        for (int j = 0; j < centers.cols; j++) {
            fout1 << centers.at<float>(i, j) << endl;
        }
    }

    for (int i = 0; i < labels.rows; i++) {
        for (int j = 0; j < labels.cols; j++) {
            fout2 << labels.at<int>(i, j) << endl;
        }
    }
}

void IO::readFromFile(Mat& centers, Mat& labels) {
    ifstream fin1("centers.out");
    ifstream fin2("labels.out");
    float val;
    for (int j = 0; j < 100; j++) {
        Mat temp = Mat(1, 128, CV_32F);
        for (int i = 0; i < 128; i++) {
            fin1 >> val;
            temp.at<float>(0, i) = val;
        }
        centers.push_back(temp);
    }

    int val2;
    for (int i = 0; i < 201960; i++) {
        fin2 >> val2;
        labels.push_back(val2);
    }
}

void IO::printConfustionMat(int mat[15][15], ostream& fout) {
    //Print Confusion Matrices Results
    cout << endl << endl;
    fout << endl << endl;
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            cout << mat[i][j] << " ";
            fout << mat[i][j] << " ";
        }
        cout << endl;
        fout << endl;
    }
    cout << endl << endl;
    fout << endl << endl;
}

