
//Initiating portions of the code: Make sure Camera_Capture is commented in order to have it run of webcam
//#define Camera_Capture
#define Display_Results
//#define Template_Process;

//#include "opencv2/core/core.hpp"
#ifdef Display_Results
//#include "opencv2/highgui/highgui.hpp"
#endif
//#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdint.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include "hwlib.h"
#include "socal/socal.h"
#include "socal/hps.h"
#include "socal/alt_gpio.h"
#include "hps_0.h"

#define HW_REGS_BASE ( ALT_STM_OFST )
#define HW_REGS_SPAN ( 0x04000000 )
#define HW_REGS_MASK ( HW_REGS_SPAN - 1 )

using namespace cv;
using namespace std;


//Function prototypes
void addressFinderOut(uint32_t value);
int addressFinderIn();
int Angelas_magic(int x_of_circle, int y_of_circle, int w_of_image, int h_of_image);

//Definitions
vector<vector<Point> > contours;
vector<Vec4i> hierarchy;
vector<Vec3f> vecCircles;
vector<Vec3f>::iterator itrCircles;
vector<vector<Point> > contours_2;
vector<Vec4i> hierarchy_2;
vector<Vec3f> vecCircles_2;
vector<Vec3f>::iterator itrCircles_2;
//time_t start_time;
//time_t now;

Mat drawingFinal;
Mat temp;
int top_x, top_y, bottom_x, bottom_y;
Mat drawing;
Scalar color;
Mat Copy;
int count_BLAH;
int top_x_2, top_y_2, bottom_x_2, bottom_y_2, middle_x, middle_y;
int num_templates=10;
int height, width;
Size s;

//Non-volatile Variables for Flight Controller
int ctr_width; // horizontal position of center of cross (from circle)
int ctr_height; // vertical position of center of cross (from circle)
int w; // width of entire image
int h; // height of entire image
// may not want to include w_i and h_i, the width and height of the cross in pixels
// these are guesses
int w_i = 64;
int h_i = 35;
//int distance; // determined by LIDAR or size of cross
int output;
int i = 0;
int switchValue;
time_t start_time, now;
bool centeredL = false;
bool centeredH = false;
uint32_t value;
uint32_t value_out; 

Mat MatchingMethod(Mat Source)
{
	/// Source image to display
	Mat img_display,result;
	Source.copyTo(img_display);
	int i;
	/// Create the result matrix
	char buffer[400];
	double minVal_Final = 0; double maxVal_Final = 0; Point minLoc_Final; Point maxLoc_Final; Point matchLoc; int rows; int columns;
	cvtColor(Source, Source, CV_BGR2GRAY);
	for (i = 1; i < num_templates + 1; i++){
		Mat Template;
		sprintf(buffer, "C:/Users/Lindsey/Documents/Visual Studio 2013/Projects/OpenCVHoughCode_Final/Templates/t%d.png", i);
		Template = imread(buffer);
		cvtColor(Template, Template, CV_BGR2GRAY);
		int result_cols = Source.cols - Template.cols + 1;
		int result_rows = Source.rows - Template.rows + 1;

		result.create(result_rows, result_cols, CV_32FC1);

		/// Do the Matching and Normalize
		matchTemplate(Source, Template, result, CV_TM_CCOEFF);
		normalize(result, result, 0, 1, NORM_MINMAX, -1, Mat());

		//namedWindow("Template", WINDOW_AUTOSIZE);
		/// Localizing the best match with minMaxLoc
		double minVal; double maxVal; Point minLoc; Point maxLoc;
		Point matchLoc;
		minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, Mat());
		//imshow("Template", result);
		//waitKey(0);
		if (maxVal > maxVal_Final)
		{
			maxVal_Final = maxVal;
			minVal_Final = minVal;
			minLoc_Final = minLoc;
			maxLoc_Final = maxLoc;
			rows = Template.rows;
			columns = Template.cols;

		}

	}

	int match_method = 4;
		/// For SQDIFF and SQDIFF_NORMED, the best matches are lower values. For all the other methods, the higher the better
	if (match_method == CV_TM_SQDIFF || match_method == CV_TM_SQDIFF_NORMED)
	{
		matchLoc = minLoc_Final;
	}
	else
	{
		matchLoc = maxLoc_Final;
	}
		
	rectangle(img_display, matchLoc, Point(matchLoc.x + columns, matchLoc.y + rows), Scalar::all(0), 2, 8, 0);
	rectangle(result, matchLoc, Point(matchLoc.x + columns, matchLoc.y + rows), Scalar::all(0), 2, 8, 0);
	
	/// Show me what you got
	
	
	return result;
}

