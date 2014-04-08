/******************************************************************************
 * Copyright (c) 2013 - 2014, AllSeen Alliance. All rights reserved.
 *
 *    Permission to use, copy, modify, and/or distribute this software for any
 *    purpose with or without fee is hereby granted, provided that the above
 *    copyright notice and this permission notice appear in all copies.
 *
 *    THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 *    WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 *    MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 *    ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 *    WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 *    ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 *    OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 ******************************************************************************/

#ifndef CONTROL_GENERATED_H_
#define CONTROL_GENERATED_H_

#include <alljoyn.h>
#include <alljoyn/controlpanel/Widgets/ActionWidget.h>
#include <alljoyn/controlpanel/Widgets/PropertyWidget.h>
#include <alljoyn/controlpanel/Widgets/ContainerWidget.h>
#include <alljoyn/controlpanel/Widgets/LabelWidget.h>
#include <alljoyn/controlpanel/Widgets/DialogWidget.h>
#include <alljoyn/controlpanel/Common/HttpControl.h>
#include <alljoyn/services_common/ServicesCommon.h>

/**
 * Defines and objectPaths
 */

#define GET_WIDGET_VALUE_CASES \
case EN_MYDEVICE_ROOTCONTAINER_GET_VALUE: \
case EN_MYDEVICE_TEMPANDHUMIDITYCONTAINER_GET_VALUE: \
case EN_MYDEVICE_CURRENTTEMPSTRINGPROPERTY_GET_VALUE: \
case EN_MYDEVICE_CURRENTHUMIDITYSTRINGPROPERTY_GET_VALUE: \
case EN_MYDEVICE_CONTROLSCONTAINER_GET_VALUE: \
case EN_MYDEVICE_AC_MODE_GET_VALUE: \
case EN_MYDEVICE_STATUSSTRINGPROPERTY_GET_VALUE: \
case EN_MYDEVICE_SET_TEMPERATURE_GET_VALUE: \
case EN_MYDEVICE_FAN_SPEED_GET_VALUE: \


#define GET_WIDGET_ALL_VALUE_CASES \
case EN_MYDEVICE_ROOTCONTAINER_GET_ALL_VALUES: \
case EN_MYDEVICE_TEMPANDHUMIDITYCONTAINER_GET_ALL_VALUES: \
case EN_MYDEVICE_CURRENTTEMPSTRINGPROPERTY_GET_ALL_VALUES: \
case EN_MYDEVICE_CURRENTHUMIDITYSTRINGPROPERTY_GET_ALL_VALUES: \
case EN_MYDEVICE_CONTROLSCONTAINER_GET_ALL_VALUES: \
case EN_MYDEVICE_AC_MODE_GET_ALL_VALUES: \
case EN_MYDEVICE_STATUSSTRINGPROPERTY_GET_ALL_VALUES: \
case EN_MYDEVICE_SET_TEMPERATURE_GET_ALL_VALUES: \
case EN_MYDEVICE_FAN_SPEED_GET_ALL_VALUES: \


#define GET_ROOT_VALUE_CASES \
case MYDEVICE_ROOT_CONTROLPANEL_ROOTCONTAINER_GET_VALUE: \


#define GET_ROOT_ALL_VALUE_CASES \
case MYDEVICE_ROOT_CONTROLPANEL_ROOTCONTAINER_GET_ALL_VALUES: \


#define SET_VALUE_CASES \
case MYDEVICE_ROOT_CONTROLPANEL_ROOTCONTAINER_SET_VALUE: \
case EN_MYDEVICE_ROOTCONTAINER_SET_VALUE: \
case EN_MYDEVICE_TEMPANDHUMIDITYCONTAINER_SET_VALUE: \
case EN_MYDEVICE_CURRENTTEMPSTRINGPROPERTY_SET_VALUE: \
case EN_MYDEVICE_CURRENTHUMIDITYSTRINGPROPERTY_SET_VALUE: \
case EN_MYDEVICE_CONTROLSCONTAINER_SET_VALUE: \
case EN_MYDEVICE_AC_MODE_SET_VALUE: \
case EN_MYDEVICE_STATUSSTRINGPROPERTY_SET_VALUE: \
case EN_MYDEVICE_SET_TEMPERATURE_SET_VALUE: \
case EN_MYDEVICE_FAN_SPEED_SET_VALUE: \


