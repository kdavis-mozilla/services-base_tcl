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

#include <alljoyn/controlpanel/Common/ControlMarshalUtil.h>
#include <alljoyn/controlpanel/Common/BaseWidget.h>

#define ROOT_INTERFACE_VERSION 1

AJ_Status AddHints(AJ_Message* reply, const uint16_t hints[], uint16_t numHints)
{
    AJ_Status status;
    AJ_Arg arrayArg;

    CPS_CHECK(AJ_MarshalContainer(reply, &arrayArg, AJ_ARG_ARRAY));
    uint16_t cnt;
    for (cnt = 0; cnt < numHints; cnt++)
        CPS_CHECK(AJ_MarshalArgs(reply, "q", hints[cnt]));

    return AJ_MarshalCloseContainer(reply, &arrayArg);
}

AJ_Status AddConstraintValue(AJ_Message* reply, const char* sig, const void* value, const char* displayValue)
{
    AJ_Status status;
    AJ_Arg structArg;

    CPS_CHECK(AJ_MarshalContainer(reply, &structArg, AJ_ARG_STRUCT));
    CPS_CHECK(MarshalVariant(reply, sig, value));
    CPS_CHECK(AJ_MarshalArgs(reply, "s", displayValue));

    return AJ_MarshalCloseContainer(reply, &structArg);
}

AJ_Status AddConstraintRange(AJ_Message* reply, const char* valueSig, const void* min, const void* max, const void* increment)
{
    AJ_Status status;
    AJ_Arg structArg;

    CPS_CHECK(AJ_MarshalContainer(reply, &structArg, AJ_ARG_STRUCT));
    CPS_CHECK(MarshalVariant(reply, valueSig, min));
    CPS_CHECK(MarshalVariant(reply, valueSig, max));
    CPS_CHECK(MarshalVariant(reply, valueSig, increment));

    return AJ_MarshalCloseContainer(reply, &structArg);
}

AJ_Status StartComplexOptionalParam(AJ_Message* reply, AJ_Arg* arg, uint16_t key, const char* sig)
{
    AJ_Status status;

    CPS_CHECK(AJ_MarshalContainer(reply, arg, AJ_ARG_DICT_ENTRY));
    CPS_CHECK(AJ_MarshalArgs(reply, "q", key));

    return AJ_MarshalVariant(reply, sig);
}

AJ_Status AddBasicOptionalParam(AJ_Message* reply, uint16_t key, const char* sig, const void* value)
{
    AJ_Status status;
    AJ_Arg dictArg;

    CPS_CHECK(AJ_MarshalContainer(reply, &dictArg, AJ_ARG_DICT_ENTRY));
    CPS_CHECK(AJ_MarshalArgs(reply, "q", key));
    CPS_CHECK(MarshalVariant(reply, sig, value));

    return AJ_MarshalCloseContainer(reply, &dictArg);
}

AJ_Status AddPropertyForGetAll(AJ_Message* reply, char* key, const char* sig,
                               BaseWidget* widget, uint16_t lang, MarshalWidgetFptr functionPtr)
{
    AJ_Status status;
    AJ_Arg dictArg;

    CPS_CHECK(AJ_MarshalContainer(reply, &dictArg, AJ_ARG_DICT_ENTRY));
    CPS_CHECK(AJ_MarshalArgs(reply, "s", key));
    CPS_CHECK(AJ_MarshalVariant(reply, sig));
    CPS_CHECK(functionPtr(widget, reply, lang));

    return AJ_MarshalCloseContainer(reply, &dictArg);
}

AJ_Status MarshalVariant(AJ_Message* reply, const char* sig, const void* value)
{
    AJ_Status status;
    CPS_CHECK(AJ_MarshalVariant(reply, sig));

    if (value == 0)
        return AJ_ERR_UNEXPECTED;

    if (strcmp(sig, "s") == 0)
        return AJ_MarshalArgs(reply, sig, *((char**)value));
    else if (strcmp(sig, "i") == 0)
        return AJ_MarshalArgs(reply, sig, *((int*)value));
    else if (strcmp(sig, "b") == 0)
        return AJ_MarshalArgs(reply, sig, *((uint8_t*)value));
    else if (strcmp(sig, "q") == 0)
        return AJ_MarshalArgs(reply, sig, *((uint16_t*)value));
    else if (strcmp(sig, "u") == 0)
        return AJ_MarshalArgs(reply, sig, *((uint32_t*)value));
    else if (strcmp(sig, "d") == 0)
        return AJ_MarshalArgs(reply, sig, *((double*)value));
    else if (strcmp(sig, "g") == 0)
        return AJ_MarshalArgs(reply, sig, *((char**)value));
    else if (strcmp(sig, "o") == 0)
        return AJ_MarshalArgs(reply, sig, *((char**)value));
    else if (strcmp(sig, "n") == 0)
        return AJ_MarshalArgs(reply, sig, *((int16_t*)value));
    else if (strcmp(sig, "t") == 0)
        return AJ_MarshalArgs(reply, sig, *((uint64_t*)value));
    else if (strcmp(sig, "x") == 0)
        return AJ_MarshalArgs(reply, sig, *((int64_t*)value));
    else if (strcmp(sig, "y") == 0)
        return AJ_MarshalArgs(reply, sig, *((char*)value));
    else if (strcmp(sig, "h") == 0)
        return AJ_MarshalArgs(reply, sig, *((int*)value));

    return AJ_ERR_UNEXPECTED;
}

AJ_Status MarshalAllRootProperties(AJ_Message* reply)
{
    AJ_Status status;
    AJ_Arg rootGetAllArray;
    AJ_Arg dictArg;

    CPS_CHECK(AJ_MarshalContainer(reply, &rootGetAllArray, AJ_ARG_ARRAY));
    CPS_CHECK(AJ_MarshalContainer(reply, &dictArg, AJ_ARG_DICT_ENTRY));
    CPS_CHECK(AJ_MarshalArgs(reply, "s", PROPERTY_TYPE_VERSION_NAME));
    CPS_CHECK(AJ_MarshalVariant(reply, PROPERTY_TYPE_VERSION_SIG));
    CPS_CHECK(MarshalVersionRootProperties(reply));
    CPS_CHECK(AJ_MarshalCloseContainer(reply, &dictArg));
    return AJ_MarshalCloseContainer(reply, &rootGetAllArray);
}

AJ_Status MarshalVersionRootProperties(AJ_Message* reply)
{
    return AJ_MarshalArgs(reply, PROPERTY_TYPE_VERSION_SIG, ROOT_INTERFACE_VERSION);
}