int main()
{

	Mat image_input,grey_image,color_image, hsv_image, color_threshed;
	//bool Success;

	//count = 0; 
#ifdef Camera_Capture 
	VideoCapture cap(0);
#else
	

	//VideoCapture cap(0);
	//VideoWriter out;
	//out.open("C:/Users/Lindsey/Documents/Visual Studio 2013/Projects/OpenCVHoughCode_Final/IMG_0450_out.mov", CV_FOURCC('D', 'I', 'V', 'X'), 120, cv::Size(1200, 1600), true);
#endif

#ifdef Display_Results
	//namedWindow("Transformed", WINDOW_AUTOSIZE);
	//namedWindow("Original", WINDOW_AUTOSIZE);
#else 
#endif
	std::ostringstream name;
	count_BLAH = 0;
	//Infinite loop video/camera input
	

		std::cout<<"Copy Count at: " << count_BLAH << "\n";
		count_BLAH = count_BLAH + 1;
		
		name << "/root/ntfs/" << count_BLAH << ".jpg";
		std::cout<<"File Name: " << name.str() << "\n";
		//Error Check Successfull camera READ 
		image_input = imread("/root/ntfs/Camera_Cap_Final.jpg");
		//imwrite(name.str(), image_input);

		//Convert to grayscale
		cvtColor(image_input, grey_image, CV_BGR2GRAY);
		
		//Threshold image BINARY
		threshold(grey_image, grey_image, 100, 255, THRESH_BINARY);
		//imshow("Transformed", grey_image);
		//Threshold image ORANGE_Color (run on original image)
		inRange(image_input, Scalar(0,100,240), Scalar(253,255,255), color_threshed);
		//imshow("Original", color_threshed);
		cvtColor(grey_image, color_image, CV_GRAY2BGR);

		//Isolate orange colors byy finding contours then encapsulating in Boxes (Boxes are filled with white to generate region with orange)

		findContours(color_threshed, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));

		vector<vector<Point> > contours_poly(contours.size());
		vector<Rect> boundRect(contours.size());
		vector<Point2f>center(contours.size());
		vector<float> radius(contours.size());

		for (int i = 0; i < contours.size(); i++)
		{
			approxPolyDP(Mat(contours[i]), contours_poly[i], 3, true);
			boundRect[i] = boundingRect(Mat(contours_poly[i]));
		}


		
		grey_image.copyTo(drawing);
		threshold(drawing, drawing, 256, 256, THRESH_BINARY);

		for (int i = 0; i< contours.size(); i++)
		{
			Scalar color = Scalar(255, 255, 255);
			drawContours(drawing, contours_poly, i, color, 1, 8, vector<Vec4i>(), 0, Point());
			top_x = boundRect[i].tl().x;
			top_y = boundRect[i].tl().y;
			bottom_x = boundRect[i].br().x;
			bottom_y = boundRect[i].br().y;
			rectangle(drawing, Point(top_x - 3, top_y - 3), Point(bottom_x + 3, bottom_y + 3) , color, CV_FILLED, 8, 0);
			
		}
		
		
		//Combine the black and white and orange region image to find region with cross
		
		bitwise_not(grey_image, grey_image);
		//imshow("Original", grey_image);
		bitwise_and(drawing, grey_image, drawingFinal);

		//imwrite("C:/Users/Lindsey/Documents/Visual Studio 2013/Projects/OpenCVHoughCode_Final/Final_Image.png", drawingFinal);
		//Eliminate noise within the image NEED TO ADD CENTER PROTOCOL 
		erode(drawingFinal, drawingFinal, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		//dilate(drawingFinal, drawingFinal, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		dilate(drawingFinal, drawingFinal, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

		//Isolate white regions in the resulting image and find the largest white region to find cross

		drawingFinal = color_threshed;
		
		drawingFinal.copyTo(Copy);
		cvtColor(drawingFinal,drawingFinal, CV_GRAY2BGR);
		//Canny(Copy, Copy, 60, 60);
		findContours(Copy, contours_2, hierarchy_2, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));

		vector<vector<Point> > contours_poly_2(contours_2.size());
		vector<Rect> boundRect_2(contours_2.size());
		vector<Point2f>center_2(contours_2.size());
		vector<float>radius_2(contours_2.size());

		for (int i = 0; i < contours_2.size(); i++)
		{
			approxPolyDP(Mat(contours_2[i]), contours_poly_2[i], 3, true);
			boundRect_2[i] = boundingRect(Mat(contours_poly_2[i]));
		}

		int max_size = 0;
		int box_size = 0;
		int center_x=0, center_y=0;
		//std::cout << "RRRG" << contours_2.size() << "\n";

		//count = 0;
		for (int i = 0; i< contours_2.size(); i++)
		{
			color = Scalar(80, 0, 80);
			//drawContours(drawingFinal, contours_poly_2, i, color, 1, 8, vector<Vec4i>(), 0, Point());
			top_x_2 = boundRect_2[i].tl().x;
			top_y_2 = boundRect_2[i].tl().y;
			bottom_x_2 = boundRect_2[i].br().x;
			bottom_y_2 = boundRect_2[i].br().y;
			box_size = abs(bottom_x_2 - top_x_2)*abs(top_y_2 - bottom_y_2);
			middle_x = (top_x_2 + bottom_x_2) / 2;
			middle_y = (top_y_2 + bottom_y_2) / 2;
			if (box_size > max_size)
			{
				max_size = box_size;
				center_x = middle_x;
				center_y = middle_y;
				
			}
			else
			{
				//Needs to be done -- Take average of blobs
			}
			
		}

		
		circle(drawingFinal, Point(center_x, center_y), 32, Scalar(0, 255, 0), 1, 8);
		std::cout << "Image X coordinate: " << center_x << " " << "Image Y coordinate: " << center_y << "\n";
		
		//s = drawingFinal.size();
		//height = s.height();
		//width = s.width();
		
		height = drawingFinal.size.p[0];
		width = drawingFinal.size.p[1];
		std::cout << "Image Heigth: " << height << "Image Width: " << width <<"\n";
		Angelas_magic(center_x, center_y, width, height);
		
		
