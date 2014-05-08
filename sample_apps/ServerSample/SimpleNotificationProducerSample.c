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

/**
 * Per-module definition of the current module for debug logging.  Must be defined
 * prior to first inclusion of aj_debug.h.
 * The corresponding flag dbgAJSVCAPP is defined in the containing sample app.
 */
#define AJ_MODULE AJSVCAPP
#include <aj_debug.h>
#include <aj_crypto.h>

#include <NotificationProducerSample.h>
#include <alljoyn/notification/NotificationCommon.h>
#include <alljoyn/notification/NotificationProducer.h>

#ifdef __linux
#include <NotificationProducerSampleUtil.h>
#else
#define MESSAGES_INTERVAL 10000
#define Producer_GetNotificationFromUser(...) do { } while (0)
#define Producer_SetupEnv(...) do { } while (0)
#define Producer_GetShouldDeleteNotificationFromUser(...) do { } while (0)
#define Producer_FreeNotification(...) do { } while (0)
#endif

#ifndef NDEBUG
extern AJ_EXPORT uint8_t dbgAJSVCAPP;
#endif

#define NUM_CUSTOMS 2
#define NUM_TEXTS   2
#define NUM_RICH_AUDIO 2

/**
 * Static non consts - sample application specific
 */
const static char* lang1  = "en";
const static char* lang2 = "de-AT";
const static char* hello1 = "Hello AJL World";
const static char* hello2 = "Hallo AJL Welt";
const static char* onKey = "On";
const static char* offKey = "Off";
const static char* HelloVal = "Hello";
const static char* GoodbyeVal = "Goodbye";
const static char* Audio1URL = "http://www.getAudio1.org";
const static char* Audio2URL = "http://www.getAudio2.org";
const static char* Icon1URL = "http://www.getIcon1.org";
const static char* controlPanelServiceObjectPath = "/ControlPanel/MyDevice/areYouSure";
const static char* richIconObjectPath = "/icon/MyDevice";
const static char* richAudioObjectPath = "/audio/MyDevice";
static uint8_t inputMode = 0;
static AJ_Time isMessageTime;
static uint32_t nextMessageTime = MESSAGES_INTERVAL;
AJNS_DictionaryEntry textToSend[NUM_TEXTS], customAttributesToSend[NUM_CUSTOMS], richAudioUrls[NUM_RICH_AUDIO];

typedef enum _PriorityType {
    PRIORITY_TYPE_FIXED,
    PRIORITY_TYPE_RANDOM,
} PriorityType;

static PriorityType priorityType = PRIORITY_TYPE_FIXED;

typedef enum _IntervalType {
    INTERVAL_TYPE_FIXED,
    INTERVAL_TYPE_RANDOM,
} IntervalType;

static IntervalType intervalType = INTERVAL_TYPE_RANDOM;

#define FIXED_MESSAGE_TYPE AJNS_NOTIFICATION_MESSAGE_TYPE_INFO
#define FIXED_TTL 20000

/**
 * Initial the Notifications that will be used during this sample app
 */
static AJNS_NotificationContent notificationContent;
static void InitNotification()
{
    notificationContent.numCustomAttributes = NUM_CUSTOMS;
    customAttributesToSend[0].key   = onKey;
    customAttributesToSend[0].value = HelloVal;
    customAttributesToSend[1].key   = offKey;
    customAttributesToSend[1].value = GoodbyeVal;
    notificationContent.customAttributes = customAttributesToSend;

    notificationContent.numTexts = NUM_TEXTS;
    textToSend[0].key   = lang1;
    textToSend[0].value = hello1;
    textToSend[1].key   = lang2;
    textToSend[1].value = hello2;
    notificationContent.texts = textToSend;

    notificationContent.numAudioUrls = NUM_RICH_AUDIO;
    richAudioUrls[0].key   = lang1;
    richAudioUrls[0].value = Audio1URL;
    richAudioUrls[1].key   = lang2;
    richAudioUrls[1].value = Audio2URL;
    notificationContent.richAudioUrls = richAudioUrls;

    notificationContent.richIconUrl = Icon1URL;
    notificationContent.richIconObjectPath = richIconObjectPath;
    notificationContent.richAudioObjectPath = richAudioObjectPath;
    notificationContent.controlPanelServiceObjectPath = controlPanelServiceObjectPath;
}

