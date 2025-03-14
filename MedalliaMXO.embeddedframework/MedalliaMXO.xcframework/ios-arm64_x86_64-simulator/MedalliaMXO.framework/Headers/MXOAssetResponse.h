//
//  MXOAssetResponse.h
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
The enum which specifies how a user responded to an MXO Asset response.
 
## Options
- `MXOAssetResponseSentimentPositive`: The positive tap on an Asset.
- `MXOAssetResponseSentimentNeutral`: The Asset is dismissed or ignored.
- `MXOAssetResponseSentimentNegative`: The Asset is rejected.
- `MXOAssetResponseSentimentUnknown`: Unknown response.
*/
typedef NS_ENUM(NSInteger, MXOAssetResponseSentiment) {
    /**
    * The positive tap on an Asset.
    */
    MXOAssetResponseSentimentPositive NS_SWIFT_NAME(positive),
    /**
    * The Asset is dismissed or ignored.
    */
    MXOAssetResponseSentimentNeutral NS_SWIFT_NAME(neutral),
    /**
    * The Asset is rejected.
    */
    MXOAssetResponseSentimentNegative NS_SWIFT_NAME(negative),
    /**
    * Unknown response.
    */
    MXOAssetResponseSentimentUnknown NS_SWIFT_NAME(unknown)
};

/*!
The enum which specifies the location of an MXO Asset response.
 
## Options
- `MXOAssetResponseTargetInApp`: The Asset is targeted to the same app.
- `MXOAssetResponseTargetExternal`: The Asset is targeted to an external `URL`.
- `MXOAssetResponseTargetContext`: The Asset is targeted to an Action context.
- `MXOAssetResponseTargetUnknown`: Unknown response.
*/
typedef NS_ENUM(NSInteger, MXOAssetResponseTarget) {
    /**
    * The Asset is targeted to the same app.
    */
    MXOAssetResponseTargetInApp NS_SWIFT_NAME(in_app),
    /**
    * The Asset is targeted to an external `URL`.
    */
    MXOAssetResponseTargetExternal NS_SWIFT_NAME(external),
    /**
    * The Asset is targeted to an Action context.
    */
    MXOAssetResponseTargetContext NS_SWIFT_NAME(context),
    /**
    * Unknown response.
    */
    MXOAssetResponseTargetUnknown NS_SWIFT_NAME(unknown)
};

@class MXOResponseCode;

//=========================================
#pragma mark - MXOAssetResponse
//=========================================

/*!
The MXO Asset response for tracking.
 
## Properties
- `code`: The code to send to MXO when an Asset is responded to.
- `sentiment`: The type of response to track.
- `label`: The label to show if desired.
- `imageUrl`: The image to load if desired.
- `targetUrl`: The target `URL` to load if desired.
- `target`: The location the sentiment should send to a user.
*/
@interface MXOAssetResponse : NSObject

//=========================================
#pragma mark - Properties
//=========================================

/*!
The code to send to MXO when an Asset is responded to.
*/
@property (nonatomic, strong, nullable, readonly) MXOResponseCode *code;

/*!
The type of response to track.
*/
@property (nonatomic, assign, readonly) MXOAssetResponseSentiment sentiment;

/*!
The label to show if desired.
*/
@property (nonatomic, strong, nullable, readonly) NSString *label;

/*!
The image to load if desired.
*/
@property (nonatomic, strong, nullable, readonly) NSString *imageUrl;

/*!
The target `URL` to load if desired.
*/
@property (nonatomic, strong, nullable, readonly) NSString *targetUrl;

/*!
The location the sentiment should send to a user.
*/
@property (nonatomic, assign, readonly) MXOAssetResponseTarget target;

@end

NS_ASSUME_NONNULL_END
