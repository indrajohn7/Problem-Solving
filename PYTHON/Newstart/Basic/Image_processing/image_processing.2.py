#!/usr/bin/python

# Python program to read 
# image using matplotlib
 
# importing matplotlib modules
import matplotlib.image as mpimg
import matplotlib.pyplot as plt
 
# Read Images
img = mpimg.imread('thumb-1920-637668.jpg')
 
# Output Images
plt.imshow(img)
