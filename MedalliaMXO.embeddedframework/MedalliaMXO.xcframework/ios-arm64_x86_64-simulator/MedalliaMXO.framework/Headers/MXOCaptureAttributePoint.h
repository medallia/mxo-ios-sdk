//
//  MXOCaptureAttributePoint.h
//  MedalliaMXO
//
//  Copyright © 2023 Medallia. Use subject to licensing terms.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, MXOCaptureElementType) {
    MXOCaptureElementTypeTextField NS_SWIFT_NAME(textfield),
    MXOCaptureElementTypeCheckboxRadio NS_SWIFT_NAME(checkbox_radio),
    MXOCaptureElementTypeDisplayElem NS_SWIFT_NAME(display_elem),
    MXOCaptureElementTypeDropDown NS_SWIFT_NAME(drop_down),
    MXOCaptureElementTypeUnknown NS_SWIFT_NAME(unknown)
};

typedef NS_ENUM(NSInteger, MXOCaptureType) {
    MXOCaptureTypeAttribute NS_SWIFT_NAME(attribute),
    MXOCaptureTypeText NS_SWIFT_NAME(text),
    MXOCaptureTypeValue NS_SWIFT_NAME(value),
    MXOCaptureTypeCookie NS_SWIFT_NAME(cookie),
    MXOCaptureTypeUnknown NS_SWIFT_NAME(unknown),
};

typedef NS_ENUM(NSInteger, MXOCapturePhase) {
    MXOCapturePhaseLoad NS_SWIFT_NAME(phase_load),
    MXOCapturePhaseOnClick NS_SWIFT_NAME(on_click),
    MXOCapturePhaseParameter NS_SWIFT_NAME(parameter),
    MXOCapturePhaseUnknown NS_SWIFT_NAME(unknown)
};


@interface MXOCaptureAttributePoint : NSObject

@property (nonatomic, copy, nullable, readonly) NSString *identifier;

@property (nonatomic, copy, nullable, readonly) NSString *path;

@property (nonatomic, assign, readonly) MXOCaptureElementType elementType;

@property (nonatomic, copy, nullable, readonly) NSString *elementName;

@property (nonatomic, copy, nullable, readonly) NSString *elementAttributeName;

@property (nonatomic, readonly) NSInteger captureDelay;

@property (nonatomic, assign, readonly) MXOCaptureType captureType;

@property (nonatomic, assign, readonly) MXOCapturePhase capturePhase;

@end

NS_ASSUME_NONNULL_END
