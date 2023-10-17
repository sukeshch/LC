#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>

using namespace std;

enum class CarType {
  SEDAN = 0,
  SUV,
  ALL
  // Open to add new car types
};

ostream &operator<<(ostream &os, const CarType &carType) {
  string type = "ALL";
  if (carType == CarType::SEDAN) {
    type = "SEDAN";
  } else if (carType == CarType::SUV) {
    type = "SUV  ";
  }
  os << type;
  return os;
}

class Car {
public:
  Car(string license_plate, string brand)
      : license_plate_(license_plate), brand_(brand) {}
  virtual ~Car() {}

  virtual int getCapacity() const = 0;
  virtual CarType getType() const = 0;
  string getLicensePlate() const { return license_plate_; }
  friend ostream &operator<<(ostream &os, const Car &car);

private:
  string license_plate_;
  string brand_;
};

ostream &operator<<(ostream &os, const Car &car) {
  os << "Car - \tLicense: " << car.license_plate_
     << " \tCar Type: " << car.getType() << " \tCapacity: " << car.getCapacity()
     << endl;
  return os;
}

#define DEFAULT_CAR_CAPACITY 5
#define SEDAN_CAPACITY_SPORT 2

// Sedan - optional sport
class Sedan : public Car {
public:
  Sedan(string license_plate, string brand, bool has_sport_package)
      : Car(license_plate, brand), has_sport_package_(has_sport_package) {}

  int getCapacity() const override {
    // Assuming SPORT SEDAN has different seating capcity
    if (has_sport_package_) {
      return SEDAN_CAPACITY_SPORT;
    }
    return DEFAULT_CAR_CAPACITY;
  }

  CarType getType() const override { return CarType::SEDAN; }

private:
  bool has_sport_package_;
};

// SUV - optional 3rd row (+3)
class SUV : public Car {
public:
  SUV(string license_plate, string brand, bool has_third_row)
      : Car(license_plate, brand), has_third_row_(has_third_row) {}

  int getCapacity() const override {
    if (has_third_row_) {
      return DEFAULT_CAR_CAPACITY + 3;
    }
    return DEFAULT_CAR_CAPACITY;
  }

  CarType getType() const override { return CarType::SUV; }

private:
  bool has_third_row_;
};

class CarRental {
public:
  /*
  Optional package could be a struct to handle options
  based on type optional_package means
  Sedan -- optional_package == has_sport_package
  SUV   -- optional_package == has_third_row
  */
  void createCar(string license_plate, string brand, CarType type,
                 bool optional_package = false) {
    if (inventory_.count(license_plate)) {
      cout << "Error: License Plate already found!!" << endl;
      return;
    }
    if (type == CarType::SUV)
      inventory_[license_plate] =
          std::make_unique<SUV>(license_plate, brand, optional_package);
    else if (type == CarType::SEDAN)
      inventory_[license_plate] =
          std::make_unique<Sedan>(license_plate, brand, optional_package);
  }

  void deleteCar(string license_plate) {
    if (inventory_.count(license_plate) == 0) {
      cout << "Error deleting! License Plate not found." << endl;
      return;
    }
    inventory_.erase(license_plate);
  }

  void printCars(CarType type = CarType::ALL) {
    cout << "Printing " << type << " cars. \n";
    for (const auto &p : inventory_) {
      if (type == CarType::ALL) {
        cout << *(p.second);
      } else if (p.second->getType() == type) {
        cout << *(p.second);
      }
    }
  }

private:
  // Assuming license plate is unique
  // license -> car
  unordered_map<string, std::unique_ptr<Car>> inventory_;
};

int main() {
  CarRental carRental;
  carRental.createCar("A", "bmw", CarType::SUV, false);
  carRental.createCar("B", "bmw", CarType::SUV, true);
  carRental.createCar("C", "audi", CarType::SEDAN, false);
  carRental.createCar("D", "audi", CarType::SEDAN, true);
  carRental.printCars();
  carRental.printCars(CarType::SEDAN);
}