#ifdef Display_Results
		//imshow("Transformed", drawingFinal);
		//waitKey(1);
		//imshow("Original", image_input);
		//out.write(drawingFinal);
		//cvWaitKey(1);
#endif

#ifdef Camera_Capture 
		waitKey(1);
#else
		//waitKey(0);
#endif
		if (contours_2.size() == 0){
			std::cout << "Error: Couldn't find cross!!" << "\n";
			//COULDNT FIND CROSS!!!
		}
		//imwrite("C:/Users/Lindsey/Documents/Visual Studio 2013/Projects/OpenCVHoughCode_Final/HSV_Out.png", image_input);

#ifdef Template_Process
		Mat results;
		results = MatchingMethod(image_input);
#ifdef Display_Results
		//namedWindow("Template", WINDOW_AUTOSIZE);
		//imshow("Template", results);
#endif
#endif

		
#ifdef Camera_Capture
#else
		/*char k;
		k = cvWaitKey(0);
		if (k == 'q')
		{
			//out.release();
			break;
		}*/
#endif

		//garbage Keeping 
		contours_poly.clear();
		boundRect.clear();
		center.clear();
		radius.clear();

		contours_poly_2.clear();
		boundRect_2.clear();
		center.clear();
		radius.clear();


	
	return(0);
}



