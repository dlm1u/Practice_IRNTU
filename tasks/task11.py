import cv2
import numpy as np

# Загружаем изображение
image = cv2.imread("C:/Users/vikusik/Desktop/proga/praktika.cpp/test_2.jpg")

# Размытие для снижения шумов
blurred = cv2.GaussianBlur(image, (11, 11), 0)

# Перевод в HSV
hsv = cv2.cvtColor(blurred, cv2.COLOR_BGR2HSV)

# Зелёный цвет
green_min = np.array((36, 25, 25), np.uint8)
green_max = np.array((70, 255, 255), np.uint8)
green_mask = cv2.inRange(hsv, green_min, green_max)

# Поиск контуров зелёных объектов с иерархией
green_contours, green_hierarchy = cv2.findContours(green_mask.copy(), cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

# Обрабатываем только внешние контуры (Parent == -1)
for i, contour in enumerate(green_contours):
    # Проверяем иерархию
    if green_hierarchy[0][i][3] == -1:  # Parent == -1 значит внешний контур
        x, y, w, h = cv2.boundingRect(contour)
        center = (int(x + w/2), int(y + h/2))

        cv2.circle(image, center, 7, (0, 0, 255), 2)
        cv2.drawContours(image, [contour], -1, (255, 0, 0), 4)
        #cv2.rectangle(image, (x, y), (x + w, y + h), (255, 0, 0), 2)

# Жёлтый цвет
yellow_min = np.array((20, 100, 100), np.uint8)
yellow_max = np.array((36, 255, 255), np.uint8)
yellow_mask = cv2.inRange(hsv, yellow_min, yellow_max)

# Поиск контуров жёлтых объектов с иерархией
yellow_contours, yellow_hierarchy = cv2.findContours(yellow_mask.copy(), cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

# Обрабатываем только внешние контуры
for i, contour in enumerate(yellow_contours):
    if yellow_hierarchy[0][i][3] == -1:  # внешний контур
        x, y, w, h = cv2.boundingRect(contour)
        center = (int(x + w/2), int(y + h/2))

        cv2.circle(image, center, 7, (0, 0, 255), 2)
        cv2.drawContours(image, [contour], -1, (0, 255, 0), 4)
        #cv2.rectangle(image, (x, y), (x + w, y + h), (0, 255, 0), 2)

# Показ результата
cv2.imshow("result", image)
cv2.waitKey(0)
cv2.destroyAllWindows()
