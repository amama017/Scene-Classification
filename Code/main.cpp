#include "Manager.h"

int main() {
    Manager manager;
    //============== Read images ========================================  
    cout << "Reading images ........" << endl;
    manager.readImages();
    //================= Clustering Using K-Means ===============================
    cout << "Clustering dataset .........." << endl;
    manager.clustering();
    //================ Training ================================================
    cout << "Training the classifier ........." << endl;
    manager.train();
    //================ Testing =================================================
    cout << "Testing the classifier .........." << endl;
    manager.test();
}
