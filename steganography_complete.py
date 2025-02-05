import tkinter as tk
from tkinter import filedialog, messagebox
from PIL import Image, ImageTk
import numpy as np
import os

class SteganographyTool:
    @staticmethod
    def encode_message(image_path, message, output_path):
        # Open the image
        img = Image.open(image_path)
        # Convert image to numpy array
        img_array = np.array(img)
        
        # Convert message to binary
        binary_message = ''.join(format(ord(char), '08b') for char in message)
        binary_message += '00000000'  # Add delimiter to know where message ends
        
        # Check if the image is large enough to store the message
        if len(binary_message) > img_array.shape[0] * img_array.shape[1] * 3:
            raise ValueError("Message is too large for this image")
        
        # Flatten the image array
        flat_img = img_array.flatten()
        
        # Modify the least significant bits
        for i in range(len(binary_message)):
            flat_img[i] = (flat_img[i] & ~1) | int(binary_message[i])
        
        # Reshape the array back to image dimensions
        encoded_img_array = flat_img.reshape(img_array.shape)
        
        # Create and save the new image
        encoded_img = Image.fromarray(encoded_img_array)
        encoded_img.save(output_path)
        return "Message encoded successfully"

    @staticmethod
    def decode_message(image_path):
        # Open the encoded image
        img = Image.open(image_path)
        img_array = np.array(img)
        
        # Flatten the image array
        flat_img = img_array.flatten()
        
        # Extract the LSB of each pixel value
        binary_message = ''
        for i in range(len(flat_img)):
            binary_message += str(flat_img[i] & 1)
            
            # Check for delimiter every 8 bits
            if len(binary_message) % 8 == 0:
                # Convert 8 bits to character
                char_binary = binary_message[len(binary_message)-8:]
                char = chr(int(char_binary, 2))
                
                # Check for delimiter
                if char == '\x00':
                    # Remove the delimiter and break
                    binary_message = binary_message[:-8]
                    break
        
        # Convert binary message to text
        message = ''
        for i in range(0, len(binary_message), 8):
            char_binary = binary_message[i:i+8]
            message += chr(int(char_binary, 2))
        
        return message

    @staticmethod
    def create_sample_image(width=300, height=300, output_path='sample.png'):
        # Create a simple colored image
        img = Image.new('RGB', (width, height), color='white')
        pixels = img.load()
        
        # Add some colors to make it interesting
        for x in range(width):
            for y in range(height):
                pixels[x, y] = (
                    (x % 256),  # Red
                    (y % 256),  # Green
                    ((x + y) % 256)  # Blue
                )
        
        img.save(output_path)
        return output_path

    @staticmethod
    def create_logo_image(width=500, height=500, output_path='logo.png'):
        # Create a simple logo-like image
        img = Image.new('RGB', (width, height), color='white')
        pixels = img.load()
        
        # Create a blue gradient background
        for x in range(width):
            for y in range(height):
                blue_val = int((x + y) / 4) % 256
                pixels[x, y] = (240, 240, blue_val)
        
        # Add some simple shapes to make it look like a logo
        for x in range(100, 400):
            for y in range(200, 300):
                if (x-250)**2 + (y-250)**2 < 5000:
                    pixels[x, y] = (30, 144, 255)  # Dodger blue
        
        img.save(output_path)
        return output_path