int Angelas_magic(int x_of_circle, int y_of_circle, int w_of_image, int h_of_image)
{
	//These are in case the UAV goes off course after centering
	centeredL = false;
	centeredH = false;
	bool stop = false;
	//Top left of image is 0,0 by OpenCV Convention
	/* --- BEGIN ACTION LEFT/RIGHT --- */
	 
	ctr_width = x_of_circle;  
	ctr_height = y_of_circle; 
	w = w_of_image; 
	h = h_of_image;
	

	//BEGINNING DISTANCE CHECK
	//DO NOT MOVE AT ALL IF THERE IS ANYTHING WITH 00 SENSOR READING
	switchValue = addressFinderIn();
	std::cout<<"Switch Value: " << switchValue << "\n" ; 
	if(switchValue == 0) //sensors give 00 response if really close
	{
		//std::cout<<"Close to Object: Avoidance signal input" << "\n";
		value = 7;
		addressFinderOut(value);
		stop = true;
	}

	if(stop != true)
	{
		if (ctr_width < (w/2 - w_i/2)) //Cross: Left - Move: Left
		{
			//output = 100;
			value = 4; 
			addressFinderOut(value); //*(led) = 4;
			start_time = time(NULL);
			now = time(NULL);
			while ((difftime(now, start_time)) < 2)
			{
				now = time(NULL);
			}
			//output = 000;
			addressFinderOut(0); //*(led) = 0;
			//ctr_width += 5;
		}
		
		else if (ctr_width > (w/2 + w_i/2)) //Cross: Right - Move: Right
		{
			//output = 101;
			value = 5;
			addressFinderOut(value); //*(led) = 5;
			start_time = time(NULL);
			now = time(NULL);
			while ((difftime(now, start_time)) < 2)
			{
				now = time(NULL);
			}
			//output = 000;
			addressFinderOut(0); //*(led) = 0;
			//ctr_width -= 5;
		}

		else
		{
			std::cout<<"Centered on Plain" << "\n";
			centeredL = true;
		}
		/* --- END OF ACTION LEFT/RIGHT --- */
		/* --- BEGIN ACTION UP/DOWN --- */

		if (ctr_height > (h / 2 + h_i / 2)) //Cross: Down - Move: Down
		{
			//output = 011;
			value = 3;
			addressFinderOut(value); //*(led) = 3;
			start_time = time(NULL);
			now = time(NULL);
			while ((difftime(now, start_time)) < 2)
			{
				now = time(NULL);
			}
			//output = 000;
			addressFinderOut(0); //*(led) = 0;
			//ctr_height += 5;
		}
		
		else if (ctr_height < (h / 2 - h_i / 2)) // Cross: Up - Move: UP
		{
			//output = 010;
			value = 2; 
			addressFinderOut(value); //*(led) = 2;
			start_time = time(NULL);
			now = time(NULL);
			while ((difftime(now, start_time)) < 2)
			{
				now = time(NULL);
			}
			//output = 000;
			addressFinderOut(0); //*(led) = 0;
			//ctr_height -= 5;
		}
		else
		{
			std::cout<<"Centered on Height"<<"\n";
			centeredH = true;
		}
		/* --- END OF ACTION UP/DOWN --- */
		/* --- BEGIN ACTION FORWARD --- */

		//std::cout<<"Current Center Status Left: " << centeredL << "\n";
		//std::cout<<"Current Center Status Height: " << centeredH << "\n";

		if(centeredL && centeredH)
		{
			//switchValue = addressFinderIn();
			switchValue = 3;
			if (switchValue == 3) //Cross: Ahead - Move: Ahead
			{
				//output = 001;
				value = 1; 
				addressFinderOut(value); //*(led) = 1;
				start_time = time(NULL);
				now = time(NULL);
				while ((difftime(now, start_time)) < 2)
				{
					now = time(NULL);
				}
				//output = 000;
				addressFinderOut(0); //*(led) = 0;
			}
			
			else if (switchValue == 2) //Cross: Ahead - Move: Ahead
			{
				//output = 001;
				value = 1;
				addressFinderOut(value); //*(led) = 1;
				start_time = time(NULL);
				now = time(NULL);
				while ((difftime(now, start_time)) < 2)
				{
					now = time(NULL);
				}
				//output = 000;
				value = 0;
				addressFinderOut(value); //*(led) = 0;
			}

			else if (switchValue == 1) //Cross: Ahead - Move: Ahead
			{
				//output = 001;
				value = 1; 
				addressFinderOut(value); //*(led) = 1;
				start_time = time(NULL);
				now = time(NULL);
				while ((difftime(now, start_time)) < 2)
				{
					now = time(NULL);
				}
				//output = 000;
				value = 0; 
				addressFinderOut(value); //*(led) = 0;
			}
			
			/* --- END ACTION FORWARD --- */

			else //AVOID, switch value = 0
			{
				//output = 111;
				std::cout<<"Avoidance activated"<<"\n";
				value = 7; 
				addressFinderOut(value); //*(led) = 7;
				start_time = time(NULL);
				now = time(NULL);
				while ((difftime(now, start_time)) < 2)
				{
					now = time(NULL);
				}
			}

		return (0);

		}
	return(0);
	}
}

