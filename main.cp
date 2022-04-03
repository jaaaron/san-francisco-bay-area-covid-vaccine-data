#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
double percentFunc(double population, double testingGroup);
void signature();
void getData();
int main(int argc, const char * argv[]) {
    // Headline Title
    cout << setprecision(2) << fixed;
    cout << "     County     "  << setw(23) << "Demographic" << setw(40) << "% Fully Vaccinated       " << setw(7) << "% Partially Vaccinated" << setw(25) << "   % Fully Vaccinated       " << setw(10) << "% Partially Vaccinated" << endl;
    cout << "                " << setw(23) << "           " << setw(35) << "Respect To Est Pop" << "      Respect to Est Pop" << setw(25) << "Respect To 12+ Pop" << "      Respect to 12+ Pop" <<endl;
    
    //Input Data
    getData();
    //Signature
    signature();
    
    return 0;
}
double percentFunc(double population, double testingGroup){
    /*Pre: population - Amount Of People
        testingGroup - Amount Of People With Vaccine
     Post: Calculate Percent Of Vaccinated
     Purpose: Compute Value
     */
    return (testingGroup / population) * 100;
}// percentFunc
void getData(){
    /*Pre: nothing
     Post: Gather data from file
     Purpose: Display Data
     */
    // Variables
    string county, demographic, throwAway;
    double population, estAge, vaccinated, oneDose;
    //double vaccinatedPcent, oneDosePcent;
    double fullyVacEstPop, partVacEstPop;
    double fullyVac12pop, partVac12pop;
    
    //Declare file pointer
    ofstream fileOut;
    ifstream inFile;
    
    //Open file
    fileOut.open("covidDataOutput.txt");
    inFile.open("covidVaccinationData.txt");
    if (inFile.fail()){
        cout << "Error opening file";
        exit(100);
    }
    
    // Headline Title
    fileOut << setprecision(2) << fixed;
    fileOut << "     County     "  << setw(23) << "Demographic" << setw(40) << "% Fully Vaccinated       " << setw(7) << "% Partially Vaccinated" << setw(25) << "   % Fully Vaccinated       " << setw(10) << "% Partially Vaccinated" << endl;
    fileOut << "                " << setw(23) << "           " << setw(35) << "Respect To Est Pop" << "      Respect to Est Pop" << setw(25) << "Respect To 12+ Pop" << "      Respect to 12+ Pop" <<endl;
    
    //Redirect output to this object
    while (!inFile.eof()){
        
    // Gathering Data From File - County & Demographic
    getline(inFile, county);
        if (county.substr(county.size()-1) == "\n" || county.substr(county.size()-1) == "\r") {county= county.substr(0, county.size()-1);}
    getline(inFile, demographic);
        if (demographic.substr(demographic.size()-1) == "\n" || demographic.substr(demographic.size()-1) == "\r") {demographic= demographic.substr(0, demographic.size()-1);}
        
    // Displaying County & Demographic Data
    cout << setprecision(2) << fixed;
    cout << left << setw(20) << county << setw(45) << demographic;
    
    fileOut << setprecision(2) << fixed;
    fileOut << left << setw(20) << county << setw(45) << demographic;
        
    // Displaying Partially & Fully Vaccinated Data
    inFile >> population >> estAge >> vaccinated >> oneDose;
    if (population > 0){
        
    fullyVacEstPop = (vaccinated / population) * 100;
    partVacEstPop = (oneDose / population) * 100;
    fullyVac12pop = (vaccinated / estAge) * 100;
    partVac12pop = (oneDose / estAge) * 100;
        
    cout << fixed << setprecision(1);
    cout << right << setw(6) << fullyVacEstPop << " " << setw(14) << partVacEstPop << " " << setw(24) << fullyVac12pop << " " << setw(20) << partVac12pop << endl; //testing
    fileOut << fixed << setprecision(1);
    fileOut << right << setw(6) << fullyVacEstPop << " " << setw(14) << partVacEstPop << " " << setw(24) << fullyVac12pop << " " << setw(20) << partVac12pop << endl; //testing
        } else {
    cout << right << setw(8) << " " << " " << setw(4) << " " << endl;
    fileOut << right << setw(8) << " " << " " << setw(4) << " " << endl;
        }
    getline(inFile, throwAway);
    }
    fileOut << endl;
    fileOut << "Covid Vaccinations\n";
    //Close file
    fileOut.close();
    
}
void signature(){
    cout << endl;
    cout << "Covid Vaccinations\n";
}
