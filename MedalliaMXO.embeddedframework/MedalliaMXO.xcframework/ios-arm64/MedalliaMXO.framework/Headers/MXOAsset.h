//
//  MXOAsset.h
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
The enum which specifies possible types of MXO Assets.
 
## Options
- `MXOMimeTypeJSON`: The Asset of a `json` type.
- `MXOMimeTypeTXT`: The Asset of a `text` type.
- `MXOMimeTypeHTML`: The Asset of an `html` type.
- `MXOMimeTypeXML`: The Asset of an `xml` type.
- `MXOMimeTypeExternal`: The Asset of an `external` type.
- `MXOMimeTypeUnknown`: Unknown Asset type.
*/
typedef NS_ENUM(NSInteger, MXOMimeType) {
    /**
    * The Asset of a `json` type.
    */
    MXOMimeTypeJSON NS_SWIFT_NAME(json),
    /**
    * The Asset of a `text` type.
    */
    MXOMimeTypeTXT NS_SWIFT_NAME(txt),
    /**
    * The Asset of an `html` type.
    */
    MXOMimeTypeHTML NS_SWIFT_NAME(html),
    /**
    * The Asset of an `xml` type.
    */
    MXOMimeTypeXML NS_SWIFT_NAME(xml),
    /**
    * The Asset of an `external` type.
    */
    MXOMimeTypeExternal NS_SWIFT_NAME(external),
    /**
    * Unknown Asset type.
    */
    MXOMimeTypeUnknown NS_SWIFT_NAME(unknown)
};

@class MXOAssetResponse;

//=========================================
#pragma mark - MXOAsset
//=========================================

/*!
Captures Attributes when a user visits an MXO Interaction.
 
## Properties
- `markup`: The language markup for presenting an Asset.
- `mimeType`: The markup language type.
- `responses`: Optional responses for informing the MXO of a user Interaction with an Asset.
- `contentUrl`: The remote location an Asset represents.
*/
@interface MXOAsset : NSObject

//=========================================
#pragma mark - Properties
//=========================================

/*!
The language markup for presenting an Asset.
*/
@property (nonatomic, copy, nullable, readonly) NSString *markup;

/*!
The markup language type.
*/
@property (nonatomic, assign, readonly) MXOMimeType mimeType;

/*!
Optional responses for informing the MXO of a user Interaction with an Asset.
*/
@property (nonatomic, strong, nullable, readonly) NSArray<MXOAssetResponse *> *responses;

/*!
The remote location an Asset represents.
*/
@property (nonatomic, strong, nullable, readonly) NSString *contentUrl;

@end

NS_ASSUME_NONNULL_END
