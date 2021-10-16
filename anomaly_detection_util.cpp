#include "anomaly_detection_util.h"
#include <iostream>
#include <cmath>

//this is the source file for anomaly_detection_util library
//it's the ex1 for 89210 project
// returns the variance of X and Y
//helper method to calculate the sum of variables
float sumMembers(float* x, int size) {
    float sum = 0;
    //loop through floats and sum them
    for (int i = 0; i < size; i++) {
        sum += x[i];
    }
    return sum;
}

//helper method to calculate the sum of squares
float sumSquares(float* x, int size) {
    float sum = 0;
    //loop through floats and sum the squares of them
    for (int i = 0; i < size; i++) {
        sum += pow(x[i], 2);
    }
    return sum;
}

float avg(float *x, int size) {
   float sum = sumMembers(x,size);
    return sum / (float) size;
}

// returns the variance of X and Y
float var(float* x, int size) {
    /*add check if any of floats in x are negative?
    add check for valid size: not 0 or negative etc */

    //first some calculation preparations to simplify the formula
    float sum = sumMembers(x, size);
    float squareSum = sumSquares(x, size);
    float ro = avg(x,size) ;
    //finally calculate variance using the formula
    float var = (squareSum / (float)size)  - pow(ro, 2);
    return var;
}

// returns the covariance of X and Y
float cov(float *x, float *y, int size) {
   //calculate avg to use later in the loop
    float ruX = avg(x,size);
    float ruY = avg(y,size);
    //init sum
    float sum = 0;
    //sum the product of (Xi - ruX) * (Yi - ruY) like the formula said
    for(int i =0 ;i<size; i++) {
        float deltaX = x[i] - ruX;
        float deltaY = y[i] - ruY;
        sum += (deltaX*deltaY);
    }
    //cov is the sum divided by the population size
    float cov = (sum / size);
    //return the covariance
    return cov;
}


// returns the Pearson correlation coefficient of X and Y
float pearson(float *x, float *y, int size) {
    //calculate covariance
    float covariance = cov(x,y,size);
    //calculate the deviation using variance
    float varX = var(x,size);
    float varY = var(y,size);
    float deviation = sqrtf((varX*varY));
    //calculate pearson correlation
    float correlation = covariance / deviation ;
    //return the pearson correlation
    return correlation;
}






// performs a linear regression and return s the line equation
Line linear_reg(Point **points, int size) ;

// returns the deviation between point p and the line equation of the points
float dev(Point p, Point **points, int size) ;

// returns the deviation between point p and the line
float dev(Point p, Line l) ;

int main() {
    float X[] = {2,4,6,8,10};
    float Y[] = {12,11,8,3,1};
    std :: cout  << "var X is" << var(X,5) << "\n"; //8
    std :: cout << "var Y is " << var(Y,5) << "\n"; //18.8
    std :: cout << "cov X Y is " << cov(X,Y,5) << "\n"; //-12
    std :: cout << "correlation X Y is " << pearson(X,Y,5) << "\n"; //-0.9785



}//end of the library
