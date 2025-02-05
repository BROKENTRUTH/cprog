import cv2 
import face_recognition 

# Load an image
image = face_recognition.load_image_file("your_image.jpg")

# Find all face locations
face_locations = face_recognition.face_locations(image)
print(f"Found {len(face_locations)} face(s) in this photograph.")

# Display the image with face locations
for face_location in face_locations:
    top, right, bottom, left = face_location
    cv2.rectangle(image, (left, top), (right, bottom), (0, 255, 0), 2)

# Convert the image to BGR color space
image = cv2.cvtColor(image, cv2.COLOR_RGB2BGR)

# Show the image with faces recognized
cv2.imshow("Faces Found", image)
cv2.waitKey(0)
cv2.destroyAllWindows()
