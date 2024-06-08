#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

double calculateDistance(int fromX,int fromY, int toX, int toY){
    double xDistance = toX - fromX;
    double yDistance = toY - fromY;
    double xDistanceSquared = xDistance * xDistance;
    double yDistanceSquared = yDistance * yDistance;
    double xPlusY = xDistanceSquared + yDistanceSquared;
    double squareRoot = 0.5;
    double distance = pow(xPlusY, squareRoot);
    return distance;
}

double calculateTotalDistanceGPS(int allX[], int allY[], int allTime[], int interval, int totalSeconds, int totalWalks) {
    int *totalX = new int[totalSeconds+1];
    int *totalY = new int[totalSeconds+1];

    int secondsCounter = 0;
    for (int i = 0; i < totalWalks; i++)
    {
        if (i == 0)
        {
			totalX[secondsCounter] = allX[i];
			totalY[secondsCounter] = allY[i];
			secondsCounter++;
		}
        else
        {
            double xsteps = (allX[i] - allX[i - 1]) / (allTime[i] - allTime[i-1]);
            double ysteps = (allY[i] - allY[i - 1]) / (allTime[i] - allTime[i - 1]);
			int time = allTime[i] - allTime[i - 1];
            for (int j = 0; j < (allTime[i] - allTime[i - 1]); j++)
            {
				totalX[secondsCounter] = totalX[secondsCounter - 1] + xsteps;
				totalY[secondsCounter] = totalY[secondsCounter - 1] + ysteps;
				secondsCounter++;
			}
		}
	
    }
    totalX[totalSeconds] = allX[totalWalks - 1];
    totalY[totalSeconds] = allY[totalWalks - 1];
    //for (int i = 0; i < totalWalks; i++)
    //{
    //    cout << allX[i] << " " << allY[i] << endl;
    //    cout << allTime[i] << endl;
    //}
    //cout << endl;
    //for (int i = 0; i < totalSeconds + 1; i++)
    //{
    //    cout << totalX[i] << " " << totalY[i] << endl;
    //}
    // then we calculate the total distance
    double totalDistance = 0;
    int lastInterval = 0;
    for (int i = 0; i < totalSeconds - interval; i+=interval)
    {
		totalDistance += calculateDistance(totalX[i], totalY[i], totalX[i + interval], totalY[i + interval]);
        lastInterval = i + interval;
	}
    totalDistance += calculateDistance(totalX[lastInterval], totalY[lastInterval], totalX[totalSeconds], totalY[totalSeconds]);
    return totalDistance;




}

double calculateDiffInPercent(double a, double b) {
    double difference = a - b;
    double inPercent = (difference / a) * 100;
    return inPercent;

}

int main() {
    int n;
    int t;
    cin >> n >> t;
    int x[100];
    int y[100]; 
    int time[100];
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i] >> time[i];
    }
    int counter = 0;
    double totalDistanceOG = 0;
    double totalDistanceGPS = calculateTotalDistanceGPS(x, y, time, t, time[(n-1)], n);

    for (int i = 0; i < n - 1; i++)
    {
        totalDistanceOG += calculateDistance(x[i], y[i], x[i + 1], y[i + 1]);
    }
    double diffInPercent = calculateDiffInPercent(totalDistanceOG, totalDistanceGPS);
    cout << fixed << setprecision(10) << diffInPercent;

    return 0;
}