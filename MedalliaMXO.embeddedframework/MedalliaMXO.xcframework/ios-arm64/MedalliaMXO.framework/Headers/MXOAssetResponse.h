//
//  MXOAssetResponse.h
//  MedalliaMXO
//
//  Copyright © 2023 Medallia. Use subject to licensing terms.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, MXOAssetResponseSentiment) {
    MXOAssetResponseSentimentPositive NS_SWIFT_NAME(positive),
    MXOAssetResponseSentimentNeutral NS_SWIFT_NAME(neutral),
    MXOAssetResponseSentimentNegative NS_SWIFT_NAME(negative),
    MXOAssetResponseSentimentUnknown NS_SWIFT_NAME(unknown)
};

@class MXOResponseCode;

@interface MXOAssetResponse : NSObject

@property (nonatomic, strong, nullable, readonly) MXOResponseCode *code;

@property (nonatomic, assign, readonly) MXOAssetResponseSentiment sentiment;

@end

NS_ASSUME_NONNULL_END
