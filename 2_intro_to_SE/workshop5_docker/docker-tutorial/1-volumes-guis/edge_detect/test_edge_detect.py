#!/usr/bin/python3
from webcam_edge_detect import edge_detect

def test_frame_sum():
    frame_sum = edge_detect(filename="./2022-12-05-111733.mp4", no_gui=True)
    assert frame_sum == 1082291145.0