import cv2
from pytesseract import pytesseract
from pytesseract import Output

pytesseract.tesseract_cmd = "C:\\Program Files\\Tesseract-OCR\\tesseract.exe"

foto = cv2.imread("nowaf.png")

foto_data = pytesseract.image_to_data(foto, output_type=Output.DICT)

for i, word in enumerate(foto_data['text']):
	if word != "":
		x, y, w, h = foto_data['left'][i], foto_data['top'][i], foto_data['width'][i], foto_data['height'][i]
		cv2.rectangle(foto, (x, y), (x+w, y+h), (0, 255, 0), 3)
		cv2.putText(foto, word, (x, y-16), cv2.FONT_HERSHEY_COMPLEX, 1, (0, 0, 255), 2)

cv2.imshow("hasil", foto)
cv2.waitKey(0)