import face_recognition
# Load a sample picture and learn how to recognize it.
image = face_recognition.load_image_file("your_image.jpg")
face_locations = face_recognition.face_locations(image)
print(f"I found {len(face_locations)} face(s) in this photograph.")    