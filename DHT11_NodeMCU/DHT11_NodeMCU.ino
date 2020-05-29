// Nhóm N9
//  17110154  Đoàn Quốc Hùng  Team Leader,  Developer
//  17110163  Trương Minh Khoa  Developer, Tester
//  17150086  Tôn Thất Tấn  Developer, Reporter
//  17110238  Pham Ngọc Tiến  Tester, Designer

// Xây dựng gói thu thập dữ liệu nền dựa trên IoT ghi nhận nhiệt độ và độ ẩm theo
// thời gian, sau đó đưa dữ liệu lên FireBase và lưu trữ dạng Real Time Data

#include <ESP8266WiFi.h>                                                    // esp8266 library
#include <DHT.h>                                                            // dht11 temperature and humidity sensor library
#include <FirebaseArduino.h>                                                // firebase library

#define FIREBASE_HOST "atest-581aa.firebaseio.com"                          // the project name address from firebase id
#define FIREBASE_AUTH "1CYCCBDVR425k89MLPJ0oY32HYWJC8qFlxwTWqer"            // the secret key generated from firebase

#define WIFI_SSID "DASAN_GONT990910"                                        // input your home or public wifi name
#define WIFI_PASSWORD "1234567890a"                                         // password of wifi ssid

#define DHTPIN D4                                                           // what digital pin we're connected to 
// Chân DATA nối với chân D4

#define DHTTYPE DHT11                                                       // select dht type as DHT 11 or DHT22

// Khởi tạo cảm biến
DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  // put your setup code here, to run once:
  // Khởi tạo cổng serial baud 9600
  Serial.begin(9600);
  Serial.println("DHT11 test!");
  connectWifi();

  delay(1000);

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);                              // connect to firebase
  dht.begin();                                                               // Bắt đầu đọc dữ liệu
}

void loop()
{
  // Đợi chuyển đổi dữ liệu khoảng 2s
  delay(2000);
  // put your main code here, to run repeatedly:
  showTemperatureAndHumid();
}

void connectWifi()
{
  Serial.println("Wait wifi connect!");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                      // try to connect with wifi
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Serial.print("IP Address is : ");
  Serial.println(WiFi.localIP());                                            // print local IP address

  // In ra dia chi IP
  Serial.println(WiFi.localIP());
}

void showTemperatureAndHumid()
{
  float h = dht.readHumidity();                                              // Reading temperature or humidity takes about 250 milliseconds!
  // Đọc giá trị nhiệt độ C (mặc định)
  float t = dht.readTemperature();                                           // Read temperature as Celsius (the default)

  // Đọc giá trị nhiệt độ F(isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Kiểm tra quá trình đọc thành công hay không
  if (isnan(h) || isnan(t) || isnan(f)) {                                    // Check if any reads failed and exit early (to try again).
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // IN thông tin ra màn hình
  Serial.println("FireBaseGoogle: ");
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  String fireHumid = String(h) + String("%");                                // convert integer humidity to string humidity
  Serial.print("%  Temperature: ");
  Serial.print(t);
  Serial.println(" °C ");
  String fireTemp = String(t) + String("°C");                                // convert integer temperature to string temperature
  delay(4000);

  Firebase.pushString("/DHT11/Humidity", fireHumid);                         // setup path and send readings
  Firebase.pushString("/DHT11/Temperature", fireTemp);                       // setup path and send readings
}