class SteganographyGUI:
    def __init__(self, root):
        self.root = root
        self.root.title("Advanced Image Steganography")
        self.root.geometry("900x700")
        
        # Variables
        self.image_path = None
        self.image_label = None
        self.steg_tool = SteganographyTool()
        
        # Create GUI elements
        self.create_widgets()
        
    def create_widgets(self):
        # Main frame
        main_frame = tk.Frame(self.root, padx=20, pady=20)
        main_frame.pack(expand=True, fill='both')
        
        # Title
        title = tk.Label(main_frame, text="Advanced Image Steganography", 
                        font=('Arial', 20, 'bold'))
        title.pack(pady=10)
        
        # Description
        desc = tk.Label(main_frame, text="Hide secret messages in images", 
                       font=('Arial', 12))
        desc.pack(pady=5)
        
        # Image frame
        self.image_frame = tk.Frame(main_frame)
        self.image_frame.pack(pady=20)
        
        # Initial image label
        self.image_label = tk.Label(self.image_frame, 
                                  text="No image selected\nSelect an image or create a new one",
                                  height=20)
        self.image_label.pack()
        
        # Buttons frame
        button_frame = tk.Frame(main_frame)
        button_frame.pack(pady=20)
        
        # Create frames for different button groups
        image_buttons = tk.LabelFrame(button_frame, text="Image Operations", padx=10, pady=5)
        image_buttons.pack(side=tk.LEFT, padx=10)
        
        message_buttons = tk.LabelFrame(button_frame, text="Message Operations", padx=10, pady=5)
        message_buttons.pack(side=tk.LEFT, padx=10)
        
        # Image operation buttons
        tk.Button(image_buttons, text="Select Image", command=self.select_image,
                 width=15).pack(pady=2)
        tk.Button(image_buttons, text="Create Sample Image", 
                 command=lambda: self.create_new_image("sample"),
                 width=15).pack(pady=2)
        tk.Button(image_buttons, text="Create Logo Image", 
                 command=lambda: self.create_new_image("logo"),
                 width=15).pack(pady=2)
        
        # Message operation buttons
        tk.Button(message_buttons, text="Hide Message", command=self.hide_message,
                 width=15).pack(pady=2)
        tk.Button(message_buttons, text="Extract Message", command=self.extract_message,
                 width=15).pack(pady=2)
        
    def select_image(self):
        file_path = filedialog.askopenfilename(
            title="Select Image",
            filetypes=[
                ("Image files", "*.png *.jpg *.jpeg *.bmp *.gif"),
                ("All files", "*.*")
            ]
        )
        
        if file_path:
            self.load_image(file_path)
    
    def load_image(self, file_path):
        try:
            self.image_path = file_path
            # Load and display the image
            image = Image.open(file_path)
            # Resize image to fit the window while maintaining aspect ratio
            display_size = (400, 400)
            image.thumbnail(display_size, Image.Resampling.LANCZOS)
            photo = ImageTk.PhotoImage(image)
            
            # Update image display
            if self.image_label:
                self.image_label.destroy()
            self.image_label = tk.Label(self.image_frame, image=photo)
            self.image_label.image = photo  # Keep a reference
            self.image_label.pack()
            
            messagebox.showinfo("Success", "Image loaded successfully!")
        except Exception as e:
            messagebox.showerror("Error", f"Failed to load image: {str(e)}")
    
    def create_new_image(self, type_="sample"):
        try:
            if type_ == "sample":
                path = self.steg_tool.create_sample_image()
            else:
                path = self.steg_tool.create_logo_image()
            
            self.load_image(path)
            messagebox.showinfo("Success", f"Created new {type_} image: {path}")
        except Exception as e:
            messagebox.showerror("Error", f"Failed to create image: {str(e)}")
    
    def hide_message(self):
        if not self.image_path:
            messagebox.showerror("Error", "Please select an image first!")
            return
            
        # Create a dialog for message input
        dialog = tk.Toplevel(self.root)
        dialog.title("Hide Message")
        dialog.geometry("500x400")
        
        # Message input
        tk.Label(dialog, text="Enter your secret message:", 
                font=('Arial', 12)).pack(pady=10)
        text_widget = tk.Text(dialog, height=10, width=50)
        text_widget.pack(pady=10, padx=20)
        
        def save_message():
            message = text_widget.get("1.0", tk.END).strip()
            if not message:
                messagebox.showerror("Error", "Please enter a message!")
                return
                
            try:
                # Get save location
                save_path = filedialog.asksaveasfilename(
                    defaultextension=".png",
                    filetypes=[("PNG files", "*.png")],
                    initialfile="encoded_image.png"
                )
                
                if save_path:
                    self.steg_tool.encode_message(self.image_path, message, save_path)
                    messagebox.showinfo("Success", 
                        f"Message hidden successfully!\nSaved as: {save_path}")
                    dialog.destroy()
                    
            except Exception as e:
                messagebox.showerror("Error", f"Failed to hide message: {str(e)}")
        
        tk.Button(dialog, text="Hide Message", command=save_message,
                 width=15).pack(pady=10)
    
    def extract_message(self):
        if not self.image_path:
            messagebox.showerror("Error", "Please select an image first!")
            return
            
        try:
            message = self.steg_tool.decode_message(self.image_path)
            
            # Show message in a new window
            dialog = tk.Toplevel(self.root)
            dialog.title("Extracted Message")
            dialog.geometry("500x400")
            
            # Message display
            tk.Label(dialog, text="Hidden message:", 
                    font=('Arial', 12)).pack(pady=10)
            text_widget = tk.Text(dialog, height=10, width=50)
            text_widget.pack(pady=10, padx=20)
            text_widget.insert("1.0", message)
            text_widget.config(state='disabled')  # Make it read-only
            
            tk.Button(dialog, text="Close", command=dialog.destroy,
                     width=15).pack(pady=10)
            
        except Exception as e:
            messagebox.showerror("Error", f"Failed to extract message: {str(e)}")

if __name__ == "__main__":
    root = tk.Tk()
    app = SteganographyGUI(root)
    root.mainloop()