#define ACTION_CASES \


#define GET_URL_CASES \


#define AJCPS_CONTROLLEE_GENERATED_OBJECTS \
    {  MyDeviceRootContainerObjectPath, ControlPanelInterfaces, AJ_OBJ_FLAG_HIDDEN | AJ_OBJ_FLAG_DISABLED | AJ_OBJ_FLAG_ANNOUNCED  }, \
    {  enMyDeviceRootContainerObjectPath, ContainerInterfaces  }, \
    {  enMyDeviceTempAndHumidityContainerObjectPath, ContainerInterfaces  }, \
    {  enMyDeviceCurrentTempStringPropertyObjectPath, PropertyInterfaces  }, \
    {  enMyDeviceCurrentHumidityStringPropertyObjectPath, PropertyInterfaces  }, \
    {  enMyDeviceControlsContainerObjectPath, ContainerInterfaces  }, \
    {  enMyDeviceAc_modeObjectPath, PropertyInterfaces  }, \
    {  enMyDeviceStatusStringPropertyObjectPath, PropertyInterfaces  }, \
    {  enMyDeviceSet_temperatureObjectPath, PropertyInterfaces  }, \
    {  enMyDeviceFan_speedObjectPath, PropertyInterfaces  }, \


#define AJCPS_CONTROLLEE_GENERATED_OBJECTS_COUNT               10

#define MAX_NUM_LANGUAGES                                      1

#define MYDEVICE_MYLANGUAGES_EN 0

#define MYDEVICE_ROOT_CONTROLPANEL_ROOTCONTAINER_GET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 0, 0, AJ_PROP_GET)
#define MYDEVICE_ROOT_CONTROLPANEL_ROOTCONTAINER_SET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 0, 0, AJ_PROP_SET)
#define MYDEVICE_ROOT_CONTROLPANEL_ROOTCONTAINER_GET_ALL_VALUES             AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 0, 0, AJ_PROP_GET_ALL)
#define MYDEVICE_ROOT_CONTROLPANEL_ROOTCONTAINER_VERSION_PROPERTY           AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 0, 1, 0)

#define EN_MYDEVICE_ROOTCONTAINER_GET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 1, 0, AJ_PROP_GET)
#define EN_MYDEVICE_ROOTCONTAINER_SET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 1, 0, AJ_PROP_SET)
#define EN_MYDEVICE_ROOTCONTAINER_GET_ALL_VALUES             AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 1, 0, AJ_PROP_GET_ALL)
#define EN_MYDEVICE_ROOTCONTAINER_VERSION_PROPERTY           AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 1, 1, 0)
#define EN_MYDEVICE_ROOTCONTAINER_STATES_PROPERTY            AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 1, 1, 1)
#define EN_MYDEVICE_ROOTCONTAINER_OPTPARAMS_PROPERTY         AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 1, 1, 2)
#define EN_MYDEVICE_ROOTCONTAINER_SIGNAL_PROPERTIES_CHANGED  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 1, 1, 3)

#define EN_MYDEVICE_TEMPANDHUMIDITYCONTAINER_GET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 2, 0, AJ_PROP_GET)
#define EN_MYDEVICE_TEMPANDHUMIDITYCONTAINER_SET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 2, 0, AJ_PROP_SET)
#define EN_MYDEVICE_TEMPANDHUMIDITYCONTAINER_GET_ALL_VALUES             AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 2, 0, AJ_PROP_GET_ALL)
#define EN_MYDEVICE_TEMPANDHUMIDITYCONTAINER_VERSION_PROPERTY           AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 2, 1, 0)
#define EN_MYDEVICE_TEMPANDHUMIDITYCONTAINER_STATES_PROPERTY            AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 2, 1, 1)
#define EN_MYDEVICE_TEMPANDHUMIDITYCONTAINER_OPTPARAMS_PROPERTY         AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 2, 1, 2)
#define EN_MYDEVICE_TEMPANDHUMIDITYCONTAINER_SIGNAL_PROPERTIES_CHANGED  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 2, 1, 3)

