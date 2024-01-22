import subprocess
import os
import io
import whatimage
import pyheif
import traceback
from PIL import Image

def decodeImage(bytesIo):
    try:
        fmt = whatimage.identify_image(bytesIo)
        # print('fmt = ', fmt)
        if fmt in ['heic']:
            i = pyheif.read_heif(bytesIo)
            pi = Image.frombytes(mode = i.mode, size = i.size, data = i.data)
            pi.save('heeh.jpg', format = "jpeg")
    except:
        traceback.print_exc()

def read_image_file_rb(file_path):
     with open(file_path, 'rb') as f:
        file_data = f.read()
        return file_data
 
 
if __name__ == "__main__":
    file_path = './test_image.HEIC'
    print('file_path = ', file_path)
 
    data = read_image_file_rb(file_path)
    # print('data = ', data)
    decodeImage(data)