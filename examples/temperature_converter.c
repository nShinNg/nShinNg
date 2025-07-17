#include <stdio.h>

// Function prototypes
double celsiusToFahrenheit(double celsius);
double fahrenheitToCelsius(double fahrenheit);
double celsiusToKelvin(double celsius);
double kelvinToCelsius(double kelvin);

int main() {
    int choice;
    double temperature, result;
    
    printf("Temperature Converter\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);
    
    printf("Enter temperature: ");
    scanf("%lf", &temperature);
    
    switch(choice) {
        case 1:
            result = celsiusToFahrenheit(temperature);
            printf("%.2lf°C = %.2lf°F\n", temperature, result);
            break;
        case 2:
            result = fahrenheitToCelsius(temperature);
            printf("%.2lf°F = %.2lf°C\n", temperature, result);
            break;
        case 3:
            result = celsiusToKelvin(temperature);
            printf("%.2lf°C = %.2lf K\n", temperature, result);
            break;
        case 4:
            result = kelvinToCelsius(temperature);
            printf("%.2lf K = %.2lf°C\n", temperature, result);
            break;
        default:
            printf("Invalid choice!\n");
    }
    
    return 0;
}

// Function definitions
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0/5.0) + 32;
}

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5.0/9.0;
}

double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

double kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}