/**
 * Initialize service
 */
AJ_Status NotificationProducer_Init()
{
    AJ_Status status = AJ_OK;

    Producer_SetupEnv(&inputMode);
    InitNotification();
    AJ_InitTimer(&isMessageTime);
    isMessageTime.seconds -= nextMessageTime / 1000; // Expire next message timer
    isMessageTime.milliseconds -= nextMessageTime % 1000; // Expire next message timer
    status = AJNS_Producer_Start();

    return status;
}

/**
 * Meant to simulate scenario where sometimes Notifications are sent when
 * DoWork is called and sometimes not and also toggle between a regular
 * notification and a notication with action.
 * Send the notification every MESSAGES_INTERVAL milliseconds.
 */
static void PossiblySendNotification(AJ_BusAttachment* busAttachment)
{
    AJ_Status status;
    uint16_t messageType = FIXED_MESSAGE_TYPE;
    uint32_t ttl = FIXED_TTL;
    uint32_t serialNum;
    uint32_t random;
    uint32_t elapsed = AJ_GetElapsedTime(&isMessageTime, TRUE);
    static uint32_t offset = 0;

    if (elapsed >= nextMessageTime) {
        if (!inputMode) {
            notificationContent.controlPanelServiceObjectPath = ((notificationContent.controlPanelServiceObjectPath == NULL) ? controlPanelServiceObjectPath : NULL); // Toggle notification with action ON/OFF
            if (priorityType == PRIORITY_TYPE_RANDOM) { // Randomize message type if priority type is RANDOM
                AJ_RandBytes((uint8_t*)&random, sizeof(random));
                messageType = (uint16_t)(((random & 0xFF) * AJNS_NUM_MESSAGE_TYPES) / 0xFF);
            }
            if (intervalType == INTERVAL_TYPE_RANDOM) { // Randomize next message time if interval type is RANDOM
                AJ_RandBytes((uint8_t*)&random, sizeof(random));
                if (elapsed < MESSAGES_INTERVAL) {
                    offset += MESSAGES_INTERVAL - elapsed;
                } else {
                    offset = 0;
                }
                nextMessageTime = (((random & 0xFFFF) * MESSAGES_INTERVAL) / 0xFFFF) + offset;
                AJ_AlwaysPrintf(("\n\nRANDOM: %x => nextMessageTime: %u offset: %u\n\n", random & 0xFFFF, nextMessageTime, offset));
            }
        } else {
            Producer_GetNotificationFromUser(&notificationContent, &messageType, &ttl, &nextMessageTime);
        }
        status = AJNS_Producer_SendNotification(busAttachment, &notificationContent, messageType, ttl, &serialNum);
        AJ_AlwaysPrintf(("Send Message Type: %d returned: '%s'\n", messageType, AJ_StatusText(status)));
        if (inputMode) {
            Producer_FreeNotification(&notificationContent);
        }
        AJ_InitTimer(&isMessageTime);
    }
}

/**
 * Allow the user the possibility to delete sent Notifications when DoWork is called.
 * Give the user an option to delete a notification a second after one was sent.
 */
static void PossiblyDeleteNotification(AJ_BusAttachment* busAttachment)
{
    AJ_Status status;
    uint8_t delMsg = FALSE;
    uint16_t delMsgType = AJNS_NOTIFICATION_MESSAGE_TYPE_INFO;

    if (inputMode) {
        if (AJ_GetElapsedTime(&isMessageTime, FALSE) >= 1000) {
            Producer_GetShouldDeleteNotificationFromUser(busAttachment, &delMsg, &delMsgType);
            if (delMsg) {
                status = AJNS_Producer_DeleteLastNotification(busAttachment, delMsgType);
                AJ_AlwaysPrintf(("Delete Last Message Type: %d returned: '%s'\n", delMsgType, AJ_StatusText(status)));
            }
        }
    }
}

void NotificationProducer_DoWork(AJ_BusAttachment* busAttachment)
{
    PossiblySendNotification(busAttachment);
    PossiblyDeleteNotification(busAttachment);
}

AJ_Status NotificationProducer_Finish()
{
    return AJ_OK;
}
