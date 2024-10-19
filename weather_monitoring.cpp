#include <iostream>
#include <string>
#include <curl/curl.h>
#include <json/json.h>
#include <ctime>

using namespace std;

// Function to convert Kelvin to Celsius
double kelvin_to_celsius(double kelvin) {
    return kelvin - 273.15;
}

// Callback function to handle API response
size_t write_callback(void* contents, size_t size, size_t nmemb, string* buffer) {
    size_t total_size = size * nmemb;
    buffer->append((char*)contents, total_size);
    return total_size;
}

// Fetch weather data from OpenWeatherMap API
string fetch_weather_data(const string& api_url) {
    CURL* curl;
    CURLcode res;
    string response;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, api_url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }

    return response;
}

// Process and display weather data
void process_weather_data(const string& response) {
    Json::Value json_data;
    Json::Reader reader;
    reader.parse(response, json_data);

    double temp_kelvin = json_data["main"]["temp"].asDouble();
    double temp_celsius = kelvin_to_celsius(temp_kelvin);
    string weather_condition = json_data["weather"][0]["main"].asString();

    time_t dt = json_data["dt"].asInt64();
    tm* local_time = localtime(&dt);

    cout << "Temperature: " << temp_celsius << " °C" << endl;
    cout << "Weather: " << weather_condition << endl;
    cout << "Time: " << asctime(local_time) << endl;
}

int main() {
    string api_key = "your_api_key";  // Replace with your actual OpenWeatherMap API key
    string city = "Bangalore";
    string api_url = "http://api.openweathermap.org/data/2.5/weather?q=" + city + "&appid=" + api_key;

    // Fetch and process weather data every 5 minutes
    while (true) {
        string response = fetch_weather_data(api_url);
        process_weather_data(response);

        // Sleep for 5 minutes (300 seconds)
        this_thread::sleep_for(chrono::seconds(300));
    }

    return 0;
}
