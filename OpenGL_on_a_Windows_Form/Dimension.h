#ifndef Dimension_H
#define Dimension_H

#include "DataNode.h"
#include <vector>
#include <string>

/*
Author: Daniel Ortyn
Last Update: 2018/22/01
Purpose: CS 481 Project
*/


using namespace std;

// a class to hold and manage data with a common index for several sets
class Dimension {
public:
	// create a dimension of size 0 at index 0
	Dimension();
	// create a dimension for the pass index(index) and passed size(size)
	Dimension(int index, int size);
	// delete the object
	~Dimension();


	// copies Dimension Pointer.
	Dimension* copyDimensionToPtr(Dimension& toCopy);
	// get the index of the the dimension was created with
	int getOriginalIndex() const;
	// set the index of the the dimension, and returns the old index
	int setOriginalIndex(int newIndex);
	// calibrate the data to the [0,1] space
	void calibrateData();
	// gets the data for the set of the passed index(dataIndex)
	double getData(int dataIndex) const;
	// gets the data calibrated, but not inverted or shifted data for the set of the passed index(dataIndex)
	double getCalibratedData(int dataIndex) const;
	// gets the original data for the set of the passed index(dataIndex)
	double getOriginalData(int dataIndex) const;
	// gets the name
	string* getName();
	// sets the name and returns the old name
	void setName(string* newName);
	// sets the data of the set at the passed index(dataIndex) to the passed value(newData), alters the original data
	void setData(int dataIndex, double newData);
	// deletes the set at the passed index (dataIndex)
	void deleteData(int dataIndex);


	// multiplies all the data in the dimension by the passed double, does not alter original data
	void multiplyData(double multiplier);
	// divides all the data in the dimension by the passed double, does not alter original data
	void divideData(double divisor);
	// adds the passed double to all the data in the dimension, does not alter original data
	void addToData(double addend);
	// adds the amount passed(shiftAmount) to the data shift amount
	void shiftDataBy(double modToShiftAmount);
	// gets the amount data shift amount
	double getShift();
	// returns whether the dimension is inverted or not
	bool isInverted();
	// toggles whether the data is inverted
	void invert();


	// gets the number of sets in the dimensions
	int size() const;
	// returns whether there is artificial calibration or not
	bool isArtificiallyCalibrated();
	// sets the calibration to use the data's(not the artificial) maximum and minimum
	void clearArtificialCalibration();
	// sets the bounds to be used for artificial calibration
	void setCalibrationBounds(double newMaximum, double newMinimum);
	// gets the artificial maximum
	double getArtificialMaximum() const;
	// gets the artificial minimum
	double getArtificialMinimum() const;
	// gets the maximum data value in the dimension
	double getMaximum() const;
	// gets the minimum data value in the dimension
	double getMinimum() const;

	// gets all the data in the dimension
	vector<DataNode*> getAllData();
	// sets all the data in the dimension
	void setAllData(vector<DataNode*> toSet);
	// gets whether this dimension is drawn or not
	bool isVisible();
	// sets whether this dimension is drawn or not
	void setVisibility(bool isDrawn);

private:
	// the vector holding all the data
	vector<DataNode*> data;
	// the amount to add to data when it is retrieved
	double shiftAmount;
	// holds whether the data is inverted or not
	bool inverted;
	// holds whether the dimension is drawn or not
	bool isDrawn;
	// gets the index the dimension was originally at
	int originalIndex;
	// the boolean checking whether to use artificial calibration
	bool useArtificialCalibration;
	// the maximum to calibrate the set with
	double artificialMaximum;
	// the minimum to calibrate the set with
	double artificialMinimum;
	// the name of the dimension
	std::string name;
};

#endif