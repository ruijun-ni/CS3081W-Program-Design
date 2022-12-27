#!/usr/bin/python3

# Corey Knutson, 2022-12-05

import cv2
import sys
import numpy as np
from time import sleep

def edge_detect(filename=None, no_gui=None):

    edge_sum = 0

    if filename is None:
        video_capture = cv2.VideoCapture(0)
    else:
        video_capture = cv2.VideoCapture(filename)

    while True:
        ret, image = video_capture.read()

        if not ret:
            break

        # Setting parameter values
        t_lower = 50  # Lower Threshold
        t_upper = 150  # Upper threshold
        
        # Applying the Canny Edge filter
        edge = cv2.Canny(image, t_lower, t_upper)

        edge_sum += np.sum(edge)

        print("edge area: {}".format(np.sum(edge)))
        if no_gui is None:
            cv2.imshow("Edges", edge)
            if filename is not None:
                sleep(1.0/video_capture.get(cv2.CAP_PROP_FPS))

        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    video_capture.release()
    cv2.destroyAllWindows()

    print("total edge area of video: {}".format(edge_sum))
    return edge_sum

if __name__ == "__main__":
    if len(sys.argv) > 1:
        edge_detect(*(sys.argv[1:]))
    else:
        edge_detect()