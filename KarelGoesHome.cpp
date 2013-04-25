/*
 * File: KarelGoesHome.cpp
 * ----------------------
 * Section: SCPD, Aaron Broder <abroder@stanford.edu>
 * Copyright 2013 Eric Beach <ebeach@google.com>
 * Assignment 3 - Pt. 0A - Karl Goes Home
 *
 */

#include <iostream>
#include "console.h"
using namespace std;

/* Given a street number and avenue number, which are 1-indexed,
 *   returns the number of paths Karel can take back home that only
 *   moves left or down.
 */
int numPathsHome(int street, int avenue);

/*
 * Run unit tests.
 */
void runTests();

int main() {
    runTests();
    return 0;
}

/*
 * Determine if two integers are equal.
 */
bool assertEqual(int expected, int actual) {
    if (expected == actual) {
        return true;
    } else {
        cout << "Expected: " << expected << "; Actual: " << actual;
        return false;
    }
}

/*
 * Determine the number of paths home from the current location.
 */
int calcNumPathsHome(int street, int avenue) {
    int numPaths = 0;
    if (street <= 0 || avenue <= 0) {
        // Attempting to calculate path from an invalid location.
        //   no paths must exist
        return 0;
    } else if (street == 1 && avenue == 1) {
        // Karl is home; no paths available
        return 1;
    } else {
        // Karl is not home; determine how many paths back from current location
        for (int i = 0; i < 2; i++) {
            return calcNumPathsHome(street - 1, avenue) +
            calcNumPathsHome(street, avenue - 1);
        }
    }
    return numPaths;
}

/*
 * Calculate the number of paths home from a given street and avenue.
 */
int numPathsHome(int street, int avenue) {
    if (street == 1 && avenue == 1) {
        // account for special case that you are already at home
        return 0;
    } else {
        return calcNumPathsHome(street, avenue);
    }
}

/*
 * Run unit tests.
 */
void runTests() {
    assertEqual(2, numPathsHome(2, 2));
    assertEqual(0, numPathsHome(1, 1));
    assertEqual(3, numPathsHome(2, 3));
    assertEqual(3, numPathsHome(3, 2));
    assertEqual(5, numPathsHome(3, 3));
}