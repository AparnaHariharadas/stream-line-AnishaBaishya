#include "BMS_Sender.h"


bool ProcessSenderData(BatteryParameterInfo *parameterInfo ,Sender *DataFromSender, float (*funp_ReadDataFromSensor)(float,float)) {
  int index;
  int inner_index;
  bool isDataReadFromSensor = TRUE;
  for(index=0; index<DataFromSender->number_of_values; index++)
  {
    for(inner_index=0; inner_index<NoOfParameter; inner_index++)
    {
      parameterInfo[inner_index].parameterdata[index] = funp_ReadDataFromSensor(parameterInfo[inner_index].minimumThreshold,parameterInfo[inner_index].maximumThreshold);
      if(parameterInfo[inner_index].parameterdata[index] == NULL)
        isDataReadFromSensor = FALSE;
    }
  }
  if(isDataReadFromSensor == TRUE)
    DisplaySensorDataOnConsole(parameterInfo ,DataFromSender);
  return isDataReadFromSensor;
}

void PrintOnConsole(BatteryParameterInfo *parameterInfo, int index, int inner_index)
{
  if(inner_index == (NoOfParameter-1))
    printf("%f \n",parameterInfo[inner_index].parameterdata[index]);
  else
    printf("%f ,",parameterInfo[inner_index].parameterdata[index]);
}

void DisplaySensorDataOnConsole(BatteryParameterInfo *parameterInfo ,Sender *DataFromSender)
{
  int index;
  int inner_index;
  for(index=0;index<DataFromSender->number_of_values;index++)
  {
    for(inner_index=0; inner_index<NoOfParameter-1; inner_index++)
    {
      PrintOnConsole(parameterInfo,index,inner_index);
    }
    PrintOnConsole(parameterInfo,index,(NoOfParameter-1));
  }
}
