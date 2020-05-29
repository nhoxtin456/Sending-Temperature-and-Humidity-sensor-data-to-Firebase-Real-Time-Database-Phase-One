Nhóm N9
 - 17110154  Đoàn Quốc Hùng  Team Leader,  Developer
 - 17110163  Trương Minh Khoa  Developer, Tester
 - 17150086  Tôn Thất Tấn  Developer, Reporter
 - 17110238  Pham Ngọc Tiến  Tester, Designer

Xây dựng gói thu thập dữ liệu nền dựa trên IoT ghi nhận nhiệt độ và độ ẩm theo
thời gian, sau đó đưa dữ liệu lên FireBase và lưu trữ dạng Real Time Data

# Sending-Temperature-and-Humidity-sensor-data-to-Firebase-Real-Time-Database-Phase-One
Technologies
- IoT
- C++
- Cloud computing (Firebase)(Data)

Device
- Microcontroller ESP8266 NodeMCU
- Temperature - Humidity sensor DHT11

Development environment and tools
- Arduino IDE
- JRE

Driver
- Download and Install CP210x USB to UART Bridge VCP Drivers
- Arduino Driver

Configuring Arduino IDE

 +Add board ESP8266
- Step 1: File -> Preferences -> Additional Boards Manager URLs: http://arduino.esp8266.com/stable/package_esp8266com_index.json
- Step 2: Tools -> Board -> Boards Manager -> Search and install: esp8266

 +Installing library for programming firebase API
- Sketch -> Include Library -> Add .Zip Library -> Add: Firebase ESP8266 Client
- Sketch -> Include Library -> Manage Libraries -> Search and install: ArduinoJson
