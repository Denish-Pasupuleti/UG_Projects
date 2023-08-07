#include <iostream>
#include <string>
#include "Appliance.h"
#include "Stove.h"
#include "Dishwasher.h"

int main () {
  Appliance myAppliance("Fridge","Cooling",1);
  Stove myStove("Stove","Heating",1,1);
  Dishwasher myDishwasher("Dishwasher","Cleaning",1,30);

  //Example 1: Making each item "UseAppliance"
  cout << "Example 1 - Each item calls UseAppliance" << endl;
  myAppliance.UseAppliance(); //Calls UseAppliance on an Appliance
  myStove.UseAppliance(); //Calls UseAppliance on a Stove
  myDishwasher.UseAppliance(); //Calls UseAppliance on a Dishwasher
  cout << endl;
  
  //Example 2: Putting all appliances into an Appliance array
  cout << "Example 2 - Using an Appliance Array to Display" << endl;
  Appliance myHouse [3]; //Creates an array for all Appliances (Stoves are appliances)
  myHouse[0] = myAppliance; //Puts the generic appliance in the array
  myHouse[1] = myStove; //Puts the stove in the array
  myHouse[2] = myDishwasher; //Puts the dishwasher in the array
  for(int i = 0; i < 3; i++){ //Iterates over the array
    myHouse[i].UseAppliance(); //Calls UseAppliance on each item
  }
  return 0;
}
