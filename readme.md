# Assignment: Mengambil Data Sensor DHT11 dan Mengirimkannya ke Server Lokal

## Deskripsi

Dalam assignment ini, kita akan membuat sebuah sistem yang terdiri dari ESP32 dan sensor DHT11 untuk mengukur suhu dan kelembaban. Data dari sensor akan dikirimkan ke server lokal melalui HTTP REST API (POST Method). Berikut adalah panduan penggunaan untuk file `.ino` dan `.py` yang diperlukan.

## Persiapan

### Hardware yang dibutuhkan

1. ESP32 Development Board
2. Sensor DHT11
3. Kabel jumper
4. Breadboard (opsional)

### Library yang dibutuhkan

1. DHT sensor library
2. WiFi library (built-in pada Arduino IDE)
3. HTTPClient library (built-in pada Arduino IDE)

## Setup Hardware

1. **Hubungkan sensor DHT11 ke ESP32:**
   - VCC ke 3.3V pada ESP32
   - GND ke GND pada ESP32
   - Data ke GPIO 19 pada ESP32

## Panduan Penggunaan

### 1. Menggunakan File `dht_sensor_to_server.ino`

1. Buka [Wokwi.com](https://wokwi.com) dan buat proyek baru untuk ESP32.
2. Masukkan kode ino yang sudah dibuat


3. Hubungkan sensor DHT11 di pin GPIO 19 sesuai dengan kode.
4. Tambahkan library DHT di Wokwi dengan mengklik tombol "Libraries" dan mencari "DHT sensor library".
5. Konfigurasi WiFi dengan SSID "Wokwi-GUEST" dan biarkan password kosong.
6. Upload dan Jalankan Kode di Wokwi untuk memulai ESP32 dan mengirim data ke server.

### 2. Menjalankan Server Lokal dengan `server.py`

1. Pastikan Python sudah terinstal di komputer Anda. Jika belum, instal Python dari [python.org](https://www.python.org/).
2. Instal Flask
4. Jalankan server
5. Pastikan server berjalan di `http://192.168.0.1:5000/sensor/data`.

## Pengujian

- Pastikan ESP32 dan komputer yang menjalankan server berada dalam jaringan yang sama.
- Setelah kode diunggah ke ESP32 dan server berjalan, data dari sensor akan dikirimkan ke server setiap 3 detik.
- Anda akan melihat data suhu dan kelembaban ditampilkan di serial monitor pada Wokwi dan juga di terminal yang menjalankan server Flask.

Dengan mengikuti panduan ini, Anda akan dapat menjalankan sistem yang mengirim data dari sensor DHT11 ke server lokal menggunakan ESP32 dan Flask.
