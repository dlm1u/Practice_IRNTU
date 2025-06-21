#include <Adafruit_NeoPixel.h>
 
// Параметры подключения и матрицы
#define LED_PIN     6      // Пин Arduino, к которому подключена лента WS2812
#define LED_COUNT   64     // Общее количество светодиодов (8x8)
#define BRIGHTNESS  100     // Яркость (0–255)
#define WIDTH       8      // Ширина матрицы
#define HEIGHT      8      // Высота матрицы
 
// Создание объекта ленты
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
 
// Функция для перевода координат (x, y) в индекс светодиода
int getPixelIndex(int x, int y) {
  // Змейка: чётные строки слева направо, нечётные — справа налево
  if (y % 2 == 0) {
    return y * WIDTH + x;
  } else {
    return y * WIDTH + (WIDTH - 1 - x);
  }
}
 
// Установка цвета пикселя по координатам x, y
void setPixelXY(int x, int y, uint32_t color) {
  // Проверка, чтобы не выйти за границы массива
  if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
    strip.setPixelColor(getPixelIndex(x, y), color);
  }
}
 
void setup() {
  strip.begin();               // Инициализация ленты
  strip.show();                // Очистка (все пиксели выключены)
  strip.setBrightness(BRIGHTNESS); // Установка яркости
}
 
void loop() {
  showHeart(3);         // Показать сердце в течение 3 секунд
  rainbowEffect(20);    // Радужный эффект
}
 
// Вывод пиксельного изображения сердца
void showHeart(unsigned long duration) {
  // 8×8 пикселей: 1 — красный пиксель, 0 — выключен
  uint8_t heart[8][8] = {
    {0,1,1,0,0,1,1,0},
    {1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1},
    {0,1,1,1,1,1,1,0},
    {0,0,1,1,1,1,0,0},
    {0,0,0,1,1,0,0,0},
    {0,0,0,0,0,0,0,0}
  };
 
  unsigned long start = millis(); // Засекаем начало
 
  // Цикл, пока не пройдёт указанное время
  while (millis() - start < duration * 1000) {
    // Проходим по каждой точке и рисуем сердце
    for (int y = 0; y < 8; y++) {
      for (int x = 0; x < 8; x++) {
        // Если в массиве 1 — включаем пиксель красным, иначе — чёрный
        setPixelXY(x, y, heart[y][x] ? strip.Color(255, 0, 0) : 0);
      }
    }
    strip.show();  // Обновляем экран
    delay(50);
  }
}
 
// Радужная волна по всей матрице
void rainbowEffect(int wait) {
  for (long firstPixelHue = 0; firstPixelHue < 5 * 65536; firstPixelHue += 256) {
    for (int i = 0; i < strip.numPixels(); i++) {
      // Смещаем цвет каждого пикселя относительно начала
      int pixelHue = firstPixelHue + (i * 65536L / strip.numPixels());
      strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue))); // Преобразуем в RGB
    }
    strip.show();
    delay(wait);
  }
}