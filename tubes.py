import cv2
import numpy as np


cam = cv2.VideoCapture(1) #0 default camera

while True:
	
	_, frame = cam.read() #membaca tiap frame


	hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV) #convert RGB to HSV

	
	#set range color orange
	orange_lower = np.array([5, 85, 50], np.uint8)
	orange_upper = np.array([18, 255, 255], np.uint8)
	maskOrange = cv2.inRange(hsv, orange_lower, orange_upper)

	#set apel color red
	apel_lower = np.array([160, 20, 70], np.uint8)
	apel_upper = np.array([190, 255, 255], np.uint8)
	maskApel = cv2.inRange(hsv, apel_lower, apel_upper)

	#set pisang color kuning
	pisang_lower = np.array([25, 50, 70], np.uint8)
	pisang_upper = np.array([35, 255, 255], np.uint8)
	maskPisang = cv2.inRange(hsv, pisang_lower, pisang_upper)

	kernal = np.ones((1, 1), "uint8") 

	#for orange
	orange_mask = cv2.dilate(maskOrange, kernal)
	orange = cv2.bitwise_and(frame, frame, mask = orange_mask)

	#for apel
	apel_mask = cv2.dilate(maskApel, kernal)
	apel = cv2.bitwise_and(frame, frame, mask = apel_mask)

	#for pisang
	pisang_mask = cv2.dilate(maskPisang, kernal)
	pisang = cv2.bitwise_and(frame, frame, mask = pisang_mask)


	#counter for orange
	(cnt, heirarchy) = cv2.findContours(orange_mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

	for pic, contour in enumerate(cnt): 
		area = cv2.contourArea(contour) 
		if(area > 9000): 
			x, y, w, h = cv2.boundingRect(contour) 
			frame = cv2.rectangle(frame, (x, y), 
									(x + w, y + h), 
									(0, 0, 255), 2) 
			
			cv2.putText(frame, "Jeruk", (x, y), cv2.FONT_HERSHEY_SIMPLEX, 1.0, (0, 0, 250),3)
			

	#counter for apple
	(cnt, heirarchy) = cv2.findContours(apel_mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

	for pic, contour in enumerate(cnt): 
		area = cv2.contourArea(contour) 
		if(area > 9000): 
			x, y, w, h = cv2.boundingRect(contour) 
			frame = cv2.rectangle(frame, (x, y), 
									(x + w, y + h), 
									(0, 0, 255), 2) 
			
			cv2.putText(frame, "Apel", (x, y), cv2.FONT_HERSHEY_SIMPLEX, 1.0, (0, 0, 250),3)
	

	#counter for pisang
	(cnt, heirarchy) = cv2.findContours(pisang_mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

	for pic, contour in enumerate(cnt): 
		area = cv2.contourArea(contour) 
		if(area > 9000): 
			x, y, w, h = cv2.boundingRect(contour) 
			frame = cv2.rectangle(frame, (x, y), 
									(x + w, y + h), 
									(0, 0, 255), 2) 
			
			cv2.putText(frame, "Pisang", (x, y), cv2.FONT_HERSHEY_SIMPLEX, 1.0, (0, 0, 250),3)		

	cv2.imshow('detek', frame)
	

	if cv2.waitKey(1) == ord('q'):
		break

