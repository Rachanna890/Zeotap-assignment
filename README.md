# Zeotap-assignment
Readme file:
Zeotap Intern Assignment
Assignment 1: Rule Engine with AST
Objective:
Develop a simple 3-tier rule engine application with a UI, API, and backend to determine user eligibility based on attributes like age, department, and salary. The system uses an Abstract Syntax Tree (AST) to represent rules.
Features:
•	Create rules based on user attributes.
•	Combine multiple rules into a single AST.
•	Evaluate the AST against a given set of user data.
Prerequisites:
•	C++ compiler (e.g., GCC, Clang).
•	Make sure you have C++11 or later versions.
Instructions to Run:
1.	Clone the repository:
git clone <repository-url>
cd RuleEngineAST
2.	Compile the code:
g++ -std=c++11 rule_engine.cpp -o rule_engine
3.	Run the program:
./rule_engine
4.	Explanation:
o	The code will create two rules:
	Rule 1: age > 30 AND department = 'Sales'
	Rule 2: age < 25 AND department = 'Marketing'
o	The two rules will be combined using an OR operator.
o	The program will evaluate user data (age, department) to determine eligibility.
Example Output:
User is eligible.
File Structure:
•	rule_engine.cpp: Contains the main code for creating, combining, and evaluating rules
Assignment 2: Real-Time Data Processing System for Weather Monitoring
Objective:
Develop a real-time system to monitor weather conditions using the OpenWeatherMap API, process data, and provide daily summaries and alerts.
Features:
•	Retrieve real-time weather data for specified cities (e.g., Bangalore) from the OpenWeatherMap API.
•	Convert temperatures from Kelvin to Celsius.
•	Provide daily summaries of weather (average, max, min temperature, and dominant weather condition).
•	Trigger alerts based on user-defined thresholds.
Prerequisites:
•	C++ Compiler: Make sure you have C++11 or later.
•	libcurl: For API requests.
•	jsoncpp: For parsing JSON responses.
To Install Dependencies:
1.	Install libcurl:
sudo apt-get install libcurl4-openssl-dev
2.	Install jsoncpp:
sudo apt-get install libjsoncpp-dev
Instructions to Run:
1.	Clone the repository:
git clone <repository-url>
cd WeatherMonitoring
2.	Replace API Key:
o	Go to OpenWeatherMap and sign up for a free API key.
o	Open weather_monitoring.cpp and replace your_api_key with your actual API key.
3.	Compile the code:
g++ -std=c++11 weather_monitoring.cpp -o weather_monitoring -lcurl -ljsoncpp
4.	Run the program:
./weather_monitoring
5.	Explanation:
o	The program will fetch the current weather data for Bangalore (or any specified city).
o	It will convert the temperature from Kelvin to Celsius and display the weather condition and temperature.
o	The program runs in a loop, fetching weather data every 5 minutes.
File Structure:
•	weather_monitoring.cpp: Contains the code for retrieving and processing real-time weather data.

