/*
 * ObjectRecognizer.h
 *
 *  Created on: Feb 15, 2013
 *      Author: olehp
 */

#ifndef OBJECTRECOGNIZER_H_
#define OBJECTRECOGNIZER_H_

#include "HaarCascade.h"
#include <opencv2/opencv.hpp>

class ObjectRecognizer {

public:
	ObjectRecognizer();
	~ObjectRecognizer();
	void LoadHaarCascade(const char *path);
	void LoadImage(const char *path);
	void UnloadImage();
	void Recognize();
private:

	void ComputeIntegralImages();

	bool StagesPass(int x, int y, double scale, double inv, double stdDev);
	double TreesPass(Stage &stage, int x, int y, double scale, double inv, double stdDev);
	double RectsPass(Tree &tree, int x, int y, double scale);

	inline int RectSum(int *ii, int x, int y, int w, int h);
	template<typename T>
	inline T MatrVal(T *arr, int row, int col, int width) {

		return arr[row * width + col];
	}

	template<typename T>
	inline void SetMatrVal(T *arr, int row, int col, T val, int width) {
		arr[row * width + col] = val;
	}


	int pic_width;
	int pic_height;
	cv::Mat_<int> grayscaled_pic;
	const int *grayscaled_bytes;
	int *ii;
	int *ii2;

	HaarCascade haar_cascade;
};

#endif /* OBJECTRECOGNIZER_H_ */