#define EN_MYDEVICE_CURRENTTEMPSTRINGPROPERTY_GET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 3, 0, AJ_PROP_GET)
#define EN_MYDEVICE_CURRENTTEMPSTRINGPROPERTY_SET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 3, 0, AJ_PROP_SET)
#define EN_MYDEVICE_CURRENTTEMPSTRINGPROPERTY_GET_ALL_VALUES             AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 3, 0, AJ_PROP_GET_ALL)
#define EN_MYDEVICE_CURRENTTEMPSTRINGPROPERTY_VERSION_PROPERTY           AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 3, 1, 0)
#define EN_MYDEVICE_CURRENTTEMPSTRINGPROPERTY_STATES_PROPERTY            AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 3, 1, 1)
#define EN_MYDEVICE_CURRENTTEMPSTRINGPROPERTY_OPTPARAMS_PROPERTY         AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 3, 1, 2)
#define EN_MYDEVICE_CURRENTTEMPSTRINGPROPERTY_SIGNAL_PROPERTIES_CHANGED  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 3, 1, 3)
#define EN_MYDEVICE_CURRENTTEMPSTRINGPROPERTY_VALUE_PROPERTY             AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 3, 1, 4)
#define EN_MYDEVICE_CURRENTTEMPSTRINGPROPERTY_SIGNAL_VALUE_CHANGED       AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 3, 1, 5)

#define EN_MYDEVICE_CURRENTHUMIDITYSTRINGPROPERTY_GET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 4, 0, AJ_PROP_GET)
#define EN_MYDEVICE_CURRENTHUMIDITYSTRINGPROPERTY_SET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 4, 0, AJ_PROP_SET)
#define EN_MYDEVICE_CURRENTHUMIDITYSTRINGPROPERTY_GET_ALL_VALUES             AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 4, 0, AJ_PROP_GET_ALL)
#define EN_MYDEVICE_CURRENTHUMIDITYSTRINGPROPERTY_VERSION_PROPERTY           AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 4, 1, 0)
#define EN_MYDEVICE_CURRENTHUMIDITYSTRINGPROPERTY_STATES_PROPERTY            AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 4, 1, 1)
#define EN_MYDEVICE_CURRENTHUMIDITYSTRINGPROPERTY_OPTPARAMS_PROPERTY         AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 4, 1, 2)
#define EN_MYDEVICE_CURRENTHUMIDITYSTRINGPROPERTY_SIGNAL_PROPERTIES_CHANGED  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 4, 1, 3)
#define EN_MYDEVICE_CURRENTHUMIDITYSTRINGPROPERTY_VALUE_PROPERTY             AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 4, 1, 4)
#define EN_MYDEVICE_CURRENTHUMIDITYSTRINGPROPERTY_SIGNAL_VALUE_CHANGED       AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 4, 1, 5)

#define EN_MYDEVICE_CONTROLSCONTAINER_GET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 5, 0, AJ_PROP_GET)
#define EN_MYDEVICE_CONTROLSCONTAINER_SET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 5, 0, AJ_PROP_SET)
#define EN_MYDEVICE_CONTROLSCONTAINER_GET_ALL_VALUES             AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 5, 0, AJ_PROP_GET_ALL)
#define EN_MYDEVICE_CONTROLSCONTAINER_VERSION_PROPERTY           AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 5, 1, 0)
#define EN_MYDEVICE_CONTROLSCONTAINER_STATES_PROPERTY            AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 5, 1, 1)
#define EN_MYDEVICE_CONTROLSCONTAINER_OPTPARAMS_PROPERTY         AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 5, 1, 2)
#define EN_MYDEVICE_CONTROLSCONTAINER_SIGNAL_PROPERTIES_CHANGED  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 5, 1, 3)

