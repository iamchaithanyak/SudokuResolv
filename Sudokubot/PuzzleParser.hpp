//
//  PuzzleParser.h
//  Sudokubot
//
//  Created by Haoest on 3/19/11.
//  Copyright 2011 none. All rights reserved.
//

#import <opencv2/core/core.hpp>
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "cvutil.hpp"
#import "basicOCR.hpp"

using namespace cv;
@interface PuzzleParser : NSObject {

}

+(UIImage*) BlurImage: (UIImage*) image;
+(UIImage*) FindLines: (UIImage*) image;

basicOCR* GetOCR();
void CleanUp();

void MergeAdjacentLines(vector<Vec2f>* lines);
bool CompareLineByTheta( Vec2f line1,  Vec2f line2);
bool CompareLineByRho(Vec2f line1, Vec2f line2);
void SplitIntoHorizontalAndVeriticalLines(vector<Vec2f>* allLines, vector<Vec2f>* horizontalLines, vector<Vec2f>* verticalLines);
void drawLines(Mat *mat, vector<Vec2f> *lines);
void GetRectanglesFromLines(cv::Rect dst_rectangles[], vector<Vec2f>* horizontalLines, vector<Vec2f>* verticalLines);
IplImage* ParseFromImage(UIImage* puzzleUIImage);
IplImage* FindExistingNumbers(IplImage* puzzle, cv::Rect grids[], int numbers[][9]);

IplImage* CreateSubImage(IplImage* fullImage, cv::Rect& region);
@end