//
//  MXOAsset.h
//  MedalliaMXO
//
//  Copyright © 2023 Medallia. Use subject to licensing terms.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, MXOMimeType) {
    MXOMimeTypeJSON NS_SWIFT_NAME(json),
    MXOMimeTypeTXT NS_SWIFT_NAME(txt),
    MXOMimeTypeHTML NS_SWIFT_NAME(html),
    MXOMimeTypeXML NS_SWIFT_NAME(xml),
    MXOMimeTypeExternal NS_SWIFT_NAME(external),
    MXOMimeTypeUnknown NS_SWIFT_NAME(unknown)
};

@class MXOAssetResponse;

@interface MXOAsset : NSObject

@property (nonatomic, copy, nullable, readonly) NSString *markup;

@property (nonatomic, assign, readonly) MXOMimeType mimeType;

@property (nonatomic, strong, nullable, readonly) NSArray<MXOAssetResponse *> *responses;

@end

NS_ASSUME_NONNULL_END
