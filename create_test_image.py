from PIL import Image
import numpy as np
import os

# Create a simple 300x300 colored image
width, height = 300, 300
img = Image.new('RGB', (width, height), color='white')

# Add some colors to make it interesting
pixels = img.load()
for x in range(width):
    for y in range(height):
        pixels[x, y] = (
            (x % 256),  # Red
            (y % 256),  # Green
            ((x + y) % 256)  # Blue
        )

# Save the image
output_path = 'original.png'
img.save(output_path)

# Print confirmation and file location
abs_path = os.path.abspath(output_path)
print(f"\nImage created successfully!")
print(f"Location: {abs_path}")

# Display the image
img.show()  # This will open the image in your default image viewer
