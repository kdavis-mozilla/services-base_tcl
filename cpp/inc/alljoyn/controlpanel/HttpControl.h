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

#ifndef HTTPCONTROL_H_
#define HTTPCONTROL_H_

#include <alljoyn/BusObject.h>
#include <alljoyn/controlpanel/WidgetEnums.h>

namespace ajn {
namespace services {

class ControlPanelDevice;
class HttpControlBusObject;

/**
 * HttpControl class. Allows definition of a url
 */
class HttpControl {
  public:

    /**
     * Constructor for HttpControl
     * @param url - url of HttpControl
     */
    HttpControl(qcc::String const& url);

    /**
     * Constructor for HttpControl
     * @param url - url of HttpControl
     */
    HttpControl(qcc::String const& objectPath, ControlPanelDevice* device);

    /**
     * Destructor of HttpControl
     */
    virtual ~HttpControl();

    /**
     * Get the Interface Version of the HttpControl
     * @return interface Version
     */
    const uint16_t getInterfaceVersion() const;

    /**
     * Register the HttpControl BusObject
     * @param bus - bus used for registering the object
     * @param unitName - name of unit
     * @return status - success/failure
     */
    QStatus registerObjects(BusAttachment* bus, qcc::String const& unitName);

    /**
     * Register the HttpControl BusObject
     * @param bus - bus used for registering the object
     * @return status - success/failure
     */
    QStatus registerObjects(BusAttachment* bus);

    /**
     * Unregister the HttpControl BusObject
     * @param bus - bus used to unregister the object
     * @return status - success/failure
     */
    QStatus unregisterObjects(BusAttachment* bus);

    /**
     * Fill MsgArg passed in with Url
     * @param val - msgArg to fill
     * @return status - success/failure
     */
    QStatus fillUrlArg(MsgArg& val);

    /**
     * Read MsgArg passed in and use it to set the url
     * @param val - MsgArg passed in
     * @return status - success/failure
     */
    QStatus readUrlArg(MsgArg const& val);

    /**
     * Get the Device that contains this HttpControl
     * @return ControlPanelDevice
     */
    ControlPanelDevice* getDevice() const;

    /**
     * Get the Url for the HttpControl
     * @return url
     */
    const qcc::String& getUrl() const;

    /**
     * Get the WidgetMode of this HttpControl
     * @return widgetMode
     */
    WidgetMode getWidgetMode() const;

    //TODO: Possibly switch setVersion for readVersionArg
    /**
     * Set the version of this HttpControl
     * @param version
     */
    void setVersion(uint16_t version);

  private:

    /**
     * Url of HttpControl
     */
    qcc::String m_Url;

    /**
     * ObjectPath of HttpControl
     */
    qcc::String m_ObjectPath;

    /**
     * BusObject of HttpControl
     */
    HttpControlBusObject* m_HttpControlBusObject;

    /**
     * The Device containing the HttpControl
     */
    ControlPanelDevice* m_Device;

    /**
     * The mode of the Widget
     */
    WidgetMode m_WidgetMode;

    /**
     * Version of the Widget
     */
    uint16_t m_Version;
};
} //namespace services
} //namespace ajn

#endif /* HTTPCONTROL_H_ */
