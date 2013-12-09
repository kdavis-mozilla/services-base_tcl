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

#include <alljoyn/controlpanel/Widgets/PropertyWidget.h>
#include <alljoyn/controlpanel/Common/ControlMarshalUtil.h>
#include <alljoyn/controlpanel/Common/DateTimeUtil.h>

void initializePropertyWidget(PropertyWidget* widget)
{
    initializeBaseWidget(&widget->base);
    widget->signature = 0;
    widget->getValue = 0;
    widget->propertyType = SINGLE_VALUE_PROPERTY;

    initializePropertyOptParam(&widget->optParams);
    widget->optParams.constraintRange.signature = &widget->signature;

    widget->base.marshalOptParam = &marshalPropertyOptParam;
    widget->base.marshalAllProp = &marshalAllPropertyProperties;
}

AJ_Status marshalPropertyValue(PropertyWidget* widget, AJ_Message* reply, uint16_t language)
{
    switch (widget->propertyType) {
    case SINGLE_VALUE_PROPERTY:
        return MarshalVariant(reply, widget->signature, widget->getValue());

    case DATE_VALUE_PROPERTY:
        return marshalDatePropertyValue(widget->getValue(), reply);

    case TIME_VALUE_PROPERTY:
        return marshalTimePropertyValue(widget->getValue(), reply);
    }
    return AJ_ERR_UNEXPECTED;
}

AJ_Status unmarshalPropertyValue(PropertyWidget* widget, AJ_Message* message, void* newValue, const char* lockerId)
{
    AJ_Status status = AJ_ERR_UNEXPECTED;

    switch (widget->propertyType) {
    case SINGLE_VALUE_PROPERTY:
        return AJ_UnmarshalArgs(message, widget->signature, newValue);

    case DATE_VALUE_PROPERTY:
        return unmarshalDatePropertyValue(newValue, message);

    case TIME_VALUE_PROPERTY:
        return unmarshalTimePropertyValue(newValue, message);
    }
    return status;
}

void initializePropertyOptParam(PropertyOptParams* optParams)
{
    optParams->unitOfMeasure = 0;
    optParams->getUnitOfMeasure = 0;

    optParams->constraintList = 0;
    optParams->numConstraints = 0;

    optParams->constraintRangeDefined = FALSE;
    initializeConstraintRange(&optParams->constraintRange);
}

AJ_Status marshalPropertyOptParam(BaseWidget* widget, AJ_Message* reply, uint16_t language)
{
    PropertyOptParams* optParams = &((PropertyWidget*)widget)->optParams;
    AJ_Status status;
    AJ_Arg propertyOptParams;

    CPS_CHECK(StartOptionalParams(reply, &propertyOptParams));

    CPS_CHECK(marshalBaseOptParam(widget, reply, language));

    if (optParams->getUnitOfMeasure) {
        const char* unitOfMeasure = optParams->getUnitOfMeasure(language);
        CPS_CHECK(AddBasicOptionalParam(reply, PROPERTY_UNIT_OF_MEASURE,
                                        PROPERTY_UNIT_OF_MEASURE_SIG, &unitOfMeasure));
    } else if (optParams->unitOfMeasure) {
        const char* unitOfMeasure = optParams->unitOfMeasure[language];
        CPS_CHECK(AddBasicOptionalParam(reply, PROPERTY_UNIT_OF_MEASURE,
                                        PROPERTY_UNIT_OF_MEASURE_SIG, &unitOfMeasure));
    }

    if (optParams->constraintList && optParams->numConstraints) {
        CPS_CHECK(marshalConstraintList(optParams->constraintList, reply,
                                        optParams->numConstraints, ((PropertyWidget*)widget)->signature, language));
    }

    if (optParams->constraintRangeDefined) {
        CPS_CHECK(marshalConstraintRange(&optParams->constraintRange, reply));
    }

    return AJ_MarshalCloseContainer(reply, &propertyOptParams);
}

AJ_Status marshalAllPropertyProperties(BaseWidget* widget, AJ_Message* reply, uint16_t language)
{
    AJ_Status status;
    AJ_Arg propertyGetAllArray;

    CPS_CHECK(AJ_MarshalContainer(reply, &propertyGetAllArray, AJ_ARG_ARRAY));

    CPS_CHECK(marshalAllBaseProperties(widget, reply, language));

    CPS_CHECK(AddPropertyForGetAll(reply, PROPERTY_TYPE_OPTPARAMS_NAME, PROPERTY_TYPE_OPTPARAMS_SIG,
                                   widget, language, marshalPropertyOptParam));

    CPS_CHECK(AddPropertyForGetAll(reply, PROPERTY_TYPE_VALUE_NAME, PROPERTY_TYPE_VALUE_SIG,
                                   widget, language, (MarshalWidgetFptr)marshalPropertyValue));

    return AJ_MarshalCloseContainer(reply, &propertyGetAllArray);
}