#define EN_MYDEVICE_AC_MODE_GET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 6, 0, AJ_PROP_GET)
#define EN_MYDEVICE_AC_MODE_SET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 6, 0, AJ_PROP_SET)
#define EN_MYDEVICE_AC_MODE_GET_ALL_VALUES             AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 6, 0, AJ_PROP_GET_ALL)
#define EN_MYDEVICE_AC_MODE_VERSION_PROPERTY           AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 6, 1, 0)
#define EN_MYDEVICE_AC_MODE_STATES_PROPERTY            AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 6, 1, 1)
#define EN_MYDEVICE_AC_MODE_OPTPARAMS_PROPERTY         AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 6, 1, 2)
#define EN_MYDEVICE_AC_MODE_SIGNAL_PROPERTIES_CHANGED  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 6, 1, 3)
#define EN_MYDEVICE_AC_MODE_VALUE_PROPERTY             AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 6, 1, 4)
#define EN_MYDEVICE_AC_MODE_SIGNAL_VALUE_CHANGED       AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 6, 1, 5)

#define EN_MYDEVICE_STATUSSTRINGPROPERTY_GET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 7, 0, AJ_PROP_GET)
#define EN_MYDEVICE_STATUSSTRINGPROPERTY_SET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 7, 0, AJ_PROP_SET)
#define EN_MYDEVICE_STATUSSTRINGPROPERTY_GET_ALL_VALUES             AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 7, 0, AJ_PROP_GET_ALL)
#define EN_MYDEVICE_STATUSSTRINGPROPERTY_VERSION_PROPERTY           AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 7, 1, 0)
#define EN_MYDEVICE_STATUSSTRINGPROPERTY_STATES_PROPERTY            AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 7, 1, 1)
#define EN_MYDEVICE_STATUSSTRINGPROPERTY_OPTPARAMS_PROPERTY         AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 7, 1, 2)
#define EN_MYDEVICE_STATUSSTRINGPROPERTY_SIGNAL_PROPERTIES_CHANGED  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 7, 1, 3)
#define EN_MYDEVICE_STATUSSTRINGPROPERTY_VALUE_PROPERTY             AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 7, 1, 4)
#define EN_MYDEVICE_STATUSSTRINGPROPERTY_SIGNAL_VALUE_CHANGED       AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 7, 1, 5)

#define EN_MYDEVICE_SET_TEMPERATURE_GET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 8, 0, AJ_PROP_GET)
#define EN_MYDEVICE_SET_TEMPERATURE_SET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 8, 0, AJ_PROP_SET)
#define EN_MYDEVICE_SET_TEMPERATURE_GET_ALL_VALUES             AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 8, 0, AJ_PROP_GET_ALL)
#define EN_MYDEVICE_SET_TEMPERATURE_VERSION_PROPERTY           AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 8, 1, 0)
#define EN_MYDEVICE_SET_TEMPERATURE_STATES_PROPERTY            AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 8, 1, 1)
#define EN_MYDEVICE_SET_TEMPERATURE_OPTPARAMS_PROPERTY         AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 8, 1, 2)
#define EN_MYDEVICE_SET_TEMPERATURE_SIGNAL_PROPERTIES_CHANGED  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 8, 1, 3)
#define EN_MYDEVICE_SET_TEMPERATURE_VALUE_PROPERTY             AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 8, 1, 4)
#define EN_MYDEVICE_SET_TEMPERATURE_SIGNAL_VALUE_CHANGED       AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 8, 1, 5)

