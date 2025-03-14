//
//  MXOCaptureAttributePoint.h
//  MedalliaMXO
//
//  Copyright © 2023 Medallia. Use subject to licensing terms.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

//=========================================
#pragma mark - typedef
//=========================================

/*!
The enum which specifies the type of an element.
 
## Options
- `MXOCaptureElementTypeTextField`: Input value for the text or search field.
- `MXOCaptureElementTypeCheckboxRadio`: Input value for the selected checkbox/radio button.
- `MXOCaptureElementTypeDisplayElem`: Display value for the selected display element.
- `MXOCaptureElementTypeDropDown`: Input value for the selected dropdown list.
- `MXOCaptureElementTypeUnknown`: The unknown Attribute Capture element type.
*/
typedef NS_ENUM(NSInteger, MXOCaptureElementType) {
    /**
    * Input value for the text or search field.
    */
    MXOCaptureElementTypeTextField NS_SWIFT_NAME(textfield),
    /**
    * Input value for the selected checkbox/radio button.
    */
    MXOCaptureElementTypeCheckboxRadio NS_SWIFT_NAME(checkbox_radio),
    /**
    * Display value for the selected display element.
    */
    MXOCaptureElementTypeDisplayElem NS_SWIFT_NAME(display_elem),
    /**
    * Input value for the selected dropdown list.
    */
    MXOCaptureElementTypeDropDown NS_SWIFT_NAME(drop_down),
    /**
    * The unknown Attribute Capture element type.
    */
    MXOCaptureElementTypeUnknown NS_SWIFT_NAME(unknown)
};

/*!
The enum which specifies the type of value to capture from an element.
 
## Options
- `MXOCaptureTypeAttribute`: The name of an Attribute.
- `MXOCaptureTypeText`: Captures a text.
- `MXOCaptureTypeValue`: Captures a Boolean value.
- `MXOCaptureTypeCookie`: Captures data from a cookie on the current page.
- `MXOCaptureTypeUnknown`: The unknown Attribute Capture type.
*/
typedef NS_ENUM(NSInteger, MXOCaptureType) {
    /**
    * The name of an Attribute.
    */
    MXOCaptureTypeAttribute NS_SWIFT_NAME(attribute),
    /**
    * Captures a text.
    */
    MXOCaptureTypeText NS_SWIFT_NAME(text),
    /**
    * Captures a Boolean value.
    */
    MXOCaptureTypeValue NS_SWIFT_NAME(value),
    /**
    * Captures data from a cookie on the current page.
    */
    MXOCaptureTypeCookie NS_SWIFT_NAME(cookie),
    /**
    * The unknown Attribute Capture type.
    */
    MXOCaptureTypeUnknown NS_SWIFT_NAME(unknown),
};

/*!
The enum which specifies the phase in which to capture an Attribute.
 
## Options
- `MXOCapturePhaseLoad`: The Attribute is captured whenever a page is loaded.
- `MXOCapturePhaseOnClick`: The Attribute is captured once clicked or tapped.
- `MXOCapturePhaseParameter`: The Attribute is captured for a query parameter.
- `MXOCapturePhaseUnknown`: The unknown Attribute Capture phase.
*/
typedef NS_ENUM(NSInteger, MXOCapturePhase) {
    /**
    * The Attribute is captured whenever a page is loaded.
    */
    MXOCapturePhaseLoad NS_SWIFT_NAME(phase_load),
    /**
    * The Attribute is captured once clicked or tapped.
    */
    MXOCapturePhaseOnClick NS_SWIFT_NAME(on_click),
    /**
    * The Attribute is captured for a query parameter.
    */
    MXOCapturePhaseParameter NS_SWIFT_NAME(parameter),
    /**
    * The unknown Attribute Capture phase.
    */
    MXOCapturePhaseUnknown NS_SWIFT_NAME(unknown)
};

//=========================================
#pragma mark - MXOCaptureAttributePoint
//=========================================

/*!
Captures Attributes when a user visits an MXO Interaction.
 
## Properties
- `identifier`: The internal MXO id of a Point.
- `path`: The location of an Attribute to capture, such as a button clicked.
- `elementType`: The type of an element.
- `elementName`: The name of an element.
- `elementAttributeName`: The name of an element Attribute to capture.
- `captureDelay`: How long to wait to capture the value.
- `captureType`: The type of a Capture.
- `capturePhase`: The lifecycle time to capture the value.
*/
@interface MXOCaptureAttributePoint : NSObject

//=========================================
#pragma mark - Properties
//=========================================

/*!
The internal MXO id of a Point.
*/
@property (nonatomic, copy, nullable, readonly) NSString *identifier;

/*!
The location of an Attribute to capture, such as a button click.
*/
@property (nonatomic, copy, nullable, readonly) NSString *path;

/*!
The type of an element.
*/
@property (nonatomic, assign, readonly) MXOCaptureElementType elementType;

/*!
The name of an element.
*/
@property (nonatomic, copy, nullable, readonly) NSString *elementName;

/*!
The name of an element Attribute to capture.
*/
@property (nonatomic, copy, nullable, readonly) NSString *elementAttributeName;

/*!
How long to wait to capture the value.
*/
@property (nonatomic, readonly) NSInteger captureDelay;

/*!
The type of a Capture.
*/
@property (nonatomic, assign, readonly) MXOCaptureType captureType;

/*!
The lifecycle time to capture the value.
*/
@property (nonatomic, assign, readonly) MXOCapturePhase capturePhase;

@end

NS_ASSUME_NONNULL_END
