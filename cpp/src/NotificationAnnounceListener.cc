/******************************************************************************
 * Copyright (c) 2013, AllSeen Alliance. All rights reserved.
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

#include <alljoyn/notification/NotificationService.h>

#include "NotificationAnnounceListener.h"
#include "NotificationConstants.h"
#include "Transport.h"

using namespace ajn;
using namespace services;
using namespace nsConsts;
using namespace qcc;

NotificationAnnounceListener::NotificationAnnounceListener() :
    AnnounceHandler(), TAG(TAG_NOTIFICATION_ANNOUNCE_LISTENER)
{

}

NotificationAnnounceListener::~NotificationAnnounceListener()
{

}

void NotificationAnnounceListener::Announce(uint16_t version, uint16_t port, const char* busName, const ObjectDescriptions& objectDescs, const AboutData& aboutData)
{
    GenericLogger* logger = NotificationService::getInstance()->getLogger();
    if (logger)
        logger->debug(TAG, "Received Announce Signal");

    for (AboutClient::ObjectDescriptions::const_iterator it = objectDescs.begin(); it != objectDescs.end(); ++it) {
        std::vector<qcc::String> interfaces = it->second;
        std::vector<qcc::String>::const_iterator interfaceIter;

        for (interfaceIter = interfaces.begin(); interfaceIter != interfaces.end(); ++interfaceIter) {

            if (logger)
                logger->debug(TAG, "Received announce of interface " + *interfaceIter +
                              " for objectpath " + it->first);

            if (0 == interfaceIter->compare(AJ_SA_INTERFACE_NAME)) {
                if (logger)
                    logger->debug(TAG, "Received announce of superAgent interface");

                Transport::getInstance()->listenToSuperAgent(busName);
                return;
            }
        }
    }
}