#define EN_MYDEVICE_FAN_SPEED_GET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 9, 0, AJ_PROP_GET)
#define EN_MYDEVICE_FAN_SPEED_SET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 9, 0, AJ_PROP_SET)
#define EN_MYDEVICE_FAN_SPEED_GET_ALL_VALUES             AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 9, 0, AJ_PROP_GET_ALL)
#define EN_MYDEVICE_FAN_SPEED_VERSION_PROPERTY           AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 9, 1, 0)
#define EN_MYDEVICE_FAN_SPEED_STATES_PROPERTY            AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 9, 1, 1)
#define EN_MYDEVICE_FAN_SPEED_OPTPARAMS_PROPERTY         AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 9, 1, 2)
#define EN_MYDEVICE_FAN_SPEED_SIGNAL_PROPERTIES_CHANGED  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 9, 1, 3)
#define EN_MYDEVICE_FAN_SPEED_VALUE_PROPERTY             AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 9, 1, 4)
#define EN_MYDEVICE_FAN_SPEED_SIGNAL_VALUE_CHANGED       AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 9, 1, 5)



extern const char MyDeviceRootContainerObjectPath[];
extern const char enMyDeviceRootContainerObjectPath[];
extern const char enMyDeviceTempAndHumidityContainerObjectPath[];
extern const char enMyDeviceCurrentTempStringPropertyObjectPath[];
extern const char enMyDeviceCurrentHumidityStringPropertyObjectPath[];
extern const char enMyDeviceControlsContainerObjectPath[];
extern const char enMyDeviceAc_modeObjectPath[];
extern const char enMyDeviceStatusStringPropertyObjectPath[];
extern const char enMyDeviceSet_temperatureObjectPath[];
extern const char enMyDeviceFan_speedObjectPath[];


extern ContainerWidget MyDeviceRootContainer;
extern ContainerWidget MyDeviceTempAndHumidityContainer;
extern PropertyWidget MyDeviceCurrentTempStringProperty;
extern PropertyWidget MyDeviceCurrentHumidityStringProperty;
extern ContainerWidget MyDeviceControlsContainer;
extern PropertyWidget MyDeviceAc_mode;
extern PropertyWidget MyDeviceStatusStringProperty;
extern PropertyWidget MyDeviceSet_temperature;
extern PropertyWidget MyDeviceFan_speed;


typedef struct {
    const char* sender;
    uint16_t numSignals;
    int32_t signals[MAX_NUM_LANGUAGES];
} SetValueContext;

typedef struct {
    uint8_t signalType;
    int32_t signalId;
} Signal;

typedef struct {
    uint16_t numSignals;
    Signal signals[MAX_NUM_LANGUAGES * 2];
} ExecuteActionContext;
/**
 *
 * @return
 */
void WidgetsInit();

/**
 * Set Value of a property.
 * @param replyMsg - reply message
 * @param propId - id of property being changed
 * @param context - setvaluecontext. can be used to send signals
 * @return status
 */
AJ_Status SetValueProperty(AJ_Message* replyMsg, uint32_t propId, void* context);

/**
 * Execute Action
 * @param msg - the msg for the response
 * @param msgId - the Action being executed
 * @param context - ExecuteActionContext used to send signals as a result of action
 * @return status
 */
AJ_Status ExecuteAction(AJ_Message* msg, uint32_t msgId, ExecuteActionContext* context);


/* Defines and functions for Tester App */
typedef struct {
    uint32_t msgId;
    uint16_t numParams;
    uint16_t param[3];
} CPSTest;

#define NUMBER_OF_TESTS //NUM_TESTS_GO_HERE

#define ALL_REPLY_CASES                //ALL_REPLIES_GO_HERE

void TestsInit(CPSTest* testsToRun);

void* IdentifyMsgOrPropId(uint32_t identifier, uint16_t* widgetType, uint16_t* propType, uint16_t* language);
void* IdentifyMsgOrPropIdForSignal(uint32_t identifier, uint8_t* isProperty);
uint8_t IdentifyRootMsgOrPropId(uint32_t identifier);
AJSVC_ServiceStatus GeneratedMessageProcessor(AJ_BusAttachment* bus, AJ_Message* msg, AJ_Status* msgStatus);

#endif /* CONTROL_GENERATED_H_ */