/*HoughLines(grey_image, Hough_Output, 1, CV_PI / 180, 50, 0, 0);

std::cout << Hough_Output.size() << '\n';


//int i = 1;

for (size_t i = 0; i < Hough_Output.size(); i++)
{
//std::cout << "hi";
float rho = Hough_Output[i][0];
float theta = Hough_Output[i][1];

Point pt1, pt2;
double a = cos(theta);
double b = sin(theta);

double x0 = a*rho;
double y0 = b*rho;

pt1.x = cvRound(x0 + 1000 * (-b));
pt1.y = cvRound(y0 + 1000 * (a));
pt2.x = cvRound(x0 - 1000 * (-b));
pt2.y = cvRound(y0 - 1000 * (a));
line(color_image, pt1, pt2, Scalar(0, 0, 255), 3, CV_AA);
}*/

//namedWindow("HELLO", WINDOW_AUTOSIZE);
//imwrite("C:/Users/Lindsey/Documents/Visual Studio 2013/Projects/OpenCVHoughCode_Final/light_output.png", color_image);
//imshow("HELLO", color_image);


void addressFinderOut(uint32_t value) { //value is in decimal

	void *virtual_base;
	int fd;
	void *h2p_lw_led_addr;

	// map the address space for the LED registers into user space so we can interact with them.
	// we'll actually map in the entire CSR span of the HPS since we want to access various registers within that span

	if( ( fd = open( "/dev/mem", ( O_RDWR | O_SYNC ) ) ) == -1 ) {
		printf( "ERROR: could not open \"/dev/mem\"...\n" );
	}

	virtual_base = mmap( NULL, HW_REGS_SPAN, ( PROT_READ | PROT_WRITE ), MAP_SHARED, fd, HW_REGS_BASE );

	if( virtual_base == MAP_FAILED ) {
		printf( "ERROR: mmap() failed...\n" );
		close( fd );
	}
	
	h2p_lw_led_addr=virtual_base + ( ( unsigned long  )( ALT_LWFPGASLVS_OFST + FPGA_LED_BASE ) & ( unsigned long)( HW_REGS_MASK ) );

	//Write to output 3-bits
	*(uint32_t*)h2p_lw_led_addr = value;

	// clean up our memory mapping and exit
	
	if(munmap(virtual_base, HW_REGS_SPAN ) != 0) {
		//printf("ERROR: munmap() failed...\n");
		close(fd);
	}

	close(fd);
}

int addressFinderIn() {

	void *virtual_base;
	int fd;
	void *h2p_lw_led_addr;
	uint32_t value;

	// map the address space for the LED registers into user space so we can interact with them.
	// we'll actually map in the entire CSR span of the HPS since we want to access various registers within that span

	if( ( fd = open( "/dev/mem", ( O_RDWR | O_SYNC ) ) ) == -1 ) {
		printf( "ERROR: could not open \"/dev/mem\"...\n" );
		return( 1 );
	}

	virtual_base = mmap( NULL, HW_REGS_SPAN, ( PROT_READ | PROT_WRITE ), MAP_SHARED, fd, HW_REGS_BASE );

	if( virtual_base == MAP_FAILED ) {
		printf( "ERROR: mmap() failed...\n" );
		close( fd );
		return( 1 );
	}
	
	h2p_lw_led_addr=virtual_base + ( ( unsigned long  )( ALT_LWFPGASLVS_OFST + FPGA_SENSOR_BASE ) & ( unsigned long)( HW_REGS_MASK ) );
	//FPGA_SENSOR_BASE

	//Read 2-bits in
	value = *(uint32_t*)h2p_lw_led_addr;
	if( (value==4)||(value==8)||(value==12)){
		value = 0;
	}
	//value = value - 12; 

	// clean up our memory mapping and exit
	
	if( munmap(virtual_base, HW_REGS_SPAN) != 0) {
		printf("ERROR: munmap() failed...\n");
		close(fd);
		return(1);
	}

	close(fd);

	return(value);
}
