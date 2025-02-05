import cv2
import face_recognition 

# Load the known images and get the encodings
known_image = face_recognition.load_image_file("known_person.jpg")
known_encoding = face_recognition.face_encodings(known_image)[0]

# Load an image to recognize
unknown_image = face_recognition.load_image_file("unknown_person.jpg")
unknown_encodings = face_recognition.face_encodings(unknown_image)

# Initialize OpenCV to draw on the image
image_to_show = cv2.cvtColor(unknown_image, cv2.COLOR_RGB2BGR)

# Loop through faces in the unknown image
for unknown_encoding in unknown_encodings:
    results = face_recognition.compare_faces([known_encoding], unknown_encoding)
    face_locations = face_recognition.face_locations(unknown_image)
    
    for (top, right, bottom, left), match in zip(face_locations, results):
        if match:
            # Draw a rectangle around recognized face
            cv2.rectangle(image_to_show, (left, top), (right, bottom), (0, 255, 0), 3)
        else:
            cv2.rectangle(image_to_show, (left, top), (right, bottom), (0, 0, 255), 3)

# Display the result
cv2.imshow("Face Recognition", image_to_show)
cv2.waitKey(0)
cv2.destroyAllWindows()
