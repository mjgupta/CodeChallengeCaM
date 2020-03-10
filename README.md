# CodeChallengeCaM
### Code Challenge
Machine Learning Smartpens
>This project would involve adapting pathology annotation tools to prefer following edges in the base image when close. This would also involve expanding the user functions surrounding annotation, such as moving points in the drawing. Specific UI flow is up to the implementer; perhaps it's more useful to leave drawings alone, but have a button which snaps drawings to the nearest edge when pushed.

Current Status
>The current annotation tools perform point simplification after a user finishes drawing without any consideration of the base image.

Code Challenge
>Create a page or tool which performs edge detection on a given image and, given a point, returns the distance from that point to the closest edge.

*Note:* The Final Project shall be implemented using Machine Learning Models based on TensorFlow
### Approaches for a solution
#### 1. Using OpenCV
OpenCV has an excellent implementation of edge detection based on multi-stage canny edge detection, Its documentation can be found [Here](https://docs.opencv.org/2.4/doc/tutorials/imgproc/imgtrans/canny_detector/canny_detector.html) .

Canny's Edge Detection algorithm utilizes a multistep approach consisting of:
* Noise Reduction
* Intensity Gradient of the Image Matrix
* Non Maximum Supression
* Hysterisis Thresholding 

For ease, the image shall be considered GrayScale, with each pixel having intensity value 0-255.
When passed through the Canny() function, a matrix is returned which contains edge information - which in this case shall be treated as boolean 0 for non-edge pixels and 1 for pixels containing edge.

![Demonstration of the process](https://github.com/mjgupta/CodeChallengeCaM/blob/master/Annotation%202020-03-11%20020848.png)
Step by step breakdown of the process

I have utilized two approaches for finding the nearest edge for a given pixel / pointer location.
* Breadth First Search based approach
* Matrix with a predefined tolerance based approach
* Brute-forcing least distance within a predefined tolerance


![Demonstration of grayscale pixel matrix Credits: https://ai.stanford.edu/~syyeung/cvweb/Pictures1/imagematrix.png](https://ai.stanford.edu/~syyeung/cvweb/Pictures1/imagematrix.png)

Matrix containing values corresponding to each pixel's individual intensity.


![Applying Canny's Filter Credits: https://scikit-image.org/docs/dev/_images/sphx_glr_plot_canny_001.png](https://scikit-image.org/docs/dev/_images/sphx_glr_plot_canny_001.png)

Demonstration of Canny's edge detection algorithm : The output image is stored as an EdgeMatrix[][] which is passed on to function for finding the nearest edge.

Overview of C++ implementation of the matrix with speicified tolerance based nearest edge detection
* Finding if the given coordinate (x,y) lies on an edge i.e. EdgeMatrix[x][y] ==1
* Increasing the matrix size (size of the matrix remains less than the desired tolerance), with the centre element being the given coordinate, and searching the periphery of the matrix (Thus avoiding visited cells)
* For a given matrix size, storing the nearest edge point coordinates to the given point in 2 Arrays, if found.
* Returning the arrays containing required coordinates.

_Solution_ :
The above problem has been solved in the ExampleNearestEdgeSnap.cpp	file, for which the built executable file can be downloaded and run locally.
To verify the code/ solution, sample test cases can be generated from [RandomTestCaseGeneratorsite](https://test-case-generator.herokuapp.com/)
* A threshold value of maximum size of the matrix (analogous to maximum distance from the selected pixel to be searched) has been defined in the .cpp file.
* Enter the number of rows/columns in the n\*n square matrix
* Enter the matrix from the generated test cases
* Enter the coordinate from which nearest border has to be found
* The nearest points from the selected point shall change its value to 9 and the selecte point changes its value to 6


#### 2. Using Tensorflow.js
#### 3. Using self implemented techniques based on Canny edge detection
#### 4. Miscellaneous edge detection techniques

Image credits:
>https://scikit-image.org/docs/dev/auto_examples/edges/plot_canny.html https://ai.stanford.edu/~syyeung/cvweb/tutorial1.html
