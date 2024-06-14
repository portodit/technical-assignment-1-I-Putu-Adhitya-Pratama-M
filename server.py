from flask import Flask, request, jsonify

app = Flask(__name__)

@app.route('/sensor/data', methods=['POST'])
def receive_sensor_data():
    data = request.json
    temperature = data.get('temperature')
    humidity = data.get('humidity')

    print(f"Received data - Temperature: {temperature}, Humidity: {humidity}")

    response = {
        "status": "success",
        "message": "Data received",
        "data": {
            "temperature": temperature,
            "humidity": humidity
        }
    }
    return jsonify(response)

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)
