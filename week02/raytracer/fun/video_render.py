import os

import cv2

img1 = cv2.imread(r'C:/Users/stg05/CLionProjects/labs3sem/week02/raytracer/cmake-build-release/out/f1.ppm')
height, width, layers = img1.shape

video = cv2.VideoWriter(filename='video.mp4', fourcc=-1, frameSize=(width, height),
                        fps=30)

path = '../cmake-build-release/out/'
filenames = []
for i in range(1, 1+len(os.listdir(path))):
    filenames.append('f' + str(i) + '.ppm')
for filename in filenames:
    img = cv2.imread(path+filename)
    video.write(img)

cv2.destroyAllWindows()
video.release()