#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include <time.h>
#include <stdlib.h>
#include "BMS_Sender.h"

srand(time(0));
float SimulateReadDataFromSensor(float minimumThreshold,float maximumThreshold)
{
  float data = (rand() % (int)(maximumThreshold - minimumThreshold +1)) + minimumThreshold ;
  return data;
}


float (*funp_ReadDataFromSensor)(float,float) = SimulateReadDataFromSensor;


TEST_CASE("Test 1 : Prepare Data from Sensor") {

  BatteryParameterInfo parameterInfo [NoOfParameter] ;
  Sender DataFromSender ;
  
  parameterInfo[0].minimumThreshold = 0.0;
  parameterInfo[0].maximumThreshold = 60.0;
  
  parameterInfo[1].minimumThreshold = 20.0;
  parameterInfo[1].maximumThreshold = 80.0;
  
  DataFromSender.number_of_values = 50;
  REQUIRE(SenderData(parameterInfo ,&DataFromSender,funp_ReadDataFromSensor) == TRUE);
}
