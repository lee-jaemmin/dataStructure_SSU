#include <iostream>
#include "Time.cpp"

//20212861 이재민 

using namespace std;

int main() {
    int numberOfVisits = 0, totalWaitingTime = 0;
    char answer;

    do {
        bool errorFlag;
        Time arrival, seenByDoctor;

        cout << "Enter arrival time: ";
        arrival.readTime(errorFlag);
    
        while (errorFlag) {
            cout << "Arrival time was incorrectly formatted; try again: ";
            arrival.readTime(errorFlag);
        }

        cout << "Enter time seen by doctor: ";
        seenByDoctor.readTime(errorFlag);

        while (errorFlag) {
            cout << "Seen by doctor time was incorrectly formatted; try again: ";
            seenByDoctor.readTime(errorFlag);
        }

        numberOfVisits++;
        totalWaitingTime += seenByDoctor.subtractTimes(arrival);

        cout << "Done? Enter 'y' to quit, anything else to continue: ";
        cin >> answer;

    } while (answer != 'y');

    cout << "Number of visits: " << numberOfVisits << "\n";
    cout << "Total waiting time: " << totalWaitingTime << " minutes.\n";
    cout << "Average wait is " << totalWaitingTime / numberOfVisits << " minutes.\n";

    
    cout << "\nEnter the time you arrived\n";

    Time lastArrival;
    bool errorFlag;

    lastArrival.readTime(errorFlag);

    lastArrival.addTimes(lastArrival, (totalWaitingTime/numberOfVisits));

    

    return 0;
}
