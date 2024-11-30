import os
import time
import cv2

img1 = cv2.imread(r'/home/tunaspb/vscode/cpp3sem/build/out/f1.ppm')
height, width, layers = img1.shape

path = '/home/tunaspb/vscode/cpp3sem/build/out/'
path_vid = '/home/tunaspb/vscode/cpp3sem/build/vid/'

cc4 = cv2.VideoWriter_fourcc(*'mp4v')
video = cv2.VideoWriter(filename=path_vid+time.asctime(time.localtime())+'.mp4', fourcc=cc4, frameSize=(width, height),
                        fps=30)


filenames = []
for i in range(1, 1+len(os.listdir(path))):
    filenames.append('f' + str(i) + '.ppm')
for filename in filenames:
    img = cv2.imread(path+filename)
    video.write(img)

cv2.destroyAllWindows()
video.release()