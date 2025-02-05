#include <opencv2/opencv.hpp>
#include <opencv2/face.hpp>
#include <vector>

using namespace cv;
using namespace cv::face;

int main() {
    // Load pre-trained face detector
    CascadeClassifier faceDetector("haarcascade_frontalface_default.xml");

    // Load the image
    Mat image = imread("your_image.jpg");

    // Convert to grayscale
    Mat gray;
    cvtColor(image, gray, COLOR_BGR2GRAY);

    // Detect faces
    std::vector<Rect> faces;
    faceDetector.detectMultiScale(gray, faces);

    // Initialize face recognizer
    Ptr<LBPHFaceRecognizer> recognizer = LBPHFaceRecognizer::create();
    
    // Train the recognizer (Load the dataset and fit the model)

    // For each face detected, recognize it
    for (Rect face : faces) {
        Mat faceROI = gray(face);
        int label;
        double confidence;

        recognizer->predict(faceROI, label, confidence);
        // Draw rectangle around the face and label it with confidence
    }

    // Display the result
    imshow("Face Recognition", image);
    waitKey(0);

    return 0;
}
 